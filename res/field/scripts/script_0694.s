    .include "macros/scrcmd.inc"

    .data

    .byte 1
    .long _0006-.-4
    .byte 0

_0006:
    .short 0x4001, 0, 2
    .short 0

    .balign 4, 0
