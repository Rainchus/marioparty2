#ifndef _COMMON_STRUCTS_H_
#define _COMMON_STRUCTS_H_

#include "ultra64.h"

typedef struct Vec{
    f32 x;
    f32 y;
    f32 z;
} Vec;

typedef struct unkfunc_8001AFD8 {
    s16 unk0;
    struct unkfunc_8001AFD8* unk4; //is this correct?
    s16 unk8;
} unkfunc_8001AFD8;

typedef struct unkfunc_8007EE0C {
    void* GetEepTypeFunc; //func pointer
    unkfunc_8001AFD8* unk4; //is this correct?
    s32 unk8;
    OSMesgQueue* mesgQueue;
} unkfunc_8007EE0C;

typedef struct UnkEep {
    u16 unk0;
    char unk2[2];
    u8* unk4;
    u16 unk8;
} UnkEep;

typedef struct board_overlay_entrypoint {
    s16 index;
    void (*fn)();
} board_overlay_entrypoint;

typedef struct UnkBoardStatus {
    char unk0[2];
    s16 unk_02;
    char unk4[0x1A];
    s16 unk_1E;
    s16 unk_20;
    s16 unk_22;
    s16 unk_24;
    s16 unk_26;
} UnkBoardStatus; //sizeof 0x28

typedef struct PlayerData {
/* 0x00 */ u8 group; //for which group you belong to in a minigame
/* 0x01 */ u8 cpu_difficulty;
/* 0x02 */ u8 cpu_difficulty2; //copied from 0x01 for some reason..?
/* 0x03 */ u8 controller_port;
/* 0x04 */ u8 characterID;
/* 0x05 */ char padding_05;
/* 0x06 */ s16 flags;
/* 0x08 */ s16 coins;
/* 0x0A */ s16 extra_coins_collected_during_minigame;
/* 0x0C */ s16 minigameCoinsWon; //coins won on current minigame, also stores battle placement briefly
/* 0x0E */ s16 stars;
/* 0x10 */ s16 cur_chain_index;
/* 0x12 */ s16 cur_space_index;
/* 0x14 */ s16 next_chain_index;
/* 0x16 */ s16 next_space_index;
/* 0x18 */ char unk_18;
/* 0x19 */ s8 item;
/* 0x1A */ s8 turn_status;
/* 0x1B */ s8 player_space_color; //(color for minigame dividing)
/* 0x1C */ char unk_1C[4];
/* 0x20 */ void* unk_20;
/* 0x24 */ void* unk_24;
/* 0x28 */ s16 minigame_coins_collected;
/* 0x2A */ s16 coinPeak; //used for coin star
/* 0x2C */ u8 happening_spaces_landed_on;
/* 0x2D */ u8 red_spaces_landed_on;
/* 0x2E */ u8 blue_spaces_landed_on;
/* 0x2F */ u8 chance_spaces_landed_on;
/* 0x30 */ u8 bowser_spaces_landed_on;
/* 0x31 */ u8 battle_spaces_landed_on;
/* 0x32 */ u8 item_spaces_landed_on;
/* 0x33 */ u8 bank_spaces_landed_on;
} PlayerData __attribute__((aligned(4))); //sizeof 0x34
//P1 - 800FD2C0
//P2 - 800FD2F4
//P3 - 800FD328
//P4 - 800FD35C

typedef struct omObjData {
/* 0x00 */ u16 stat;
/* 0x02 */ s16 next_idx_alloc;
/* 0x04 */ s16 prio;
/* 0x06 */ s16 prev;
/* 0x08 */ s16 next;
/* 0x0A */ s16 next_idx;
/* 0x0C */ s16 group;
/* 0x0E */ s16 group_idx;
/* 0x10 */ s32 unk_10;
/* 0x14 */ void* func_ptr;
/* 0x18 */ Vec trans;
/* 0x24 */ Vec rot;
/* 0x30 */ Vec scale;
/* 0x3C */ u16 mdlcnt;
// /* 0x3E */ char unk_3E[2];
/* 0x40 */ s16* model;
/* 0x44 */ u16 mtncnt;
// /* 0x46 */ char unk_46[2];
/* 0x48 */ s16* motion;
/* 0x4C */ u8 work[4];
/* 0x50 */ void* unk_50;
} omObjData; //sizeof 0x54

typedef struct SpriteStuff {
    /* 0x00 */ s8 unk_00;
    /* 0x01 */ s8 unk1;                             /* inferred */
    /* 0x02 */ s8 unk2[2];                             /* inferred */
    /* 0x04 */ char pad4[2];                        /* maybe part of unk2[4]? */
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ char pad7[1];
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ char padA[2];
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ char padE[2];
    /* 0x10 */ f32 xPos;
    /* 0x14 */ f32 yPos;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ s32 unk30;                           /* inferred */
    /* 0x34 */ char pad34[2];
    /* 0x36 */ s16 unk_36;
    /* 0x38 */ u8 unk_38[12];
    /* 0x44 */ s16 unk_44[2];
} SpriteStuff;                                      /* size = 0x48 */

typedef struct Vec2f {
    f32 unk_00; //f32?
    f32 unk_04; //f32?
} Vec2f; //sizeof 0x8

typedef struct RectF {
    f32 x1;
    f32 y1;
    f32 x2;
    f32 y2;
} RectF;

typedef struct UnkItemSprite2 {
    f32 unk_00;
    f32 unk_04;
} UnkItemSprite2; //sizeof 0x8

typedef struct HeapNode {
    s32 size;
    u8 heap_constant;
    u8 active; // bool
    struct HeapNode* prev;
    struct HeapNode* next;
} HeapNode;

#endif