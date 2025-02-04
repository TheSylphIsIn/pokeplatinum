#include "unk_0200C6E4.h"

#include <nitro.h>
#include <string.h>

#include "struct_defs/sprite_template.h"
#include "struct_defs/struct_02009508.h"
#include "struct_defs/struct_0200C738.h"
#include "struct_defs/struct_0200D0F4.h"

#include "overlay007/struct_ov7_0224F2EC.h"
#include "overlay007/struct_ov7_0224F358.h"
#include "overlay104/struct_ov104_022412F4.h"
#include "overlay104/struct_ov104_02241308.h"
#include "overlay104/struct_ov104_0224133C.h"

#include "cell_actor.h"
#include "cell_transfer.h"
#include "char_transfer.h"
#include "heap.h"
#include "narc.h"
#include "palette.h"
#include "pltt_transfer.h"
#include "sprite_resource.h"
#include "sprite_transfer.h"
#include "unk_020093B4.h"
#include "unk_0200A784.h"
#include "unk_02017728.h"

typedef struct CellTransferStateData_t {
    int unk_00;
    int unk_04;
    int unk_08;
    NNSG2dCellTransferState *unk_0C;
    UnkStruct_0200C738 unk_10;
} SpriteRenderer;

typedef struct AnimationResourceCollection_t {
    CellActorCollection *unk_00;
    UnkStruct_02009508 *unk_04;
    SpriteResourceTable *unk_08;
    SpriteResourceCollection *unk_0C[6];
    SpriteResourceList *unk_24[6];
    int unk_3C[6];
    int unk_54;
} SpriteGfxHandler;

static BOOL sub_0200D11C(SpriteRenderer *param0, SpriteGfxHandler *param1, int param2, int param3, int param4, int param5, int param6);
static BOOL sub_0200D18C(SpriteRenderer *param0, SpriteGfxHandler *param1, NARC *param2, int param3, int param4, int param5, int param6);
static BOOL sub_0200D1FC(SpriteResourceList *param0, SpriteResource *param1);
static BOOL sub_0200D27C(SpriteResourceCollection *param0, SpriteResourceList *param1, int param2);
static BOOL sub_0200D2D0(SpriteResourceCollection *param0, SpriteResourceList *param1, int param2);
static BOOL sub_0200D230(SpriteResourceCollection *param0, SpriteResourceList *param1, int param2);

SpriteRenderer *sub_0200C6E4(int param0)
{
    SpriteRenderer *v0 = NULL;

    v0 = Heap_AllocFromHeap(param0, sizeof(SpriteRenderer));

    if (v0 == NULL) {
        return NULL;
    }

    v0->unk_00 = param0;
    v0->unk_04 = 0;
    v0->unk_08 = 1;

    return v0;
}

SpriteGfxHandler *sub_0200C704(SpriteRenderer *param0)
{
    int v0;
    SpriteGfxHandler *v1 = NULL;

    GF_ASSERT(param0 != NULL);

    v1 = Heap_AllocFromHeap(param0->unk_00, sizeof(SpriteGfxHandler));

    if (v1 == NULL) {
        return NULL;
    }

    param0->unk_04++;

    for (v0 = 0; v0 < 6; v0++) {
        v1->unk_0C[v0] = NULL;
    }

    return v1;
}

UnkStruct_0200C738 *sub_0200C738(SpriteRenderer *param0)
{
    return &param0->unk_10;
}

BOOL sub_0200C73C(SpriteRenderer *param0, const UnkStruct_ov104_0224133C *param1, const UnkStruct_ov104_022412F4 *param2, int param3)
{
    GF_ASSERT(param0 != NULL);

    if (param0 == NULL) {
        return 0;
    }

    {
        CharTransferTemplate v0;

        v0.maxTasks = param2->unk_00;
        v0.sizeMain = param2->unk_04;
        v0.sizeSub = param2->unk_08;
        v0.heapID = param0->unk_00;

        CharTransfer_InitWithVramModes(&v0, param2->unk_0C, param2->unk_10);
    }

    PlttTransfer_Init(param3, param0->unk_00);
    NNS_G2dInitOamManagerModule();

    if (param0->unk_08 == 1) {
        sub_0200A784(param1->unk_00, param1->unk_04, param1->unk_08, param1->unk_0C, param1->unk_10, param1->unk_14, param1->unk_18, param1->unk_1C, param0->unk_00);
    }

    param0->unk_0C = CellTransfer_New(32, param0->unk_00);

    CharTransfer_ClearBuffers();
    PlttTransfer_Clear();

    return 1;
}

BOOL sub_0200C7C0(SpriteRenderer *param0, SpriteGfxHandler *param1, int param2)
{
    if ((param0 == NULL) || (param1 == NULL)) {
        return 0;
    }

    param1->unk_00 = sub_020095C4(param2, &param0->unk_10, param0->unk_00);
    return 1;
}

void sub_0200C7E4(CellActor *param0)
{
    CellActor_Delete(param0);
}

void sub_0200C7EC(SpriteGfxHandler *param0)
{
    GF_ASSERT(param0 != NULL);
    CellActorCollection_Update(param0->unk_00);
}

void OAMManager_ApplyAndResetBuffers(void)
{
    sub_0200A858();
}

void sub_0200C808(void)
{
    CellTransfer_Update();
}

void sub_0200C810(SpriteGfxHandler *param0)
{
    CellActorCollection_Delete(param0->unk_00);
}

