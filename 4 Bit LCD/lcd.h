#include<lpc214x.h>
#include "C:/ArmExtendedUtilities.h"
#define delll 2
class lcd{
	public:
		private:
		gpio_pin rs,rw,en,d3,d2,d1,d0;
		public:
			
		void setlow(gpio_pin pin){
			if(pin.port==1){
				IOCLR1 |= (1<<pin.pin); 
			}
			else if(pin.port==0){
				IOCLR0 |= (1<<pin.pin); 
			}
		}
		
		void sethigh(gpio_pin pin){
			if(pin.port==1){
				IOSET1 |= (1<<pin.pin); 
			}
			else if(pin.port==0){
				IOSET0 |= (1<<pin.pin); 
			}
		}
		
		void pulse(gpio_pin pin){
			if(pin.port == 1){
				IODIR1 |= (1<<pin.pin);
				IOSET1 |= (1<<pin.pin);
				delay(delll);
				IOCLR1 |= (1<<pin.pin);
				delay(delll);
			}
		}
		
		
		void set_mode(){
			all_low();
			delay(100);
			char command = 0x02;
			gpio_pin lcd_pins[] = {d3,d2,d1,d0};
			setlow(rs);
			setlow(rw);
			for(int i=0;i<=3;i++){
				if((command&(1<<i))==(1<<i)){
					sethigh(lcd_pins[i]);
				}
				else{
					setlow(lcd_pins[i]);
				}
			}
			pulse(en);
		}
		
		void init(gpio_pin in_rs,gpio_pin in_rw,gpio_pin in_en,gpio_pin in_d3,gpio_pin in_d2,gpio_pin in_d1,gpio_pin in_d0){
			// There's a bug, and since i am too lazy to fiz it, we gotta live with it. 
			// the first datapin argument is the LSB or D4 on lcd , 2nd is D5 and So the 3rd and 4th.
			IODIR1 = 0xffffffff;
			rs = in_rs;
			rw = in_rw;
			en = in_en;
			d0 = in_d0;
			d1 = in_d1;
			d2 = in_d2;
			d3 = in_d3;
			all_low();
			set_mode();
			send_command(0x02);
			send_command(0x28);       // 4-bit mode - 2 line - 5x7 font.
			send_command(0x0E);
			send_command(0x0C);       // Display no cursor - no blink.
			send_command(0x06);       // Automatic Increment - No Display shift.
			send_command(0x80);       // Address DDRAM with 0 offset 80h.
		}
		void all_low(){
			setlow(rs);
			setlow(rw);
			setlow(en);
			setlow(d0);
			setlow(d1);
			setlow(d2);
			setlow(d3);
		}
		void send_command(char command){
			gpio_pin lcd_pins[] = {d3,d2,d1,d0};
			all_low();
			setlow(rs);
			setlow(rw);
			for(int i=0;i<=3;i++){
				if((command&(1<<(i+4)))==(1<<(i+4))){
					sethigh(lcd_pins[i]);
				}
				else{
					setlow(lcd_pins[i]);
				}
			}
			pulse(en);
			for(int i=0;i<=3;i++){
				if((command&(1<<i))==(1<<i)){
					sethigh(lcd_pins[i]);
				}
				else{
					setlow(lcd_pins[i]);
				}
			}
			pulse(en);
			
			
		}
		void clear(){
				send_command(0x01);
		}
		void print_char(char ch){
			all_low();
			gpio_pin lcd_pins[] = {d3,d2,d1,d0};
			sethigh(rs);
			setlow(rw);
		
			for(int i=0;i<=3;i++){
				if((ch&(1<<(i+4)))==(1<<(i+4))){
					sethigh(lcd_pins[i]);
				}
				else{
					setlow(lcd_pins[i]);
				}
			}
			pulse(en);
			for(int i=0;i<=3;i++){
				if((ch&(1<<i))==(1<<i)){
					sethigh(lcd_pins[i]);
				}
				else{
					setlow(lcd_pins[i]);
				}
			}
			pulse(en);
		}
		void print(char str[]){
			int i=0;
			for(i=0;str[i]!='\0';i++){
				 print_char(str[i]);
				delay(delll);
			}
		}
		
};
