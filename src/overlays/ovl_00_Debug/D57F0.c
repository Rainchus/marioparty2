#include "common.h"

typedef struct UnkDebug0 {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    f32 unk10;
    char pad[4];
} UnkDebug0; //this should have been 0x14 in size, but it needs 0x18?

typedef struct UnkDebug1 {
    char pad[3];
    u8 unk3;
    char unk4[0xBC];
} UnkDebug1;

typedef struct UnkDebug2 {
    u8 groups[4];
    u8 unk_04[4];
    s16 unk_06;
    s16 unk_08;
    s16 unk_0A;
    s16 unk_0C;
} UnkDebug2;

typedef struct UnkDebug3 {
    s16 unk_00;
    s16 unk_02;
} UnkDebug3;

typedef struct UnkDebug4 {
    s16 unk_00;
    s16 unk_02;
} UnkDebug4;
typedef struct DebugOverlayData {
    u8 unk0;
    u8 overlayID;
    u16 unk2;
    u32 unk4;
    u16 unk8;
    char* name;
} DebugOverlayData; //size of this is probably wrong?

void func_8001A7C8_1B3C8(u16, f32);
void DrawDebugText(u16, u16, char*);
s32 HuGetPadInserted(s16);
void espDispOn(u16);
void func_8001CA48_1D648(void);
void func_80067D90_68990(void);
void func_80068964_69564(void);
void func_800689A0_695A0(void);
void func_80068A20_69620(void);
void func_80103838_D6828_Debug(omObjData*);
void func_80105B5C_D8B4C_Debug(u16, u16, char*, u16, u16);
void func_80105BDC_D8BCC_Debug(void);
void func_80104FB4_D7FA4_Debug(omObjData* obj);
void func_80102D54_D5D44_Debug(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
void func_80026D28_27928(s32);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s32, f32, f32, f32);
void func_80076BD0_777D0(s32, s32);
s16 func_80018A98_19698(s32, s32);
void func_80018CCC_198CC(omObjData*, s32, s32);
void omDelObj(omObjData*);
s16 func_8001A2F8_1AEF8(s32);
void func_8001A340_1AF40(s16, f32, f32, f32);
u16 func_8001AAAC_1B6AC(s16, s16, u16);
void func_8001A788_1B388(u16, u16);
void func_8001A708_1B308(u16, s16);
void func_8001A6BC_1B2BC(u16, u8);
void espPosSet(u16, s16, s16);
void func_8001A91C_1B51C(u16, f32, f32);
void func_80103594_D6584_Debug(omObjData* arg0);
void func_80079E60_7AA60(void);
void func_80102DEC_D5DDC_Debug(void);
s32 HuGetPadInserted(s16);
void func_80105A2C_D8A1C_Debug(s32);
void func_80105BDC_D8BCC_Debug(void);
s16 func_8007959C_7A19C(s16);
void func_800795D8_7A1D8(s16, s8);
s32 func_8001A8DC_1B4DC(u16);
void func_8001A96C_1B56C(u16, u8, u8, u8);
void func_8001AC44_1B844(u16);
s32 func_800A5610_A6210(char*);
void func_80103C4C_D6C3C_Debug(omObjData* arg0);
void func_80104FA4_D7F94_Debug(omObjData* obj);
void espDispOff(u16);
void func_80105964_D8954_Debug(u16 arg0);
void func_801059B0_D89A0_Debug(s16 arg0);
void func_80103E50_D6E40_Debug(void);
void func_80104ADC_D7ACC_Debug(void);

