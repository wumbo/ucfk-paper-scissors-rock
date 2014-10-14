/*
 * File: main.c
 * Author: Simon
 * Date: 14/10/14
 * Brief: Main module
 */

#include "pacer.h"
#include "tinygl.h"
#include "message.h"

int main (void)
{
    tinygl_init(10000);
    pacer_init(10000);

    display_winner_message();
    
    return 0;
}
