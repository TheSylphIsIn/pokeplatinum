    .include "macros/scrcmd.inc"

    .data

    .long _0032-.-4
    .long _0075-.-4
    .long _0081-.-4
    .long _0012-.-4
    .short 0xFD13

_0012:
    ScrCmd_32B 0x4004
    ScrCmd_011 0x4004, 0
    ScrCmd_01C 1, _0061
    ScrCmd_011 0x4004, 1
    ScrCmd_01C 1, _006B
    ScrCmd_002

_0032:
    ScrCmd_25B
    ScrCmd_011 0x4069, 0x122
    ScrCmd_01D 5, _0079
    ScrCmd_32B 0x4004
    ScrCmd_011 0x4004, 0
    ScrCmd_01C 1, _0061
    ScrCmd_011 0x4004, 1
    ScrCmd_01C 1, _006B
    ScrCmd_002

_0061:
    ScrCmd_18A 3, 17, 1
    ScrCmd_002

_006B:
    ScrCmd_18A 2, 17, 1
    ScrCmd_002

_0075:
    ScrCmd_25C
    ScrCmd_002

_0079:
    ScrCmd_028 0x4069, 0
    ScrCmd_01B

_0081:
    ScrCmd_002

    .byte 0
