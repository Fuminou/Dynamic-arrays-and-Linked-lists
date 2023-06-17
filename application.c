/*
 * In this file, you should implement an application that compares the
 * performance of a dynamic array and a linked list, as described in the
 * README. Don't forget to include your name and @oregonstate.edu email
 * address below.
 *
 * Name: Joon Yuan Chong
 * Email: chongjoo@oregonstate.edu
 */

#include <stdlib.h>
#include <stdio.h>

#include "time.h"
#include "dynarray.h"
#include "dynarray.c"
#include "list.c"
#include "list.h"

#define TEST_DATA_SIZE 1000000

/*
 * This function generates and an array of random integers of size n.
 */
int* generate_random_array(int n) {
  int* arr = malloc(n * sizeof(int));
  int i;

  for (i = 0; i < n; i++) {
    arr[i] = rand();
  }

  return arr;
}

int main(int argc, char const *argv[]) {
  int* test_data = generate_random_array(TEST_DATA_SIZE);

  /*
   * You should write code here to insert the data in test_data into a
   * dynamic array using the dynamic array interface you implemented.  As
   * you're doing this, measure two things:
   *   1. The total amount of time it takes to insert all the data into the
   *      dynamic array.
   *   2. The maximum amount of time it takes to insert any single element into
   *      the dynamic array.
   * To help with this, you can use the C functions time() and difftime()
   * from time.h.  Don't forget to include time.h above!
   */
   clock_t startTime, endTime;
   clock_t startTimeSingle, endTimeSingle;
   double totalTime, totalTimeSingle;
   double totalTimeSingleMax=0;
   int i;

   startTime = clock();
   struct dynarray* da;
   da = dynarray_create();

for(i = 0; i < 1000000; i++){
  startTimeSingle=clock();
  dynarray_insert(da, &test_data[i]);
  endTimeSingle=clock();
  totalTimeSingle = (double)(endTimeSingle - startTimeSingle) / CLOCKS_PER_SEC;
  if(totalTimeSingleMax<totalTimeSingle){
    totalTimeSingleMax=totalTimeSingle;
  }
}

   endTime = clock();
   totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
   printf("Total time to insert data into dynamic array: %f\n",totalTime);
   printf("Total time to insert 1 element into dynamic array: %f\n",totalTimeSingleMax);

  dynarray_free(da);
   /*
    * You should write code here to insert the data in test_data into a
    * linked list using the linked list interface you implemented.  As
    * you're doing this, measure two things:
    *   1. The total amount of time it takes to insert all the data into the
    *      linked list.
    *   2. The maximum amount of time it takes to insert any single element into
    *      the linked list.
    * Again, you can use the C functions time() and difftime() from time.h to
    * help with this.
    *
    * How do the times associated with the dynamic array compare to the times
    * associated with the linked list?  How does this change if you modify the
    * value of TEST_DATA_SIZE above?
    */

   clock_t startTimeList, endTimeList;
   clock_t startTimeListSingle, endTimeListSingle;
  double totalTimeList, totalTimeListSingle;
  double totalTimeListSingleMax=0;
  double diff;
 
  startTimeList=clock();
    struct list* list;
    list = list_create();

for(int y = 0; y < 1000000; y++){
    startTimeListSingle=clock();
    list_insert(list, &test_data[y]);
    endTimeListSingle=clock();
    totalTimeListSingle = (double)(endTimeListSingle - startTimeListSingle) / CLOCKS_PER_SEC;

  if(totalTimeListSingleMax<totalTimeListSingle){
    totalTimeListSingleMax=totalTimeListSingle;
  }
}
endTimeList=clock();
    totalTimeList = (double)(endTimeList - startTimeList) / CLOCKS_PER_SEC;
   printf("Total time to insert data into linked list: %f\n",totalTimeList);
    printf("Total time to insert 1 element into linked list: %f\n",totalTimeListSingleMax);

  free(test_data);
  list_free(list);
  return 0;
}