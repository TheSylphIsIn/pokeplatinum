#include "macros/scrcmd.inc"
#include "res/text/bank/route_222_gate_to_sunyshore_city.h"

    .data

    ScriptEntry _000A
    ScriptEntry _001D
    TableEnd

_000A:
    PlayFanfare SEQ_SE_CONFIRM
    LockAll
    FacePlayer
    Message 0
    WaitABXPadPress
    CloseMessage
    ReleaseAll
    End

_001D:
    PlayFanfare SEQ_SE_CONFIRM
    LockAll
    FacePlayer
    Message 1
    WaitABXPadPress
    CloseMessage
    ReleaseAll
    End
