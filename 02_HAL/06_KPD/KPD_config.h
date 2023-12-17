
#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

#define row_init GPIO_PIN0
#define row_end  GPIO_PIN3


#define colum_init GPIO_PIN4
#define colum_end  GPIO_PIN7


#define KPD_PORT GPIO_PORTD

uint8_t KPD_Buttons[4][4] = { 

								{'7','8','9','/'}, /* Row0 */
						  	    {'4','5','6','*'}, /* Row1 */
						   		{'1','2','3','-'}, /* Row2 */
						        {'?','0','=','+'}  /* Row3 */};




#define KPD_R0 GPIO_PIN0
#define KPD_R1 GPIO_PIN1
#define KPD_R2 GPIO_PIN2
#define KPD_R3 GPIO_PIN3

#define KPD_C0 GPIO_PIN4
#define KPD_C1 GPIO_PIN5
#define KPD_C2 GPIO_PIN6
#define KPD_C3 GPIO_PIN7


#endif