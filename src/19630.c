#include "common.h"

extern u32 rnd_seed;

INCLUDE_ASM(const s32, "19630", func_80018A30_19630);

INCLUDE_ASM(const s32, "19630", func_80018A64_19664);

INCLUDE_ASM(const s32, "19630", func_80018A98_19698);

INCLUDE_ASM(const s32, "19630", func_80018ACC_196CC);

s32 rand8(void) {
    rnd_seed = (rnd_seed * 0x41C64E6D) + 0x3039;
    return (u8)(((rnd_seed + 1) >> 16) & 0xFF);
}

INCLUDE_ASM(const s32, "19630", LoadOverlay);

INCLUDE_ASM(const s32, "19630", func_80018BD0_197D0);

INCLUDE_ASM(const s32, "19630", func_80018C34_19834);

INCLUDE_ASM(const s32, "19630", func_80018CCC_198CC);

INCLUDE_ASM(const s32, "19630", func_80018D20_19920);

INCLUDE_ASM(const s32, "19630", func_80018D64_19964);

INCLUDE_ASM(const s32, "19630", func_80018DC0_199C0);
