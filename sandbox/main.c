#include <gb/gb.h>
#include <stdio.h>

unsigned char smile[] =
    {
        0x3C, 0x3C, 0x42, 0x42, 0x81, 0x81, 0xA5, 0xA5,
        0x81, 0x81, 0x81, 0xA5, 0x42, 0x5A, 0x3C, 0x3C};

void main(void)
{
    int x = 50;
    int y = 50;

    SPRITES_8x8;
    set_sprite_data(0, 0, smile);
    set_sprite_tile(0, 0);
    move_sprite(0, x, y); // Move sprite to our predefined x and y coords

    SHOW_SPRITES;
    printf("Hello World!!");
    while (1)
    {
        while (joypad())
        {
            if (joypad() & J_RIGHT)
            {
                x++;
            }
            if (joypad() & J_LEFT)
            {
                x--;
            }
            if (joypad() & J_UP)
            {
                y--;
            }
            if (joypad() & J_DOWN)
            {
                y++;
            }
            delay(10);
            move_sprite(0, x, y);
        }
    }
}
