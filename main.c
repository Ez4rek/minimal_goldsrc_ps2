#include <tamtypes.h>
#include <kernel.h>

#include "platform/ps2_video.h"
#include "platform/ps2_input.h"
#include "platform/ps2_system.h"
#include "engine/host.h"

int main()
{
    ps2_system_init();

    ps2_video_init();

    ps2_input_init();

    host_init();

    while(1)
    {
        ps2_input_update();

        host_frame();

        ps2_video_swap();
    }

    return 0;
}