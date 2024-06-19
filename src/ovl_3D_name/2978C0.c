#include "common.h"

void func_80062B14_63714(void);
s32 func_80068328_68F28(s32);
void func_8006836C_68F6C(s32);
void func_800683BC_68FBC(s32);
void omInitObjMan(s32, s32);
void omOvlGotoEx(s32, s32, u16);
void omOvlHisChg(s32, s32, s32, s32);
void omAddPrcObj(void* userFunc, u16 priority, s32 stack_size, s32 extra_data_size);
void func_80079128_79D28(void);
void func_801028CC_29795C(void);
void HuPrcVSleep(void); 
void func_80044F88_45B88(s32, s32);
void func_80045184_45D84(s32, s32);
void func_800451F8_45DF8(s32, s32);
void func_800453C4_45FC4(s32, s32);
void func_80045488_46088(s32, s32);
void func_800455CC_461CC(s32, s32);
s32 func_8004CC7C_4D87C(s32, s32, s32);
void func_8004CD70_4D970(s32);
void omOvlReturnEx(s32);
void omOvlKill(void);
void func_80088640_89240(void);
void func_8008CE5C_8DA5C(void);
void InitFadeIn(s32, s32);
void InitFadeOut(s32, s32);
s32 func_8008F618_90218();
void func_80062BE0_637E0(void);

extern u16 D_8010163C_10223C;

void func_80102830_2978C0(void) {
    if (func_80068328_68F28(0) != 0) {
        func_8006836C_68F6C(0x41);
    } else {
        func_800683BC_68FBC(0x41);
    }
    omInitObjMan(0xA, 0);
    func_80062B14_63714();
    omOvlGotoEx(0x3D, 1, 0x192);
    omOvlHisChg(0, 0x3D, 1, 0x192);
}

void func_801028A4_297934(void) {
    omInitObjMan(0xA, 0);
    func_80062BE0_637E0();
}

void func_801028CC_29795C(void) {
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

void func_801029E0_297A70(void) {
    omInitObjMan(0xA, 0xA);
    func_80079128_79D28();
    omAddPrcObj(&func_801028CC_29795C, 0x1005, 0, 0);
}