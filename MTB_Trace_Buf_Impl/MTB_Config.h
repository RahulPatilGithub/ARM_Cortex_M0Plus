#ifndef MTB_CONFIG_H_
#define MTB_CONFIG_H_

// Stores 2 ^ TRACE_BUFFER_MAGNITUDE_PACKETS packets.
// 7 -> 128 packets
#define TRACE_BUFFER_MAGNITUDE_PACKETS 7
// Size in uint32_t. Two per packet.
#define TRACE_BUFFER_SIZE (1 << (TRACE_BUFFER_MAGNITUDE_PACKETS + 1))
// Size in bytes. 8 bytes per packet.
#define TRACE_BUFFER_SIZE_BYTES (TRACE_BUFFER_SIZE << 3)
__attribute__((__aligned__(TRACE_BUFFER_SIZE_BYTES))) uint32_t mtb[TRACE_BUFFER_SIZE];

#define REG_MTB_POSITION           (*(uint32_t *)0x41006000U)
#define REG_MTB_MASTER             (*(uint32_t *)0x41006004U)
#define REG_MTB_FLOW               (*(uint32_t *)0x41006008U)
#define REG_MTB_BASE               (*(uint32_t *)0x4100600CU)

void Config_MTB_TraceBuf(void);
void DeConfig_MTB_TraceBuf(void);

#endif

