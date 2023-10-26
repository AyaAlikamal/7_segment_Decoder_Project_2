/* 
 * File:   application.c
 * Author: AyaAli
 * Created on September 22, 2023, 10:24 AM
 */
#include "application.h"
 
uint_8  number = 0, bcd_number = 0 ;
int main() {
    
Std_ReturnType ret = E_NOT_OK;
application_initialize();
while(1){
    
 bcd_number = (((uint_8) number%10) | ((uint_8)((number/10)<<4)));
         ret = gpio_port_write_logic(PORTC_INDEX, bcd_number); 
         number++;
      if(number == 99){
             number = 0;
         }
         _delay(250000);
        
  }
  return (EXIT_SUCCESS);
}
void application_initialize(void){
    Std_ReturnType ret = E_NOT_OK;
ret = gpio_port_direction_intialize(PORTC_INDEX, 0x00);

}