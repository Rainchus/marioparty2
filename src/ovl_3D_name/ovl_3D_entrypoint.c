#include "common.h"

void func_80066F6C_67B6C(char*, s16);
extern s16 D_800CD414_CE014;

void func_80102830_2978C0(void);
void func_801028A4_297934(void);
void func_801029E0_297A70(void);

static board_overlay_entrypoint D_80102A20[] = {
    {0, &func_80102830_2978C0},
    {1, &func_801028A4_297934},
    {2, &func_801029E0_297A70},
    {-1, 0},
};

void func_80102800_297890(void) {
    func_80066F6C_67B6C(D_80102A20, D_800CD414_CE014);
}