#include "common.h"

void func_8005E584_5F184(void);
void func_80050AE0_516E0(void);
void func_80050E1C_51A1C(void);
void func_8004430C_44F0C(s32);
void func_800581D0_58DD0(void);
void func_80059400_5A000(void);
void func_80059704_5A304(void);
void func_8005E260_5EE60(s16);

void func_80103C98_40B7C8_MinigameCoaster(void);
void func_80103DD4_40B904_MinigameCoaster(void);
void func_80103C5C_40B78C_MinigameCoaster(void);
void func_80103D34_40B864_MinigameCoaster(void);
void func_80103360_40AE90_MinigameCoaster(void);
void func_80103C18_40B748_MinigameCoaster(void);
extern s32 D_80103E00_40B930_MinigameCoaster[];

extern u8 D_01164160[]; //?

void func_80102800_40A330(void) {
    D_800F93A8.unk_02 = 7;
    omInitObjMan(50, 10);
    func_80103D34_40B864_MinigameCoaster();
    func_80103C5C_40B78C_MinigameCoaster();
    func_80088640_89240();
    func_8005E570_5F170();
    omAddPrcObj(&func_80103360_40AE90_MinigameCoaster, 0x300U, 0x2000, 0);
    omAddObj(0x1000, 0, 0, -1, &func_80103C18_40B748_MinigameCoaster);
}

void func_80102884_40A3B4_MinigameCoaster(s16 arg0) {
    s32 thing = 1 << gPlayers[0].controller_port;
    func_8008D59C_8E19C(arg0, thing);
}

INCLUDE_ASM(const s32, "overlays/ovl_6E_MinigameCoaster/40A330", func_801028B8_40A3E8_MinigameCoaster);

INCLUDE_ASM(const s32, "overlays/ovl_6E_MinigameCoaster/40A330", func_801028FC_40A42C_MinigameCoaster);

INCLUDE_ASM(const s32, "overlays/ovl_6E_MinigameCoaster/40A330", func_801032AC_40ADDC_MinigameCoaster);

INCLUDE_ASM(const s32, "overlays/ovl_6E_MinigameCoaster/40A330", func_80103360_40AE90_MinigameCoaster);

void func_80103BCC_40B6FC_MinigameCoaster(void) {
    if (func_8008F618_90218() == 0) {
        func_80103DD4_40B904_MinigameCoaster();
        func_80103C98_40B7C8_MinigameCoaster();
        func_8008CE5C_8DA5C();
        func_8005E584_5F184();
        omOvlReturnEx(1);
    }
}

INCLUDE_ASM(const s32, "overlays/ovl_6E_MinigameCoaster/40A330", func_80103C18_40B748_MinigameCoaster);

void func_80103C5C_40B78C_MinigameCoaster(void) {
    func_800433D8_43FD8();
    func_8005E2B8_5EEB8();
    func_800593C0_59FC0();
    func_8005965C_5A25C();
    func_800581A0_58DA0();
}

void func_80103C98_40B7C8_MinigameCoaster(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_8005E260_5EE60(i);
    }

    for (i = 0; i < 5; i++) {
        if (D_80103E00_40B930_MinigameCoaster[i] == 0) {
            continue;
        }
        func_8004430C_44F0C(D_80103E00_40B930_MinigameCoaster[i]);
        D_80103E00_40B930_MinigameCoaster[i] = 0;
    }

    func_80059400_5A000();
    func_80059704_5A304();
    func_800581D0_58DD0();
}

void func_80103D34_40B864_MinigameCoaster(void) {
    func_80018E30_19A30(1);
    func_80018BD0_197D0(0, 0, 0, 320.0f, 240.0f);
    func_80018C34_19834(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_80050A30_51630(D_01164160);
    func_80050E00_51A00(0x2E);
}

void func_80103DD4_40B904_MinigameCoaster(void) {
    func_80050E1C_51A1C();
    func_80050AE0_516E0();
}
