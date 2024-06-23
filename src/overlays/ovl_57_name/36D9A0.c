#include "common.h"

extern s32 D_80102D50_36DEF0;

INCLUDE_ASM(const s32, "overlays/ovl_57_name/36D9A0", func_80102800_36D9A0);

INCLUDE_ASM(const s32, "overlays/ovl_57_name/36D9A0", func_80102830_36D9D0);

INCLUDE_ASM(const s32, "overlays/ovl_57_name/36D9A0", func_8010290C_36DAAC);

INCLUDE_ASM(const s32, "overlays/ovl_57_name/36D9A0", func_8010292C_36DACC);

INCLUDE_ASM(const s32, "overlays/ovl_57_name/36D9A0", func_80102950_36DAF0);

void func_80102A04_36DBA4(void) {
    if (func_8008F618_90218() == 0) {
        if (D_80102D50_36DEF0 != 0) {
            omOvlGotoEx(0x62, 1, 0x193);
            return;
        }
        omOvlCallEx(0x62, 1, 0x193);
        omOvlHisChg(1, 0x62, 0, 0x192);
    }
}

INCLUDE_ASM(const s32, "overlays/ovl_57_name/36D9A0", func_80102A6C_36DC0C);

INCLUDE_ASM(const s32, "overlays/ovl_57_name/36D9A0", func_80102AD8_36DC78);
