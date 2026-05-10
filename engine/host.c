#include "host.h"

#include "../renderer/r_main.h"
#include "../platform/ps2_input.h"

static float playerX = 0.0f;
static float playerZ = 0.0f;

void host_init()
{
    R_Init();
}

void host_frame()
{
    playerX += g_moveSide * 0.1f;
    playerZ += g_moveForward * 0.1f;

    R_RenderFrame();
}