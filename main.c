
#include <avr/io.h>


int main(void)
{
    DDRD |= (1<<PD4);       //output pin to led
    DDRD &= ~(1<<PD2);    //input pin to seat button(clear bit)
    DDRD &= ~(1<<PD3);    //input pin to heater(clear bit)

    /*Enabling pull ups at pin 2 and 4 of port D*/
    PORTD |= (1<<PD2);    //set bit
    PORTD |= (1<<PD3);    //set bit

    while(1)
    {

        if((!(PIND&(1<<PD2)))&(!(PIND&(1<<PD3))))
        {
            PORTD |= (1<<PD4);      //Turn On Led
        }

         else
        {
            PORTD &= ~(1<<PD4);     //Turn Off Led
        }
    }
    return 0;
}