void sub_0200C81C(SpriteGfxHandler *param0)
{
    if (param0->unk_04 == NULL) {
        return;
    }

    sub_020095A8(param0->unk_04);
}

void sub_0200C82C(SpriteGfxHandler *param0)
{
    int v0;
    SpriteResourceTable *v1;

    for (v0 = 0; v0 < param0->unk_54; v0++) {
        v1 = SpriteResourceTable_GetArrayElement(param0->unk_08, v0);
        SpriteResourceTable_Clear(v1);
    }

    Heap_FreeToHeap(param0->unk_08);
    SpriteTransfer_ResetCharTransferList(param0->unk_24[0]);
    SpriteTransfer_ResetPlttTransferList(param0->unk_24[1]);

    for (v0 = 0; v0 < param0->unk_54; v0++) {
        SpriteResourceList_Delete(param0->unk_24[v0]);
        SpriteResourceCollection_Delete(param0->unk_0C[v0]);
    }
}

void sub_0200C880(SpriteRenderer *param0)
{
    CellTransfer_Free(param0->unk_0C);
    CharTransfer_Free();
    PlttTransfer_Free();

    if (param0->unk_08 == 1) {
        sub_0200A878();
    }
}

void sub_0200C8A0(SpriteRenderer *param0, SpriteGfxHandler *param1)
{
    param0->unk_04--;
    Heap_FreeToHeap(param1);
}

void sub_0200C8B0(SpriteRenderer *param0, SpriteGfxHandler *param1)
{
    sub_0200C810(param1);
    sub_0200C81C(param1);
    sub_0200C82C(param1);
    sub_0200C8A0(param0, param1);
}

void sub_0200C8D4(SpriteRenderer *param0)
{
    GF_ASSERT(param0->unk_04 == 0);

    sub_0200C880(param0);
    Heap_FreeToHeap(param0);
}

BOOL sub_0200C8F0(SpriteRenderer *param0, SpriteGfxHandler *param1, const UnkStruct_ov7_0224F2EC *param2)
{
    int v0;
    int v1 = 6;
    int v2;
    SpriteResourceTable *v3;
    void *v4;

    if ((param0 == NULL) || (param1 == NULL)) {
        return 0;
    }

    if (param2->val2.unk_10 == NULL) {
        v1 = 6 - 2;
    }

    param1->unk_54 = v1;
    v2 = SpriteResourceTable_Size();
    param1->unk_08 = Heap_AllocFromHeap(param0->unk_00, v2 * v1);

    for (v0 = 0; v0 < v1; v0++) {
        v3 = SpriteResourceTable_GetArrayElement(param1->unk_08, v0);
        v4 = ReadFileToHeap(param0->unk_00, param2->val1[v0]);

        SpriteResourceTable_LoadFromBinary(v4, v3, param0->unk_00);
        Heap_FreeToHeap(v4);
    }

    for (v0 = 0; v0 < v1; v0++) {
        v3 = SpriteResourceTable_GetArrayElement(param1->unk_08, v0);
        v2 = SpriteResourceTable_GetCount(v3);

        param1->unk_0C[v0] = SpriteResourceCollection_New(v2, v0, param0->unk_00);
    }

    for (v0 = 0; v0 < v1; v0++) {
        v3 = SpriteResourceTable_GetArrayElement(param1->unk_08, v0);
        v2 = SpriteResourceTable_GetCount(v3);

        param1->unk_24[v0] = SpriteResourceList_New(v2, param0->unk_00);
        param1->unk_3C[v0] = SpriteResourceCollection_Extend(param1->unk_0C[v0], v3, param1->unk_24[v0], param0->unk_00);
    }

    SpriteTransfer_RequestCharList(param1->unk_24[0]);
    SpriteTransfer_RequestPlttWholeRangeList(param1->unk_24[1]);

    v4 = ReadFileToHeap(param0->unk_00, param2->val2.unk_18);
    param1->unk_04 = sub_02009508(v4, param0->unk_00, param1->unk_0C[0], param1->unk_0C[1], param1->unk_0C[2], param1->unk_0C[3], param1->unk_0C[4], param1->unk_0C[5]);

    Heap_FreeToHeap(v4);
    return 1;
}

CellActor *sub_0200CA08(SpriteRenderer *param0, SpriteGfxHandler *param1, const UnkStruct_ov7_0224F358 *param2)
{
    CellActor *v0 = NULL;

    v0 = sub_0200CA44(param0, param1, param2->unk_00, param2->unk_04, param2->unk_06, param2->unk_04, param2->unk_0A, param2->unk_0C, param2->unk_10, param2->unk_14, param2->unk_18, param2->unk_1C, param2->unk_20, param2->unk_24);
    return v0;
}

CellActor *sub_0200CA44(SpriteRenderer *param0, SpriteGfxHandler *param1, int param2, s16 param3, s16 param4, s16 param5, u16 param6, int param7, int param8, int param9, int param10, int param11, int param12, int param13)
{
    CellActor *v0 = NULL;
    CellActorInitParamsEx v1;

    v1.collection = param1->unk_00;
    v1.resourceData = &param1->unk_04->unk_00[param2];
    v1.position.x = FX32_CONST(param3);
    v1.position.y = FX32_CONST(param4);
    v1.position.z = FX32_CONST(param5);

    if (param9 == NNS_G2D_VRAM_TYPE_2DSUB) {
        v1.position.y += (192 << FX32_SHIFT);
    }

    v1.affineScale.x = FX32_ONE;
    v1.affineScale.y = FX32_ONE;
    v1.affineScale.z = FX32_ONE;
    v1.affineZRotation = 0;
    v1.priority = param7;
    v1.vramType = param9;
    v1.heapID = param0->unk_00;

    v0 = CellActorCollection_AddEx(&v1);

    if (v0 != NULL) {
        CellActor_SetAnim(v0, param6);
        CellActor_SetExplicitPalette(v0, param8);
    }

    return v0;
}

