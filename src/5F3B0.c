#include "common.h"

typedef struct Unk {
    s16 unk_00;
    s16 unk_02;
} Unk;

void SprAttrReset(s16, s16, s32);                        /* extern */
void SprAttrSet(s16, s16, s32);                          /* extern */
void SprPosSet(s16, s32, s16, s16);                      /* extern */
void SprScaleSet(s16, s32, f32, f32);                    /* extern */
void func_8005E7B0_5F3B0(s32);                         /* extern */
void func_8005F210_5FE10(s32);
void func_8005F2D8_5FED8(s32);
void func_8005F454_60054(s32);
void func_8005F604_60204(s32);
void func_8005F6C0_602C0(s32);
void func_8005F784_60384(s32);
void func_8005F86C_6046C(s32);
void func_80060034_60C34(s32, s32);
void func_800600F8_60CF8(s32, s16, s16);
extern s32 D_800CC990_CD590;
extern s32 D_800CC994_CD594;
extern s16 D_800E1D3E_E293E;
extern f32 D_800E1D44_E2944;
extern s16 D_800FA604_FB204;
extern Vec2f D_800FC990_FD590[];
extern UnkItemSprite2 D_800FC9EC_FD5EC[];
extern Vec2f D_800FD854_FE454[];
extern s8 D_800FDC9C_FE89C;
extern SpriteStuff D_80101510_102110[];
extern Unk D_800CC99C_CD59C[];
extern s32 D_800E1D48_E2948[];

INCLUDE_ASM(const s32, "5F3B0", func_8005E7B0_5F3B0);

void func_8005ECB8_5F8B8(void) {
    SpriteStuff* sprite;
    s32 i, j;

    for (i = 0; i < 4; i++) {
        sprite = &D_80101510_102110[i];
        for (j = 0; j < 12; j++) {
            SprAttrSet(sprite->unk_08, j, 0x8000);
        }
    }
}

void func_8005ED40_5F940(void) {
    s32 i, j;
    SpriteStuff* sprite;

    while (1) {
        if (D_800FDC9C_FE89C == 0) {
            for (i = 0; i < 4; i++) {
                if (D_800CC990_CD590 != -1) {
                    if ((D_800CC994_CD594 != -1) && (i != D_800CC990_CD590) && (i != D_800CC994_CD594)) {
                        continue;
                    }
                }
                
                sprite = &D_80101510_102110[i];
                if (sprite->unk_00 == 0) {
                    if (sprite->unk_06 & 1) {
                        for (j = 0; j < 12; j++) {
                            SprAttrSet(sprite->unk_08, j, 0x8000);
                        }
                        continue;
                    } else {
                        for (j = 0; j < 12; j++) {
                            SprAttrReset(sprite->unk_08, j, 0x8000);
                        }
                        if ((gPlayers[i].flags & 1) && !(sprite->unk_06 & 1)) {
                            SprAttrReset(sprite->unk_08, 9, 0x8000);
                        } else {
                            SprAttrSet(sprite->unk_08, 9, 0x8000);
                        }

                        if ((gPlayers[i].item != -1) && !(sprite->unk_06 & 1)) {
                            SprAttrReset(sprite->unk_08, 0xB, 0x8000);
                        } else {
                            SprAttrSet(sprite->unk_08, 0xB, 0x8000);
                        }
                        func_8005E7B0_5F3B0(i);
                    }
                } else {
                    if (sprite->unk_06 & 1) {
                        for (j = 0; j < 3; j++) {
                            SprAttrSet(sprite->unk_08, j, 0x8000);
                        }
                        SprAttrSet(sprite->unk_08, 9, 0x8000);
                        continue;
                    } else {
                        for (j = 0; j < 2; j++) {
                            SprAttrReset(sprite->unk_08, j, 0x8000);
                        }
                        if (sprite->unk_36 != -1) {
                            SprAttrReset(sprite->unk_08, j, 0x8000);
                        }
                        if ((gPlayers[i].flags) & 1 && !(sprite->unk_06 & 1)) {
                            SprAttrReset(sprite->unk_08, 9, 0x8000);
                        } else {
                            SprAttrSet(sprite->unk_08, 9, 0x8000);
                        }
                    }
                }
                if (sprite->unk_0C > 0) {
                    sprite->unk_0C--;
                    sprite->xPos += sprite->unk_20;
                    sprite->yPos += sprite->unk_24;
                    sprite->unk_20 += sprite->unk_28;
                    sprite->unk_24 += sprite->unk_2C;
                } else if (sprite->unk_0C == -1) {
                    sprite->unk_0C = -2;
                } else if (sprite->unk_0C != -2) {
                    sprite->xPos = sprite->unk_18;
                    sprite->yPos = sprite->unk_1C;
                    sprite->unk_0C = -1;
                }
                SprPosSet(sprite->unk_08, 0, ((s32) (sprite->xPos + 0.5f) + 56), ((s32) (sprite->yPos + 0.5f) + 19));     
            }
            if (D_800E1D3E_E293E != -1) {
                D_800E1D44_E2944 += 0.1f;
                if (D_800E1D44_E2944 > 1.0f) {
                    D_800E1D44_E2944 = 1.0f;
                }
                SprScaleSet(D_800E1D3E_E293E, 0, D_800E1D44_E2944, D_800E1D44_E2944);
                if (D_800FA604_FB204 > 0) {
                    D_800FA604_FB204--;
                    D_800FC9EC_FD5EC[0].unk_00 += D_800FD854_FE454[0].unk_00;
                    D_800FC9EC_FD5EC[0].unk_04 += D_800FD854_FE454[0].unk_04;
                    D_800FD854_FE454[0].unk_00 += D_800FC990_FD590[0].unk_00;
                    D_800FD854_FE454[0].unk_04 += D_800FC990_FD590[0].unk_04;
                    SprPosSet(D_800E1D3E_E293E, 0, D_800FC9EC_FD5EC[0].unk_00, D_800FC9EC_FD5EC[0].unk_04);
                }
            }
        }
        HuPrcVSleep();
    }
}

