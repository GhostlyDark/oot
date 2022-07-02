#include "global.h"
#include "viint.h"

OSViMode osViModeNtscHan1 = {
    OS_VI_NTSC_HAF1,  // type
    {
        // comRegs
        0x00002 | 0x00004 | 0x00008 |
            0x00010 | 0x00040 | 0x3000,  // ctrl
        WIDTH(640),                                          // width
        BURST(57, 34, 5, 62),                                // burst
        VSYNC(524),                                          // vSync
        HSYNC(3093, 0),                                      // hSync
        LEAP(3093, 3093),                                    // leap
        HSTART(108, 748),                                    // hStart
        SCALE(1, 0),                                         // xScale
        VCURRENT(0),                                         // vCurrent
    },
    {// fldRegs
     {
         //[0]
         ORIGIN(1280),        // origin
         SCALE(0.5, 0.5),     // yScale
         HSTART(35, 509),     // vStart
         BURST(4, 2, 14, 0),  // vBurst
         VINTR(2),            // vIntr
     },
     {
         //[1]
         ORIGIN(2560),        // origin
         SCALE(0.5, 0.5),     // yScale
         HSTART(37, 511),     // vStart
         BURST(4, 2, 14, 0),  // vBurst
         VINTR(2),            // vIntr
     }}};

OSViMode osViModeNtscLan1 = {
    2, // type
    {
        // comRegs
        0x311E,       // ctrl
        SCREEN_WIDTH, // width
        0x3E52239,    // burst
        0x20D,        // vSync
        0xC15,        // hSync
        0xC150C15,    // leap
        0x6C02EC,     // hStart
        0x200,        // xScale
        0,            // vCurrent
    },
    { // fldRegs
      {
          // [0]
          0x280,    // origin
          0x400,    // yScale
          0x2501FF, // vStart
          0xE0204,  // vBurst
          2,        // vIntr
      },
      {
          // [1]
          0x280,    // origin
          0x400,    // yScale
          0x2501FF, // vStart
          0xE0204,  // vBurst
          2,        // vIntr
      } },
};
