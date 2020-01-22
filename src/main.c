#include "settings.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
int i;
int main(void)
{
    DDRB = 1 << PB1;
    PORTB = PORTB | (1 << PB7); //PIN7 je vstup s rezistorem

    while (1)
        {
        if (!(PINB & (1 << PB7)))
            {
            i = (rand()%10);
            for(int E=0;E<=i;E++)
                {
                    for(int count=0;count <=25;count++)
                        {   
                            PORTB ^= (1 << PB1);
                            _delay_ms(2);
                        }
                    _delay_ms(500);
                    for(int count=0;count <=25;count++)
                        {   
                            PORTB ^= (1 << PB1);
                            _delay_ms(4);
                        }
                    _delay_ms(500);
                }
            for(int count=0; count <=1000; count++)
                {
                    PORTB ^= (1 << PB1);
                    _delay_ms(1); 
                }
            }
        }
    return 0;
} /* main */
