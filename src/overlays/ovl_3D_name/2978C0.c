#include "common.h"

#include "common.h"

extern u16 D_8010163C_10223C;

void func_80102830_2978C0_name_3D(void) {
    if (func_80068328_68F28(0) != 0) {
        _SetFlag(0x41);
    } else {
        func_800683BC_68FBC(0x41);
    }
    omInitObjMan(0xA, 0);
    func_80062B14_63714();
    omOvlGotoEx(0x3D, 1, 0x192);
    omOvlHisChg(0, 0x3D, 1, 0x192);
}

void func_801028A4_297934_name_3D(void) {
    omInitObjMan(0xA, 0);
    func_80062BE0_637E0();
}

void func_801028CC_29795C_name_3D(void) {
    s32 temp_s0;

    func_80088640_89240();
    InitFadeIn(0xFF, 8);
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    
    temp_s0 = func_8004CC7C_4D87C(5, 0xBC, 0);
    
    do {
        HuPrcVSleep();
        func_800455CC_461CC(3, 3);
        func_80044F88_45B88(3, 5);
        func_80045184_45D84(3, 0xB);
        func_800451F8_45DF8(3, 0xD);
        func_800453C4_45FC4(0xD, 0xB);
        func_80045488_46088(0xD, 0xE);
    } while (!(D_8010163C_10223C & 0x1000));
    
    func_8004CD70_4D970(temp_s0);
    InitFadeOut(0xFF, 8);

    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    
    func_8008CE5C_8DA5C();
    omOvlReturnEx(1);
    omOvlKill();
    HuPrcVSleep();
}

void func_801029E0_297A70_name_3D(void) {
    omInitObjMan(0xA, 0xA);
    func_80079128_79D28();
    omAddPrcObj(&func_801028CC_29795C_name_3D, 0x1005, 0, 0);
}
