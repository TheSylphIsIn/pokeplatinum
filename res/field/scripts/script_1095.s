    .include "macros/scrcmd.inc"

    .data

    .long _000E-.-4
    .long _0538-.-4
    .long _0585-.-4
    .short 0xFD13

_000E:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_020 214
    ScrCmd_01C 1, _0596
    ScrCmd_016 _0027
    ScrCmd_002

_0027:
    ScrCmd_020 167
    ScrCmd_01C 0, _0040
    ScrCmd_0CD 0
    ScrCmd_02C 15
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    ScrCmd_002

_0040:
    ScrCmd_0CD 0
    ScrCmd_02C 0
    ScrCmd_034
    ScrCmd_01E 167
    ScrCmd_01F 0x229
    ScrCmd_186 0, 4, 11
    ScrCmd_189 0, 0
    ScrCmd_188 0, 14
    ScrCmd_064 0
    ScrCmd_069 0x8004, 0x8005
    ScrCmd_011 0x8004, 9
    ScrCmd_01D 1, _0110
    ScrCmd_011 0x8004, 10
    ScrCmd_01D 1, _0126
    ScrCmd_02C 1
    ScrCmd_02C 2
    ScrCmd_034
    ScrCmd_05E 0, _04B8
    ScrCmd_05E 0xFF, _0424
    ScrCmd_05F
    ScrCmd_02C 3
    ScrCmd_034
    ScrCmd_01E 0x1AC
    ScrCmd_01F 0x29B
    ScrCmd_186 1, 4, 11
    ScrCmd_189 1, 0
    ScrCmd_188 1, 14
    ScrCmd_064 1
    ScrCmd_069 0x8004, 0x8005
    ScrCmd_011 0x8004, 9
    ScrCmd_01D 1, _0285
    ScrCmd_011 0x8004, 10
    ScrCmd_01D 1, _0291
    ScrCmd_02C 4
    ScrCmd_02C 5
    ScrCmd_02C 6
    ScrCmd_03E 0x800C
    ScrCmd_011 0x800C, 0
    ScrCmd_01C 1, _019D
    ScrCmd_011 0x800C, 1
    ScrCmd_01C 1, _013C
    ScrCmd_002

_0110:
    ScrCmd_05E 0, _0488
    ScrCmd_05F
    ScrCmd_05E 0xFF, _03E4
    ScrCmd_05F
    ScrCmd_01B

_0126:
    ScrCmd_05E 0, _04A0
    ScrCmd_05F
    ScrCmd_05E 0xFF, _03EC
    ScrCmd_05F
    ScrCmd_01B

_013C:
    ScrCmd_02C 10
    ScrCmd_034
    ScrCmd_069 0x8004, 0x8005
    ScrCmd_011 0x8004, 9
    ScrCmd_01D 1, _0165
    ScrCmd_011 0x8004, 10
    ScrCmd_01D 1, _0181
    ScrCmd_061
    ScrCmd_002

_0165:
    ScrCmd_05E 0, _04C0
    ScrCmd_05E 0xFF, _03F4
    ScrCmd_05E 1, _03CC
    ScrCmd_05F
    ScrCmd_01B

_0181:
    ScrCmd_05E 0, _04CC
    ScrCmd_05E 0xFF, _040C
    ScrCmd_05E 1, _03D8
    ScrCmd_05F
    ScrCmd_01B

_019D:
    ScrCmd_02C 8
    ScrCmd_034
    ScrCmd_0E5 0x391, 0
    ScrCmd_0EC 0x800C
    ScrCmd_011 0x800C, 0
    ScrCmd_01C 1, _0393
    ScrCmd_01A _01C3
    ScrCmd_061
    ScrCmd_002

_01C3:
    ScrCmd_01F 0x1BD
    ScrCmd_028 0x4074, 1
    ScrCmd_02C 11
    ScrCmd_034
    ScrCmd_003 15, 0x800C
    ScrCmd_0BC 6, 1, 0, 0
    ScrCmd_0BD
    ScrCmd_065 1
    ScrCmd_0BC 6, 1, 1, 0
    ScrCmd_0BD
    ScrCmd_069 0x8004, 0x8005
    ScrCmd_011 0x8004, 8
    ScrCmd_01D 1, _029D
    ScrCmd_011 0x8004, 9
    ScrCmd_01D 1, _02B1
    ScrCmd_011 0x8004, 10
    ScrCmd_01D 1, _02FA
    ScrCmd_011 0x8004, 11
    ScrCmd_01D 1, _0343
    ScrCmd_02C 13
    ScrCmd_028 0x8004, 0x1A6
    ScrCmd_028 0x8005, 1
    ScrCmd_014 0x7FC
    ScrCmd_01E 0x1AC
    ScrCmd_01F 0x1C3
    ScrCmd_01E 0x98D
    ScrCmd_02C 14
    ScrCmd_034
    ScrCmd_069 0x8004, 0x8005
    ScrCmd_011 0x8004, 9
    ScrCmd_01D 1, _0357
    ScrCmd_011 0x8004, 10
    ScrCmd_01D 1, _036B
    ScrCmd_011 0x8004, 11
    ScrCmd_01D 1, _037F
    ScrCmd_065 0
    ScrCmd_01B

