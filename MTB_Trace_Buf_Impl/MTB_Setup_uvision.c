 /******************************************************************************/
/******************************************************************************/

/*-------------------------------------------------------------------
** Define the function to enable the trace port
**-----------------------------------------------------------------*/
FUNC void MTB_Setup (void) 
{
    unsigned long position;
    unsigned long master;
    unsigned long watermark;
    unsigned long _flow;
    unsigned long positionRegAddr;

    // <e0.31> Trace: MTB (Micro Trace Buffer)
    //    <o0.0..4> Buffer Size
    //      <4=> 256B
    //      <5=> 512B
    //      <6=> 1kB
    //      <7=> 2kB
    //      <8=> 4kB
    //      <9=> 8kB
    //      <i> Trace buffer size in device RAM. MTB memory shall not be used by application.
    //   <o1> Buffer Position
    //     <i> Starting address of the trace buffer in RAM. MTB memory shall not be used by application.
    //   <o2.0> Stop Trace when buffer is full
    //   <o2.1> Stop Target when buffer is full
    //   <o3> MTB register address
    //     <i> Device-specific address of the MTB position register.
    // </e>

    /* Parameters linked to the Configuration Wizard */
    master     = 0x80000006;
    position   = 0x20000000;
    _flow      = 0x00000000;
    positionRegAddr = 0x41006000;

    /* Preparing values for MTB register */
    position  &= 0xFFFFFFF8; // Mask POSITION.POINTER field
    watermark  = position + ((16 << (master & 0x1F)) - 32);
    _flow     |= watermark;

    /* Writing values to the MTB registers on the device */
    _WDWORD(positionRegAddr+4, 0x00000000); // Clear MTB MASTER register
    _WDWORD(positionRegAddr, position);     // Write to MTB POSITION register
    _WDWORD(positionRegAddr+8, _flow);      // Write to MTB FLOW register
    _WDWORD(positionRegAddr+4, master);     // Write to MTB MASTER register to enable MTB
}
