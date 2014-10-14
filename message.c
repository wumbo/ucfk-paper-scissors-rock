/*
 * File: message.c
 * Author: Simon
 * Date: 14/10/14
 * Brief: Displays winner or loser messages
 */

#include "message.h"
#include "pacer.h"
#include "tinygl.h"
#include "font5x7_1.h"

void message_init() {
    tinygl_font_set(&font5x7_1);
    tinygl_text_speed_set(100);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
}

void display_winner_message() {
    int i;
    message_init();
    tinygl_text("WINNER");

    for (i = 0; i < 10000; i++) {
        pacer_wait();
        tinygl_update();
    }

    tinygl_clear();
    tinygl_update();
}

void display_loser_message() {
    int i;
    message_init();
    tinygl_text("LOSER");

    for (i = 0; i < 10000; i++) {
        pacer_wait();
        tinygl_update();
    }

    tinygl_clear();
    tinygl_update();
}
