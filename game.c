#include "pacer.h"
#include "tinygl.h"
#include "font.h"
#include "font5x7_1.h"

int main (void)
{
    pacer_init (10000);
    tinygl_init (10000);

    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (100);
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
    tinygl_text ("HELLO WORLD ");

    while (1)
    {
        pacer_wait ();
        tinygl_update ();
    }
    
    return 0;
}
