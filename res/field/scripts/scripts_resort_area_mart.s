#include "macros/scrcmd.inc"

    .data

    ScriptEntry _000A
    ScriptEntry _0020
    TableEnd

_000A:
    PlayFanfare SEQ_SE_CONFIRM
    LockAll
    FacePlayer
    CallCommonScript 0x7E3
    ScrCmd_035
    ScrCmd_147 1
    ReleaseAll
    End

_0020:
    End

    .byte 0
    .byte 0
