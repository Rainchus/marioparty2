#include "common.h"

void func_80066F6C_67B6C(void*, s16);
extern s16 D_800CD414_CE014;

void func_80102830_2978C0_name_3D(void);
void func_801028A4_297934_name_3D(void);
void func_801029E0_297A70_name_3D(void);

static board_overlay_entrypoint D_80102A20_297AB0_name_3D[] = {
    {0, &func_80102830_2978C0_name_3D},
    {1, &func_801028A4_297934_name_3D},
    {2, &func_801029E0_297A70_name_3D},
    {-1, 0},
};

void func_80102800_297890_name_3D(void) {
    func_80066F6C_67B6C(D_80102A20_297AB0_name_3D, D_800CD414_CE014);
}

