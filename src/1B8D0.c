#include "common.h"

extern u8 D_800C9B60[];
extern u8 D_800D89F0[];
extern u8 D_800D89F8[];
extern OSMesgQueue D_800FA5E0;

s32 GetEepType(s8** arg0) {
    s16 eepromProbeResult;
    s32 var_s1;
    s16 i;

    var_s1 = 0;
    eepromProbeResult = osEepromProbe(&D_800FA5E0);
    if ((eepromProbeResult) == 0) {
        for (i = 0; i < 4; i++) {
            eepromProbeResult = osEepromProbe(&D_800FA5E0);
            if (eepromProbeResult != 0) {
                break;
            }
        }

        if (i == 4) {
            return EEPROM_TYPE_4K;
        }
    }

    ASSERT(eepromProbeResult == EEPROM_TYPE_4K);

    if (osEepromLongRead(&D_800FA5E0, 0, D_800D89F0, (EEPROM_MAXBLOCKS * EEPROM_BLOCK_SIZE)) != 0) {
        return EEPROM_TYPE_16K;
    }

    i = 1;
    if (D_800C9B60[i] != 0) {
        while (1) {
            if (D_800D89F0[i] != D_800C9B60[i]) {
                var_s1 = 1;
                for (i = 0; i < 8; i++) {
                    D_800D89F0[i] = D_800C9B60[i];
                }

                for (i = 8; i < EEPROM_MAXBLOCKS * EEPROM_BLOCK_SIZE; i++) {
                    D_800D89F0[i] = 0;
                }

                if (osEepromLongWrite(&D_800FA5E0, 1, D_800D89F8, 0x1F8) != 0) {
                    return EEPROM_TYPE_16K;
                }
                if (osEepromLongWrite(&D_800FA5E0, 0, D_800D89F0, 8) == 0) {
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

INCLUDE_ASM(const s32, "1B8D0", func_8001AEDC_1BADC);

INCLUDE_ASM(const s32, "1B8D0", func_8001AF0C_1BB0C);

INCLUDE_ASM(const s32, "1B8D0", func_8001AFD8_1BBD8);

INCLUDE_ASM(const s32, "1B8D0", func_8001B014_1BC14);

INCLUDE_ASM(const s32, "1B8D0", func_8001B078_1BC78);

INCLUDE_ASM(const s32, "1B8D0", func_8001B0B4_1BCB4);

INCLUDE_ASM(const s32, "1B8D0", func_8001B0E8_1BCE8);

INCLUDE_ASM(const s32, "1B8D0", func_8001B114_1BD14);

INCLUDE_ASM(const s32, "1B8D0", func_8001B170_1BD70);

INCLUDE_ASM(const s32, "1B8D0", func_8001B434_1C034);

INCLUDE_ASM(const s32, "1B8D0", func_8001B548_1C148);

INCLUDE_ASM(const s32, "1B8D0", func_8001B9AC_1C5AC);

INCLUDE_ASM(const s32, "1B8D0", func_8001BB54_1C754);
