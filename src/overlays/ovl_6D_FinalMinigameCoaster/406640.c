#include "common.h"

void func_8005E584_5F184(void);
void func_80067E6C_68A6C(s32);
void func_800740AC_74CAC(void);
void func_80075424_76024(s32);
void func_8007E018_7EC18(void);
void func_8007E070_7EC70(void);
void func_80106054_409E94(void);
void func_80106214_40A054(void);
extern s32 D_800CD2C4_CDEC4;
extern s16 D_800F93C8_F9FC8;
extern s32 D_801062A0_40A0E0;
extern s32 D_801062A4_40A0E4;

typedef struct Unk_800FD8A8 {
    u8 unk0;
    u8 unk1;
    char unk2[2];
    s8 unk4;
} Unk_800FD8A8;

void func_8008D59C_8E19C(s16, s16);
void func_8005E570_5F170(void);
s32 func_80075390_75F90(s32);
void func_80079390_79F90(s32);
void func_80106018_409E58(void);
void func_80106160_409FA0(void);
extern s16 D_800CD414_CE014;
extern Unk_800FD8A8 D_800FD8A8_FE4A8;
void func_80105CE8_409B28(void);
void func_80105FBC_409DFC(void);

void func_80102800_406640(void) {
    D_800F93A8.unk_02 = 7;
    omInitObjMan(50, 20);
    func_80106160_409FA0();
    func_80106018_409E58();
    func_80088640_89240();
    func_8005E570_5F170();
    omAddPrcObj(&func_80105CE8_409B28, 0x300U, 0x2000, 0);
    omAddObj(0x1000, 0, 0, -1, &func_80105FBC_409DFC);
    gPlayers[0].characterID = D_800FD8A8_FE4A8.unk0;
    gPlayers[1].characterID = D_800FD8A8_FE4A8.unk1;
    if (D_800FD8A8_FE4A8.unk4 == 2) {
        if (D_800CD414_CE014 == 0) {
            if (func_80075390_75F90(8) != 0) {
                func_80079390_79F90(0x3D);
            } else {
                func_80079390_79F90(0x13);
            }
        }
    } else {
        func_80079390_79F90(15);
    }
}

void func_801028E0_406720(s16 arg0) {
    s32 thing = 1 << gPlayers[0].controller_port;
    func_8008D59C_8E19C(arg0, thing);
}

INCLUDE_ASM(const s32, "overlays/ovl_6D_FinalMinigameCoaster/406640", func_80102914_406754);

INCLUDE_ASM(const s32, "overlays/ovl_6D_FinalMinigameCoaster/406640", func_801029C8_406808);

INCLUDE_ASM(const s32, "overlays/ovl_6D_FinalMinigameCoaster/406640", func_80102AEC_40692C);

INCLUDE_ASM(const s32, "overlays/ovl_6D_FinalMinigameCoaster/406640", func_80102C00_406A40);

INCLUDE_ASM(const s32, "overlays/ovl_6D_FinalMinigameCoaster/406640", func_801031D0_407010);

INCLUDE_ASM(const s32, "overlays/ovl_6D_FinalMinigameCoaster/406640", func_8010370C_40754C);

INCLUDE_ASM(const s32, "overlays/ovl_6D_FinalMinigameCoaster/406640", func_80103E04_407C44);

INCLUDE_ASM(const s32, "overlays/ovl_6D_FinalMinigameCoaster/406640", func_80104270_4080B0);

INCLUDE_ASM(const s32, "overlays/ovl_6D_FinalMinigameCoaster/406640", func_801042DC_40811C);

INCLUDE_ASM(const s32, "overlays/ovl_6D_FinalMinigameCoaster/406640", func_80104380_4081C0);

INCLUDE_ASM(const s32, "overlays/ovl_6D_FinalMinigameCoaster/406640", func_80104AFC_40893C);

INCLUDE_ASM(const s32, "overlays/ovl_6D_FinalMinigameCoaster/406640", func_8010565C_40949C);

INCLUDE_ASM(const s32, "overlays/ovl_6D_FinalMinigameCoaster/406640", func_80105CE8_409B28);

void func_80105EC0_409D00(void) {
    if (func_8008F618_90218() == 0) {
        if (D_801062A0_40A0E0 != 0) {
            func_80075424_76024(0);
            func_800683BC_68FBC(0);
            func_8007E018_7EC18();
            func_8007E070_7EC70();
            func_800740AC_74CAC();
        }
        func_80106214_40A054();
        func_80106054_409E94();
        func_8008CE5C_8DA5C();
        func_8005E584_5F184();
        if (D_801062A4_40A0E4 != 0) {
            func_8006836C_68F6C(0xE);
            D_800CD2C4_CDEC4++;
            func_80067E6C_68A6C(0x27);
            omOvlCallEx(func_8003F6F0_402F0(D_800F93C8_F9FC8), 0, 0x94);
            omOvlHisChg(1, 0x6D, 1, 0x192);
            return;
        }
        func_800683BC_68FBC(0xE);
        omOvlReturnEx(1);
    }
}

INCLUDE_ASM(const s32, "overlays/ovl_6D_FinalMinigameCoaster/406640", func_80105FBC_409DFC);

INCLUDE_ASM(const s32, "overlays/ovl_6D_FinalMinigameCoaster/406640", func_80106018_409E58);

INCLUDE_ASM(const s32, "overlays/ovl_6D_FinalMinigameCoaster/406640", func_80106054_409E94);

INCLUDE_ASM(const s32, "overlays/ovl_6D_FinalMinigameCoaster/406640", func_80106160_409FA0);

INCLUDE_ASM(const s32, "overlays/ovl_6D_FinalMinigameCoaster/406640", func_80106214_40A054);