extern PlayerData debug_gPlayers[4];
extern s32 D_800F8420_F9020;
extern f32 D_800FA610_FB210;
extern Vec D_800FD474_FE074;
extern Vec D_8010274C_10334C;
extern char D_80101080_101C80[];
extern char D_8010720C_DA1FC_Debug[];
extern char D_80107220_DA210_Debug[];
extern char D_80107228_DA218_Debug[];
extern u8 D_80107470_DA460_Debug[];
extern u16 D_80107406_DA3F6_Debug;
extern u32 D_800CD408_CE008;
extern UnkDebug0 D_800CD438_CE038[];
extern s8 D_800F93CD_F9FCD;
extern UnkDebug1* D_800FC834_FD434;
extern s16 D_801073C6_DA3B6_Debug[];
extern s16 D_801073D8_DA3C8_Debug[];
extern s16 D_801073E4_DA3D4_Debug[];
extern s8 D_801073F8_DA3E8_Debug[4];
extern s8 D_801073FC_DA3EC_Debug[4];
extern s8 D_80107400_DA3F0_Debug;
extern s16 D_80107402_DA3F2_Debug;
extern s16 D_80107404_DA3F4_Debug;
extern s16 D_80107408_DA3F8_Debug;
extern s16 D_80107410_DA400_Debug[];
extern s16 D_80107474_DA464_Debug[];
extern s16 D_8010747C_DA46C_Debug[];
extern s16 D_80107484_DA474_Debug[];
extern s16 D_801072A0_DA290_Debug;
extern s16 D_801072A2_DA292_Debug;
extern s16 D_801072A4_DA294_Debug[];
extern u8 D_801073C0_DA3B0_Debug[];
extern s16 D_801073F0_DA3E0_Debug[];
extern s32 D_80107460_DA450_Debug[];
extern PlayerData debug_gPlayers[4];
extern u8 D_801073BC_DA3AC_Debug[];
extern DebugOverlayData debug_ovl_table[];
extern u32 D_800CD408_CE008;
extern UnkDebug2 debug_unkTable[4];
extern UnkDebug3 D_80106920_D9910_Debug[];
extern s32 D_801069E8_D99D8_Debug;
extern s32 D_801069EC_D99DC_Debug;
extern s32 D_801069F0_D99E0_Debug;
extern u8 D_800CD40E;
extern s16 D_8010163C_10223C[];
extern UnkDebug4 D_80106934_D9924_Debug[];
extern s32 D_801069CC_D99BC_Debug[];
extern u8 D_801069D8_D99C8_Debug;
extern char D_801071F8_DA1E8_Debug[];
extern char D_80107204_DA1F4_Debug[];
extern s16 D_801072B2_DA2A2_Debug;
extern s16 D_801072B4_DA2A4_Debug;
extern s16 D_801072B6_DA2A6_Debug;

