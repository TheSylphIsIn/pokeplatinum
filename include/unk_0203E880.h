#ifndef POKEPLATINUM_UNK_0203E880_H
#define POKEPLATINUM_UNK_0203E880_H

#include "field/field_system_decl.h"
#include "field_script_context.h"
#include "struct_defs/struct_0203F478.h"
#include "struct_decls/struct_020508D4_decl.h"
#include "struct_decls/struct_02061AB4_decl.h"
#include "overlay005/struct_ov5_021DC1A4_decl.h"
#include "struct_defs/struct_0205AA50.h"
#include "struct_decls/struct_02001AF4_decl.h"
#include "string_template.h"
#include "overlay101/struct_ov101_021D5D90_decl.h"
#include "overlay005/struct_ov5_021E1FF4_decl.h"
#include "sys_task_manager.h"

enum ScriptManagerMember {
    SCRIPT_MANAGER_WINDOW = 1,
    SCRIPT_MANAGER_UI_CONTROL,
    SCRIPT_MANAGER_MESSAGE_ID,
    SCRIPT_MANAGER_MOVEMENT_COUNT,
    SCRIPT_MANAGER_IS_COMMON_SCRIPT,
    SCRIPT_MANAGER_IS_MSG_BOX_OPEN,
    SCRIPT_MANAGER_CONTEXT_COUNT,
    SCRIPT_MANAGER_SCRIPT_ID,
    SCRIPT_MANAGER_PLAYER_DIR,
    SCRIPT_MANAGER_TARGET_OBJECT,
    SCRIPT_MANAGER_CAMERA_OBJECT,
    SCRIPT_MANAGER_SAVE_TYPE,
    SCRIPT_MANAGER_CONTEXT_0,
    SCRIPT_MANAGER_CONTEXT_1,
    SCRIPT_MANAGER_STR_TEMPLATE,
    SCRIPT_MANAGER_MESSAGE_BUF,
    SCRIPT_MANAGER_TEMPORARY_BUF,
    SCRIPT_MANAGER_SAVING_ICON,

    SCRIPT_MANAGER_DATA_PTR = 20,

    SCRIPT_MANAGER_PLAYER_TASK = 22,
    SCRIPT_MANAGER_PLAYER_WON_BATTLE,
    SCRIPT_MANAGER_TRAINER_0_SIGHT_RANGE,
    SCRIPT_MANAGER_TRAINER_0_DIRECTION,
    SCRIPT_MANAGER_TRAINER_0_SCRIPT_ID,
    SCRIPT_MANAGER_TRAINER_0_ID,
    SCRIPT_MANAGER_TRAINER_0_TYPE,
    SCRIPT_MANAGER_TRAINER_0_MAP_OBJECT,
    SCRIPT_MANAGER_TRAINER_0_TASK,
    SCRIPT_MANAGER_TRAINER_1_SIGHT_RANGE,
    SCRIPT_MANAGER_TRAINER_1_DIRECTION,
    SCRIPT_MANAGER_TRAINER_1_SCRIPT_ID,
    SCRIPT_MANAGER_TRAINER_1_ID,
    SCRIPT_MANAGER_TRAINER_1_TYPE,
    SCRIPT_MANAGER_TRAINER_1_MAP_OBJECT,
    SCRIPT_MANAGER_TRAINER_1_TASK,
    SCRIPT_MANAGER_COIN_WINDOW,
    SCRIPT_MANAGER_MONEY_WINDOW,

    SCRIPT_DATA_START = 41,
    // Parameter 0 is used for storing the mon's party slot when you use a field move, as well as the item ID for hidden items.
    // Parameters 1 and 2 are used for storing hidden item quantities and flags respectively.
    // Parameter 3 is unused.
    SCRIPT_DATA_PARAMETER_0 = SCRIPT_DATA_START,
    SCRIPT_DATA_PARAMETER_1,
    SCRIPT_DATA_PARAMETER_2,
    SCRIPT_DATA_PARAMETER_3,
    // The BG3 data below are a set of parameters for the unused script command ScrollBG3.
    SCRIPT_DATA_BG3_SCROLL_COUNT_X,
    SCRIPT_DATA_BG3_SCROLL_COUNT_Y,
    SCRIPT_DATA_DUMMY_0,
    SCRIPT_DATA_DUMMY_1,
    SCRIPT_DATA_BG3_SCROLL_DIST_X,
    SCRIPT_DATA_BG3_SCROLL_DIR_X,
    SCRIPT_DATA_BG3_SCROLL_DIST_Y,
    SCRIPT_DATA_BG3_SCROLL_DIR_Y,
    SCRIPT_DATA_DUMMY_2,
    SCRIPT_DATA_TARGET_OBJECT_ID,

    SCRIPT_DATA_MAX
};

#define SCRIPT_ID_OFFSET_SINGLE_BATTLES 3000
#define SCRIPT_ID_OFFSET_DOUBLE_BATTLES 5000
#define SCRIPT_ID_OFFSET_HIDDEN_ITEMS   8000
#define SCRIPT_ID_OFFSET_SAFARI_ZONE    8800

