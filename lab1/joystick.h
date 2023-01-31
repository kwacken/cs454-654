/****************************************************/
/*                                                  */
/*   CS-454/654 Embedded Systems Development        */
/*   Instructor: Renato Mancuso <rmancuso@bu.edu>   */
/*   Boston University                              */
/*                                                  */
/*   Description: template file to implement basic  */
/*                macros and functions to interface */
/*                with the analog joystick.         */
/*                                                  */
/****************************************************/

#ifndef __JOYSTICK_H
#define __JOYSTICK_H

#include <p33Fxxxx.h>
#include "types.h"

/* Please NOTE: */
/* BTN1 (BUTTON 1) is the "fire" button on the koystick */
/* BTN2 (BUTTON 2) is the "thumb" button on the koystick */

#define BTN1_TRIS    TRISEbits.TRISE8
#define BTN2_TRIS    TRISDbits.TRISD10

#define BTN1_PORT    PORTEbits.RE8
#define BTN2_PORT    PORTDbits.RD10

#define BTN1_PRESSED() \
    (!BTN1_PORT)

#define BTN1_RELEASED() \
    (BTN1_PORT)

#define BTN2_PRESSED() \
    (!BTN2_PORT)

#define BTN2_RELEASED() \
    (BTN2_PORT)

#define btn_initialize()    \
    do {                    \
        SETBIT(BTN1_TRIS);  \
        SETBIT(BTN2_TRIS);  \
    } while (0)

/* === Function prototypes implemented in joystic.h go here === */


#endif /* __JOYSTICK_H */