BOOL sub_0200CB30(SpriteRenderer *param0, SpriteGfxHandler *param1, const UnkStruct_ov104_02241308 *param2)
{
    int v0;
    int v1;
    int v2 = 6;
    int v3;
    SpriteResourceTable *v4;

    if ((param0 == NULL) || (param1 == NULL)) {
        return 0;
    }

    if ((param2->val2.unk_10 == 0) || (param2->val2.unk_14 == 0)) {
        v2 = 6 - 2;
    }

    param1->unk_54 = v2;

    for (v0 = 0; v0 < v2; v0++) {
        param1->unk_0C[v0] = SpriteResourceCollection_New(param2->val1[v0], v0, param0->unk_00);
    }

    for (v0 = 0; v0 < v2; v0++) {
        v3 = param2->val1[v0];

        if (v3 == 0) {
            continue;
        }

        param1->unk_24[v0] = SpriteResourceList_New(v3, param0->unk_00);
        param1->unk_3C[v0] = 0;

        for (v1 = 0; v1 < param1->unk_24[v0]->capacity; v1++) {
            param1->unk_24[v0]->resources[v1] = NULL;
        }
    }

    return 1;
}

BOOL sub_0200CBDC(SpriteRenderer *param0, SpriteGfxHandler *param1, int param2, int param3, BOOL param4, int param5, int param6)
{
    SpriteResource *v0;

    if (SpriteResourceCollection_IsIDUnused(param1->unk_0C[0], param6) == 0) {
        return 0;
    }

    v0 = SpriteResourceCollection_AddTiles(param1->unk_0C[0], param2, param3, param4, param6, param5, param0->unk_00);

    if (v0 != NULL) {
        SpriteTransfer_RequestCharAtEnd(v0);
        sub_0200D1FC(param1->unk_24[0], v0);

        return 1;
    }

    GF_ASSERT(0);

    return (v0 == NULL) ? 0 : 1;
}

BOOL SpriteRenderer_LoadCharResObjFromOpenNarc(SpriteRenderer *param0, SpriteGfxHandler *param1, NARC *param2, int param3, BOOL param4, int param5, int param6)
{
    SpriteResource *v0;

    if (SpriteResourceCollection_IsIDUnused(param1->unk_0C[0], param6) == 0) {
        return 0;
    }

    v0 = SpriteResourceCollection_AddTilesFrom(param1->unk_0C[0], param2, param3, param4, param6, param5, param0->unk_00);

    if (v0 != NULL) {
        SpriteTransfer_RequestCharAtEnd(v0);
        sub_0200D1FC(param1->unk_24[0], v0);
        return 1;
    }

    GF_ASSERT(0);

    return (v0 == NULL) ? 0 : 1;
}

s8 sub_0200CC9C(SpriteRenderer *param0, SpriteGfxHandler *param1, int param2, int param3, int param4, int param5, int param6, int param7)
{
    SpriteResource *v0;
    int v1;

    if (SpriteResourceCollection_IsIDUnused(param1->unk_0C[1], param7) == 0) {
        return -1;
    }

    v0 = SpriteResourceCollection_AddPalette(param1->unk_0C[1], param2, param3, param4, param7, param6, param5, param0->unk_00);

    if (v0 != NULL) {
        v1 = SpriteTransfer_RequestPlttFreeSpace(v0);
        GF_ASSERT(v1 == 1);

        sub_0200D1FC(param1->unk_24[1], v0);
        return SpriteTransfer_GetPlttOffset(v0, param6);
    }

    GF_ASSERT(0);

    return -1;
}

s8 sub_0200CD0C(SpriteRenderer *param0, SpriteGfxHandler *param1, NARC *param2, int param3, int param4, int param5, int param6, int param7)
{
    SpriteResource *v0;
    int v1;

    if (SpriteResourceCollection_IsIDUnused(param1->unk_0C[1], param7) == 0) {
        return -1;
    }

    v0 = SpriteResourceCollection_AddPaletteFrom(param1->unk_0C[1], param2, param3, param4, param7, param6, param5, param0->unk_00);

    if (v0 != NULL) {
        v1 = SpriteTransfer_RequestPlttFreeSpace(v0);
        GF_ASSERT(v1 == 1);
        sub_0200D1FC(param1->unk_24[1], v0);

        return SpriteTransfer_GetPlttOffset(v0, param6);
    }

    GF_ASSERT(0);
    return -1;
}

u8 sub_0200CD7C(PaletteData *param0, int param1, SpriteRenderer *param2, SpriteGfxHandler *param3, int param4, int param5, int param6, int param7, int param8, int param9)
{
    int v0;

    v0 = sub_0200CC9C(param2, param3, param4, param5, param6, param7, param8, param9);

    if (v0 != -1) {
        PaletteData_LoadBufferFromHardware(param0, param1, v0 * 16, param7 * 0x20);
    }

    return v0;
}

