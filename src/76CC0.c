#include "common.h"

typedef struct omOvlHisData { //Object Manager History Data
/* 0x00 */ s32 overlayID;
/* 0x04 */ s16 event;
/* 0x06 */ u16 stat;
} omOvlHisData; //sizeof 0x08

extern s16 D_800CD430_CE030;
extern u16 D_800F9562_FA162;
extern s16 D_800FCE84_FDA84;
extern u16 D_800FFDF2_1009F2;
extern u16 D_80102702_103302;
extern s8 D_800CD412_CE012;
extern u16 D_800E2130_E2D30;
extern u16 D_800F93A0_F9FA0;
extern s16 omovlhisidx;
extern omOvlHisData omovlhis[12];
extern u8 D_800CD360_CDF60[][2];
extern u8 D_800CD3F0_CDFF0[][2];
extern u16 D_800CD404_CE004;
extern s32 D_800CD408_CE008;
extern s16 D_800CD414_CE014;
extern s16 D_800CD416_CE016;
extern s8 D_800CD41C_CE01C;
extern u8 D_800CD434_CE034;
extern s16 D_800CD528_CE128;
extern s16 D_800CD52C_CE12C;
extern u8 D_800F92B2_F9EB2;
extern s16 D_800F93C8_F9FC8;
extern s32 D_800FA63C_FB23C;
extern u16 D_800FA63E_FB23E;

void func_80079338_79F38(s32);
void func_8007935C_79F5C(s16 arg0, s16 arg1, s16 arg2);
void func_8001A4C0_1B0C0(void);
void func_80023124_23D24(void);
void func_8002864C_2924C(void);
void func_80029708_2A308(s32);
void func_8002F1A4_2FDA4(void);
void func_80069698_6A298(void);
void omDestroyObjMan(void);
void omOvlGotoEx(s32, s32, u16);

INCLUDE_ASM(const s32, "76CC0", omInitObjMan);

INCLUDE_ASM(const s32, "76CC0", omDestroyObjMan);

INCLUDE_ASM(const s32, "76CC0", omAddObj);

INCLUDE_ASM(const s32, "76CC0", omSetObjPrio);

INCLUDE_ASM(const s32, "76CC0", omInsertObj);

INCLUDE_ASM(const s32, "76CC0", omDelObj);

INCLUDE_ASM(const s32, "76CC0", omSetStat);

INCLUDE_ASM(const s32, "76CC0", omSetStatBit);

INCLUDE_ASM(const s32, "76CC0", omResetStatBit);

INCLUDE_ASM(const s32, "76CC0", omPrcSetStat);

INCLUDE_ASM(const s32, "76CC0", omPrcSetStatBit);

INCLUDE_ASM(const s32, "76CC0", omPrcResetStatBit);

INCLUDE_ASM(const s32, "76CC0", omSetTra);

INCLUDE_ASM(const s32, "76CC0", omSetRot);

INCLUDE_ASM(const s32, "76CC0", omSetSca);

INCLUDE_ASM(const s32, "76CC0", func_80076BD0_777D0);

INCLUDE_ASM(const s32, "76CC0", func_80076CA0_778A0);

INCLUDE_ASM(const s32, "76CC0", func_80076D10_77910);

INCLUDE_ASM(const s32, "76CC0", func_80076D80_77980);

INCLUDE_ASM(const s32, "76CC0", func_80076D98_77998);

INCLUDE_ASM(const s32, "76CC0", func_80076DC0_779C0);

INCLUDE_ASM(const s32, "76CC0", func_80076E20_77A20);

INCLUDE_ASM(const s32, "76CC0", func_80076E54_77A54);

INCLUDE_ASM(const s32, "76CC0", omAddPrcObj);

INCLUDE_ASM(const s32, "76CC0", func_80076F14_77B14);

INCLUDE_ASM(const s32, "76CC0", omDelPrcObj);

INCLUDE_ASM(const s32, "76CC0", omDestroyPrcObj);

INCLUDE_ASM(const s32, "76CC0", omPrcSetDestructor);