#define FLAG_OFFSET_HIDDEN_ITEMS        730
#define FLAG_OFFSET_TRAINER_DEFEATED    1360

#define SCRIPT_MANAGER_MAGIC_NUMBER     0x3643F

typedef void (* FieldSysFunc)(FieldSystem *);

typedef struct ApproachingTrainer {
    int sightRange;
    int direction;
    int scriptID;
    int trainerID;
    int trainerType;
    MapObject * object;
    SysTask * task;
} ApproachingTrainer;

typedef struct ScriptManager {
    u32 magic;
    u8 state;
    u8 messageID;
    u8 movementCount;
    u8 isCommonScript;
    u8 isMsgBoxOpen;
    u8 ctxCount;
    u16 scriptID;
    BOOL playerWonBattle;
    UnkStruct_ov5_021DC1A4 * unk_10; // appears to be used for multichoice windows
    Window window;
    UIControlData * ctrlUI;
    int playerDir;
    MapObject * targetObject;
    MapObject * cameraObject;
    u16 * saveType; // the result of the check to determine what type of save is required in ScrCmd_CheckSaveType
    ScriptContext * ctx[2];
    StringTemplate * strTemplate;
    Strbuf * msgBuf;
    Strbuf * tmpBuf;
    void * savingIcon;
    ApproachingTrainer trainer[2]; // the player can be spotted by 2 trainers at once for a double battle
    u16 data[SCRIPT_DATA_MAX - SCRIPT_DATA_START];
    FieldSysFunc function;
    void * unk_A8;
    void * dataPtr; // used as a generic pointer to data in many different script commands
    UnkStruct_ov101_021D5D90 * unk_B0;
    SysTask * playerTask; // used to set player sprite animations while saving
    Window coinWindow;
    Window moneyWindow;
    UnkStruct_ov5_021E1FF4 * unk_D8;
} ScriptManager;

void ScriptManager_Set(FieldSystem * fieldSystem, u16 scriptID, MapObject * object);
void ScriptManager_SetApproachingTrainer(FieldSystem * fieldSystem, MapObject * object, int sightRange, int direction, int scriptID, int trainerID, int trainerType, int approachNum);
void ScriptManager_Start(TaskManager * taskManager, u16 scriptID, MapObject * object, void * saveType);
void ScriptManager_Change(TaskManager * taskManager, u16 scriptID, MapObject * object);
ScriptContext * ScriptContext_New(FieldSystem * fieldSystem, u16 scriptID);
void * ScriptManager_GetMemberPtr(ScriptManager * scriptManager, u32 member);
void * FieldSystem_GetScriptMember(FieldSystem * fieldSystem, u32 member);
void sub_0203F0C0(FieldSystem * fieldSystem);
u16 * FieldSystem_GetVarPointer(FieldSystem * fieldSystem, u16 varID);
u16 FieldSystem_TryGetVarPointer(FieldSystem * fieldSystem, u16 varID);
u16 sub_0203F164(FieldSystem * fieldSystem, u16 param1);
BOOL FieldSystem_CheckFlag(FieldSystem * fieldSystem, u16 flagID);
void FieldSystem_SetFlag(FieldSystem * fieldSystem, u16 flagID);
void FieldSystem_ClearFlag(FieldSystem * fieldSystem, u16 flagID);
void FieldSystem_ClearLocalFlags(FieldSystem * fieldSystem);
void sub_0203F1FC(FieldSystem * fieldSystem);
void FieldSystem_SetScriptParameters(FieldSystem * fieldSystem, u16 param1, u16 param2, u16 param3, u16 param4);
u16 Script_GetTrainerID(u16 eventID);
BOOL Script_GetDoubleBattleTrainerIndex(u16 scriptID);
BOOL Script_IsTrainerDoubleBattle(u16 trainerID);
BOOL Script_IsTrainerDefeated(FieldSystem * fieldSystem, u16 trainerID);
void Script_SetTrainerDefeated(FieldSystem * fieldSystem, u16 trainerID);
void Script_ClearTrainerDefeated(FieldSystem * fieldSystem, u16 trainerID);
u16 Script_GetHiddenItemFlag(u16 scriptID);
u16 Script_GetHiddenItemScript(u16 scriptID);
void FieldSystem_ClearDailyHiddenItemFlags(FieldSystem * fieldSystem);
u8 Script_GetHiddenItemRange(u16 scriptID);
UnkStruct_0203F478 * sub_0203F478(FieldSystem * fieldSystem, int param1);
void FieldSystem_InitNewGameState(FieldSystem * fieldSystem);
void FieldSystem_RunScript(FieldSystem * fieldSystem, u16 scriptID);
BOOL sub_0203F5C0(FieldSystem * fieldSystem, u8 param1);

#endif // POKEPLATINUM_UNK_0203E880_H
