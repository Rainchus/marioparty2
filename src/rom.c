#include "common.h"

OSPiHandle* osCartRomInit(void);
extern OSMesgQueue D_800E2850_E3450;
extern OSPiHandle* D_800FA190_FAD90;
extern OSMesgQueue D_801027C0_1033C0;
extern void* D_800F92F8_F9EF8;
extern void* D_800E2868_E3468;

void func_8007C370_7CF70(void) {
    osCreatePiManager(OS_PRIORITY_PIMGR, &D_801027C0_1033C0, &D_800F92F8_F9EF8, 0x2A);
    D_800FA190_FAD90 = osCartRomInit();
    osCreateMesgQueue(&D_800E2850_E3450, &D_800E2868_E3468, 0xA);
}

s32 HuStartDma(OSIoMesg * msg, u8 pri, s32 direction, u8* src, u8* dest, u32 size, OSMesgQueue * retQueue) {
    msg->hdr.pri = pri;
    msg->hdr.retQueue = retQueue;
    msg->dramAddr = dest;
    msg->devAddr = (u32)src;
    msg->size = size;
    return osEPiStartDma(D_800FA190_FAD90, msg, direction);
}

s32 HuRomDmaRead(u8* src, u8* dest, s32 size)
{
    OSIoMesg msg;
    s32 curBlockOffset;
    u32 curBlockSize;
    s32 err;

    osInvalDCache(dest, OS_DCACHE_ROUNDUP_SIZE(size));

    curBlockOffset = 0;
    while (size > 0)
    {
        curBlockSize = size;
        if (size > 0x4000) {
            curBlockSize = 0x4000;
        }
        err = HuStartDma(&msg, 0, 0, &src[curBlockOffset], &dest[curBlockOffset], curBlockSize, &D_800E2850_E3450);

        if (err != 0) {
            return err;
        } 
            
        osRecvMesg(&D_800E2850_E3450, 0, 1);
        size -= 0x4000;   
        curBlockOffset += 0x4000;
        
    }
    return err;
}

s32 HuRomDmaCodeRead(u8* src, u8* dest, s32 size)
{
    OSIoMesg msg;
    s32 curBlockOffset;
    u32 curBlockSize;
    s32 err;

    osInvalICache(dest, OS_DCACHE_ROUNDUP_SIZE(size));
    osInvalDCache(dest, OS_DCACHE_ROUNDUP_SIZE(size));

    curBlockOffset = 0;
    while (size > 0)
    {
        curBlockSize = size;
        if (size > 0x4000) {
            curBlockSize = 0x4000;
        }
        err = HuStartDma(&msg, 0, 0, &src[curBlockOffset], &dest[curBlockOffset], curBlockSize, &D_800E2850_E3450);

        if (err != 0) {
            return err;
        } 
            
        osRecvMesg(&D_800E2850_E3450, 0, 1);
        size -= 0x4000;   
        curBlockOffset += 0x4000;
        
    }
    return err;
}
