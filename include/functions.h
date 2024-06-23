#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include "ultra64.h"
#include "common_structs.h"

s32 func_8007EE0C_7FA0C(unkfunc_8007EE0C* arg0, void* GetEepType, UnkEep** arg2, s32 arg3);
s32 rand8(void);
void func_80062B14_63714(void);
s32 func_80068328_68F28(s32);
void func_8006836C_68F6C(s32);
void func_800683BC_68FBC(s32);
void func_80044F88_45B88(s32, s32);
void func_80045184_45D84(s32, s32);
void func_800451F8_45DF8(s32, s32);
void func_800453C4_45FC4(s32, s32);
void func_80045488_46088(s32, s32);
void func_800455CC_461CC(s32, s32);
s32 func_8004CC7C_4D87C(s32, s32, s32);
void func_8004CD70_4D970(s32);
void func_80079128_79D28(void);
void func_801028CC_29795C(void);
void func_80088640_89240(void);
void func_8008CE5C_8DA5C(void);

void omInitObjMan(s32, s32);
void omOvlGotoEx(s32, s32, u16);
void omOvlHisChg(s16 arg0, s32 overlay, s16 event, s16 stat);
void omAddPrcObj(void* userFunc, u16 priority, s32 stack_size, s32 extra_data_size);
void HuPrcVSleep(void); 
void InitFadeIn(s32, s32);
void InitFadeOut(s32, s32);
void func_80062BE0_637E0(void);
void HuPrcSleep(s32);
void func_800114E8_120E8(s16, s32);
s16 func_8003F6F0_402F0(s16);
void func_80062A70_63670(s32, s16, s32);
void func_80062CC0_638C0(void);
void func_80063178_63D78(void);
void func_80063844_64444(void);
s32 func_800638C8_644C8(void);
s32 omOvlReturnEx(s16);
void omOvlKill(void);
s32 omOvlCallEx(s32 overlayID, s16 event, s16 stat);
void func_80079464_7A064(void);
void func_800794A8_7A0A8(s32);
s32 func_8008F618_90218(void);
s32 GetSaveFileChecksum(u16 checksumAddrOffset, u16 size);
void func_8001AFD8_1BBD8(s32 arg0, UnkEep* arg1, s16 arg2);

#endif