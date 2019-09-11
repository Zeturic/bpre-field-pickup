#pragma once

#define MON_DATA_PERSONALITY        0
#define MON_DATA_HELD_ITEM         12
#define MON_DATA_ABILITY_NUM       46
#define MON_DATA_LEVEL             56
#define MON_DATA_SPECIES2          65

struct PACKED Pokemon
{
    u8 unk0[100];
};

extern struct Pokemon gPlayerParty[];

u32 GetMonData(struct Pokemon *mon, s32 field);
void SetMonData(struct Pokemon *mon, s32 field, const void *dataArg);

// vanilla would only have two parameters,
// including it supports azurile13-style HAs
// without sacrificing compatibility with HA-less ROMs
u8 GetAbilityBySpecies(u16 species, u8 abilityNum, u32 personality);
