/**
 * @file bubble_sort.c
 * @author Hakan Gunes
 * @link enghakangunes@gmail.com
 * @details Includes bubble_sort algorithm and main function to test the 
 * algorithm with list of random numbers, that generated with rand method of 
 * stdlib.h
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
/*For srand, rand*/
#include "stdlib.h"
/*For time*/
#include "time.h"

/*uint defined as unsigned integer*/
#define uint unsigned int

/**
 * Initialize list of integers with random variables from 0 to 100
 * @param number_list - is the list that will be initialized with random values
 * @param list_size is the size of number_list
 */
void init_number_list(int number_list[], uint list_size)
{
    
    int now = time(NULL);
    srand(now);
    for(uint i=0;i<list_size;i++)
    {
        number_list[i] = rand()%100;
    }
}

/**
 * Controls out of range situation for a list and index
 * @param list_size is the size of list that was considered to check index validity
 * @param index is the considered index whether it is valid or not
 * @return True if index is valid, False otherwise 
 */
bool check_list_index(uint list_size, uint index)
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
 * @param index1 is the index of first number want to be swapped with second number
 * @param index2 is the index of second number want to be swapped with first number
 * @return True if the numbers swapped, False otherwise
 */
bool swap(int number_list[], uint list_size, uint index1, uint index2)
{
    if(!check_list_index(list_size, index1) || !check_list_index(list_size, index2))
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
void print_list(int number_list[], uint list_size)
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

/**
 * One iteration in bubble sort to determine value at index bubble_index when sorted
 * @param number_list is the list want to be sorted
 * @param list_size is the size of number_list
 * @param bubble_index is the index of number_list that's final value will be determined in this iteration
 * @return True if the value of bubble index is determined, False otherwise
 */
bool bubble_sort_iteration(int number_list[], uint list_size, uint bubble_index)
{
    bool return_value = false;

    if(check_list_index(list_size, bubble_index))
    {
        uint iter = 0;
        for(iter = 0; iter < bubble_index; iter++)
        {
            if(number_list[iter]>number_list[iter+1])
            {
                if(!swap(number_list,list_size,iter,iter+1))
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
    print_list(number_list, list_size);
    return return_value;
}

/**
 * Sorts a list of integer from smallest to largers with bubble sort algorithm
 * @param number_list is the list want to be sorted
 * @param list_sizeis the size of number_list
 * @return True is the list sorted, False otherwise
 */
bool bubble_sort(int number_list[], uint list_size)
{
    bool return_value = false;

    printf("\nInitial List: ");
    print_list(number_list, list_size);

    for(uint bubble_index=list_size-1; bubble_index>0; bubble_index-- )
    {
        if(!bubble_sort_iteration(number_list, list_size, bubble_index))
        {
            break;
        }
    }

    printf("\nSorted List: ");
    print_list(number_list, list_size);
    return_value = true;

    return return_value;
}

/**
 * Start method of program. Tests bubble sort algorithm
 */
int main()
{
    // * Create a not-sorted random nember list to test bubble sort
    int number_list[100];
    uint list_size = sizeof(number_list)/sizeof(int);
    init_number_list(number_list, list_size);

    // * Test bubble sort
    if(bubble_sort(number_list, list_size))
    {
        printf("\nList Sorted SUCCESSFULLY\n");
    }
    
    return 0;
}