_0285:
    ScrCmd_05E 1, _039C
    ScrCmd_05F
    ScrCmd_01B

_0291:
    ScrCmd_05E 1, _03B4
    ScrCmd_05F
    ScrCmd_01B

_029D:
    ScrCmd_05E 0xFF, _042C
    ScrCmd_05E 0, _04D8
    ScrCmd_05F
    ScrCmd_01B

_02B1:
    ScrCmd_011 0x8005, 4
    ScrCmd_01C 1, _02D2
    ScrCmd_05E 0xFF, _0434
    ScrCmd_05E 0, _04D8
    ScrCmd_05F
    ScrCmd_01B

_02D2:
    ScrCmd_05E 0xFF, _043C
    ScrCmd_05E 0, _04D8
    ScrCmd_05F
    ScrCmd_01B

    .byte 94
    .byte 0
    .byte 0xFF
    .byte 0
    .byte 90
    .byte 1
    .byte 0
    .byte 0
    .byte 94
    .byte 0
    .byte 0
    .byte 0
    .byte 226
    .byte 1
    .byte 0
    .byte 0
    .byte 95
    .byte 0
    .byte 27
    .byte 0

_02FA:
    ScrCmd_011 0x8005, 4
    ScrCmd_01C 1, _031B
    ScrCmd_05E 0xFF, _0454
    ScrCmd_05E 0, _04E0
    ScrCmd_05F
    ScrCmd_01B

_031B:
    ScrCmd_05E 0xFF, _045C
    ScrCmd_05E 0, _04E0
    ScrCmd_05F
    ScrCmd_01B

    .byte 94
    .byte 0
    .byte 0xFF
    .byte 0
    .byte 49
    .byte 1
    .byte 0
    .byte 0
    .byte 94
    .byte 0
    .byte 0
    .byte 0
    .byte 153
    .byte 1
    .byte 0
    .byte 0
    .byte 95
    .byte 0
    .byte 27
    .byte 0

_0343:
    ScrCmd_05E 0xFF, _0474
    ScrCmd_05E 0, _04E8
    ScrCmd_05F
    ScrCmd_01B

_0357:
    ScrCmd_05E 0xFF, _047C
    ScrCmd_05E 0, _04F0
    ScrCmd_05F
    ScrCmd_01B

_036B:
    ScrCmd_05E 0xFF, _047C
    ScrCmd_05E 0, _0508
    ScrCmd_05F
    ScrCmd_01B

_037F:
    ScrCmd_05E 0xFF, _047C
    ScrCmd_05E 0, _0520
    ScrCmd_05F
    ScrCmd_01B

_0393:
    ScrCmd_0EB
    ScrCmd_061
    ScrCmd_002

    .balign 4, 0
_039C:
    .short 12, 6
    .short 15, 1
    .short 12, 1
    .short 15, 5
    .short 32, 1
    .short 0xFE, 0x00

    .balign 4, 0
_03B4:
    .short 12, 6
    .short 15, 1
    .short 12, 1
    .short 15, 4
    .short 32, 1
    .short 0xFE, 0x00

    .balign 4, 0
_03CC:
    .short 14, 1
    .short 12, 1
    .short 0xFE, 0x00

    .balign 4, 0
_03D8:
    .short 15, 1
    .short 12, 1
    .short 0xFE, 0x00

    .balign 4, 0
_03E4:
    .short 35, 1
    .short 0xFE, 0x00

    .balign 4, 0
_03EC:
    .short 34, 1
    .short 0xFE, 0x00

    .balign 4, 0
_03F4:
    .short 63, 1
    .short 3, 1
    .short 71, 1
    .short 18, 1
    .short 72, 1
    .short 0xFE, 0x00

    .balign 4, 0
_040C:
    .short 63, 1
    .short 2, 1
    .short 71, 1
    .short 19, 1
    .short 72, 1
    .short 0xFE, 0x00

    .balign 4, 0
_0424:
    .short 33, 1
    .short 0xFE, 0x00

    .balign 4, 0
_042C:
    .short 15, 1
    .short 0xFE, 0x00

    .balign 4, 0
_0434:
    .short 35, 1
    .short 0xFE, 0x00

    .balign 4, 0
