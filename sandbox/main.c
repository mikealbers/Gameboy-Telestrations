#include <gb/gb.h>
#include <gb/drawing.h>
#include <stdio.h>
#include "C:\Users\Kerj\Desktop\GameBoyDev\gameboy-telestrations\helper_functions.c"

unsigned char sprite_brush[] =
    {
        0x00, 0x01, 0x00, 0x06, 0x00, 0x0E, 0x00, 0x1C,
        0x00, 0x38, 0xC0, 0x30, 0xA0, 0x00, 0xE0, 0x00,
        0x00, 0x01, 0x00, 0x06, 0x00, 0x0E, 0x00, 0x1C,
        0xE0, 0x18, 0x90, 0x00, 0x90, 0x00, 0xF0, 0x00,
        0x00, 0x01, 0x00, 0x06, 0xF8, 0x06, 0x84, 0x00,
        0x84, 0x00, 0x84, 0x00, 0x84, 0x00, 0xFC, 0x00};

void main(void)
{
    int x = 50;
    int y = 50;
    int brushSize = 1;

    SPRITES_8x8;
    set_sprite_data(0, 0, sprite_brush);
    set_sprite_tile(0, 0);
    move_sprite(0, x, y); // Move sprite to our predefined x and y coords

    SHOW_SPRITES;

    while (1)
    {
        while (joypad())
        {
            // color(UBYTE forecolor, UBYTE backcolor, UBYTE mode);

            int initX = x - 7;
            int initY = y - 10;
            int movementSpeed = 4;
            // if (joypad() & J_SELECT)
            // {
            //     if (brushSize == 2)
            //     {
            //         waitpad(J_B);
            //         brushSize--;
            //     }else if (brushSize == 1)
            //     {
            //         waitpad(J_A);
            //         brushSize++;
            //     }
            // }
        
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
            if (joypad() & J_A)
            {
                set_sprite_tile(0, 0);
                color(BLACK, WHITE, SOLID);
                if (brushSize == 1)
                {
                    line(initX, initY, x - 7, y - 10);
                }
                if (brushSize == 2)
                {
                    line(initX, initY, x, y);
                    line(initX - 1, initY, x - 1, y);
                    line(initX, initY - 1, x, y - 1);
                    line(initX + 1, initY, x + 1, y);
                }
                movementSpeed = 5;
            }
            if (joypad() & J_B)
            {
                set_sprite_tile(0, 1);
                color(WHITE, WHITE, SOLID);
                box(initX + 1, initY + 1, x - 8, y - 11, M_FILL);
            }
            performantDelay(movementSpeed);
            move_sprite(0, x, y);
        }
    }
}
