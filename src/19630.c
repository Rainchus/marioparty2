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

typedef struct OverlayTable {
/* 0x00 */ u8* romStart;
/* 0x04 */ u8* romEnd;
/* 0x08 */ u8* vramStart;
/* 0x0C */ u8* textVramStart;
/* 0x10 */ u8* textVramEnd;
/* 0x14 */ u8* dataVramStart;
/* 0x18 */ u8* dataVramEnd;
/* 0x1C */ u8* bssVramStart;
/* 0x20 */ u8* bssVramEnd;
} OverlayTable; //sizeof 0x24

void func_8007C4E4_7D0E4(u8*, u8*, u8*);
extern s8 D_800C8870_C9470;
extern OverlayTable overlay_table[];

void LoadOverlay(s32 arg0) {
    u8* romStart;
    u8* romEnd;
    u8* bssStart;
    u8* bssEnd;
    u8* curBssAddr;
    
    romStart = overlay_table[arg0].romStart;
    romEnd = overlay_table[arg0].romEnd;
    bssStart = overlay_table[arg0].bssVramStart;
    bssEnd = overlay_table[arg0].bssVramEnd;
    
    func_8007C4E4_7D0E4(romStart, overlay_table[arg0].vramStart, (u8*)(romEnd - romStart));
    curBssAddr = bssStart;
    while (bssStart < bssEnd) {
        *curBssAddr++ = 0;
        bssStart++;
    }
    
    D_800C8870_C9470 = 0;
}

INCLUDE_ASM(const s32, "19630", func_80018BD0_197D0);

INCLUDE_ASM(const s32, "19630", func_80018C34_19834);

INCLUDE_ASM(const s32, "19630", func_80018CCC_198CC);

INCLUDE_ASM(const s32, "19630", func_80018D20_19920);

INCLUDE_ASM(const s32, "19630", func_80018D64_19964);

INCLUDE_ASM(const s32, "19630", func_80018DC0_199C0);
