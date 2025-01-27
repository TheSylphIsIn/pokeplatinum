#include "overlay006/ov6_02243218.h"

#include <nitro.h>
#include <string.h>

#include "overlay006/wild_encounters.h"

#include "map_header_data.h"
#include "consts/map.h"

static const u32 Swarm_MapIdTable[NUM_SWARMS] = {
    MAP_HEADER_ROUTE_201,
    MAP_HEADER_ROUTE_202,
    MAP_HEADER_ROUTE_203,
    MAP_HEADER_ROUTE_206,
    MAP_HEADER_ROUTE_207,
    MAP_HEADER_ROUTE_208,
    MAP_HEADER_ROUTE_209,
    MAP_HEADER_ROUTE_214,
    MAP_HEADER_ROUTE_215,
    MAP_HEADER_ROUTE_217,
    MAP_HEADER_ROUTE_218,
    MAP_HEADER_ROUTE_221,
    MAP_HEADER_ROUTE_222,
    MAP_HEADER_ROUTE_224,
    MAP_HEADER_ROUTE_225,
    MAP_HEADER_ROUTE_226,
    MAP_HEADER_ROUTE_227,
    MAP_HEADER_ROUTE_228,
    MAP_HEADER_ROUTE_229,
    MAP_HEADER_ROUTE_230,
    MAP_HEADER_VALLEY_WINDWORKS_OUTSIDE,
    MAP_HEADER_ETERNA_FOREST
};

u32 Swarm_GetMapId(const u32 swarm)
{
    return Swarm_MapIdTable[swarm % NUM_SWARMS];
}

void Swarm_GetMapIdAndSpecies(const u32 swarm, u16 *mapIdDest, u16 *speciesDest)
{
    WildEncounters encounterData;
    u32 mapId;

    mapId = Swarm_MapIdTable[(swarm % NUM_SWARMS)];
    MapHeaderData_LoadWildEncounters(&encounterData, mapId);

    (*speciesDest) = encounterData.swarmEncounters[0];
    (*mapIdDest) = mapId;
}
