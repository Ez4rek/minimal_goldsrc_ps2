#include "ps2_video.h"

#include <dmaKit.h>
#include <gsToolkit.h>

GSGLOBAL *gsGlobal;

void ps2_video_init()
{
    dmaKit_init(
        D_CTRL_RELE_OFF,
        D_CTRL_MFD_OFF,
        D_CTRL_STS_UNSPEC,
        D_CTRL_STD_OFF,
        D_CTRL_RCYC_8);

    dmaKit_chan_init(DMA_CHANNEL_GIF);

    gsGlobal = gsKit_init_global();

    gsGlobal->PrimAlphaEnable = GS_SETTING_ON;

    gsKit_init_screen(gsGlobal);
}

void ps2_video_swap()
{
    gsKit_sync_flip(gsGlobal);
    gsKit_queue_exec(gsGlobal);
}