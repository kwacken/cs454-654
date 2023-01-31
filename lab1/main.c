/****************************************************/
/*                                                  */
/*   CS-454/654 Embedded Systems Development        */
/*   Instructor: Renato Mancuso <rmancuso@bu.edu>   */
/*   Boston University                              */
/*                                                  */
/*   Description: simple HelloWorld application     */
/*                for Amazing Ball platform         */
/*                                                  */
/****************************************************/

#include <p33Fxxxx.h>
//do not change the order of the following 3 definitions
#define FCY 12800000UL
#include <stdio.h>
#include <libpic30.h>
#include <uart.h>

#include "lcd.h"
#include "led.h"

/* Initial configuration by EE */
// Primary (XT, HS, EC) Oscillator with PLL
_FOSCSEL(FNOSC_PRIPLL);

// OSC2 Pin Function: OSC2 is Clock Output - Primary Oscillator Mode: XT Crystal
_FOSC(OSCIOFNC_OFF & POSCMD_XT);

// Watchdog Timer Enabled/disabled by user software
_FWDT(FWDTEN_OFF);

// Disable Code Protection
_FGS(GCP_OFF);


int main(){
	/* LCD Initialization Sequence */
	__C30_UART=1;
	lcd_initialize();
	lcd_clear();

	led_initialize();

	// Print names
	lcd_locate(0,0);
	lcd_printf("Jordan\nSanjana\nZach");

	// Blink LED4
	for(int i = 0; i < 3; ++i) {
	  SETLED(LED4_PORT);
	  __delay_ms(1000);
	  CLEARLED(LED4_PORT);
	}

	// Button
	uint16_t btn_1, btn_2;
	uint8_t count_1, count_2;
	bool is_pressed_1 = false, is_pressed_2 = false;

	static const uint16_t DEBOUNCE_THRESHOLD = 64;

	while(1){
	  // Check if pressed
	  if (BTN1_PRESSED()) {
	    btn_1++;
	  } else {
	    btn_1 = 0;
	    is_pressed_1 = false;
	  }
	  if (BTN2_PRESSED()) {
	    btn_2++;
	  } else {
	    btn_1 = 0;
	    is_pressed_2 = false;
	  }

	  // Check for debounce
	  if (btn_1 > DEBOUNCE_THRESHOLD) {
	    count_1++;
	    is_pressed_1 = true;
	  }
	  if (btn_2 > DEBOUNCE_THRESHOLD) {
	    count_2++;
	    is_pressed_2 = true;
	  }

	  // Set LED
	  if (is_pressed_1) {
	    SETLED(LED1_PORT);
	  } else {
	    CLEARLED(LED1_PORT);
	  }
	  if (is_pressed_2) {
	    SETLED(LED2_PORT);
	  } else {
	    CLEARLED(LED2_PORT);
	  }
	  if (is_pressed_1 ^ is_pressed_2) {
	    SETLED(LED3_PORT);
	  } else {
	    CLEARLED(LED3_PORT);
	  }

	  // Display press count
	  lcd_locate(0,4);
	  lcd_printf("%#02X, %2d | %#02X, %2d", count_1, count_1, count_2, count_2);
	}

    return 0;
}


