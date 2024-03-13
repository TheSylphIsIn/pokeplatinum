    .include "macros/scrcmd.inc"

    .data

    .long _0208-.-4
    .long _000A-.-4
    .short 0xFD13

_000A:
    ScrCmd_060
    ScrCmd_01A _006A
    ScrCmd_0CD 0
    ScrCmd_0CF 1
    ScrCmd_14D 0x800C
    ScrCmd_011 0x800C, 0
    ScrCmd_01C 1, _0031
    ScrCmd_016 _003C
    ScrCmd_002

_0031:
    ScrCmd_02C 2
    ScrCmd_016 _0047
    ScrCmd_002

_003C:
    ScrCmd_02C 3
    ScrCmd_016 _0047
    ScrCmd_002

_0047:
    ScrCmd_02C 4
    ScrCmd_034
    ScrCmd_22C
    ScrCmd_01A _00E8
    ScrCmd_049 0x603
    ScrCmd_01E 0x21C
    ScrCmd_065 1
    ScrCmd_028 0x4105, 1
    ScrCmd_061
    ScrCmd_002

_006A:
    ScrCmd_069 0x8005, 0x8006
    ScrCmd_011 0x8006, 5
    ScrCmd_01C 1, _00AC
    ScrCmd_011 0x8006, 6
    ScrCmd_01C 1, _00B8
    ScrCmd_011 0x8006, 7
    ScrCmd_01C 1, _00C4
    ScrCmd_011 0x8006, 8
    ScrCmd_01C 1, _00D0
    ScrCmd_016 _00DC
    ScrCmd_002

_00AC:
    ScrCmd_05E 1, _0168
    ScrCmd_05F
    ScrCmd_01B

_00B8:
    ScrCmd_05E 1, _017C
    ScrCmd_05F
    ScrCmd_01B

_00C4:
    ScrCmd_05E 1, _0190
    ScrCmd_05F
    ScrCmd_01B

_00D0:
    ScrCmd_05E 1, _019C
    ScrCmd_05F
    ScrCmd_01B

_00DC:
    ScrCmd_05E 1, _01B0
    ScrCmd_05F
    ScrCmd_01B

_00E8:
    ScrCmd_069 0x8005, 0x8006
    ScrCmd_011 0x8006, 5
    ScrCmd_01C 1, _012A
    ScrCmd_011 0x8006, 6
    ScrCmd_01C 1, _0136
    ScrCmd_011 0x8006, 7
    ScrCmd_01C 1, _0142
    ScrCmd_011 0x8006, 8
    ScrCmd_01C 1, _014E
    ScrCmd_016 _015A
    ScrCmd_002

_012A:
    ScrCmd_05E 1, _01C4
    ScrCmd_05F
    ScrCmd_01B

_0136:
    ScrCmd_05E 1, _01D0
    ScrCmd_05F
    ScrCmd_01B

_0142:
    ScrCmd_05E 1, _01DC
    ScrCmd_05F
    ScrCmd_01B

_014E:
    ScrCmd_05E 1, _01F0
    ScrCmd_05F
    ScrCmd_01B

_015A:
    ScrCmd_05E 1, _01FC
    ScrCmd_05F
    ScrCmd_01B

    .balign 4, 0
_0168:
    .short 75, 1
    .short 15, 1
    .short 12, 2
    .short 35, 1
    .short 0xFE, 0x00

    .balign 4, 0
_017C:
    .short 75, 1
    .short 15, 1
    .short 12, 1
    .short 35, 1
    .short 0xFE, 0x00

    .balign 4, 0
_0190:
    .short 75, 1
    .short 15, 1
    .short 0xFE, 0x00

    .balign 4, 0
_019C:
    .short 75, 1
    .short 15, 1
    .short 13, 1
    .short 35, 1
    .short 0xFE, 0x00

    .balign 4, 0
_01B0:
    .short 75, 1
    .short 15, 1
    .short 13, 2
    .short 35, 1
    .short 0xFE, 0x00

    .balign 4, 0
_01C4:
    .short 13, 2
    .short 15, 4
    .short 0xFE, 0x00

    .balign 4, 0
_01D0:
    .short 13, 1
    .short 15, 4
    .short 0xFE, 0x00

    .balign 4, 0
_01DC:
    .short 12, 1
    .short 15, 3
    .short 13, 1
    .short 15, 1
    .short 0xFE, 0x00

    .balign 4, 0
_01F0:
    .short 12, 1
    .short 15, 4
    .short 0xFE, 0x00

    .balign 4, 0
_01FC:
    .short 12, 2
    .short 15, 4
    .short 0xFE, 0x00

_0208:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_068
    ScrCmd_02C 0
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    ScrCmd_002

    .byte 0
