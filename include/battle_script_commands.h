#pragma once

#define PICKUP_ACTIVATION_CHANCE 10

#define NUM_PICKUP_ITEMS 18
#define NUM_PICKUP_RARE_ITEMS 11

#define NUM_PICKUP_ITEMS_PER_ROW 9
#define NUM_PICKUP_RARE_ITEMS_PER_ROW 2

extern const u16 sPickupItems[NUM_PICKUP_ITEMS];
extern const u16 sRarePickupItems[NUM_PICKUP_RARE_ITEMS];

extern const u8 sPickupProbabilities[NUM_PICKUP_ITEMS_PER_ROW];
extern const u8 sRarePickupProbabilities[NUM_PICKUP_RARE_ITEMS_PER_ROW];

u16 PickupItemFromRowNum(u8 rowNum);
