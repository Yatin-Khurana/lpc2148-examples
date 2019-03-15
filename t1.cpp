#include<lpc214x.h>
#define BV(bit) (1<<bit)
void delay(int time){
	for(int x=0;x<=time;x++)
		for(int y=0;y<=time;y++);
}
int main(){
	for(int x=0;x<=10;x++){
		IODIR0 |= BV(x); 
	}
	int level = 0;
	while(1){
		IOSET0 = BV(level)|BV((10-level));
		IOCLR0 = ~(BV(level)|BV((10-level)));
		if(level>=10){
			level=0;
		}
		level++;
		delay(1000);
	}
}
