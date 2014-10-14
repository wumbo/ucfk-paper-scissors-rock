/*
 * File: select.h
 * Author: Victor
 * Date: 14/10/14
 * Brief: Allows user to select what character to play
 */
 
#include "select.h"
#include "pacer.h"
#include "tinygl.h"
#include "font5x7_1.h"

#define PACER_RATE 500
#define MESSAGE_RATE 10



void display_symbol (char symbol)
{
    char buffer[2];
    buffer[0] = symbol;
    buffer[1] = '\0';
    tinygl_text (buffer);
}

char get_symbol(void) {
	
	char symbol = 'P'; // start at Paper
	
	
	/* initializes tinygl/navswitch */
	system_init ();
    tinygl_init (PACER_RATE);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    navswitch_init ();
    
	 while (1) {	
        pacer_wait ();
        tinygl_update ();
        navswitch_update ();
        
        if (navswitch_push_event_p (NAVSWITCH_NORTH)) {
			if (symbol == 'P') {
				symbol = 'R';
			} 
			else if (symbol == 'R') {
				symbol = 'S';
			}
			else {
				symbol = 'P';
			}
		}
		
		if (navswitch_push_event_p (NAVSWITCH_SOUTH)) {
			if (symbol == 'P') {
				symbol = 'S';
			} 
			else if (symbol == 'R') {
				symbol = 'P';
			}
			else {
				symbol = 'R';
			}
		}
		
		if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
			return symbol;
		}
		
		display_symbol (symbol);
	}
		
		
		
			
