#include "MTB_Config.h"


void Config_MTB_TraceBuf(void)
{
    DeConfig_MTB_TraceBuf();
    REG_MTB_POSITION = ((uint32_t) (mtb - REG_MTB_BASE)) & 0xFFFFFFF8;
    REG_MTB_FLOW = (((uint32_t) mtb - REG_MTB_BASE) + TRACE_BUFFER_SIZE_BYTES) & 0xFFFFFFF8;
    REG_MTB_MASTER = 0x80000000 + (TRACE_BUFFER_MAGNITUDE_PACKETS - 1);
}

void DeConfig_MTB_TraceBuf(void)
{
    REG_MTB_MASTER = 0x00000000;
}