u8 SpriteRenderer_LoadPalette(PaletteData *param0, enum PaletteBufferID param1, SpriteRenderer *param2, SpriteGfxHandler *param3, NARC *param4, int param5, BOOL param6, int param7, int param8, int param9)
{
    int v0;

    v0 = sub_0200CD0C(param2, param3, param4, param5, param6, param7, param8, param9);

    if (v0 != -1) {
        PaletteData_LoadBufferFromHardware(param0, param1, v0 * 16, param7 * 0x20);
    }

    return v0;
}

BOOL sub_0200CE0C(SpriteRenderer *param0, SpriteGfxHandler *param1, int param2, int param3, int param4, int param5)
{
    return sub_0200D11C(param0, param1, param2, param3, param4, 2, param5);
}

BOOL SpriteRenderer_LoadCellResObjFromOpenNarc(SpriteRenderer *param0, SpriteGfxHandler *param1, NARC *param2, int param3, BOOL param4, int param5)
{
    return sub_0200D18C(param0, param1, param2, param3, param4, 2, param5);
}

BOOL sub_0200CE3C(SpriteRenderer *param0, SpriteGfxHandler *param1, int param2, int param3, int param4, int param5)
{
    return sub_0200D11C(param0, param1, param2, param3, param4, 3, param5);
}

BOOL SpriteRenderer_LoadAnimResObjFromOpenNarc(SpriteRenderer *param0, SpriteGfxHandler *param1, NARC *param2, int param3, BOOL param4, int param5)
{
    return sub_0200D18C(param0, param1, param2, param3, param4, 3, param5);
}

CellActorData *SpriteActor_LoadResources(SpriteRenderer *param0, SpriteGfxHandler *param1, const SpriteTemplate *param2)
{
    int v0;
    int v1;
    CellActorData *v2 = NULL;
    CellActorInitParamsEx v3;
    int v4[6];

    v2 = Heap_AllocFromHeap(param0->unk_00, sizeof(CellActorData));

    if (v2 == NULL) {
        return NULL;
    }

    v2->unk_08 = Heap_AllocFromHeap(param0->unk_00, sizeof(UnkStruct_02009508));

    if (v2->unk_08 == NULL) {
        return NULL;
    }

    v2->unk_08->unk_00 = Heap_AllocFromHeap(param0->unk_00, sizeof(CellActorResourceData));
    v2->unk_04 = v2->unk_08->unk_00;

    if (v2->unk_08->unk_00 == NULL) {
        if (v2->unk_08) {
            Heap_FreeToHeap(v2->unk_08);
        }

        return NULL;
    }

    for (v0 = 0; v0 < 6; v0++) {
        v4[v0] = param2->resources[v0];
    }

    if ((param1->unk_0C[4] == NULL) || (param1->unk_0C[5] == NULL)) {
        v4[4] = 0xffffffff;
        v4[5] = 0xffffffff;
    } else {
        if ((v4[4] != 0xffffffff) && (SpriteResourceCollection_IsIDUnused(param1->unk_0C[4], v4[4]) == 0)) {
            v4[4] = 0xffffffff;
        }

        if ((v4[5] != 0xffffffff) && (SpriteResourceCollection_IsIDUnused(param1->unk_0C[5], v4[5]) == 0)) {
            v4[5] = 0xffffffff;
        }
    }

    sub_020093B4(v2->unk_04, v4[0], v4[1], v4[2], v4[3], v4[4], v4[5], param2->transferToVRAM, param2->bgPriority, param1->unk_0C[0], param1->unk_0C[1], param1->unk_0C[2], param1->unk_0C[3], param1->unk_0C[4], param1->unk_0C[5]);

    v3.collection = param1->unk_00;
    v3.resourceData = v2->unk_04;
    v3.position.x = FX32_CONST(param2->x);
    v3.position.y = FX32_CONST(param2->y);
    v3.position.z = FX32_CONST(param2->z);

    if (param2->vramType == NNS_G2D_VRAM_TYPE_2DSUB) {
        v3.position.y += (192 << FX32_SHIFT);
    }

    v3.affineScale.x = FX32_ONE;
    v3.affineScale.y = FX32_ONE;
    v3.affineScale.z = FX32_ONE;
    v3.affineZRotation = 0;
    v3.priority = param2->priority;
    v3.vramType = param2->vramType;
    v3.heapID = param0->unk_00;
    v2->unk_00 = CellActorCollection_AddEx(&v3);
    v2->unk_0C = param2->transferToVRAM;

    if (v2->unk_00 != NULL) {
        v1 = CellActor_GetExplicitPalette(v2->unk_00);

        CellActor_SetAnim(v2->unk_00, param2->animIdx);
        CellActor_SetExplicitPalette(v2->unk_00, v1 + param2->plttIdx);
    } else {
        GF_ASSERT(FALSE);
    }

    return v2;
}

const NNSG2dImagePaletteProxy *sub_0200D04C(SpriteGfxHandler *param0, int param1)
{
    SpriteResource *v0 = SpriteResourceCollection_Find(param0->unk_0C[1], param1);
    return SpriteTransfer_GetPaletteProxy(v0, NULL);
}

u32 sub_0200D05C(SpriteGfxHandler *param0, int param1, NNS_G2D_VRAM_TYPE param2)
{
    SpriteResource *v0 = SpriteResourceCollection_Find(param0->unk_0C[1], param1);
    return SpriteTransfer_GetPlttOffset(v0, param2);
}

BOOL SpriteGfxHandler_UnloadCharObjById(SpriteGfxHandler *param0, int param1)
{
    return sub_0200D27C(param0->unk_0C[0], param0->unk_24[0], param1);
}

