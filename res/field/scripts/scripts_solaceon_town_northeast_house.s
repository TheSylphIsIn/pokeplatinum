#include "macros/scrcmd.inc"
#include "res/text/bank/solaceon_town_northeast_house.h"

    .data

    ScriptEntry _000A
    ScriptEntry _002C
    TableEnd

_000A:
    PlayFanfare SEQ_SE_CONFIRM
    LockAll
    FacePlayer
    ScrCmd_247 0x800C
    ScrCmd_212 0x8004, 0x800C
    ScrCmd_17C 0, 0x8004
    Message 0
    WaitABXPadPress
    CloseMessage
    ReleaseAll
    End

_002C:
    PlayFanfare SEQ_SE_CONFIRM
    LockAll
    FacePlayer
    Message 1
    WaitABXPadPress
    CloseMessage
    ReleaseAll
    End

    .byte 0
