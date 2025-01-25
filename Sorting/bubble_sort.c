/**
 * @file BubbleSort.c
 * @author Hakan Gunes
 * @link enghakangunes@gmail.com
 * @details Includes BubbleSort algorithm 
 * 
 * @pseudocode:
 * 1. bubble = last index
 * 2. iter = 0
 * 3. if list[iter] > list[iter+1] then swap values at iter and iter+1
 * 4. increment iter by 1
 * 5. if iter < bubble continue from step 3
 * 6. decrement bubble by 1
 * 7. if bubble > 0 continue from step 2
 * 8. END
*/

/*For printf*/
#include "stdio.h"
/*For bool, true, false*/
#include "stdbool.h"

#include "../util/util_includes.h"

#include "bubble_sort.h"

/**
 * One iteration in bubble sort to determine value at index bubble_index when 
 * sorted
 * @param number_list is the list want to be sorted
 * @param list_size is the size of number_list
 * @param bubble_index is the index of number_list that's final value will be 
 * determined in this iteration
 * @return True if the value of bubble index is determined, False otherwise
 */
bool BubbleSortIteration( int number_list[], 
                            uint list_size, 
                            uint bubble_index)
{
    bool return_value = false;

    if(ValidateListIndex(list_size, bubble_index))
    {
        uint iter = 0;
        for(iter = 0; iter < bubble_index; iter++)
        {
            if(number_list[iter]>number_list[iter+1])
            {
                if(!SwapTwoValuesOfIntegerList(number_list,list_size,iter,iter+1))
                {
                    break;
                }
            }
        }
        if(iter == bubble_index)
        {
            return_value = true;
        }
    }
    
    printf("\nIteration: ");
    PrintList(number_list, list_size);
    return return_value;
}

/**
 * Sorts a list of integer from smallest to largers with bubble sort algorithm
 * @param number_list is the list want to be sorted
 * @param list_sizeis the size of number_list
 * @return True is the list sorted, False otherwise
 */
bool BubbleSort(int number_list[], uint list_size)
{
    bool return_value = false;

    printf("\nInitial List: ");
    PrintList(number_list, list_size);

    for(uint bubble_index=list_size-1; bubble_index>0; bubble_index-- )
    {
        if(!BubbleSortIteration(number_list, list_size, bubble_index))
        {
            break;
        }
    }

    printf("\nSorted List: ");
    PrintList(number_list, list_size);
    return_value = true;

    return return_value;
}