BOOL SpriteGfxHandler_UnloadPlttObjById(SpriteGfxHandler *param0, int param1)
{
    return sub_0200D2D0(param0->unk_0C[1], param0->unk_24[1], param1);
}

BOOL SpriteGfxHandler_UnloadCellObjById(SpriteGfxHandler *param0, int param1)
{
    return sub_0200D230(param0->unk_0C[2], param0->unk_24[2], param1);
}

BOOL SpriteGfxHandler_UnloadAnimObjById(SpriteGfxHandler *param0, int param1)
{
    return sub_0200D230(param0->unk_0C[3], param0->unk_24[3], param1);
}

void sub_0200D0B0(SpriteRenderer *param0, SpriteGfxHandler *param1)
{
    int v0;

    sub_0200C810(param1);
    SpriteTransfer_ResetCharTransferList(param1->unk_24[0]);
    SpriteTransfer_ResetPlttTransferList(param1->unk_24[1]);

    for (v0 = 0; v0 < param1->unk_54; v0++) {
        SpriteResourceList_Delete(param1->unk_24[v0]);
        SpriteResourceCollection_Delete(param1->unk_0C[v0]);
    }

    sub_0200C8A0(param0, param1);
}

void sub_0200D0F4(CellActorData *param0)
{
    if (param0->unk_0C) {
        SpriteTransfer_DeleteCharTransfer(param0->unk_04->imageProxy);
    }

    CellActor_Delete(param0->unk_00);
    sub_020095A8(param0->unk_08);
    Heap_FreeToHeap(param0);
}

static BOOL sub_0200D11C(SpriteRenderer *param0, SpriteGfxHandler *param1, int param2, int param3, int param4, int param5, int param6)
{
    SpriteResource *v0;
    int v1;

    if (SpriteResourceCollection_IsIDUnused(param1->unk_0C[param5], param6) == 0) {
        return 0;
    }

    v0 = SpriteResourceCollection_Add(param1->unk_0C[param5], param2, param3, param4, param6, param5, param0->unk_00);

    if (v0 != NULL) {
        v1 = sub_0200D1FC(param1->unk_24[param5], v0);

        GF_ASSERT(v1 == 1);
        return v1;
    }

    GF_ASSERT(0);
    return (v0 == NULL) ? 0 : 1;
}

static BOOL sub_0200D18C(SpriteRenderer *param0, SpriteGfxHandler *param1, NARC *param2, int param3, int param4, int param5, int param6)
{
    SpriteResource *v0;
    int v1;

    if (SpriteResourceCollection_IsIDUnused(param1->unk_0C[param5], param6) == 0) {
        return 0;
    }

    v0 = SpriteResourceCollection_AddFrom(param1->unk_0C[param5], param2, param3, param4, param6, param5, param0->unk_00);

    if (v0 != NULL) {
        v1 = sub_0200D1FC(param1->unk_24[param5], v0);

        GF_ASSERT(v1 == 1);
        return v1;
    }

    GF_ASSERT(0);

    return (v0 == NULL) ? 0 : 1;
}

static BOOL sub_0200D1FC(SpriteResourceList *param0, SpriteResource *param1)
{
    int v0;

    for (v0 = 0; v0 < param0->capacity; v0++) {
        if (param0->resources[v0] != NULL) {
            continue;
        }

        param0->resources[v0] = param1;
        param0->count++;

        return 1;
    }

    return 0;
}

static BOOL sub_0200D230(SpriteResourceCollection *param0, SpriteResourceList *param1, int param2)
{
    int v0;
    int v1;

    for (v0 = 0; v0 < param1->capacity; v0++) {
        if (param1->resources[v0] == NULL) {
            continue;
        }

        v1 = SpriteResource_GetID(param1->resources[v0]);

        if (v1 == param2) {
            SpriteResourceCollection_Remove(param0, param1->resources[v0]);

            param1->resources[v0] = NULL;
            param1->count--;

            return 1;
        }
    }

    return 0;
}

static BOOL sub_0200D27C(SpriteResourceCollection *param0, SpriteResourceList *param1, int param2)
{
    int v0;
    int v1;

    for (v0 = 0; v0 < param1->capacity; v0++) {
        if (param1->resources[v0] == NULL) {
            continue;
        }

        v1 = SpriteResource_GetID(param1->resources[v0]);

        if (v1 == param2) {
            CharTransfer_ResetTask(param2);
            SpriteResourceCollection_Remove(param0, param1->resources[v0]);

            param1->resources[v0] = NULL;
            param1->count--;

            return 1;
        }
    }

    return 0;
}

static BOOL sub_0200D2D0(SpriteResourceCollection *param0, SpriteResourceList *param1, int param2)
{
    int v0;
    int v1;

    for (v0 = 0; v0 < param1->capacity; v0++) {
        if (param1->resources[v0] == NULL) {
            continue;
        }

        v1 = SpriteResource_GetID(param1->resources[v0]);

        if (v1 == param2) {
            PlttTransfer_ResetTask(param2);
            SpriteResourceCollection_Remove(param0, param1->resources[v0]);

            param1->resources[v0] = NULL;
            param1->count--;

            return 1;
        }
    }

    return 0;
}

void SpriteActor_UpdateObject(CellActor *param0)
{
    CellActor_UpdateAnim(param0, FX32_ONE);
}

void sub_0200D330(CellActorData *param0)
{
    SpriteActor_UpdateObject(param0->unk_00);
}

