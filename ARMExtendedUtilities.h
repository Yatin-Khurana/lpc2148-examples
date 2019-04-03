#define BV(bit) (1<<bit)
void SetSeriesHIGH(volatile unsigned long int *port,int start,int end){
	for(int x =start; x<=end;x++){
		*port |= BV(x);
	}
}
void SetSeriesLOW(volatile unsigned long int *port,int start,int end){
	for(int x =start; x<=end;x++){
		*port &= ~BV(x);
	}
}
void delay(int x){
	int a;
	a=x*3000;
	for(int b=0;b<a;b++);
}
struct gpio_pin{
			int port;
			int pin;
		};
