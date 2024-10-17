#ifndef __PROCESS_H
#define __PROCESS_H

#include "common.h"
#include "PR/os.h"

typedef struct jump_buf
{
    void *sp;
    void *func;
    u32 regs[21];
} jmp_buf;

typedef void (*process_func)();

typedef struct Process {
/* 0x00 */ struct Process *next;
/* 0x04 */ struct Process *youngest_child;
/* 0x08 */ struct Process *oldest_child;
/* 0x0C */ struct Process *relative;
/* 0x10 */ struct Process *parent_oldest_child;
/* 0x14 */ struct Process *new_process;
/* 0x18 */ void *heap;
/* 0x1C */ u16 exec_mode;
/* 0x1E */ u16 stat;
/* 0x20 */ u16 priority;
/* 0x22 */ s16 dtor_idx;
/* 0x24 */ s32 sleep_time;
/* 0x28 */ void *base_sp;
/* 0x2C */ jmp_buf prc_jump;
/* 0x88 */ process_func destructor;
/* 0x8C */ void *user_data;
} Process; //sizeof 0x90

void HuPrcInit(void);
void HuPrcEnd(void);
Process *HuPrcCreate(void (*func)(void), u16 prio, u32 stack_size, s32 extra_size);
void HuPrcChildLink(Process *parent, Process *child);
void HuPrcChildUnlink(Process *process);
Process *HuPrcChildCreate(void (*func)(void), u16 prio, u32 stack_size, s32 extra_size, Process *parent);
void HuPrcChildWatch(void);
Process *HuPrcCurrentGet(void);
s32 HuPrcKill(Process *process);
void HuPrcChildKill(Process *process);
void HuPrcSleep(s32 time);
void HuPrcVSleep();
void HuPrcWakeup(Process *process);
void HuPrcDestructorSet2(Process *process, void (*func)(void));
void HuPrcDestructorSet(void (*func)(void));
void HuPrcCall(s32 tick);
void *HuPrcMemAlloc(s32 size);
void HuPrcMemFree(void *ptr);
void HuPrcSetStat(Process *process, u16 value);
void HuPrcResetStat(Process *process, u16 value);
void HuPrcAllPause(s32 flag);
void HuPrcAllUPause(s32 flag);
Process* omAddPrcObj(void* userFunc, u16 priority, s32 stack_size, s32 extra_data_size);
s32 setjmp(jmp_buf* jump_buf);
s32 longjmp(jmp_buf* jump_buf, s32 val);

#endif