void sub_0200D33C(CellActorData *param0)
{
    CellActor_UpdateAnim(param0->unk_00, FX32_CONST(2));
}

void sub_0200D34C(CellActorData *param0, fx32 param1)
{
    CellActor_UpdateAnim(param0->unk_00, param1);
}

u32 sub_0200D358(CellActorData *param0)
{
    return CellActor_GetAnimCount(param0->unk_00);
}

void sub_0200D364(CellActorData *param0, u32 param1)
{
    CellActor_SetAnim(param0->unk_00, param1);
}

void sub_0200D370(CellActorData *param0, u32 param1)
{
    CellActor_SetAnimNoRestart(param0->unk_00, param1);
}

u32 sub_0200D37C(CellActorData *param0)
{
    return CellActor_GetActiveAnim(param0->unk_00);
}

void sub_0200D388(CellActor *param0, int param1)
{
    CellActor_SetAnimateFlag(param0, param1);
}

void sub_0200D390(CellActorData *param0, int param1)
{
    sub_0200D388(param0->unk_00, param1);
}

void sub_0200D39C(CellActor *param0, fx32 param1)
{
    CellActor_SetAnimSpeed(param0, param1);
}

void sub_0200D3A4(CellActorData *param0, fx32 param1)
{
    sub_0200D39C(param0->unk_00, param1);
}

BOOL sub_0200D3B0(CellActor *param0)
{
    return CellActor_IsAnimated(param0);
}

BOOL sub_0200D3B8(CellActorData *param0)
{
    return sub_0200D3B0(param0->unk_00);
}

void sub_0200D3C4(CellActor *param0, u16 param1)
{
    SpriteActor_SetAnimFrame(param0, param1);
}

void sub_0200D3CC(CellActorData *param0, u16 param1)
{
    sub_0200D3C4(param0->unk_00, param1);
}

u16 sub_0200D3D8(CellActor *param0)
{
    return CellActor_GetAnimFrame(param0);
}

u16 sub_0200D3E0(CellActorData *param0)
{
    return sub_0200D3D8(param0->unk_00);
}

void SpriteActor_DrawSprite(CellActor *param0, int param1)
{
    CellActor_SetDrawFlag(param0, param1);
}

void SpriteActor_EnableObject(CellActorData *param0, int param1)
{
    SpriteActor_DrawSprite(param0->unk_00, param1);
}

int sub_0200D400(CellActor *param0)
{
    return CellActor_GetDrawFlag(param0);
}

int sub_0200D408(CellActorData *param0)
{
    return sub_0200D400(param0->unk_00);
}

void sub_0200D414(CellActor *param0, int param1)
{
    CellActor_SetExplicitPalette(param0, param1);
}

void sub_0200D41C(CellActorData *param0, int param1)
{
    sub_0200D414(param0->unk_00, param1);
}

void sub_0200D428(CellActor *param0, int param1)
{
    CellActor_SetExplicitPaletteOffset(param0, param1);
}

void sub_0200D430(CellActorData *param0, int param1)
{
    sub_0200D428(param0->unk_00, param1);
}

int sub_0200D43C(CellActorData *param0)
{
    return CellActor_GetExplicitPaletteOffset(param0->unk_00);
}

void sub_0200D448(CellActor *param0, int param1)
{
    CellActor_SetExplicitPriority(param0, param1);
}

int sub_0200D454(CellActorData *param0)
{
    return CellActor_GetExplicitPriority(param0->unk_00);
}

void sub_0200D460(CellActorData *param0, int param1)
{
    sub_0200D448(param0->unk_00, param1);
}

void sub_0200D46C(CellActor *param0, int param1)
{
    CellActor_SetPriority(param0, param1);
}

void sub_0200D474(CellActorData *param0, int param1)
{
    sub_0200D46C(param0->unk_00, param1);
}

u32 sub_0200D480(CellActor *param0)
{
    return CellActor_GetPriority(param0);
}

u32 sub_0200D488(CellActorData *param0)
{
    return sub_0200D480(param0->unk_00);
}

void SpriteActor_SetPositionXY(CellActor *param0, s16 param1, s16 param2)
{
    VecFx32 v0;

    v0.x = param1 * FX32_ONE;
    v0.y = param2 * FX32_ONE;

    if (CellActor_GetVRamType(param0) == NNS_G2D_VRAM_TYPE_2DSUB) {
        v0.y += (192 << FX32_SHIFT);
    }

    v0.z = 0;

    CellActor_SetPosition(param0, &v0);
}

void SpriteActor_SetSpritePositionXY(CellActorData *param0, s16 param1, s16 param2)
{
    SpriteActor_SetPositionXY(param0->unk_00, param1, param2);
}

void sub_0200D4D0(CellActor *param0, s16 param1, s16 param2, fx32 param3)
{
    VecFx32 v0;

    v0.x = param1 * FX32_ONE;
    v0.y = param2 * FX32_ONE;

    if (CellActor_GetVRamType(param0) == NNS_G2D_VRAM_TYPE_2DSUB) {
        v0.y += param3;
    }

    v0.z = 0;

    CellActor_SetPosition(param0, &v0);
}

void sub_0200D500(CellActorData *param0, s16 param1, s16 param2, fx32 param3)
{
    sub_0200D4D0(param0->unk_00, param1, param2, param3);
}

