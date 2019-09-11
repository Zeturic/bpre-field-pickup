#include "global.h"
#include "battle_script_commands.h"
#include "random.h"
#include "constants/items.h"

const u16 sPickupItems[NUM_PICKUP_ITEMS] =
{
    ITEM_POTION,
    ITEM_ANTIDOTE,
    ITEM_SUPER_POTION,
    ITEM_GREAT_BALL,
    ITEM_REPEL,
    ITEM_ESCAPE_ROPE,
    ITEM_X_ATTACK,
    ITEM_FULL_HEAL,
    ITEM_ULTRA_BALL,
    ITEM_HYPER_POTION,
    ITEM_RARE_CANDY,
    ITEM_PROTEIN,
    ITEM_REVIVE,
    ITEM_HP_UP,
    ITEM_FULL_RESTORE,
    ITEM_MAX_REVIVE,
    ITEM_PP_UP,
    ITEM_MAX_ELIXIR
};

const u16 sRarePickupItems[NUM_PICKUP_RARE_ITEMS] =
{
    ITEM_HYPER_POTION,
    ITEM_NUGGET,
    ITEM_KINGS_ROCK,
    ITEM_FULL_RESTORE,
    ITEM_ETHER,
    ITEM_WHITE_HERB,
    ITEM_TM44,
    ITEM_ELIXIR,
    ITEM_TM01,
    ITEM_LEFTOVERS,
    ITEM_TM26
};

// -----------------------------------------------------------------------------

u16 PickupItemFromRowNum(u8 rowNum)
{
    u8 rand = Random100();

    for (u32 j = 0; j < NUM_PICKUP_ITEMS_PER_ROW; ++j)
        if (rand < sPickupProbabilities[j])
            return sPickupItems[rowNum + j];

    for (u32 j = 0; j < NUM_PICKUP_RARE_ITEMS_PER_ROW; ++j)
        if (rand < sRarePickupProbabilities[j])
            return sRarePickupItems[rowNum + j];

    // should never be reached, but just in case
    return ITEM_NONE;
}

const u8 sPickupProbabilities[NUM_PICKUP_ITEMS_PER_ROW] =
{
    30, 40, 50, 60, 70, 80, 90, 94, 98
};

const u8 sRarePickupProbabilities[NUM_PICKUP_RARE_ITEMS_PER_ROW] =
{
    99, 100
};
