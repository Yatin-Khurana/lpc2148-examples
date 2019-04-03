#include<lpc214x.h>
#define HIGH 0xffffffff
#include "C:/ArmExtendedUtilities.h"

void lcdcmd(char x){
	IOCLR1 = HIGH;
	IOSET1 |= (x<<16);
	IOCLR1 |= BV(30);
	IOSET1 |= BV(31);
	delay(100);
	IOCLR1 |= BV(31);
	delay(100);  
}
void lcddata(char x){
	IOCLR1 = HIGH;
	IOSET1 |= (x<<16);
	IOSET1 |= BV(30);
	IOSET1 |= BV(31);
	delay(100);
	IOCLR1 |= BV(31);
	delay(100);
}
void display(char y[]){
	for(int i=0;y[i]!='\0';i++){
		lcddata(y[i]);
	}
}
int main(){
	IODIR1 = HIGH;
	
	while(1){
		lcdcmd(0x38);
	lcdcmd(0x0C);
	lcdcmd(0x01);
		char ch[] = "Hello Worl1"; 
		display(ch);
		delay(10000);
	}
	return 0;
}