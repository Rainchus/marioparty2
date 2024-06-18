#include "common.h"

typedef struct omOvlHisData {
/* 0x00 */ s32 overlayID;
/* 0x04 */ s16 event;
/* 0x06 */ u16 stat;
} omOvlHisData; //sizeof 0x08

void omOvlGotoEx(s32, s32, u16);
extern s16 omovlhisidx;
extern omOvlHisData omovlhis[12];

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

INCLUDE_ASM(const s32, "76CC0", omOvlGotoEx);

INCLUDE_ASM(const s32, "76CC0", omOvlHisChg);

INCLUDE_ASM(const s32, "76CC0", omOvlKill);

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

INCLUDE_ASM(const s32, "76CC0", func_8007935C_79F5C);

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