INCLUDE_ASM(const s32, "5F3B0", func_8005F210_5FE10);

INCLUDE_ASM(const s32, "5F3B0", func_8005F2D8_5FED8);

INCLUDE_ASM(const s32, "5F3B0", func_8005F454_60054);

INCLUDE_ASM(const s32, "5F3B0", func_8005F604_60204);

INCLUDE_ASM(const s32, "5F3B0", func_8005F6C0_602C0);

INCLUDE_ASM(const s32, "5F3B0", func_8005F784_60384);

INCLUDE_ASM(const s32, "5F3B0", func_8005F86C_6046C);

INCLUDE_ASM(const s32, "5F3B0", func_8005F954_60554);

INCLUDE_ASM(const s32, "5F3B0", func_8005FA50_60650);

INCLUDE_ASM(const s32, "5F3B0", func_8005FAB4_606B4);

INCLUDE_ASM(const s32, "5F3B0", func_8005FC50_60850);

void func_8005FCE8_608E8(s32 arg0) {
    SpriteStuff* sprite;
    s32 i;

    sprite = &D_80101510_102110[arg0];
    for (i = 0; i < 2; i++) {
        sprite->unk2[i] = 0;
    }

    sprite->unk_44[0] = gPlayers[arg0].coins;
    sprite->unk_44[1] = gPlayers[arg0].stars;
    sprite->unk_06 = 0;
    sprite->unk1 = -1;
    sprite->unk_00 = 0;
    func_8005F604_60204(arg0);
    func_80060034_60C34(arg0, 0);
    func_800600F8_60CF8(arg0, D_800CC99C_CD59C[arg0].unk_00, D_800CC99C_CD59C[arg0].unk_02);
    func_8005F210_5FE10(arg0);
    func_8005F2D8_5FED8(arg0);
    func_8005F454_60054(arg0);
    func_8005F6C0_602C0(arg0);
    func_8005F784_60384(arg0);
    func_8005F86C_6046C(arg0);
    func_8005E7B0_5F3B0(arg0);
    D_800E1D48_E2948[arg0] = 0;
    sprite->unk30 = 0;
}

INCLUDE_ASM(const s32, "5F3B0", func_8005FE10_60A10);

INCLUDE_ASM(const s32, "5F3B0", func_8005FEDC_60ADC);

INCLUDE_ASM(const s32, "5F3B0", func_8005FF9C_60B9C);

INCLUDE_ASM(const s32, "5F3B0", func_80060034_60C34);

