
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define D1    PINB5
#define D2    PINB1
#define BTNA  PINB6
#define BTNB  PINB7

#define getBTNA()  ( PINB&(1<<BTNA) )
#define getBTNB()  ( PINB&(1<<BTNB) )

enum{
	MODO1=1,
	MODO2	
};

char contadorA=1, contadorB=0;
char modo=MODO1;



int main(void)
{
	//Configuramos el puerto PB como salidas para D1 y D2;
    DDRB |=  ( (1<<D1)   | (1<<D2)   );
	
	//Configuramos el puerto PB como entradas para BTNA y BTNB;
	DDRB &= ~( (1<<BTNA) | (1<<BTNB) );
	
    while (1) 
    {
		
		if(modo==MODO1){
			if(contadorA==40){
				PORTB ^= (1<<D1);
				contadorA=0;
			}
			if(contadorB==70){
				PORTB ^= (1<<D2);
				contadorB=0;
			}
		}
		if(modo==MODO2){
			if(contadorA==90){
				PORTB ^= (1<<D1);
				contadorA=0;
			}
			if(contadorB==20){
				PORTB ^= (1<<D2);
				contadorB=0;
			}
		}
		
		
		
		if( getBTNA() == 0 && getBTNB() !=1 ){
			while(getBTNA() == 0 && getBTNB() !=1){
				
			}
			if(modo==MODO1){
				modo=MODO2;
			}
			if(modo==MODO2){
				modo=MODO1;
			}
		}
		if( getBTNA() != 0 && getBTNB() == 0){
			while(getBTNA() != 0 && getBTNB() == 0){
				
			}
			if(modo==MODO1){
				modo=MODO2;
			}
			if(modo==MODO2){
				modo=MODO1;
			}
		}
		
		contadorA++;
		contadorB++;
		
		
		_delay_ms(10);
    }
}
