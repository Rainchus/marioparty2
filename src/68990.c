#include "common.h"

extern u8 D_800F8CD8[];

INCLUDE_ASM(const s32, "68990", func_80067D90_68990);

INCLUDE_ASM(const s32, "68990", func_80067E6C_68A6C);

INCLUDE_ASM(const s32, "68990", func_80067E78_68A78);

INCLUDE_ASM(const s32, "68990", func_80067EF8_68AF8);

INCLUDE_ASM(const s32, "68990", func_80067F4C_68B4C);

INCLUDE_ASM(const s32, "68990", func_80067F94_68B94);

INCLUDE_ASM(const s32, "68990", func_80067FE8_68BE8);

INCLUDE_ASM(const s32, "68990", func_80068040_68C40);

INCLUDE_ASM(const s32, "68990", func_80068088_68C88);

INCLUDE_ASM(const s32, "68990", func_800680D4_68CD4);

INCLUDE_ASM(const s32, "68990", func_800680EC_68CEC);

INCLUDE_ASM(const s32, "68990", func_800680F8_68CF8);

INCLUDE_ASM(const s32, "68990", func_80068128_68D28);

INCLUDE_ASM(const s32, "68990", func_80068150_68D50);

INCLUDE_ASM(const s32, "68990", func_800681D8_68DD8);

INCLUDE_ASM(const s32, "68990", func_80068268_68E68);

INCLUDE_ASM(const s32, "68990", func_800682A4_68EA4);

INCLUDE_ASM(const s32, "68990", func_800682E0_68EE0);

void func_80068320_68F20(void) {
}

INCLUDE_ASM(const s32, "68990", func_80068328_68F28);

extern u8 D_800F8CD8[];

void _SetFlag(s32 input) {
    s32 adjustedInput;
    s32 byteIndex;
    s32 bitIndex;

    // Adjust input if negative to handle division by 8 correctly
    if (input < 0) {
        adjustedInput = input + 7;
    } else {
        adjustedInput = input;
    }
    
    // Calculate the byte index in the array
    byteIndex = adjustedInput >> 3; // Same as dividing by 8
    
    // Temporary variable to handle bit position calculation
    bitIndex = input;
    
    if (input < 0) {
        bitIndex = input + 7;
    }
    
    // Calculate the bit position within the byte
    bitIndex = bitIndex >> 3 << 3;
    
    // Set the specific bit in the byte at byteIndex
    D_800F8CD8[byteIndex] = D_800F8CD8[byteIndex] | (1 << (input - (bitIndex)));
}

void _ClearFlag(s32 input) {
    s32 adjustedInput;
    s32 byteIndex;
    s32 bitIndex;

    // Adjust input if negative to handle division by 8 correctly
    if (input < 0) {
        adjustedInput = input + 7;
    } else {
        adjustedInput = input;
    }
    
    // Calculate the byte index in the array
    byteIndex = adjustedInput >> 3; // Same as dividing by 8
    
    // Temporary variable to handle bit position calculation
    bitIndex = input;
    
    if (input < 0) {
        bitIndex = input + 7;
    }
    
    // Calculate the bit position within the byte
    bitIndex = bitIndex >> 3 << 3;
    
    // Set the specific bit in the byte at byteIndex
    D_800F8CD8[byteIndex] = D_800F8CD8[byteIndex] & ~(1 << (input - (bitIndex)));
}

INCLUDE_ASM(const s32, "68990", func_80068410_69010);

INCLUDE_ASM(const s32, "68990", func_80068448_69048);
