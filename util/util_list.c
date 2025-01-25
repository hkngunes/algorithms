/*For printf*/
#include "stdio.h"
/*For srand, rand*/
#include "stdlib.h"
/*For time*/
#include "time.h"

#include "util_includes.h"

/**
 * Initialize list of integers with random variables from 0 to 100
 * @param integer_list - is the list that will be initialized with random values
 * @param list_size is the size of integer_list
 */
void InitIntegerList(int integer_list[], uint list_size)
{
    
    int now = time(NULL);
    srand(now);
    for(uint i=0;i<list_size;i++)
    {
        integer_list[i] = rand()%100;
    }
}

/**
 * Controls out of range situation for a list and index
 * @param list_size is the size of list that was considered to check index 
 * validity
 * @param index is the considered index whether it is valid or not
 * @return True if index is valid, False otherwise 
 */
bool ValidateListIndex(uint list_size, uint index)
{
    if(index >= list_size)
    {
        printf("Out of list: list size: %d, attempt: %d",list_size, index);
        return false;
    }
    return true;
}

/**
 * Swaps two values of a list by their index
 * @param number_list is the list thats two value want to be swapped
 * @param list_size is the size of number_list
 * @param index1 is the index of first number want to be swapped with second 
 * number
 * @param index2 is the index of second number want to be swapped with first 
 * number
 * @return True if the numbers swapped, False otherwise
 */
bool SwapTwoValuesOfIntegerList(int number_list[], uint list_size, uint index1, uint index2)
{
    if( !ValidateListIndex(list_size, index1) || 
        !ValidateListIndex(list_size, index2))
    {
        return false;
    }
    int temp = number_list[index1];
    number_list[index1] = number_list[index2];
    number_list[index2] = temp;
    return true;
}

/**
 * Prints a list of integer
 * @param number_list is the list want to be printed
 * @param list_size is the size of number_list
 */
void PrintList(int number_list[], uint list_size)
{
    printf("[");
    for(uint index = 0; index < list_size; index++)
    {
        printf("%d", number_list[index]);
        if(index != list_size-1)
        {
            printf(",");
        }
    }
    printf("]");
}
