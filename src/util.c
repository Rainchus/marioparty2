#include "common.h"


typedef struct OverlayTable {
/* 0x00 */ u8* romStart;
/* 0x04 */ u8* romEnd;
/* 0x08 */ u8* vramStart;
/* 0x0C */ u8* textVramStart;
/* 0x10 */ u8* textVramEnd;
/* 0x14 */ u8* dataVramStart;
/* 0x18 */ u8* dataVramEnd;
/* 0x1C */ u8* bssVramStart;
/* 0x20 */ u8* bssVramEnd;
} OverlayTable; //sizeof 0x24

typedef struct UnkUtil {
    char unk_00[0x48];
    s16* unk_48;
} UnkUtil;

extern OverlayTable _ovltbl[];
extern u8 D_800C8870_C9470;
extern u32 rnd_seed;
extern RectF D_800C9954_CA554[];
extern Vec D_800C98C4_CA4C4[];
extern Vec D_800C990C_CA50C[];
extern s16 gNumOfControllers;

s16 func_80018ACC_196CC(s32);
void HuRomDmaCodeRead(u8* src, u8* dest, s32 size);
s16 Hu3DModelCreate(void*, s32);
void* ReadMainFS(s32 dirAndFile);
void CameraScissorSet(s16, void*);
void CameraViewportSet(s16, Vec*, Vec*);
void HuMemDirectFree(void*);
s32 func_80020EBC_21ABC(void*, s32, u8);
s32 func_8003D8F0_3E4F0(s32, void*, s32, s32);

u16 func_80018A30_19630(s32 arg0, s32 arg1) {
    return Hu3DModelCreate(ReadMainFS(arg0), arg1);
}

u16 func_80018A64_19664(s32 arg0, s32 arg1) {
    return Hu3DModelCreate(ReadMainFS(arg0), arg1);
}

u16 func_80018A98_19698(s32 arg0, s32 arg1) {
    return Hu3DModelCreate(ReadMainFS(arg0), arg1);
}

s16 func_80018ACC_196CC(s32 arg0) {
    return Hu3DModelCreate(ReadMainFS(arg0), 0x1D);
}

u8 rand8(void) {
    rnd_seed = rnd_seed* 0x41C64E6D + 0x3039;
    return ((rnd_seed + 1) >> 16);
}

// copies in an overlay and clears bss region.
void OvlLoad(s32 overlayIndex) {
    u8* romStart;
    u8* romEnd;
    u8* bssStart;
    u8* bssEnd;
    u8* curBssAddr;
    
    romStart = _ovltbl[overlayIndex].romStart;
    romEnd = _ovltbl[overlayIndex].romEnd;
    bssStart = _ovltbl[overlayIndex].bssVramStart;
    bssEnd = _ovltbl[overlayIndex].bssVramEnd;
    
    HuRomDmaCodeRead(romStart, _ovltbl[overlayIndex].vramStart, romEnd - romStart);
    curBssAddr = bssStart;
    while (bssStart < bssEnd) {
        *curBssAddr++ = 0;
        bssStart++;
    }
    
    D_800C8870_C9470 = 0;
}

void ScissorSet(u8 camIndex, f32 x1, f32 y1, f32 x2, f32 y2) {
    D_800C9954_CA554[camIndex].x1 = x1;
    D_800C9954_CA554[camIndex].y1 = y1;
    D_800C9954_CA554[camIndex].x2 = x2;
    D_800C9954_CA554[camIndex].y2 = y2;
    CameraScissorSet(camIndex, &D_800C9954_CA554[camIndex]);
}

void ViewportSet(u8 camIndex, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    D_800C98C4_CA4C4[camIndex].x = arg1;
    D_800C98C4_CA4C4[camIndex].y = arg2;
    D_800C98C4_CA4C4[camIndex].z = arg3;

    D_800C990C_CA50C[camIndex].x = arg4;
    D_800C990C_CA50C[camIndex].y = arg5;
    D_800C990C_CA50C[camIndex].z = arg6;

    CameraViewportSet(camIndex, &D_800C98C4_CA4C4[camIndex], &D_800C990C_CA50C[camIndex]);
}

void func_80018CCC_198CC(UnkUtil* arg0, u16 arg1, s32 arg2) {
    s16 temp_v0;

    temp_v0 = func_80018ACC_196CC(arg2);
    if ((temp_v0 >= 0)) {
        arg0->unk_48[arg1] = temp_v0;
    }
}

s8 func_8000B4B4_C0B4(void) {
    s8 temp_v1;

    if (gNumOfControllers > D_800C8870_C9470) {
        temp_v1 = D_800C8870_C9470++;
    } else {
        temp_v1 = -1;
    }
    return temp_v1;
}

u16 func_80018D64_19964(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_s0;
    void* temp_v0;

    temp_v0 = ReadMainFS(arg0);
    temp_s0 = func_80020EBC_21ABC(temp_v0, arg1, arg2);
    HuMemDirectFree(temp_v0);
    return temp_s0;
}

s16 func_80018DC0_199C0(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_s0;
    void* temp_v0;

    temp_v0 = ReadMainFS(arg1);
    temp_s0 = func_8003D8F0_3E4F0(arg0, temp_v0, 0, arg2);
    HuMemDirectFree(temp_v0);
    return temp_s0;
}
