#include "common.h"

void func_80020070_20C70(s32);
void func_80068410_69010(void);
void func_80102950_36DAF0_BootLogos(omObjData* arg0);
void func_80102A6C_36DC0C_BootLogos(void);
void func_80102AD8_36DC78_BootLogos(void);
void func_8008F624_90224(s32, s32, s32);
void func_80102A04_36DBA4_BootLogos(void);
s32 func_800172CC_17ECC(s32);
s32 func_80068448_69048(void);
void SprAnimKill(s16);
s16 func_8001A2F8_1AEF8(s32);
void func_8001A614_1B214(s32);
void func_8001A694_1B294(s32, s32, s32);
void func_8001A788_1B388(s32, u16);
s32 func_8001AAAC_1B6AC(s16, s32, s32);
void func_8001AC44_1B844(u16);

extern s8 D_80102708_103308;
extern s32 D_80102D50_36DEF0_BootLogos;
extern u16 D_801011FC_101DFC;
extern s32 D_80102D54_36DEF4_BootLogos;
extern u16 D_8010163C_10223C;

//TODO: this gets put into .scommon instead of .bss
//bss
extern Process* D_80102D60_36DF00_BootLogos;

void func_80102830_36D9D0_BootLogos(void) {
    func_80020070_20C70(1);
    omInitObjMan(16, 4);
    D_80102708_103308 = 1;
    if (D_80102D50_36DEF0_BootLogos == 0) {
        func_80068410_69010();
        D_80102D60_36DF00_BootLogos = omAddPrcObj(func_80102AD8_36DC78_BootLogos, 0xA, 0, 0);
        omAddObj(1000, 0, 0, -1, func_80102950_36DAF0_BootLogos);
    } else {
        D_80102D60_36DF00_BootLogos = omAddPrcObj(func_80102AD8_36DC78_BootLogos, 0xA, 0, 0);
        omAddObj(1000, 0, 0, -1, func_80102950_36DAF0_BootLogos);
        omAddObj(10, 0, 0, -1, func_80102A6C_36DC0C_BootLogos);
    }
}

void func_8010290C_36DAAC_BootLogos(void) {
    D_80102D50_36DEF0_BootLogos = 0;
    func_80102830_36D9D0_BootLogos();
}

void func_8010292C_36DACC_BootLogos(void) {
    D_80102D50_36DEF0_BootLogos = 1;
    func_80102830_36D9D0_BootLogos();
}

void func_80102950_36DAF0_BootLogos(omObjData* arg0) {
    if (((D_801011FC_101DFC != 0) || (D_80102D54_36DEF4_BootLogos != 0)) && (func_8008F618_90218() == 0)) {
        func_8008F624_90224(0, 0, 0);
        InitFadeOut(0, 9);
        arg0->func_ptr = &func_80102A04_36DBA4_BootLogos;
        if ((D_801011FC_101DFC != 0) && (func_8008F618_90218() == 0)) {
            func_8008F624_90224(0, 0, 0);
            InitFadeOut(0, 9);
            arg0->func_ptr = &func_80102A04_36DBA4_BootLogos;
        }
    }
}

void func_80102A04_36DBA4_BootLogos(void) {
    if (func_8008F618_90218() == 0) {
        if (D_80102D50_36DEF0_BootLogos != 0) {
            omOvlGotoEx(0x62, 1, 0x193);
            return;
        }
        omOvlCallEx(0x62, 1, 0x193);
        omOvlHisChg(1, 0x62, 0, 0x192);
    }
}

void func_80102A6C_36DC0C_BootLogos(void) {
    s32 temp_v0;

    if (func_8008F618_90218() == 0) {
        temp_v0 = func_80068448_69048();
        if ((temp_v0 == 1) && (func_800172CC_17ECC(0) != 0) && (D_8010163C_10223C & 0x1000)) {
            D_80102D54_36DEF4_BootLogos = temp_v0;
        }
    }
}

void func_80102AD8_36DC78_BootLogos(void) {
    s16 temp_v0;
    u16 temp_s0;

    temp_v0 = func_8001A2F8_1AEF8(0x90000);
    temp_s0 = func_8001AAAC_1B6AC(temp_v0, 0, 1);
    func_8001A694_1B294(temp_s0, 0xA0, 0x78);
    func_8001A614_1B214(temp_s0);
    func_8001A788_1B388(temp_s0, 0xFFFF);
    InitFadeIn(0, 0x1E);
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    HuPrcSleep(0x2D);
    InitFadeOut(0, 9);
    
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    
    func_8001AC44_1B844(temp_s0);
    SprAnimKill(temp_v0);
    HuPrcSleep(9);
    temp_v0 = func_8001A2F8_1AEF8(0x90001);
    temp_s0 = func_8001AAAC_1B6AC(temp_v0, 0, 1);
    func_8001A694_1B294(temp_s0, 0xA0, 0x78);
    func_8001A614_1B214(temp_s0);
    func_8001A788_1B388(temp_s0, -1);
    InitFadeIn(0, 9);
    
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    HuPrcSleep(0x2D);
    InitFadeOut(0, 9);
    
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    
    func_8001AC44_1B844(temp_s0);
    SprAnimKill(temp_v0);
    HuPrcSleep(9);
    temp_s0 = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x90002), 0, 1);
    func_8001A694_1B294(temp_s0, 0xA0, 0x78);
    func_8001A614_1B214(temp_s0);
    func_8001A788_1B388(temp_s0, -1);
    InitFadeIn(0, 9);
    
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    
    HuPrcSleep(0x2D);
    D_801011FC_101DFC = 1;
    while (1) {
        HuPrcVSleep();
    }
}
