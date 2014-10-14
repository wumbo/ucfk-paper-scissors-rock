/*
 * File: main.c
 * Author: Simon
 * Date: 14/10/14
 * Brief: Main module
 */

#include "pacer.h"
#include "tinygl.h"
#include "message.h"
#include "select.h"
#include "navswitch.h"

int main (void)
{
    char c;
    system_init();
    navswitch_init();
    tinygl_init(10000);
    pacer_init(10000);
    
    c = get_symbol();

    return 0;
}
