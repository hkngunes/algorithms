
/*For printf*/
#include "stdio.h"
/*For bool, true, false*/
#include "stdbool.h"

#include "../../util/util_includes.h"
#include "../bubble_sort.h"

/**
 * Start method of program. Tests bubble sort algorithm
 */
int main()
{
    // * Create a not-sorted random nember list to test bubble sort
    int number_list[100];
    uint list_size = sizeof(number_list)/sizeof(int);
    InitIntegerList(number_list, list_size);

    // * Test bubble sort
    if(BubbleSort(number_list, list_size))
    {
        printf("\nList Sorted SUCCESSFULLY\n");
    }
    
    return 0;
}