void func_80102800_D57F0_Debug(void) {
    omObjData* temp_s3;
    s32 temp_s0_2;
    s32 i;
    s32 rand;
    
    D_80107400_DA3F0_Debug = 0;
    _SetFlag(0x19);
    D_800F93CD_F9FCD = 0;
    if (D_800CD408_CE008 < 0x47U) {
        //award players coins collected during minigame
        for (i = 0; i < 4; i++) {
            s16 totalCoins = gPlayers[i].coins + gPlayers[i].extra_coins_collected_during_minigame;
            gPlayers[i].coins = totalCoins;
            if (totalCoins > 999) {
                gPlayers[i].coins = 999;
            }
            if (gPlayers[i].coins < 0) {
                gPlayers[i].coins = 0;
            }
            gPlayers[i].extra_coins_collected_during_minigame = 0;
        }
    }
    
    omInitObjMan(0x32, 0);
    func_80102D54_D5D44_Debug(2300.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_80026D28_27928(1);
    func_80026DAC_279AC(0, 0x80, 0x80, 0x80);
    func_80026DAC_279AC(1, 0x60, 0x60, 0x10);
    func_80026E00_27A00(1, 100.0f, -100.0f, 100.0f);
    omAddObj(0x7FDA, 0U, 0U, -1, &func_80079E60_7AA60);
    omAddObj(0, 0U, 0U, -1, &func_80102DEC_D5DDC_Debug);
    omAddObj(1, 0U, 0U, -1, &func_80103594_D6584_Debug);
    func_80076BD0_777D0(0, 0x20);
    temp_s3 = omAddObj(0xA, 1U, 0x50U, -1, NULL);
    
    for (i = 0; i < 6; i++) {
        s16 temp = func_80018A98_19698(D_800CD438_CE038[i].unk4 | D_800CD438_CE038[i].unk8, 0x69D);
        D_801073C6_DA3B6_Debug[i] = temp;
        D_800FC834_FD434[temp].unk3 = (D_800FC834_FD434[temp].unk3 | 2);

        func_80018CCC_198CC(temp_s3, 0, D_800CD438_CE038[i].unk4);
        D_801073D8_DA3C8_Debug[i] = temp_s3->motion[0];

        func_80018CCC_198CC(temp_s3, 1, D_800CD438_CE038[i].unk4 | 0x4F);
        D_801073E4_DA3D4_Debug[i] = temp_s3->motion[1];
    }
    
    omDelObj(temp_s3);
    
    for (i = 0; i < 4; i++) {
        D_801073FC_DA3EC_Debug[i] = 0;
        D_801073F8_DA3E8_Debug[i] = 0;
    }

    D_80107402_DA3F2_Debug = func_8001A2F8_1AEF8(0x3A000D);
    func_8001A340_1AF40(D_80107402_DA3F2_Debug, 0.3f, 0.3f, 0.3f);
    
    for (i = 0; i < 0x23; i++) {
        temp_s0_2 = func_8001AAAC_1B6AC(D_80107402_DA3F2_Debug, i % 6, 1);
        espDispOn(temp_s0_2);
        func_8001A788_1B388(temp_s0_2, -1);
        func_8001A708_1B308(temp_s0_2, 0x4000);
        func_8001A6BC_1B2BC(temp_s0_2, -1);
        espPosSet(temp_s0_2, ((i % 7) * 0x30), ((i / 7) * 0x30));
    }

    D_80107404_DA3F4_Debug = func_8001A2F8_1AEF8(0xE);
    D_80107406_DA3F6_Debug = func_8001AAAC_1B6AC(D_80107404_DA3F4_Debug, 0, 1);
    espDispOn(D_80107406_DA3F6_Debug);
    espPosSet(D_80107406_DA3F6_Debug, 0x80, 0x80);
    func_8001A91C_1B51C(D_80107406_DA3F6_Debug, 0.25f, 0.25f);

    for (i = 0; i < 0x28; i++) {
        D_80107410_DA400_Debug[i] = -1;
    }

    D_80107408_DA3F8_Debug = func_8001A2F8_1AEF8(0x14);

    for (i = 0; i < 4; i++) {
        D_8010747C_DA46C_Debug[i] = 0;
        D_80107484_DA474_Debug[i] = 0;
        D_80107474_DA464_Debug[i] = 0;
    }

    InitFadeIn(255, 16);
    //i give up
    //this asm below should be just
    //PlayMusic(rand8() & 7);
    //but the compiler keeps optimizing the andi instructions into 1 instruction instead of 2
    
    #ifdef SHIFT
        PlayMusic(rand8() & 7);
    #else
    asm volatile (
        ".set noreorder\n\t"
        "jal rand8\n\t"
        "nop\n\t"
        "andi $v0, $v0, 7\n\t"
        "jal PlayMusic\n\t"
        "andi $a0, %v0, 0xFF\n\t"
        ".set reorder\n\t"
        : "=r" (rand)
    );
    #endif
}

void func_80102D54_D5D44_Debug(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    func_80018E30_19A30(1);
    D_800FA610_FB210 = arg0;
    D_800FD474_FE074.x = arg1;
    D_800FD474_FE074.y = arg2;
    D_800FD474_FE074.z = arg3;
    D_8010274C_10334C.x = arg4;
    D_8010274C_10334C.y = arg5;
    D_8010274C_10334C.z = arg6;
}

//always running
INCLUDE_ASM(const s32, "overlays/ovl_00_Debug/D57F0", func_80102DEC_D5DDC_Debug);

void func_80103594_D6584_Debug(omObjData* arg0) {
    s32 i, j;

    for (i = 0; i < 6; i++) {
        D_801073C0_DA3B0_Debug[i] = 0;
    }

    for (i = 0; i < 4; i++) {
        gPlayers[i].characterID = i;
        D_801073F0_DA3E0_Debug[i] = i;
        D_801073BC_DA3AC_Debug[i] = 0;
        D_80107460_DA450_Debug[i] = 0;
    }

    for (i = 0; i < 4; i++) {
        if (HuGetPadInserted(i) != 0) {
            D_801073C0_DA3B0_Debug[i] = 1;
        }        
    }

    D_801072A0_DA290_Debug = -1;

    for (i = 0; i < 7; i++, j = 0) {
        for (j = 0; j < 10; j++) {
            //this seems kind of odd...
            if (debug_ovl_table[i * 10 + j].unk0 != 1) {
                break;
            }        
        }

        if (j == 10) {
            D_801072A4_DA294_Debug[i] = -1;
        } else {
            D_801072A4_DA294_Debug[i] = j;
        }
    }

    func_80105A2C_D8A1C_Debug(1);

    if (D_800CD408_CE008 != 999) {
        for (i = 0; i < 0x46; i++) {
            if (debug_ovl_table[i].unk4 == D_800CD408_CE008) {
                D_801072A0_DA290_Debug = i / 10;
                D_801072A2_DA292_Debug = i % 10;
                D_801072A4_DA294_Debug[D_801072A0_DA290_Debug] = D_801072A2_DA292_Debug;
            }            
        }
    }

    for (i = 0; i < 4; i++) {
        debug_gPlayers[i] = gPlayers[i];
    }

    func_80105BDC_D8BCC_Debug();
    arg0->func_ptr = &func_80103838_D6828_Debug;
}

#ifdef NON_MATCHING
void func_80103838_D6828_Debug(omObjData* arg0) {
    UnkDebug4* var_v1;
    DebugOverlayData* var_s1;
    s32 i;

    rand8();
    var_s1 = &debug_ovl_table[D_801072A0_DA290_Debug * 10];
    for (i = 0; i < 10; i++, var_s1++) {
        sprintf(D_80101080_101C80, var_s1->name);
        func_800A5610_A6210(D_80101080_101C80);
        
        if (debug_ovl_table[(D_801072A0_DA290_Debug * 10) + i].unk0 == 0) {
            var_v1 = &D_80106934_D9924_Debug[0];
        } else {
            var_v1 = &D_80106934_D9924_Debug[1];
        }
        
        if (D_801072A2_DA292_Debug == i) {
            func_80105B5C_D8B4C_Debug(0x40, (i + 0xA) * 9, D_80101080_101C80, var_v1->unk_02, var_v1->unk_00);
        } else {
            func_80105B5C_D8B4C_Debug(0x40, (i + 0xA) * 9, D_80101080_101C80, var_v1->unk_00, 0);
        }
    }

    sprintf(D_80101080_101C80, D_801071F8_DA1E8_Debug, D_801072A0_DA290_Debug + 1, 7);
    func_80105B5C_D8B4C_Debug(0x80U, 0x40U, D_80101080_101C80, 0xFU, 7U);
    sprintf(D_80101080_101C80, D_80107204_DA1F4_Debug, D_801069CC_D99BC_Debug[D_800CD40E]);
    func_80105B5C_D8B4C_Debug(0x80U, 0x48U, D_80101080_101C80, 0xEU, 6U);
    espPosSet(D_80107406_DA3F6_Debug, 0x3C, (s16) (((D_801072A2_DA292_Debug + 0xB) * 9) - 1));
    for (i = 0; i < 4; i++) {
        if (HuGetPadInserted(i) != 0) {
            if ((D_80107470_DA460_Debug[i] & 0x90) && (debug_ovl_table[(D_801072A0_DA290_Debug * 10) + D_801072A2_DA292_Debug].unk0 == 0)) {
                if (D_801069D8_D99C8_Debug == 0) {
                    omAddObj(2, 0U, 0U, -1, &func_80104FA4_D7F94_Debug);
                    D_801069D8_D99C8_Debug = 1;
                    espDispOff(D_80107406_DA3F6_Debug);
                    arg0->func_ptr = &func_80104ADC_D7ACC_Debug;
                    func_80105964_D8954_Debug(1);
                }
            } else {
                if (D_80107470_DA460_Debug[i] & 1) {
                    func_801059B0_D89A0_Debug(-1);
                    func_80105BDC_D8BCC_Debug();
                    func_80105964_D8954_Debug(0);
                } else if (D_80107470_DA460_Debug[i] & 2) {
                    func_801059B0_D89A0_Debug(1);
                    func_80105BDC_D8BCC_Debug();
                    func_80105964_D8954_Debug(0);                    
                }
                else {
                    if (D_80107470_DA460_Debug[i] & 4) {
                        func_80105A2C_D8A1C_Debug(-1);
                        func_80105BDC_D8BCC_Debug();
                        func_80105964_D8954_Debug(4);
                    } else if (D_80107470_DA460_Debug[i] & 8) {
                        func_80105A2C_D8A1C_Debug(1);
                        func_80105BDC_D8BCC_Debug();
                        func_80105964_D8954_Debug(4);                        
                    } else {
                        if (D_80107470_DA460_Debug[i] & 0x40) {
                            D_801072B2_DA2A2_Debug = 0;
                            D_801072B4_DA2A4_Debug = 0;
                            D_801072B6_DA2A6_Debug = 0;
                            arg0->func_ptr = &func_80103E50_D6E40_Debug;
                        }
                        else if (D_8010163C_10223C[i] & 0x10) {
                            if (++D_800CD40E >= 3U) {
                                D_800CD40E = 0;
                            }
                        } else {
                            if (D_80107470_DA460_Debug[i] & 0x20) {
                                espDispOff(D_80107406_DA3F6_Debug);
                                arg0->func_ptr = &func_80103C4C_D6C3C_Debug;
                            }
                        }
                    }
                }
            }
        }
    } 
}
#else
INCLUDE_ASM(const s32, "overlays/ovl_00_Debug/D57F0", func_80103838_D6828_Debug);
#endif

void func_80103C4C_D6C3C_Debug(omObjData* arg0) {
    s32 i;

    rand8();
    sprintf(D_80101080_101C80, D_8010720C_DA1FC_Debug);
    func_80105B5C_D8B4C_Debug(0x60, 0x58, D_80101080_101C80, 0xE, 6);
    sprintf(D_80101080_101C80, D_80107220_DA210_Debug);
    func_80105B5C_D8B4C_Debug(0x70, 0x68, D_80101080_101C80, 0xD, 5);
    sprintf(D_80101080_101C80, D_80107228_DA218_Debug);
    func_80105B5C_D8B4C_Debug(0x70, 0x70, D_80101080_101C80, 0xD, 5);
    for (i = 0; i < MAX_PLAYERS; i++) {
        if (HuGetPadInserted(i) == 0) {
            continue;
        }
        
        if (D_80107470_DA460_Debug[i] & 0x20) {
            espDispOn(D_80107406_DA3F6_Debug);
            arg0->func_ptr = &func_80103838_D6828_Debug;
            continue;
        }
        
        if (D_80107470_DA460_Debug[i] & 0x10) {
            func_80067D90_68990();
            func_800689A0_695A0();
            espDispOn(D_80107406_DA3F6_Debug);
            func_8001CA48_1D648();
            func_80068964_69564();
            func_80068A20_69620();
            for (i = 0; i < MAX_PLAYERS; i++) {
                debug_gPlayers[i] = gPlayers[i];
            }
            func_80105BDC_D8BCC_Debug();
            arg0->func_ptr = &func_80103838_D6828_Debug;
        }
    }
}

INCLUDE_ASM(const s32, "overlays/ovl_00_Debug/D57F0", func_80103E50_D6E40_Debug);

void func_80104ADC_D7ACC_Debug(void) {
    s32 temp_s2;
    s32 i;
    s32 var_s4;
    s32 var_s5;
    u32 temp_s3;

    var_s5 = 0xC;
    var_s4 = 6;
    rand8();
    sprintf(D_80101080_101C80, debug_ovl_table[D_801072A0_DA290_Debug * 10 + D_801072A2_DA292_Debug].name);
    
    temp_s3 = (u32) (0x140 - (func_800A5610_A6210(D_80101080_101C80) * 8)) >> 1;
    temp_s2 = (D_801072A2_DA292_Debug + 0xA) * 9;
    //required to match. this prevents the compiler from making a small optimization
    do { } while (0);
    if ((temp_s2 - D_801069E8_D99D8_Debug) >= 0x31) {
        if (--D_801069F0_D99E0_Debug == 0) {
            D_80107410_DA400_Debug[D_801069EC_D99DC_Debug] = func_8001AAAC_1B6AC(D_80107408_DA3F8_Debug, 0, 1);
            func_8001A708_1B308(D_80107410_DA400_Debug[D_801069EC_D99DC_Debug], 0x4000);
            func_8001A788_1B388(D_80107410_DA400_Debug[D_801069EC_D99DC_Debug], 0x8000U);
            func_8001A91C_1B51C(D_80107410_DA400_Debug[D_801069EC_D99DC_Debug], 0.75f, 0.75f);
            func_8001A7C8_1B3C8(D_80107410_DA400_Debug[D_801069EC_D99DC_Debug], 8.0f);
            espPosSet(D_80107410_DA400_Debug[D_801069EC_D99DC_Debug], temp_s3, ((temp_s2 - D_801069E8_D99D8_Debug) + var_s4 + 8));
            func_8001A96C_1B56C(D_80107410_DA400_Debug[D_801069EC_D99DC_Debug], 0xFF, 0xFF, 0xBE);
            D_801069EC_D99DC_Debug += 1;
            D_80107410_DA400_Debug[D_801069EC_D99DC_Debug] = func_8001AAAC_1B6AC(D_80107408_DA3F8_Debug, 0, 1U);
            func_8001A708_1B308(D_80107410_DA400_Debug[D_801069EC_D99DC_Debug], 0x4000);
            func_8001A788_1B388(D_80107410_DA400_Debug[D_801069EC_D99DC_Debug], 0x8000U);
            func_8001A91C_1B51C(D_80107410_DA400_Debug[D_801069EC_D99DC_Debug], 0.75f, 0.75f);
            func_8001A7C8_1B3C8(D_80107410_DA400_Debug[D_801069EC_D99DC_Debug], 8.0f);
            espPosSet(D_80107410_DA400_Debug[D_801069EC_D99DC_Debug], (temp_s3 + (func_800A5610_A6210(debug_ovl_table[D_801072A0_DA290_Debug * 10 + D_801072A2_DA292_Debug].name) * 8)), ((temp_s2 - D_801069E8_D99D8_Debug) + var_s4) + 8);
            func_8001A96C_1B56C(D_80107410_DA400_Debug[D_801069EC_D99DC_Debug], 255, 255, 0xBE);
            D_801069EC_D99DC_Debug += 1;
            D_801069F0_D99E0_Debug = 4;
        }
        
        D_801069E8_D99D8_Debug += 4;
        
        if (temp_s2 < (temp_s2 - D_801069E8_D99D8_Debug) + var_s5) {
            var_s5 = (temp_s2 - D_801069E8_D99D8_Debug) + var_s5 - temp_s2;
        }
        if (temp_s2 < (temp_s2 - D_801069E8_D99D8_Debug) + var_s4) {
            var_s4 = (temp_s2 - D_801069E8_D99D8_Debug) + var_s4 - temp_s2;
        }
        D_800F8420_F9020 = 9;
        DrawDebugText(temp_s3, ((temp_s2 - D_801069E8_D99D8_Debug) + var_s5), D_80101080_101C80);
        D_800F8420_F9020 = 0xD;
        DrawDebugText(temp_s3, ((temp_s2 - D_801069E8_D99D8_Debug) + var_s4), D_80101080_101C80);
    }

    for (i = 0; i < D_801069EC_D99DC_Debug; i++) {
        if ((D_80107410_DA400_Debug[i] != -1) && (func_8001A8DC_1B4DC(D_80107410_DA400_Debug[i]) & 6)) {
            var_s4 = D_80107410_DA400_Debug[i];
            func_8001AC44_1B844(var_s4);
            D_80107410_DA400_Debug[i] = -1;
        }        
    }
    temp_s3 = func_800A5610_A6210(D_80101080_101C80) * 8 - 0xA0;
    temp_s3 = 0xA0 - temp_s3;
    temp_s3 >>= 1;
    D_800F8420_F9020 = 7;
    DrawDebugText((temp_s3 + 1), ((temp_s2 + 1) - D_801069E8_D99D8_Debug), D_80101080_101C80);
    D_800F8420_F9020 = 0xF;
    DrawDebugText(temp_s3, (temp_s2 - D_801069E8_D99D8_Debug), D_80101080_101C80);
}

void func_80104FA4_D7F94_Debug(omObjData* obj) {
    obj->func_ptr = func_80104FB4_D7FA4_Debug;
}

//used after minigame is selected, character select is on screen
INCLUDE_ASM(const s32, "overlays/ovl_00_Debug/D57F0", func_80104FB4_D7FA4_Debug);

void func_80105964_D8954_Debug(u16 arg0) {
    func_800795D8_7A1D8(func_8007959C_7A19C(D_80106920_D9910_Debug[arg0].unk_00), D_80106920_D9910_Debug[arg0].unk_02);
}

void func_801059B0_D89A0_Debug(s16 arg0) {
    s16 var_a1;

    var_a1 = D_801072A2_DA292_Debug;
    //real do-while?
    do {
        var_a1 += arg0;
        if (var_a1 >= 0xA) {
            var_a1 = 0;
        } else if (var_a1 < 0) {
            var_a1 = 9;
        }
    } while (debug_ovl_table[(D_801072A0_DA290_Debug * 0xA) + var_a1].unk0 == 1);
    D_801072A2_DA292_Debug = var_a1;
}

void func_80105A2C_D8A1C_Debug(s32 arg0) {
    u16 var_a3;
    s32 j;
    s16 temp;
    s16 var_a2;
    
    var_a3 = 0;
    temp = var_a2 = D_801072A0_DA290_Debug;
    do {
        var_a2 += arg0;
        if (var_a2 >= 7) {
            var_a2 = 0;
        } else if (var_a2 < 0) {
            var_a2 = 6;
        }
        for (j = 0; j < 10; j++) {
            if (debug_ovl_table[var_a2 * 10 + j].unk0 == 0) {
                var_a3 = 1;
                break;
            }
        }
    } while(!(var_a3));
    
    D_801072A0_DA290_Debug = var_a2;
    
    if (temp == -1) {
        D_801072A2_DA292_Debug = -1;
        func_801059B0_D89A0_Debug(1);
        D_801072A4_DA294_Debug[D_801072A0_DA290_Debug] = D_801072A2_DA292_Debug;
        return;
    }
    
    D_801072A4_DA294_Debug[temp] = D_801072A2_DA292_Debug;
    D_801072A2_DA292_Debug = D_801072A4_DA294_Debug[D_801072A0_DA290_Debug];
}

void func_80105B5C_D8B4C_Debug(u16 arg0, u16 arg1, char* arg2, u16 arg3, u16 arg4) {
    D_800F8420_F9020 = arg4;
    DrawDebugText((arg0 + 1), (arg1 + 1), arg2);
    D_800F8420_F9020 = arg3;
    DrawDebugText(arg0, arg1, arg2);
}

void func_80105BDC_D8BCC_Debug(void) {
    PlayerData* temp_v0;
    u8* temp_v1;

    temp_v1 = debug_unkTable[debug_ovl_table[D_801072A0_DA290_Debug * 10 + D_801072A2_DA292_Debug].overlayID - 1].groups;
    //surely this is fake...right?
    temp_v0 = &debug_gPlayers[0];
    (temp_v0++)->group = temp_v1[0];
    (temp_v0++)->group = temp_v1[1];
    (temp_v0++)->group = temp_v1[2];
    (temp_v0++)->group = temp_v1[3];
}

void func_80105C50_D8C40_Debug(void) {
    s32 i;
    PlayerData* player;
    PlayerData* debugPlayer;

    for (i = 0; i < MAX_PLAYERS; i++, player++, debugPlayer++) {
        debugPlayer = &debug_gPlayers[i];
        player = &gPlayers[i];
        
        player->flags = debugPlayer->flags;
        player->group = debugPlayer->group;
        player->controller_port = debugPlayer->controller_port;
        player->cpu_difficulty = debugPlayer->cpu_difficulty;
        player->coins = debugPlayer->coins;
    }
}

void func_80105CC0_D8CB0_Debug(void) {
    u8 playerGroups[MAX_PLAYERS];
    u8 sp18[MAX_PLAYERS];
    s32 i;
    s32 randInt;

    for (i = 0; i < MAX_PLAYERS; i++) {
        playerGroups[i] = debug_gPlayers[i].group;
        sp18[i] = 0;
    }

    for (i = 0; i < MAX_PLAYERS; i++) {
        while (1) {
            randInt = rand8() & 3;
            if (sp18[randInt] != 1) {
                break;
            }
        }
        sp18[randInt] = 1;
        debug_gPlayers[i].group = playerGroups[randInt];
    }
}

void func_80105D9C_D8D8C_Debug(void) {
    u8 sp10[MAX_PLAYERS];
    s32 i;
    s32 randInt;

    for (i = 0; i < MAX_PLAYERS; i++) {
        sp10[i] = 0;
    }

    for (i = 0; i < MAX_PLAYERS; i++) {
        while (1) {
            randInt = rand8() & 3;
            if (sp10[randInt] != 1) {
                break;
            }
        }
        sp10[randInt] = 1;
        debug_gPlayers[i].controller_port = randInt;
    }
}