INCLUDE_ASM(const s32, "5F3B0", func_800600C0_60CC0);

INCLUDE_ASM(const s32, "5F3B0", func_800600DC_60CDC);

INCLUDE_ASM(const s32, "5F3B0", func_800600F8_60CF8);

INCLUDE_ASM(const s32, "5F3B0", func_800601A0_60DA0);

INCLUDE_ASM(const s32, "5F3B0", func_800601DC_60DDC);

INCLUDE_ASM(const s32, "5F3B0", func_80060210_60E10);

INCLUDE_ASM(const s32, "5F3B0", func_800609D8_615D8);

INCLUDE_ASM(const s32, "5F3B0", func_80060A1C_6161C);

INCLUDE_ASM(const s32, "5F3B0", func_80060B04_61704);

INCLUDE_ASM(const s32, "5F3B0", func_80060C4C_6184C);

INCLUDE_ASM(const s32, "5F3B0", func_80060D94_61994);

INCLUDE_ASM(const s32, "5F3B0", func_80060DF8_619F8);

INCLUDE_ASM(const s32, "5F3B0", func_80060F90_61B90);

INCLUDE_ASM(const s32, "5F3B0", func_80061078_61C78);

INCLUDE_ASM(const s32, "5F3B0", func_8006110C_61D0C);

INCLUDE_ASM(const s32, "5F3B0", func_8006135C_61F5C);

INCLUDE_ASM(const s32, "5F3B0", func_800614B4_620B4);

INCLUDE_ASM(const s32, "5F3B0", func_800614D0_620D0);

INCLUDE_ASM(const s32, "5F3B0", func_800614E8_620E8);

INCLUDE_ASM(const s32, "5F3B0", func_80061504_62104);

INCLUDE_ASM(const s32, "5F3B0", func_80061518_62118);

INCLUDE_ASM(const s32, "5F3B0", func_80061584_62184);

INCLUDE_ASM(const s32, "5F3B0", func_800615F0_621F0);

INCLUDE_ASM(const s32, "5F3B0", func_800615FC_621FC);

INCLUDE_ASM(const s32, "5F3B0", func_800616C4_622C4);

INCLUDE_ASM(const s32, "5F3B0", func_80061720_62320);

INCLUDE_ASM(const s32, "5F3B0", func_80061734_62334);

INCLUDE_ASM(const s32, "5F3B0", func_80061750_62350);

INCLUDE_ASM(const s32, "5F3B0", func_8006176C_6236C);

INCLUDE_ASM(const s32, "5F3B0", func_800618F8_624F8);

INCLUDE_ASM(const s32, "5F3B0", func_80061A68_62668);

INCLUDE_ASM(const s32, "5F3B0", func_80061BD8_627D8);

INCLUDE_ASM(const s32, "5F3B0", func_80061DC4_629C4);

INCLUDE_ASM(const s32, "5F3B0", func_80062008_62C08);

INCLUDE_ASM(const s32, "5F3B0", func_80062268_62E68);

INCLUDE_ASM(const s32, "5F3B0", func_80062294_62E94);

INCLUDE_ASM(const s32, "5F3B0", func_800622E4_62EE4);

INCLUDE_ASM(const s32, "5F3B0", func_80062340_62F40);

INCLUDE_ASM(const s32, "5F3B0", func_8006239C_62F9C);

INCLUDE_ASM(const s32, "5F3B0", func_800623C8_62FC8);

INCLUDE_ASM(const s32, "5F3B0", func_80062588_63188);

INCLUDE_ASM(const s32, "5F3B0", func_80062660_63260);

INCLUDE_ASM(const s32, "5F3B0", func_80062824_63424);

INCLUDE_ASM(const s32, "5F3B0", func_8006286C_6346C);

INCLUDE_ASM(const s32, "5F3B0", func_80062888_63488);

INCLUDE_ASM(const s32, "5F3B0", func_800628C0_634C0);

INCLUDE_ASM(const s32, "5F3B0", func_8006296C_6356C);

INCLUDE_ASM(const s32, "5F3B0", func_800629AC_635AC);

INCLUDE_ASM(const s32, "5F3B0", func_800629F0_635F0);

INCLUDE_ASM(const s32, "5F3B0", func_80062A28_63628);
