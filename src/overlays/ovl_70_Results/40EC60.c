#include "common.h"

extern u16 D_800F9D24_FA924[];
extern s8 D_801076A1_413B01_Results;
extern s8 D_801076A2_413B02_Results;

void PlayMusic(u8);
void func_80104278_4106D8_Results(void);
void func_8010492C_410D8C_Results(void);
void func_80104B90_410FF0_Results(void);
void func_80104D3C_41119C_Results(void);
void func_801028A0_40ED00_Results(void);
void func_80103DB4_410214_Results(void);
void func_801041C8_410628_Results(void);

void func_80102800_40EC60_Results(void) {
    omInitObjMan(0x14, 0x14);
    func_8010492C_410D8C_Results();
    func_80104278_4106D8_Results();
    func_80104B90_410FF0_Results();
    func_80104D3C_41119C_Results();
    omAddPrcObj(&func_80103DB4_410214_Results, 0x300U, 0x3000, 0);
    PlayMusic(0x14);
    omAddObj(5, 0U, 0U, -1, &func_801041C8_410628_Results);
    omAddObj(5, 0U, 0U, -1, &func_801028A0_40ED00_Results);
}

void func_801028A0_40ED00_Results(void) {
    s8 i;

    if (D_801076A2_413B02_Results != 1) {
        for (i = 0; i < 4; i++) {
            if (!(gPlayers[i].flags & 1)) {
                if (D_800F9D24_FA924[gPlayers[i].controller_port] & (A_BUTTON | START_BUTTON)) {
                    D_801076A1_413B01_Results = 1;
                }
            }
        }
    }
}

//related to creating(?) and moving the player sprites
INCLUDE_ASM(const s32, "overlays/ovl_70_Results/40EC60", func_80102944_40EDA4_Results);

INCLUDE_ASM(const s32, "overlays/ovl_70_Results/40EC60", func_801038A4_40FD04_Results);

typedef struct UnkResults1 {
    char pad[116];
} UnkResults1;

void SprAnimKill(s16);                                 /* extern */
void SprAnimKill(s16);                                 /* extern */ 
void func_8006AE14_6BA14(void*);                          /* extern */
extern char D_80107870_413CD0_Results[]; //? related to killing sprites?
extern s32 D_801078E4_413D44_Results;
extern s32 D_801078E8_413D48_Results[];
extern s32 D_801078F8_413D58_Results;
extern s32 D_80107900_413D60_Results[];
extern s32 D_80107910_413D70_Results;
extern s32 D_80107914_413D74_Results;
extern s32 D_80107918_413D78_Results;
extern s32 D_8010791C_413D7C_Results;
extern UnkResults1 D_80107920_413D80_Results[];
extern s32 D_80107CE8_414148_Results;
extern s32 D_80107CEC_41414C_Results;
extern s32 D_80107CE0_414140_Results;
void SprKill(s16);

void func_80103C6C_4100CC_Results(void) {
    s32 i;
    s32 var_s0_3;

    func_8006AE14_6BA14(D_80107870_413CD0_Results);
    
    for (i = 0; i < 4; i++) {
        SprAnimKill(D_80107900_413D60_Results[i]);
    }

    for (i = 0; i < 4; i++) {
        SprAnimKill(D_801078E8_413D48_Results[i]);
    }

    SprKill(D_801078E4_413D44_Results);
    SprKill(D_801078F8_413D58_Results);
    SprAnimKill(D_80107CEC_41414C_Results);
    SprKill(D_80107CE8_414148_Results);
    SprAnimKill(D_80107914_413D74_Results);
    SprAnimKill(D_8010791C_413D7C_Results);
    SprKill(D_80107910_413D70_Results);
    SprKill(D_80107918_413D78_Results);
    SprKill(D_80107CE0_414140_Results);
    var_s0_3 = (func_80068328_68F28(0xD) != 0) * 4;

    for (; var_s0_3 < 8; var_s0_3++) {
        func_8006AE14_6BA14(&D_80107920_413D80_Results[var_s0_3]);
    }
    
    func_8008CE5C_8DA5C();
}

INCLUDE_ASM(const s32, "overlays/ovl_70_Results/40EC60", func_80103DB4_410214_Results);

INCLUDE_ASM(const s32, "overlays/ovl_70_Results/40EC60", func_801041C8_410628_Results);

INCLUDE_ASM(const s32, "overlays/ovl_70_Results/40EC60", func_80104278_4106D8_Results);

INCLUDE_ASM(const s32, "overlays/ovl_70_Results/40EC60", func_801042B4_410714_Results);

INCLUDE_ASM(const s32, "overlays/ovl_70_Results/40EC60", func_801042D8_410738_Results);

INCLUDE_ASM(const s32, "overlays/ovl_70_Results/40EC60", func_8010438C_4107EC_Results);

INCLUDE_ASM(const s32, "overlays/ovl_70_Results/40EC60", func_801043B0_410810_Results);

INCLUDE_ASM(const s32, "overlays/ovl_70_Results/40EC60", func_80104418_410878_Results);

INCLUDE_ASM(const s32, "overlays/ovl_70_Results/40EC60", func_80104458_4108B8_Results);

INCLUDE_ASM(const s32, "overlays/ovl_70_Results/40EC60", func_80104498_4108F8_Results);

INCLUDE_ASM(const s32, "overlays/ovl_70_Results/40EC60", func_801044D0_410930_Results);

INCLUDE_ASM(const s32, "overlays/ovl_70_Results/40EC60", func_801046DC_410B3C_Results);

INCLUDE_ASM(const s32, "overlays/ovl_70_Results/40EC60", func_8010492C_410D8C_Results);

INCLUDE_ASM(const s32, "overlays/ovl_70_Results/40EC60", func_80104B90_410FF0_Results);

INCLUDE_ASM(const s32, "overlays/ovl_70_Results/40EC60", func_80104D3C_41119C_Results);

INCLUDE_ASM(const s32, "overlays/ovl_70_Results/40EC60", func_80105AB8_411F18_Results);

INCLUDE_ASM(const s32, "overlays/ovl_70_Results/40EC60", func_80105F50_4123B0_Results);

INCLUDE_ASM(const s32, "overlays/ovl_70_Results/40EC60", func_801063E8_412848_Results);

INCLUDE_ASM(const s32, "overlays/ovl_70_Results/40EC60", func_80107140_4135A0_Results);

INCLUDE_ASM(const s32, "overlays/ovl_70_Results/40EC60", func_801072B0_413710_Results);

INCLUDE_ASM(const s32, "overlays/ovl_70_Results/40EC60", func_80107544_4139A4_Results);
