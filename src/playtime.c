#include <nitro.h>

#include "playtime.h"

#define PLAYTIME_MAX_HOURS 999
#define PLAYTIME_MAX_MINUTES 59
#define PLAYTIME_MAX_SECONDS 59

void PlayTime_Init(PlayTime *playTime)
{
    playTime->hours = 0;
    playTime->minutes = 0;
    playTime->seconds = 0;
}

void PlayTime_Increment(PlayTime *playTime, u32 seconds)
{
    if (playTime->hours == PLAYTIME_MAX_HOURS 
        && playTime->minutes == PLAYTIME_MAX_MINUTES 
        && playTime->seconds == PLAYTIME_MAX_SECONDS) {
        return;
    }

    u32 hours = playTime->hours;
    u32 minutes = playTime->minutes;
    u32 newSeconds = playTime->seconds + seconds;

    if (newSeconds > PLAYTIME_MAX_SECONDS) {
        minutes = playTime->minutes + newSeconds / (PLAYTIME_MAX_SECONDS + 1);
        newSeconds %= PLAYTIME_MAX_SECONDS + 1;

        if (minutes > PLAYTIME_MAX_MINUTES) {
            hours = playTime->hours + minutes / (PLAYTIME_MAX_MINUTES + 1);
            minutes %= PLAYTIME_MAX_MINUTES + 1;

            if (hours >= PLAYTIME_MAX_HOURS) {
                hours = PLAYTIME_MAX_HOURS;
                minutes = PLAYTIME_MAX_MINUTES;
                newSeconds = PLAYTIME_MAX_SECONDS;
            }
        }
    }

    playTime->hours = hours;
    playTime->minutes = minutes;
    playTime->seconds = newSeconds;
}

u16 PlayTime_GetHours(const PlayTime *playTime)
{
    return playTime->hours;
}

u8 PlayTime_GetMinutes(const PlayTime *playTime)
{
    return playTime->minutes;
}

u8 PlayTime_GetSeconds(const PlayTime *playTime)
{
    return playTime->seconds;
}
