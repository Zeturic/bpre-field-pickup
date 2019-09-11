#include "global.h"
#include "battle.h"
#include "battle_script_commands.h"
#include "pokemon.h"
#include "random.h"
#include "constants/abilities.h"
#include "constants/items.h"

void atkE5_pickup(void)
{
    for (u32 i = 0; i < PARTY_SIZE; ++i)
    {
        u32 personality = GetMonData(&gPlayerParty[i], MON_DATA_PERSONALITY);
        u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2);
        u16 heldItem = GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM);
        u8 abilityNum = GetMonData(&gPlayerParty[i], MON_DATA_ABILITY_NUM);

        u8 ability = GetAbilityBySpecies(species, abilityNum, personality);

        if (ability != ABILITY_PICKUP || heldItem != ITEM_NONE || Random100() >= PICKUP_ACTIVATION_CHANCE)
            continue;

        heldItem = PickupItemFromRowNum((GetMonData(&gPlayerParty[i], MON_DATA_LEVEL) - 1) / 10);

        SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &heldItem);
    }

    ++gBattlescriptCurrInstr;
}
