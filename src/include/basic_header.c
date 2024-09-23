#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void temp(void) {
  (void) printf("%s] %s) %d- Hello, Header!\n", __FILE__, __func__, __LINE__);
  return;
}

typedef struct target_return {
  bool found;
  uint16_t found_index;
  uint16_t nums_index_start;
  uint16_t nums_index_end;
} target_return;

/* Binary search */
target_return* findTarget(int* nums, target_return* current_search_space, const int target) {
  enum case_enum {
    SIZE_1 = 3,
    LARGEST = 2,
    SMALLEST = 1,
    OTHER = 0
  };
  /* 
    Find length 
      numsSize
  */
  const uint16_t current_lowest_index = current_search_space->nums_index_start;
  const uint16_t current_highest_index = current_search_space->nums_index_end;
  (void) printf("current lowest %d \t current highest %d\n", current_lowest_index, current_highest_index);
  (void) printf("current width : %d \n", (current_search_space->nums_index_end - current_search_space->nums_index_start));
  /* 
    Degenerate case:
    numsSize = 0
    answer either 0 or error
  */
  if(0 == ((1 + current_search_space->nums_index_end) - current_search_space->nums_index_start)) {
    current_search_space->found_index = 0;
    current_search_space->found = true;
    return current_search_space;
  }

  /* 
    Basic cases:
    1) numsSize = 1
      - target <= nums[0] -> 0
      - target > nums[0] -> 1
    2) sign based results 
      - nums[0] >= 0 && target < -1 -> 0
      - nums[(numsSize -1)] < 0 && target <= 0 -> numsSize
    3) End cases 
      - target =< nums[0] -> 0
      - target >= nums[(numsSize -1)]  -> numsSize
    
    NB: End cases contains sign based results, but sign based may have advantages given simplicity of determining sign.
  */
  int current_lowest_value = nums[current_lowest_index];
  int current_highest_value = nums[current_highest_index];
  const bool target_smallerOrEqual_than_all = (target <= current_lowest_value);
  const bool target_largerOrEqual_than_all = (target > current_highest_value);

  (void) printf("target_smallerOrEqual_than_all : %d\t target_largerOrEqual_than_all: %d\n", target_smallerOrEqual_than_all, target_largerOrEqual_than_all);
  (void) printf("target : %d \tcurrent_lowest_value : %d\t current_highest_value: %d\n", target, current_lowest_value, current_highest_value);

  const uint16_t index_width = 1 + ((current_search_space->nums_index_end + 1) - current_search_space->nums_index_start); 
  const uint16_t case_values = ((uint16_t) target_smallerOrEqual_than_all) + (2 * ((uint16_t) target_largerOrEqual_than_all) + (3* (index_width == 1)));

  (void) printf("case value: %d\n", case_values); 
  /* 
    Non basic cases:
    1) Binary search
    2) Parallel binary search
  */
  switch(case_values) {
    case SIZE_1 : {
      current_search_space->found = true;
      if(target <= current_lowest_value) {
      current_search_space->found_index = current_lowest_index;  
      } else {
        current_search_space->found_index = current_highest_index + 1;
      }
      break;
    };
    case SMALLEST : {
      (void) printf("%s] %s) %d- CASE: smallest.\n", __FILE__, __func__, __LINE__);
      current_search_space->found = true;
      if(current_lowest_index > 0) {
        if(current_lowest_value != target) {
        current_search_space->found_index = current_lowest_index -1; 
        } else {
          current_search_space->found_index = current_lowest_index;
        }
        (void) printf("current_lowest - 1 %d\n", (current_lowest_index - 1));
        (void) printf("current_lowest_value %d \ttarget %d\n", current_lowest_value, target);
      } else {
        (void) printf("current_lowest %d\n", current_lowest_index);
        current_search_space->found_index = current_lowest_index; 
      }
      break;
    };
    case LARGEST : {
      (void) printf("%s] %s) %d- CASE: largest.\n", __FILE__, __func__, __LINE__);
      current_search_space->found = true;
      current_search_space->found_index = current_highest_index + 1; 
      (void) printf("current_highest %d\tcurrent_search_space->found_index: %d\n", current_highest_index, current_search_space->found_index);
      break;
    };
    case OTHER : {
      (void) printf("%s] %s) %d- CASE: other.\n", __FILE__, __func__, __LINE__);
      /* binary search */

      /* find center of array */
      /* 
        SPLIT:
          store index of central value of current array fragment
          check if 
            target < than center value
            target > center value
            target == center value -> return center value index

        CHECK END CASES:
          center value < target <= center value + 1 -> return center value index
          center value > target >= center value - 1 -> return center value index
          else:

        RECURSE TO SPLIT
      */
      (void) printf("index_width : %d\n", index_width);
      const uint16_t index_middle = index_width / 2;
      (void) printf("index_middle : %d\n", index_middle);
      if(target <= nums[index_middle]) { 
        (void) printf("Target less than or equal to middle value: %d <= %d\n", target, nums[index_middle]);
        current_search_space->nums_index_start = index_middle;
      } else {
        (void) printf("Target greater than to middle value: %d > %d\n", target, nums[index_middle]);
        current_search_space->nums_index_end = (index_middle - 1);
      }

      break;
    };
    default: {
      /* shouldn't reach */
      (void) printf("%s] %s) %d- Error reaching correct case.\n", __FILE__, __func__, __LINE__);
      exit(EXIT_FAILURE);
      break;
    }
  }
  (void) printf("returning value as target %d", current_search_space->found_index);
  return current_search_space;
}

int searchInsert(int* nums, int numsSize, int target) {
  int* current_nums = nums;
  int current_size = numsSize;

  target_return is_found = {};
  is_found.nums_index_start = 0;
  is_found.nums_index_end = (current_size - 1);

  while(false == is_found.found) {
    is_found = *findTarget(nums, &is_found, target);
  }

  return is_found.found_index;
}