s32 omOvlCallEx(s32 overlayID, s16 event, s16 stat) {
    omOvlHisData* history;
    s32 index = omovlhisidx;
    s32 result;

    if (index < ARRAY_COUNT(omovlhis)) {
        history = &omovlhis[++omovlhisidx];
        history->overlayID = overlayID;
        history->event = event;
        history->stat = stat;
        omOvlGotoEx(overlayID, event, stat);
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

s32 omOvlReturnEx(s16 level) {
    omovlhisidx -= level;
    
    if (omovlhisidx < 0) {
        omovlhisidx = 0;
        omOvlGotoEx(omovlhis[0].overlayID, omovlhis[0].event, omovlhis[0].stat);
        return 0;
    }
    omOvlGotoEx(omovlhis[omovlhisidx].overlayID, omovlhis[omovlhisidx].event, omovlhis[omovlhisidx].stat);
    return 1;
}

#ifdef NON_EQUIVALENT
void omOvlGotoEx(s32 arg0, s16 arg1, u16 arg2) {
    u8 var_a0_3;
    u8 var_v1_2;
    s32 var_v0_3;

    if ((D_800FA63C_FB23C != 0x73) && (D_800FA63C_FB23C != 0)) {
        if ((D_800FA63C_FB23C != 0x5F) && (D_800FA63C_FB23C != 0x6F) && (D_800FA63C_FB23C != 0x70)) {
            D_800CD408_CE008 = D_800FA63C_FB23C;
        }
        if ((D_800FA63C_FB23C != 0x73) && (D_800FA63C_FB23C != 0)) {
            D_800CD404_CE004 = D_800FA63E_FB23E;
        }
    }

    D_800CD41C_CE01C = 1;
    D_800FA63C_FB23C = arg0;
    D_800CD414_CE014 = arg1;
    D_800CD416_CE016 = arg2;
    D_800FCE84_FDA84 = 0;

    if (arg2 & 0x40 && D_800F92B2_F9EB2 != 2) {
        func_80079338_79F38(2);
    } else if (arg2 & 0x80 && (D_800F92B2_F9EB2 != 3)) {
        func_80079338_79F38(3);
    }

    if (arg2 & 1) {
        if (D_800FFDF2_1009F2 == 0x1000 && (D_800F9562_FA162 == 0x2004) && (D_80102702_103302 == 0x180)) {
            func_8007935C_79F5C(0x1000, 0x2000, 0x180); //this line is incorrect
        } else {
            func_8007935C_79F5C(0x1000, 0x2004, 0x180); //maybe this as well
        }
    } else if ((arg2 & 2) && (D_800FFDF2_1009F2 != 0x800 || (D_800F9562_FA162 == 0x1000) && (D_80102702_103302 != 0x180))) {
        func_8007935C_79F5C(0x800, 0x1000, 0x180);
    } else if (arg2 & 4 && (D_800FFDF2_1009F2 != 0x1000 || (D_800F9562_FA162 != 0x2004) || (D_80102702_103302 != 0x180))) {
        func_8007935C_79F5C(0x1000, 0x2004, 0x180);
    }

    if (!(arg2 & 0x2000)) {
        if (arg2 & 2) {
            var_a0_3 = D_800CD3F0_CDFF0[D_800F93A8.unk_02][0];
            var_v1_2 = D_800CD3F0_CDFF0[D_800F93A8.unk_02][1];
            var_v0_3 = arg2 & 0x100;
        } else if (arg2 & 4) {
            var_a0_3 = 1;
            if ((arg0 == 0x5F) || (arg0 == 0x6F)) {
                var_v1_2 = 0x14;
                var_v0_3 = arg2 & 0x100;
            } else {
                var_a0_3 = D_800CD360_CDF60[D_800F93C8_F9FC8 - 1][0];
                var_v1_2 = D_800CD360_CDF60[D_800F93C8_F9FC8 - 1][1];
                var_v0_3 = arg2 & 0x100;
            }
        } else {
            var_a0_3 = 1;
            var_v1_2 = 0x14;
            var_v0_3 = arg2 & 0x100;
        }

        if (var_v0_3) {
            var_a0_3 = 1;
            var_v1_2 = 0x14;
        } else if (arg2 & 0x200) {
            var_a0_3 = 2;
            var_v1_2 = 0x14;
        } else if (arg2 & 0x400) {
            var_a0_3 = 3;
            var_v1_2 = 0x14;
        } else if (arg2 & 0x800) {
            var_a0_3 = 4;
            var_v1_2 = 0x14;
        } else if (arg2 & 0x1000) {
            var_a0_3 = 5;
            var_v1_2 = 0x14;
        }

        D_800CD434_CE034 = var_v1_2;
        D_800CD528_CE128 = var_a0_3 & 0xFF;
    }

    if (((((arg0 - 0x5A) < 2U) || (arg0 == 0x5C)) || ((arg0 == 0x5D) || (arg0 == 0x62)) || (arg0 == 0x58))) {
        D_800CD52C_CE12C = 1;
        return;
    }
    D_800CD52C_CE12C = 0;
}
#else
INCLUDE_ASM(const s32, "76CC0", omOvlGotoEx);
#endif

void omOvlHisChg(s16 arg0, s32 overlay, s16 event, s16 stat) {
    omOvlHisData* history;
    s32 ovlhisIndex;

    ovlhisIndex = omovlhisidx - arg0;
    if (ovlhisIndex >= 0) {
        history = &omovlhis[ovlhisIndex];
        history->overlayID = overlay;
        history->event = event;
        history->stat = stat;
    }
}

void omOvlKill(void) {
    D_800CD412_CE012 = 4;
    D_800E2130_E2D30 = D_800F93A0_F9FA0;
    func_80069698_6A298();
    func_8002864C_2924C();
    func_8002F1A4_2FDA4();
    omDestroyObjMan();
    func_8001A4C0_1B0C0();
    func_80023124_23D24();
    func_80029708_2A308(1);
}

INCLUDE_ASM(const s32, "76CC0", omMain);

INCLUDE_ASM(const s32, "76CC0", func_80077EF0_78AF0);

INCLUDE_ASM(const s32, "76CC0", func_80077F50_78B50);

INCLUDE_ASM(const s32, "76CC0", func_80078A08_79608);

INCLUDE_ASM(const s32, "76CC0", func_80078EA8_79AA8);

INCLUDE_ASM(const s32, "76CC0", func_80078EC8_79AC8);

INCLUDE_ASM(const s32, "76CC0", func_80078FF8_79BF8);

INCLUDE_ASM(const s32, "76CC0", func_80079128_79D28);

INCLUDE_ASM(const s32, "76CC0", func_80079294_79E94);

INCLUDE_ASM(const s32, "76CC0", func_80079338_79F38);

void func_8007935C_79F5C(s16 arg0, s16 arg1, s16 arg2) {
    D_800FFDF2_1009F2 = arg0;
    D_800F9562_FA162 = arg1;
    D_80102702_103302 = arg2;
    D_800CD430_CE030 = 1;
    D_800FCE84_FDA84 = 4;
}

INCLUDE_ASM(const s32, "76CC0", func_80079390_79F90);

INCLUDE_ASM(const s32, "76CC0", func_80079428_7A028);

INCLUDE_ASM(const s32, "76CC0", func_80079464_7A064);

INCLUDE_ASM(const s32, "76CC0", func_800794A8_7A0A8);

INCLUDE_ASM(const s32, "76CC0", func_800794F0_7A0F0);

INCLUDE_ASM(const s32, "76CC0", func_80079518_7A118);

INCLUDE_ASM(const s32, "76CC0", func_8007954C_7A14C);

INCLUDE_ASM(const s32, "76CC0", func_80079574_7A174);

INCLUDE_ASM(const s32, "76CC0", func_8007959C_7A19C);

INCLUDE_ASM(const s32, "76CC0", func_800795D8_7A1D8);

INCLUDE_ASM(const s32, "76CC0", func_80079614_7A214);

INCLUDE_ASM(const s32, "76CC0", func_80079684_7A284);

INCLUDE_ASM(const s32, "76CC0", func_800796F0_7A2F0);

INCLUDE_ASM(const s32, "76CC0", func_80079718_7A318);

INCLUDE_ASM(const s32, "76CC0", func_8007975C_7A35C);

INCLUDE_ASM(const s32, "76CC0", func_80079798_7A398);

INCLUDE_ASM(const s32, "76CC0", func_800797DC_7A3DC);

INCLUDE_ASM(const s32, "76CC0", func_80079848_7A448);

INCLUDE_ASM(const s32, "76CC0", func_80079868_7A468);

INCLUDE_ASM(const s32, "76CC0", func_80079884_7A484);

INCLUDE_ASM(const s32, "76CC0", func_800798D4_7A4D4);

INCLUDE_ASM(const s32, "76CC0", func_800798F8_7A4F8);

INCLUDE_ASM(const s32, "76CC0", func_80079920_7A520);

INCLUDE_ASM(const s32, "76CC0", func_800799A4_7A5A4);

INCLUDE_ASM(const s32, "76CC0", func_80079A70_7A670);

INCLUDE_ASM(const s32, "76CC0", func_80079B88_7A788);

INCLUDE_ASM(const s32, "76CC0", func_80079C60_7A860);

INCLUDE_ASM(const s32, "76CC0", func_80079D10_7A910);

INCLUDE_ASM(const s32, "76CC0", func_80079D7C_7A97C);

INCLUDE_ASM(const s32, "76CC0", func_80079DB4_7A9B4);
