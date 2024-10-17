#include "common.h"
#include "engine/siman.h"

extern u8 D_800C9B60[];
extern u8 D_800D89F0_D95F0[];
extern u8 D_800D89F8_D95F8[];
extern OSMesgQueue D_800FA5E0_FB1E0;

s32 GetEepType(s8** arg0) {
    s16 eepromProbeResult;
    s32 var_s1;
    s16 i;

    var_s1 = 0;
    eepromProbeResult = osEepromProbe(&D_800FA5E0_FB1E0);
    if ((eepromProbeResult) == 0) {
        for (i = 0; i < 4; i++) {
            eepromProbeResult = osEepromProbe(&D_800FA5E0_FB1E0);
            if (eepromProbeResult != 0) {
                break;
            }
        }

        if (i == 4) {
            return EEPROM_TYPE_4K;
        }
    }

    ASSERT(eepromProbeResult == EEPROM_TYPE_4K);

    if (osEepromLongRead(&D_800FA5E0_FB1E0, 0, D_800D89F0_D95F0, (EEPROM_MAXBLOCKS * EEPROM_BLOCK_SIZE)) != 0) {
        return EEPROM_TYPE_16K;
    }

    i = 1;
    if (D_800C9B60[i] != 0) {
        while (1) {
            if (D_800D89F0_D95F0[i] != D_800C9B60[i]) {
                var_s1 = 1;
                //Write "HUDSON\0\0" header
                for (i = 0; i < 8; i++) {
                    D_800D89F0_D95F0[i] = D_800C9B60[i];
                }

                for (i = 8; i < EEPROM_MAXBLOCKS * EEPROM_BLOCK_SIZE; i++) {
                    D_800D89F0_D95F0[i] = 0;
                }

                if (osEepromLongWrite(&D_800FA5E0_FB1E0, 1, D_800D89F8_D95F8, 0x1F8) != 0) {
                    return EEPROM_TYPE_16K;
                }
                if (osEepromLongWrite(&D_800FA5E0_FB1E0, 0, D_800D89F0_D95F0, 8) == 0) {
                    **arg0 = var_s1;
                    return 0;
                }
                return EEPROM_TYPE_16K;
            }      
            i++;
            if (D_800C9B60[i] == 0) {
                break;
            }
        }
    }
    **arg0 = var_s1;
    return 0;
}

s32 func_8001AEDC_1BADC(unkfunc_8001AFD8* arg0) {
    unkfunc_8007EE0C sp10;
    unkfunc_8001AFD8* sp20 = arg0; //?

    return func_8007EE0C_7FA0C(&sp10, &GetEepType, &sp20, 1);
}

s32 func_8001AF0C_1BB0C(UnkEep* arg0) {
    u8 eepromBlockCount;
    s16 i;
    s32 alignmentOffset;
    s32 startOffset;

    if (arg0->unk0 >= 8) {
        for (i = 0; i < arg0->unk8; i++) {
            if (arg0->unk0 + i >= (EEPROM_MAXBLOCKS * EEPROM_BLOCK_SIZE)) {
                break;
            }
            D_800D89F0_D95F0[arg0->unk0 + i] = arg0->unk4[i];
        }
        
        eepromBlockCount = (arg0->unk0 / EEPROM_BLOCK_SIZE);
        alignmentOffset = arg0->unk0 & 7;
        startOffset = (arg0->unk8 + alignmentOffset + 7) & 0xFFF8;
        return (osEepromLongWrite(&D_800FA5E0_FB1E0, eepromBlockCount, &D_800D89F0_D95F0[eepromBlockCount * EEPROM_BLOCK_SIZE], startOffset) != 0) * 2;
    }
    return 2;
}

void func_8001AFD8_1BBD8(s32 arg0, UnkEep* arg1, s16 arg2) {
    unkfunc_8007EE0C sp10;
    UnkEep sp20;

    sp20.unk0 = arg0 + 8;
    sp20.unk4 = arg1;
    sp20.unk8 = arg2;

    func_8007EE0C_7FA0C(&sp10, func_8001AF0C_1BB0C, &sp20, 1);
}

s32 func_8001B014_1BC14(UnkEep* arg0) {
    if (osEepromLongRead(&D_800FA5E0_FB1E0, 0, D_800D89F0_D95F0, (EEPROM_MAXBLOCKS * EEPROM_BLOCK_SIZE)) != 0) {
        return 2;
    }
    bcopy(&D_800D89F0_D95F0[arg0->unk0], arg0->unk4, arg0->unk8);
    return 0;
}

void func_8001B078_1BC78(s32 arg0, UnkEep* arg1, s16 arg2) {
    unkfunc_8007EE0C sp10;
    UnkEep sp20;

    sp20.unk0 = arg0 + 8;
    sp20.unk4 = arg1;
    sp20.unk8 = arg2;

    func_8007EE0C_7FA0C(&sp10, (HuSiFunc)func_8001B014_1BC14, &sp20, 1);
}

s32 func_8001B0B4_1BCB4(void) {
    return (osEepromWrite(&D_800FA5E0_FB1E0, 0, &D_800C9B60[1]) != 0) * 2;
}

s32 func_8001B0E8_1BCE8(UnkEep* arg0) {
    unkfunc_8007EE0C sp10;

    return func_8007EE0C_7FA0C(&sp10, (HuSiFunc)func_8001B0B4_1BCB4, 0, 1);
}

u16 GetSaveFileChecksum(u16 checksumAddrOffset, u16 size) {
    u16 offset;
    u16 checksumTotal;

    checksumTotal = 0;
    checksumAddrOffset += EEPROM_BLOCK_SIZE;

    while (size--) {
        offset = checksumAddrOffset;
        checksumAddrOffset++;
        checksumTotal += D_800D89F0_D95F0[offset];
        if ((checksumAddrOffset) >= (EEPROM_MAXBLOCKS * EEPROM_BLOCK_SIZE)) {
            break;
        }
    }
    return checksumTotal;
}
