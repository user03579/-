#include "main.h"
#include "motor_io.h"
#include "led_sw.h"


void main(void)
{
	mtr_io_init();
	led_init();	// LED 포트 출력으로 설정 및 모든 LED on off
	sw_init();
	led_test();	// 모든 LED 1회씩 on/off
	_delay_ms(500);
	
	int Motor_speed=50;
	while(TRUE){
		if(sw_onoff(SW1)){
			while(TRUE){
				mtr_io_dir_spd(MOTOR_MOVE_CW, Motor_speed,0.1);	
				
				if(Motor_speed == 50){ led_onoff(LED1 | LED2 ,0.1); _delay_ms(100);}
				else if(Motor_speed == 60){ led_onoff(LED3 | LED4, 0.1); _delay_ms(100);}
				else { led_onoff(LED5 | LED6, 0.1); _delay_ms(100);}
					
				if(sw_onoff(SW1)) {led_off(LED_ALL); break;}
				else if(sw_onoff(SW2)) {
					led_off(LED_ALL);
					if(Motor_speed==70)Motor_speed=50;
					else Motor_speed+=10;
				}
			}
		}
	}
}
