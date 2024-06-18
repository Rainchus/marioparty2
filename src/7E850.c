#include "common.h"

extern OSMesgQueue D_800FD3C8;
void HuPrcVSleep(void);

u16 func_8007DC50_7E850(void) {
    return GetSaveFileChecksum(0, (EEPROM_MAXBLOCKS * EEPROM_BLOCK_SIZE) - 0x10);
}

INCLUDE_ASM(const s32, "7E850", func_8007DC74_7E874);

extern u8 D_800EB900;

void func_8007DCAC_7E8AC(void) {
    u16 checksumResult;

    checksumResult = func_8007DC50_7E850();
    if (D_800EB900 != 0) {
        func_8001AFD8_1BBD8((EEPROM_MAXBLOCKS * EEPROM_BLOCK_SIZE) - 0x10, &checksumResult, 2);
    }
}

INCLUDE_ASM(const s32, "7E850", func_8007DCE8_7E8E8);

INCLUDE_ASM(const s32, "7E850", func_8007DD68_7E968);

INCLUDE_ASM(const s32, "7E850", func_8007DF5C_7EB5C);

INCLUDE_ASM(const s32, "7E850", func_8007DF98_7EB98);

INCLUDE_ASM(const s32, "7E850", func_8007E018_7EC18);

INCLUDE_ASM(const s32, "7E850", func_8007E070_7EC70);

INCLUDE_ASM(const s32, "7E850", func_8007E0C8_7ECC8);

INCLUDE_ASM(const s32, "7E850", func_8007E0F8_7ECF8);

INCLUDE_ASM(const s32, "7E850", func_8007E128_7ED28);

INCLUDE_ASM(const s32, "7E850", func_8007E150_7ED50);

INCLUDE_ASM(const s32, "7E850", func_8007E180_7ED80);

INCLUDE_ASM(const s32, "7E850", func_8007E224_7EE24);

INCLUDE_ASM(const s32, "7E850", func_8007E260_7EE60);

INCLUDE_ASM(const s32, "7E850", func_8007E2A0_7EEA0);

INCLUDE_ASM(const s32, "7E850", func_8007E4D4_7F0D4);

INCLUDE_ASM(const s32, "7E850", func_8007E560_7F160);

INCLUDE_ASM(const s32, "7E850", func_8007E5DC_7F1DC);

INCLUDE_ASM(const s32, "7E850", func_8007E638_7F238);

INCLUDE_ASM(const s32, "7E850", func_8007E754_7F354);

INCLUDE_ASM(const s32, "7E850", func_8007E8D4_7F4D4);

INCLUDE_ASM(const s32, "7E850", func_8007EA50_7F650);

INCLUDE_ASM(const s32, "7E850", func_8007EAF4_7F6F4);

INCLUDE_ASM(const s32, "7E850", func_8007EB2C_7F72C);

INCLUDE_ASM(const s32, "7E850", func_8007EB8C_7F78C);

INCLUDE_ASM(const s32, "7E850", func_8007EBFC_7F7FC);

INCLUDE_ASM(const s32, "7E850", func_8007EC68_7F868);

INCLUDE_ASM(const s32, "7E850", func_8007ECD0_7F8D0);

INCLUDE_ASM(const s32, "7E850", func_8007ED44_7F944);

s32 func_8007EE0C_7FA0C(unkfunc_8007EE0C* arg0, void* GetEepType, UnkEep** arg2, s32 arg3) {
    OSMesgQueue sp10;
    OSMesg sp28;

    arg0->GetEepTypeFunc = GetEepType;
    arg0->unk4 = (void*)arg2;
    arg0->mesgQueue = &sp10;
    osCreateMesgQueue(&sp10, &sp28, 1);
    osSendMesg(&D_800FD3C8, arg0, 1);
    switch (arg3) {
    case 0:
        arg0->unk8 = 0;
        break;
    case 1:
        osRecvMesg(&sp10, 0, 1);
        break;
    case 2:
        while (osRecvMesg(&sp10, 0, 0) != 0) {
            HuPrcVSleep(); //sleep 1 frame
        }
        break;
    }
    return arg0->unk8;
}
