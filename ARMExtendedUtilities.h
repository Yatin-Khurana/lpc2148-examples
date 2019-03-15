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
void delay(int time){
	for(int x=0;x<=time;x++)
		for(int y=0;y<=x;y++);
}
