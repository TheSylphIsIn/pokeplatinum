#include <nitro.h>
#include <string.h>

#include "pokemon.h"
#include "unk_020244AC.h"

#include "unk_020244AC.h"
#include "poketch_data.h"
#include "pokemon_icon.h"
#include "savedata/save_table.h"

int Poketch_SaveSize(void)
{
    return sizeof(PoketchData);
}

static const struct {
        u8 x;
        u8 y;
} sDefaultMapMarkers[POKETCH_MAPMARKER_COUNT] = {
    {104, 152},
    {120, 152},
    {136, 152},
    {152, 152},
    {168, 152},
    {184, 152}
};

void Poketch_Init(PoketchData *poketchData)
{
    int i;

    for (i = 0; i < POKETCH_REGISTRY_SIZE; i++) {
        poketchData->appRegistry[i] = 0;
    }

    poketchData->appCount = 0;
    poketchData->appIndex = 0;
    poketchData->unk_00_0 = 0;
    poketchData->screenColor = 0;
    poketchData->pedometerEnabled = 0;
    poketchData->pedometer = 0;
    poketchData->alarmSet = 0;
    poketchData->alarmHour = 0;
    poketchData->alarmMinute = 0;
    poketchData->unk_A8 = 1;
    poketchData->unk_A4 = 0;

    for (i = 0; i < POKETCH_MAPMARKER_COUNT; i++) {
        poketchData->markMapPositions[i].x = sDefaultMapMarkers[i].x;
        poketchData->markMapPositions[i].y = sDefaultMapMarkers[i].y;
    }

    for (i = 0; i < 12; i++) {
        poketchData->unk_B8[i].unk_00 = 0;
        poketchData->unk_B8[i].unk_02 = 0;
        poketchData->unk_B8[i].unk_04 = 0;
    }

    poketchData->unk_00_2 = 0;
    PoketchData_RegisterApp(poketchData, POKETCH_APPID_DIGITALWATCH);
}

void sub_020567D0 (PoketchData *poketchData)
{
    poketchData->unk_00_0 = 1;
}

BOOL sub_020567E0 (PoketchData *poketchData)
{
    return poketchData->unk_00_0;
}

BOOL PoketchData_CheckAppRegistered(PoketchData *poketchData, enum PoketchAppID appID)
{
    return poketchData->appRegistry[appID];
}

BOOL PoketchData_RegisterApp(PoketchData *poketchData, enum PoketchAppID appID)
{
    BOOL appRegistered = FALSE;

    GF_ASSERT(appID >= 0 && appID < POKETCH_APPID_MAX);

    if (poketchData->appCount < POKETCH_APPID_MAX && poketchData->appRegistry[appID] == 0) {
        poketchData->appRegistry[appID] = 1;
        poketchData->appCount++;

        if (appID == POKETCH_APPID_PEDOMETER) {
            poketchData->pedometerEnabled = 1;
        }

        appRegistered = TRUE;
    }    

    return appRegistered;
}

enum PoketchAppID PoketchData_CurrentAppID(const PoketchData *poketchData)
{
    return poketchData->appIndex;
}

int PoketchData_IncrementAppID(PoketchData *poketchData)
{
    int nextIndex = poketchData->appIndex;

    while (TRUE) {
        if (++nextIndex >= POKETCH_APPID_MAX) {
            nextIndex = 0;
        }

        if (nextIndex == poketchData->appIndex) {
            break;
        }

        if (poketchData->appRegistry[nextIndex]) {
            break;
        }
    }

    poketchData->appIndex = nextIndex;

    return poketchData->appIndex;
}

int PoketchData_DecrementAppID(PoketchData *poketchData)
{
    int prevIndex = poketchData->appIndex;

    while (TRUE) {
        if (--prevIndex < 0) {
            prevIndex = POKETCH_APPID_MAX - 1;
        }

        if (prevIndex == poketchData->appIndex) {
            break;
        }

        if (poketchData->appRegistry[prevIndex]) {
            break;
        }
    }

    poketchData->appIndex = prevIndex;

    return poketchData->appIndex;
}

u32 PoketchData_CurrentScreenColor(const PoketchData *poketchData)
{
    GF_ASSERT(poketchData);
    return poketchData->screenColor;
}

void PoketchData_SetScreenColor(PoketchData *poketchData, u32 screenColor)
{
    GF_ASSERT(poketchData);
    GF_ASSERT(screenColor < POKETCH_SCREEN_COLOR_MAX);

    poketchData->screenColor = screenColor;
}

u32 PoketchData_PedometerValue(const PoketchData *poketchData)
{
    return poketchData->pedometer;
}

