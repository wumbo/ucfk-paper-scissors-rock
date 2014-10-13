#include "pacer.h"
#include "tinygl.h"

int main (void)
{
    pacer_init (10000);
    tinygl_init (10000);

    tinygl_draw_line (tinygl_point (1, 2), tinygl_point (3, 5), 1);

    while (1)
    {
        pacer_wait ();
        tinygl_update ();
    }
    
    return 0;
}