_043C:
    .short 12, 1
    .short 35, 1
    .short 0xFE, 0x00

    .byte 12
    .byte 0
    .byte 2
    .byte 0
    .byte 35
    .byte 0
    .byte 1
    .byte 0
    .byte 254
    .byte 0
    .byte 0
    .byte 0

    .balign 4, 0
_0454:
    .short 34, 1
    .short 0xFE, 0x00

    .balign 4, 0
_045C:
    .short 12, 1
    .short 34, 1
    .short 0xFE, 0x00

    .byte 12
    .byte 0
    .byte 2
    .byte 0
    .byte 34
    .byte 0
    .byte 1
    .byte 0
    .byte 254
    .byte 0
    .byte 0
    .byte 0

    .balign 4, 0
_0474:
    .short 14, 1
    .short 0xFE, 0x00

    .balign 4, 0
_047C:
    .short 63, 1
    .short 33, 1
    .short 0xFE, 0x00

    .balign 4, 0
_0488:
    .short 12, 6
    .short 15, 1
    .short 12, 1
    .short 15, 5
    .short 12, 1
    .short 0xFE, 0x00

    .balign 4, 0
_04A0:
    .short 12, 6
    .short 15, 1
    .short 12, 1
    .short 15, 4
    .short 12, 1
    .short 0xFE, 0x00

    .balign 4, 0
_04B8:
    .short 33, 1
    .short 0xFE, 0x00

    .balign 4, 0
_04C0:
    .short 63, 1
    .short 34, 1
    .short 0xFE, 0x00

    .balign 4, 0
_04CC:
    .short 63, 1
    .short 35, 1
    .short 0xFE, 0x00

    .balign 4, 0
_04D8:
    .short 34, 1
    .short 0xFE, 0x00

    .balign 4, 0
_04E0:
    .short 35, 1
    .short 0xFE, 0x00

    .balign 4, 0
_04E8:
    .short 35, 1
    .short 0xFE, 0x00

    .balign 4, 0
_04F0:
    .short 13, 1
    .short 14, 5
    .short 13, 1
    .short 14, 1
    .short 13, 6
    .short 0xFE, 0x00

    .balign 4, 0
_0508:
    .short 13, 1
    .short 14, 4
    .short 13, 1
    .short 14, 1
    .short 13, 6
    .short 0xFE, 0x00

    .balign 4, 0
_0520:
    .short 13, 1
    .short 14, 5
    .short 13, 1
    .short 14, 1
    .short 13, 6
    .short 0xFE, 0x00

_0538:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_068
    ScrCmd_02C 7
    ScrCmd_03E 0x800C
    ScrCmd_011 0x800C, 1
    ScrCmd_01C 1, _057A
    ScrCmd_02C 8
    ScrCmd_034
    ScrCmd_0E5 0x391, 0
    ScrCmd_0EC 0x800C
    ScrCmd_011 0x800C, 0
    ScrCmd_01C 1, _0393
    ScrCmd_01A _01C3
    ScrCmd_061
    ScrCmd_002

_057A:
    ScrCmd_02C 9
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    ScrCmd_002

_0585:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_02C 12
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    ScrCmd_002

_0596:
    ScrCmd_020 0x124
    ScrCmd_01C 1, _0027
    ScrCmd_01E 0x124
    ScrCmd_01F 0x1A6
    ScrCmd_186 2, 4, 11
    ScrCmd_064 2
    ScrCmd_069 0x8004, 0x8005
    ScrCmd_011 0x8004, 9
    ScrCmd_01D 1, _06CF
    ScrCmd_011 0x8004, 10
    ScrCmd_01D 1, _06E5
    ScrCmd_02C 16
    ScrCmd_069 0x8004, 0x8005
    ScrCmd_011 0x8004, 9
    ScrCmd_01D 1, _0713
    ScrCmd_011 0x8004, 10
    ScrCmd_01D 1, _071F
    ScrCmd_02C 17
    ScrCmd_03E 0x800C
    ScrCmd_011 0x800C, 1
    ScrCmd_01C 1, _0753
    ScrCmd_034
    ScrCmd_05E 2, _07F0
    ScrCmd_05E 0xFF, _0858
    ScrCmd_05F
    ScrCmd_003 15, 0x800C
    ScrCmd_02C 18
    ScrCmd_069 0x8004, 0x8005
    ScrCmd_011 0x8004, 9
    ScrCmd_01D 1, _0713
    ScrCmd_011 0x8004, 10
    ScrCmd_01D 1, _071F
    ScrCmd_011 0x8004, 9
    ScrCmd_01D 1, _06FB
    ScrCmd_011 0x8004, 10
    ScrCmd_01D 1, _0707
    ScrCmd_03E 0x800C
    ScrCmd_011 0x800C, 1
    ScrCmd_01C 1, _0753
    ScrCmd_02C 19
    ScrCmd_034
    ScrCmd_05E 0xFF, _0864
    ScrCmd_05E 2, _07F8
    ScrCmd_05F
    ScrCmd_02C 20
    ScrCmd_034
    ScrCmd_069 0x8004, 0x8005
    ScrCmd_011 0x8004, 9
    ScrCmd_01D 1, _072B
    ScrCmd_011 0x8004, 10
    ScrCmd_01D 1, _073F
    ScrCmd_02C 21
    ScrCmd_03E 0x800C
    ScrCmd_011 0x800C, 1
    ScrCmd_01C 1, _0753
    ScrCmd_02C 22
    ScrCmd_016 _075E
    ScrCmd_002