void PoketchData_SetPedometerValue(PoketchData *poketchData, u32 value)
{
    if (poketchData->pedometerEnabled) {
        poketchData->pedometer = value;
    }
}

BOOL PoketchData_IsAlarmSet(const PoketchData *poketchData)
{
    return poketchData->alarmSet;
}

void PoketchData_AlarmTime(const PoketchData *poketchData, u32 *hour, u32 *minute)
{
    *hour = poketchData->alarmHour;
    *minute = poketchData->alarmMinute;
}

void PoketchData_SetAlarm(PoketchData *poketchData, BOOL enable, u32 hour, u32 minute)
{
    poketchData->alarmSet = enable;
    poketchData->alarmHour = hour;
    poketchData->alarmMinute = minute;
}

void sub_02056934 (PoketchData *poketchData, u32 param1, u32 param2)
{
    if (poketchData->unk_A8 == param1) {
        poketchData->unk_A4 |= (1 << (param2 - 1));
    } else {
        poketchData->unk_A8 = param1;
        poketchData->unk_A4 = (1 << (param2 - 1));
    }
}

void sub_02056970 (PoketchData *poketchData, u32 param1, u32 param2)
{
    if (poketchData->unk_A8 == param1) {
        poketchData->unk_A4 &= ~(1 << (param2 - 1));
    } else {
        poketchData->unk_A8 = param1;
        poketchData->unk_A4 = 0;
    }
}

BOOL sub_020569A8 (const PoketchData *poketchData, u32 param1, u32 param2)
{
    if (poketchData->unk_A8 == param1) {
        return (poketchData->unk_A4 >> (param2 - 1)) & 1;
    } else {
        return 0;
    }
}

void PoketchData_SetMapMarker(PoketchData *poketchData, int index, u8 x, u8 y)
{
    GF_ASSERT(index < POKETCH_MAPMARKER_COUNT);

    poketchData->markMapPositions[index].x = x;
    poketchData->markMapPositions[index].y = y;
}

void PoketchData_MapMarkerPos(const PoketchData *poketchData, int index, u8 *x, u8 *y)
{
    GF_ASSERT(index < POKETCH_MAPMARKER_COUNT);

    *x = poketchData->markMapPositions[index].x;
    *y = poketchData->markMapPositions[index].y;
}

BOOL sub_02056A10 (const PoketchData *poketchData)
{
    return poketchData->unk_00_2;
}

void sub_02056A18 (const PoketchData *poketchData, u8 *param1)
{
    if (poketchData->unk_00_2) {
        MI_CpuCopy8(poketchData->unk_2A, param1, 120);
    }
}

void sub_02056A2C (PoketchData *poketchData, const u8 *param1)
{
    MI_CpuCopy8(param1, poketchData->unk_2A, 120);
    poketchData->unk_00_2 = 1;
}

void sub_02056A48 (PoketchData *poketchData, const BoxPokemon * param1)
{
    int v0;

    v0 = sub_02056AAC(poketchData);

    if (v0 >= 12) {
        int v1;

        for (v1 = 0; v1 < (12 - 1); v1++) {
            poketchData->unk_B8[v1] = poketchData->unk_B8[v1 + 1];
        }

        v0 = 12 - 1;
    }

    poketchData->unk_B8[v0].unk_00 = BoxPokemon_GetValue((BoxPokemon *)param1, MON_DATA_SPECIES, NULL);
    poketchData->unk_B8[v0].unk_02 = BoxPokemon_IconFormOffset(param1);
    poketchData->unk_B8[v0].unk_04 = BoxPokemon_GetValue((BoxPokemon *)param1, MON_DATA_FORM, NULL);
}

int sub_02056AAC (const PoketchData *poketchData)
{
    int v0;

    for (v0 = 0; v0 < 12; v0++) {
        if (poketchData->unk_B8[v0].unk_00 == 0) {
            return v0;
        }
    }

    return v0;
}

void sub_02056AC8 (const PoketchData *poketchData, int param1, int *param2, int *param3)
{
    GF_ASSERT(param1 < 12);
    GF_ASSERT(poketchData->unk_B8[param1].unk_00);

    *param2 = poketchData->unk_B8[param1].unk_00;
    *param3 = poketchData->unk_B8[param1].unk_02;
}

u32 sub_02056AFC (const PoketchData *poketchData, int param1)
{
    GF_ASSERT(param1 < 12);
    GF_ASSERT(poketchData->unk_B8[param1].unk_00);

    return poketchData->unk_B8[param1].unk_04;
}

PoketchData* SaveData_PoketchData(SaveData *saveData)
{
    return SaveData_Get(saveData, SAVE_TABLE_ENTRY_POKETCH);
}