void sub_0200D50C(CellActor *param0, s16 *param1, s16 *param2)
{
    const VecFx32 *v0;

    v0 = CellActor_GetPosition(param0);
    *param1 = v0->x / FX32_ONE;

    if (CellActor_GetVRamType(param0) == NNS_G2D_VRAM_TYPE_2DSUB) {
        *param2 = (v0->y - (192 << FX32_SHIFT)) / FX32_ONE;
    } else {
        *param2 = v0->y / FX32_ONE;
    }
}

void SpriteActor_GetSpritePositionXY(CellActorData *param0, s16 *param1, s16 *param2)
{
    sub_0200D50C(param0->unk_00, param1, param2);
}

void sub_0200D55C(CellActor *param0, s16 *param1, s16 *param2, fx32 param3)
{
    const VecFx32 *v0;

    v0 = CellActor_GetPosition(param0);
    *param1 = v0->x / FX32_ONE;

    if (CellActor_GetVRamType(param0) == NNS_G2D_VRAM_TYPE_2DSUB) {
        *param2 = (v0->y - param3) / FX32_ONE;
    } else {
        *param2 = v0->y / FX32_ONE;
    }
}

void sub_0200D5A0(CellActorData *param0, s16 *param1, s16 *param2, fx32 param3)
{
    sub_0200D55C(param0->unk_00, param1, param2, param3);
}

void sub_0200D5AC(CellActor *param0, s16 param1, s16 param2)
{
    const VecFx32 *v0;
    VecFx32 v1;

    v0 = CellActor_GetPosition(param0);

    v1.x = v0->x + (param1 * FX32_ONE);
    v1.y = v0->y + (param2 * FX32_ONE);
    v1.z = v0->z;

    CellActor_SetPosition(param0, &v1);
}

void sub_0200D5DC(CellActorData *param0, s16 param1, s16 param2)
{
    sub_0200D5AC(param0->unk_00, param1, param2);
}

void sub_0200D5E8(CellActorData *param0, fx32 param1, fx32 param2)
{
    const VecFx32 *v0;
    VecFx32 v1;

    v0 = CellActor_GetPosition(param0->unk_00);

    v1.x = v0->x + param1;
    v1.y = v0->y + param2;
    v1.z = v0->z;

    CellActor_SetPosition(param0->unk_00, &v1);
}

void sub_0200D614(CellActorData *param0, fx32 param1, fx32 param2)
{
    const VecFx32 *v0;
    VecFx32 v1;

    v0 = CellActor_GetPosition(param0->unk_00);

    v1.x = param1;
    v1.y = param2;
    v1.z = v0->z;

    CellActor_SetPosition(param0->unk_00, &v1);
}

void sub_0200D638(CellActorData *param0, fx32 *param1, fx32 *param2)
{
    const VecFx32 *v0;
    VecFx32 v1;

    v0 = CellActor_GetPosition(param0->unk_00);

    *param1 = v0->x;
    *param2 = v0->y;
}

void sub_0200D650(CellActorData *param0, fx32 param1, fx32 param2, fx32 param3)
{
    if (CellActor_GetVRamType(param0->unk_00) == NNS_G2D_VRAM_TYPE_2DSUB) {
        sub_0200D614(param0, param1, param2 + param3);
    } else {
        sub_0200D614(param0, param1, param2);
    }
}

void sub_0200D67C(CellActorData *param0, fx32 *param1, fx32 *param2, fx32 param3)
{
    sub_0200D638(param0, param1, param2);

    if (CellActor_GetVRamType(param0->unk_00) == NNS_G2D_VRAM_TYPE_2DSUB) {
        *param2 = *param2 - param3;
    }
}

void sub_0200D69C(CellActor *param0, int param1)
{
    CellActor_SetAffineOverwriteMode(param0, param1);
}

void sub_0200D6A4(CellActorData *param0, int param1)
{
    sub_0200D69C(param0->unk_00, param1);
}

void sub_0200D6B0(CellActor *param0, f32 param1, f32 param2)
{
    const VecFx32 *v0;
    VecFx32 *v1;

    v0 = CellActor_GetAffineScale(param0);
    v1 = (VecFx32 *)v0;

    v1->x = (param1 * FX32_ONE);
    v1->y = (param2 * FX32_ONE);

    CellActor_SetAffineScale(param0, v1);
}

void sub_0200D6E8(CellActorData *param0, f32 param1, f32 param2)
{
    sub_0200D6B0(param0->unk_00, param1, param2);
}

void sub_0200D6F4(CellActor *param0, f32 param1, f32 param2)
{
    const VecFx32 *v0;
    VecFx32 *v1;

    v0 = CellActor_GetAffineScale(param0);
    v1 = (VecFx32 *)v0;

    v1->x = v0->x + (param1 * FX32_ONE);
    v1->y = v0->y + (param2 * FX32_ONE);

    CellActor_SetAffineScale(param0, v1);
}

void sub_0200D74C(CellActorData *param0, f32 param1, f32 param2)
{
    sub_0200D6F4(param0->unk_00, param1, param2);
}

void sub_0200D758(CellActor *param0, f32 *param1, f32 *param2)
{
    const VecFx32 *v0;
    VecFx32 *v1;

    v0 = CellActor_GetAffineScale(param0);

    *param1 = FX_FX32_TO_F32(v0->x);
    *param2 = FX_FX32_TO_F32(v0->y);
}

void sub_0200D788(CellActorData *param0, f32 *param1, f32 *param2)
{
    sub_0200D758(param0->unk_00, param1, param2);
}

void sub_0200D794(CellActor *param0, u16 param1)
{
    CellActor_SetAffineZRotation(param0, param1);
}

