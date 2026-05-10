#include "r_main.h"

#include "../platform/ps2_video.h"

#include <gsKit.h>
#include <gsInline.h>

float camX = 0.0f;
float camY = 0.0f;
float camZ = 0.0f;

void R_Init()
{
}

void R_RenderFrame()
{
    gsKit_clear(gsGlobal, GS_SETREG_RGBAQ(20,20,30,0x80,0));

    gsKit_prim_sprite(
        gsGlobal,
        100,
        100,
        300,
        300,
        1,
        GS_SETREG_RGBAQ(255,0,0,0x80,0)
    );
}