#include "ps2_input.h"

#include <libpad.h>

float g_moveForward = 0.0f;
float g_moveSide = 0.0f;

static unsigned char padBuf[256] __attribute__((aligned(64)));

void ps2_input_init()
{
    padInit(0);

    padPortOpen(0, 0, padBuf);
}

void ps2_input_update()
{
    struct padButtonStatus buttons;

    int state = padRead(0, 0, &buttons);

    if(state != 0)
    {
        g_moveForward = 0.0f;
        g_moveSide = 0.0f;

        if(!(buttons.btns & PAD_UP))
            g_moveForward = 1.0f;

        if(!(buttons.btns & PAD_DOWN))
            g_moveForward = -1.0f;

        if(!(buttons.btns & PAD_LEFT))
            g_moveSide = -1.0f;

        if(!(buttons.btns & PAD_RIGHT))
            g_moveSide = 1.0f;
    }
}