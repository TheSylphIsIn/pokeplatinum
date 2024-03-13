    .include "macros/scrcmd.inc"

    .data

    .long _001A-.-4
    .long _002D-.-4
    .long _0044-.-4
    .long _005B-.-4
    .long _0070-.-4
    .long _0085-.-4
    .short 0xFD13

_001A:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_068
    ScrCmd_02C 2
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    ScrCmd_002

_002D:
    ScrCmd_036 3, 1, 0, 0x800C
    ScrCmd_038 3
    ScrCmd_039
    ScrCmd_03B 0x800C
    ScrCmd_014 0x7D0
    ScrCmd_002

_0044:
    ScrCmd_036 4, 1, 0, 0x800C
    ScrCmd_038 3
    ScrCmd_039
    ScrCmd_03B 0x800C
    ScrCmd_014 0x7D0
    ScrCmd_002

_005B:
    ScrCmd_037 3, 0
    ScrCmd_038 3
    ScrCmd_039
    ScrCmd_03A 5, 0x800C
    ScrCmd_014 0x7D0
    ScrCmd_002

_0070:
    ScrCmd_037 3, 0
    ScrCmd_038 3
    ScrCmd_039
    ScrCmd_03A 6, 0x800C
    ScrCmd_014 0x7D0
    ScrCmd_002

_0085:
    ScrCmd_060
    ScrCmd_05E 5, _0268
    ScrCmd_05F
    ScrCmd_014 0x7FA
    ScrCmd_069 0x8004, 0x8005
    ScrCmd_011 0x8005, 0x2F5
    ScrCmd_01C 1, _00D1
    ScrCmd_011 0x8005, 0x2F6
    ScrCmd_01C 1, _00E1
    ScrCmd_011 0x8005, 0x2F7
    ScrCmd_01C 1, _00F1
    ScrCmd_011 0x8005, 0x2F8
    ScrCmd_01C 1, _0101
    ScrCmd_002

_00D1:
    ScrCmd_05E 5, _0230
    ScrCmd_05F
    ScrCmd_016 _0111

_00E1:
    ScrCmd_05E 5, _0238
    ScrCmd_05F
    ScrCmd_016 _0111

_00F1:
    ScrCmd_05E 5, _0248
    ScrCmd_05F
    ScrCmd_016 _0111

_0101:
    ScrCmd_05E 5, _0258
    ScrCmd_05F
    ScrCmd_016 _0111

_0111:
    ScrCmd_0CE 0
    ScrCmd_0CD 1
    ScrCmd_02C 0
    ScrCmd_034
    ScrCmd_0DE 0x800C
    ScrCmd_011 0x800C, 0x183
    ScrCmd_01C 1, _014C
    ScrCmd_011 0x800C, 0x186
    ScrCmd_01C 1, _0158
    ScrCmd_016 _0140

_0140:
    ScrCmd_0E5 247, 0
    ScrCmd_016 _0164

_014C:
    ScrCmd_0E5 248, 0
    ScrCmd_016 _0164

_0158:
    ScrCmd_0E5 249, 0
    ScrCmd_016 _0164

_0164:
    ScrCmd_0EC 0x800C
    ScrCmd_011 0x800C, 0
    ScrCmd_01C 1, _0207
    ScrCmd_0CE 0
    ScrCmd_02C 1
    ScrCmd_034
    ScrCmd_069 0x8004, 0x8005
    ScrCmd_011 0x8005, 0x2F5
    ScrCmd_01C 1, _01B9
    ScrCmd_011 0x8005, 0x2F6
    ScrCmd_01C 1, _01C9
    ScrCmd_011 0x8005, 0x2F7
    ScrCmd_01C 1, _01D9
    ScrCmd_011 0x8005, 0x2F8
    ScrCmd_01C 1, _01E9
    ScrCmd_002

_01B9:
    ScrCmd_05E 5, _0210
    ScrCmd_05F
    ScrCmd_016 _01F9

_01C9:
    ScrCmd_05E 5, _0218
    ScrCmd_05F
    ScrCmd_016 _01F9

_01D9:
    ScrCmd_05E 5, _0220
    ScrCmd_05F
    ScrCmd_016 _01F9

_01E9:
    ScrCmd_05E 5, _0228
    ScrCmd_05F
    ScrCmd_016 _01F9

_01F9:
    ScrCmd_065 5
    ScrCmd_028 0x4088, 1
    ScrCmd_061
    ScrCmd_002

_0207:
    ScrCmd_0EB
    ScrCmd_061
    ScrCmd_002

    .balign 4, 0
_0210:
    .short 19, 10
    .short 0xFE, 0x00

    .balign 4, 0
_0218:
    .short 19, 10
    .short 0xFE, 0x00

    .balign 4, 0
_0220:
    .short 19, 10
    .short 0xFE, 0x00

    .balign 4, 0
_0228:
    .short 19, 10
    .short 0xFE, 0x00

    .balign 4, 0
_0230:
    .short 18, 4
    .short 0xFE, 0x00

    .balign 4, 0
_0238:
    .short 18, 2
    .short 17, 1
    .short 18, 2
    .short 0xFE, 0x00

    .balign 4, 0
_0248:
    .short 18, 2
    .short 17, 2
    .short 18, 2
    .short 0xFE, 0x00

    .balign 4, 0
_0258:
    .short 18, 2
    .short 17, 3
    .short 18, 2
    .short 0xFE, 0x00

    .balign 4, 0
_0268:
    .short 63, 1
    .short 75, 1
    .short 63, 1
    .short 0xFE, 0x00
