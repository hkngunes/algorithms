#pragma once
/*For bool, true, false*/
#include "stdbool.h"
#include "util_types.h"

void InitIntegerList(int integer_list[], uint list_size);
bool ValidateListIndex(uint list_size, uint index);
bool SwapTwoValuesOfIntegerList(int number_list[], uint list_size, uint index1, uint index2);
void PrintList(int number_list[], uint list_size);