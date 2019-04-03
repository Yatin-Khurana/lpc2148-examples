#include<lpc214x.h>
#include "lcd.h"
int main(){
	IODIR1 = 0xffffffff;
  gpio_pin rs,rw,en,d0,d1,d2,d3;
  rs.port = 1;
	rw.port = 1;
	en.port = 1;
	d0.port = 1;
	d1.port = 1;
	d2.port = 1;
	d3.port = 1;
	
	rs.pin = 17;
	rw.pin = 18;
	en.pin = 19;
	d0.pin = 20;
	d1.pin = 21;
	d2.pin = 22;
	d3.pin = 23;
lcd mylcd;
mylcd.init(rs,rw,en,d0,d1,d2,d3); // 
while(1){
	mylcd.clear();
	mylcd.print("Hello To This");
	mylcd.send_command(0xC0);
	mylcd.print("*ucking World");
	delay(1000);
}
return 0;
}
