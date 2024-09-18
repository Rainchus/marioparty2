#include "common.h"

void func_80066F6C_67B6C(void*, s16);
extern s16 D_800CD414_CE014;

void func_8010290C_36DAAC_BootLogos(void);
void func_8010292C_36DACC_BootLogos(void);

static board_overlay_entrypoint D_80102D30_36DED0_BootLogos[] = {
    {0, &func_8010290C_36DAAC_BootLogos},
    {1, &func_8010292C_36DACC_BootLogos},
    {-1, 0},
};

void func_80102800_36D9A0(void) {
    func_80066F6C_67B6C(&D_80102D30_36DED0_BootLogos, D_800CD414_CE014);
}