_06CF:
    ScrCmd_05E 2, _07B0
    ScrCmd_05F
    ScrCmd_05E 0xFF, _0848
    ScrCmd_05F
    ScrCmd_01B

_06E5:
    ScrCmd_05E 2, _07C8
    ScrCmd_05F
    ScrCmd_05E 0xFF, _0850
    ScrCmd_05F
    ScrCmd_01B

_06FB:
    ScrCmd_05E 0xFF, _0848
    ScrCmd_05F
    ScrCmd_01B

_0707:
    ScrCmd_05E 0xFF, _0850
    ScrCmd_05F
    ScrCmd_01B

_0713:
    ScrCmd_05E 2, _07E0
    ScrCmd_05F
    ScrCmd_01B

_071F:
    ScrCmd_05E 2, _07E8
    ScrCmd_05F
    ScrCmd_01B

_072B:
    ScrCmd_05E 2, _0800
    ScrCmd_05E 0xFF, _0870
    ScrCmd_05F
    ScrCmd_01B

_073F:
    ScrCmd_05E 2, _080C
    ScrCmd_05E 0xFF, _087C
    ScrCmd_05F
    ScrCmd_01B

_0753:
    ScrCmd_02C 23
    ScrCmd_016 _075E
    ScrCmd_002

_075E:
    ScrCmd_034
    ScrCmd_069 0x8004, 0x8005
    ScrCmd_011 0x8004, 9
    ScrCmd_01D 1, _0788
    ScrCmd_011 0x8004, 10
    ScrCmd_01D 1, _079C
    ScrCmd_065 2
    ScrCmd_061
    ScrCmd_002

_0788:
    ScrCmd_05E 2, _0818
    ScrCmd_05E 0xFF, _0888
    ScrCmd_05F
    ScrCmd_01B

_079C:
    ScrCmd_05E 2, _0830
    ScrCmd_05E 0xFF, _0888
    ScrCmd_05F
    ScrCmd_01B

    .balign 4, 0
_07B0:
    .short 12, 6
    .short 15, 1
    .short 12, 1
    .short 15, 5
    .short 12, 1
    .short 0xFE, 0x00

    .balign 4, 0
_07C8:
    .short 12, 6
    .short 15, 1
    .short 12, 1
    .short 15, 4
    .short 12, 1
    .short 0xFE, 0x00

    .balign 4, 0
_07E0:
    .short 34, 1
    .short 0xFE, 0x00

    .balign 4, 0
_07E8:
    .short 35, 1
    .short 0xFE, 0x00

    .balign 4, 0
_07F0:
    .short 32, 1
    .short 0xFE, 0x00

    .balign 4, 0
_07F8:
    .short 13, 1
    .short 0xFE, 0x00

    .balign 4, 0
_0800:
    .short 12, 1
    .short 34, 1
    .short 0xFE, 0x00

    .balign 4, 0
_080C:
    .short 12, 1
    .short 35, 1
    .short 0xFE, 0x00

    .balign 4, 0
_0818:
    .short 13, 1
    .short 14, 5
    .short 13, 1
    .short 14, 1
    .short 13, 6
    .short 0xFE, 0x00

    .balign 4, 0
_0830:
    .short 13, 1
    .short 14, 4
    .short 13, 1
    .short 14, 1
    .short 13, 6
    .short 0xFE, 0x00

    .balign 4, 0
_0848:
    .short 35, 1
    .short 0xFE, 0x00

    .balign 4, 0
_0850:
    .short 34, 1
    .short 0xFE, 0x00

    .balign 4, 0
_0858:
    .short 63, 1
    .short 32, 1
    .short 0xFE, 0x00

    .balign 4, 0
_0864:
    .short 63, 1
    .short 33, 1
    .short 0xFE, 0x00

    .balign 4, 0
_0870:
    .short 63, 1
    .short 35, 1
    .short 0xFE, 0x00

    .balign 4, 0
_087C:
    .short 63, 1
    .short 34, 1
    .short 0xFE, 0x00

    .balign 4, 0
_0888:
    .short 63, 2
    .short 2, 1
    .short 0xFE, 0x00