void sub_0200D79C(CellActorData *param0, u16 param1)
{
    sub_0200D794(param0->unk_00, param1);
}

void sub_0200D7A8(CellActor *param0, s32 param1)
{
    u16 v0;

    v0 = CellActor_GetAffineZRotation(param0);
    v0 += param1;

    CellActor_SetAffineZRotation(param0, v0);
}

void sub_0200D7C0(CellActorData *param0, s32 param1)
{
    sub_0200D7A8(param0->unk_00, param1);
}

void sub_0200D7CC(CellActor *param0, int param1)
{
    CellActor_SetFlipMode(param0, param1);
}

void sub_0200D7D4(CellActorData *param0, int param1)
{
    sub_0200D7CC(param0->unk_00, param1);
}

void sub_0200D7E0(CellActorData *param0, s16 param1, s16 param2)
{
    VecFx32 v0;

    v0.x = param1 << FX32_SHIFT;
    v0.y = param2 << FX32_SHIFT;
    v0.z = 0;

    CellActor_SetAffineTranslation(param0->unk_00, &v0);
}

void sub_0200D7FC(CellActorData *param0, BOOL param1)
{
    CellActor_SetPixelated(param0->unk_00, param1);
}

void sub_0200D808(CellActor *param0, GXOamMode param1)
{
    CellActor_SetExplicitOAMMode(param0, param1);
}

void SpriteActor_SetOAMMode(CellActorData *param0, GXOamMode param1)
{
    sub_0200D808(param0->unk_00, param1);
}

u32 sub_0200D81C(CellActorData *param0)
{
    return CellActor_GetUserAttrForCurrentAnimFrame(param0->unk_00);
}

BOOL sub_0200D828(SpriteRenderer *param0, SpriteGfxHandler *param1, int param2, int param3, BOOL param4, int param5, int param6)
{
    SpriteResource *v0;

    if (SpriteResourceCollection_IsIDUnused(param1->unk_0C[0], param6) == 0) {
        return 0;
    }

    v0 = SpriteResourceCollection_AddTiles(param1->unk_0C[0], param2, param3, param4, param6, param5, param0->unk_00);

    if (v0 != NULL) {
        SpriteTransfer_RequestCharWithHardwareMappingType(v0);
        sub_0200D1FC(param1->unk_24[0], v0);

        return 1;
    }

    GF_ASSERT(0);

    return (v0 == NULL) ? 0 : 1;
}

BOOL sub_0200D888(SpriteRenderer *param0, SpriteGfxHandler *param1, int param2, int param3, BOOL param4, int param5, int param6)
{
    SpriteResource *v0;

    if (SpriteResourceCollection_IsIDUnused(param1->unk_0C[0], param6) == 0) {
        return 0;
    }

    v0 = SpriteResourceCollection_AddTiles(param1->unk_0C[0], param2, param3, param4, param6, param5, param0->unk_00);

    if (v0 != NULL) {
        SpriteTransfer_RequestCharAtEndWithHardwareMappingType(v0);
        sub_0200D1FC(param1->unk_24[0], v0);

        return 1;
    }

    GF_ASSERT(0);

    return (v0 == NULL) ? 0 : 1;
}

BOOL sub_0200D8E8(SpriteRenderer *param0, SpriteGfxHandler *param1, NARC *param2, int param3, BOOL param4, int param5, int param6)
{
    SpriteResource *v0;

    if (SpriteResourceCollection_IsIDUnused(param1->unk_0C[0], param6) == 0) {
        return 0;
    }

    v0 = SpriteResourceCollection_AddTilesFrom(param1->unk_0C[0], param2, param3, param4, param6, param5, param0->unk_00);

    if (v0 != NULL) {
        SpriteTransfer_RequestCharAtEndWithHardwareMappingType(v0);
        sub_0200D1FC(param1->unk_24[0], v0);

        return 1;
    }

    GF_ASSERT(0);

    return (v0 == NULL) ? 0 : 1;
}

void sub_0200D948(SpriteRenderer *param0, SpriteGfxHandler *param1, int param2, int param3, BOOL param4, int param5)
{
    SpriteResource *v0;

    v0 = SpriteResourceCollection_Find(param1->unk_0C[0], param5);

    SpriteResourceCollection_ModifyTiles(param1->unk_0C[0], v0, param2, param3, param4, param0->unk_00);
    SpriteTransfer_RetransferCharData(v0);
}

void sub_0200D97C(SpriteRenderer *param0, SpriteGfxHandler *param1, int param2, int param3, BOOL param4, int param5)
{
    SpriteResource *v0;

    v0 = SpriteResourceCollection_Find(param1->unk_0C[1], param5);

    SpriteResourceCollection_ModifyPalette(param1->unk_0C[1], v0, param2, param3, param4, param0->unk_00);
    SpriteTransfer_ReplacePlttData(v0);
}

CellActorCollection *sub_0200D9B0(SpriteGfxHandler *param0)
{
    return param0->unk_00;
}

void sub_0200D9B4(SpriteRenderer *param0, SpriteGfxHandler *param1, NARC *param2, int param3, BOOL param4, int param5)
{
    SpriteResource *v0;

    v0 = SpriteResourceCollection_Find(param1->unk_0C[0], param5);

    SpriteResourceCollection_ModifyTilesFrom(param1->unk_0C[0], v0, param2, param3, param4, param0->unk_00);
    SpriteTransfer_RetransferCharData(v0);
}
