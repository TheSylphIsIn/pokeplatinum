    .include "macros/scrcmd.inc"

    .data

    .long _0107-.-4
    .long _003A-.-4
    .long _004D-.-4
    .long _0060-.-4
    .long _0073-.-4
    .long _0086-.-4
    .long _0099-.-4
    .long _00AC-.-4
    .long _00BF-.-4
    .long _00D2-.-4
    .long _00E5-.-4
    .long _00F6-.-4
    .long _0109-.-4
    .long _0193-.-4
    .short 0xFD13

_003A:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_068
    ScrCmd_02C 0
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    ScrCmd_002

_004D:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_068
    ScrCmd_02C 1
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    ScrCmd_002

_0060:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_068
    ScrCmd_02C 2
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    ScrCmd_002

_0073:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_068
    ScrCmd_02C 3
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    ScrCmd_002

_0086:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_068
    ScrCmd_02C 4
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    ScrCmd_002

_0099:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_068
    ScrCmd_02C 5
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    ScrCmd_002

_00AC:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_068
    ScrCmd_02C 6
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    ScrCmd_002

_00BF:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_068
    ScrCmd_02C 7
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    ScrCmd_002

_00D2:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_068
    ScrCmd_02C 8
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    ScrCmd_002

_00E5:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_02C 9
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    ScrCmd_002

_00F6:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_02C 10
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    ScrCmd_002

_0107:
    ScrCmd_002

_0109:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_028 0x8005, 6
    ScrCmd_016 _011D
    ScrCmd_002

_011D:
    ScrCmd_02C 13
    ScrCmd_041 31, 11, 0, 1, 0x800C
    ScrCmd_33A 1
    ScrCmd_042 15, 0
    ScrCmd_042 16, 1
    ScrCmd_042 17, 2
    ScrCmd_043
    ScrCmd_029 0x8008, 0x800C
    ScrCmd_011 0x8008, 0
    ScrCmd_01C 1, _0167
    ScrCmd_011 0x8008, 1
    ScrCmd_01C 1, _0188
    ScrCmd_016 _0161
    ScrCmd_002

_0161:
    ScrCmd_034
    ScrCmd_061
    ScrCmd_002

_0167:
    ScrCmd_014 0x7D6
    ScrCmd_029 0x800C, 0x4000
    ScrCmd_011 0x800C, 0
    ScrCmd_01C 1, _0161
    ScrCmd_034
    ScrCmd_014 0x802
    ScrCmd_061
    ScrCmd_002

_0188:
    ScrCmd_02C 14
    ScrCmd_016 _011D
    ScrCmd_002

_0193:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_028 0x8005, 5
    ScrCmd_016 _01A7
    ScrCmd_002

_01A7:
    ScrCmd_02C 11
    ScrCmd_041 31, 11, 0, 1, 0x800C
    ScrCmd_33A 1
    ScrCmd_042 15, 0
    ScrCmd_042 16, 1
    ScrCmd_042 17, 2
    ScrCmd_043
    ScrCmd_029 0x8008, 0x800C
    ScrCmd_011 0x8008, 0
    ScrCmd_01C 1, _01F1
    ScrCmd_011 0x8008, 1
    ScrCmd_01C 1, _0212
    ScrCmd_016 _01EB
    ScrCmd_002

_01EB:
    ScrCmd_034
    ScrCmd_061
    ScrCmd_002

_01F1:
    ScrCmd_014 0x7D6
    ScrCmd_029 0x800C, 0x4000
    ScrCmd_011 0x800C, 0
    ScrCmd_01C 1, _01EB
    ScrCmd_034
    ScrCmd_014 0x802
    ScrCmd_061
    ScrCmd_002

_0212:
    ScrCmd_02C 12
    ScrCmd_016 _01A7

    .byte 2
    .byte 0
    .byte 0
    .byte 0
    .byte 0
