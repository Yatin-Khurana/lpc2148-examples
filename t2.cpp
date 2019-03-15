#include<lpc214x.h>
#include "ARMExtendedUtilities.h"
int main(){
	SetSeriesHIGH(&IODIR0,0,10);
	while(1){
		for(int i=0;i<=1024;i++){
			IOSET0 = i;
			IOCLR0 = ~i;
			delay(100);
		}
	}
}
