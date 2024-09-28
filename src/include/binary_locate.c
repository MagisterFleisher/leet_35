

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

void temp(void) {
  (void) printf("%s] %s) %d- Hello, Header!\n", __FILE__, __func__, __LINE__);
  return;
}


int binaryLocate(int* nums, int numsSize, int target) {
  int found_index = -1;
  
  enum search_enum {
    EQUAL_TO_MIDDLE = 1,
    GREATER_THAN_MIDDLE = 2,
    LESS_THAN_MIDDLE = 3
  };

  (void) assert(0 <= numsSize);
  bool continue_searching = true;
  int_fast16_t start_index = 0;
  int_fast16_t end_index = numsSize - 1;
  int_fast8_t case_search_size = (end_index - start_index);
  int_fast16_t middle_index = numsSize / 2;  
  int_fast8_t find_area = (target == nums[middle_index]) + (2*(target > nums[middle_index])) + (3*(target < nums[middle_index]));

  while(continue_searching) {
    if(case_search_size == 0) {
        /*
          1 VALUE IN ARRAY 
        */
        if(target == nums[middle_index]) {
          (void) printf("\n%d-\ttarget %d == nums[middle_index] %d\tmiddle_index: %d\n", __LINE__, target, nums[middle_index], middle_index);
          return middle_index;
        }
        if(target < nums[middle_index]) {
          (void) printf("\n%d\ttarget %d < nums[middle_index] %d\tmiddle_index: %d\n", __LINE__, target, nums[middle_index], middle_index);
          return middle_index;
        }
        if(target > nums[middle_index]) {
          (void) printf("\n%d\ttarget %d > nums[middle_index] %d\tmiddle_index: %d\n", __LINE__, target, nums[middle_index], middle_index);
          return (middle_index + 1);
        }
    } else {
        /*
          MORE THAN 1 VALUES IN ARRAY
        */
        /* Find area
          1 -> the search value is at the middle value
          2 -> the search value is greater than the  middle value
          3 -> the search value is less than the middle value
          default -> this shouldn't happen
        */
        switch(find_area) {
          case EQUAL_TO_MIDDLE : {
            (void) printf("\n%d-\ttarget: %d\tfound at middle index: %jd\tmiddle index value: %d\n", __LINE__, target, middle_index, nums[middle_index]);
            return middle_index;
            //found_index = middle_index;
            continue_searching = false;
            break;
          };
          case GREATER_THAN_MIDDLE : {
            (void) printf("%d-\tgreater than middle index: %ju\tmiddle index value: %d\n", __LINE__, middle_index, nums[middle_index]);
            start_index = middle_index + 1;
            case_search_size = end_index - start_index;
            middle_index = (end_index - start_index) + middle_index;
            break;
          };
          case LESS_THAN_MIDDLE : {
            (void) printf("%d-\tless that middle index: %ju\tmiddle index value: %d\n", __LINE__, middle_index, nums[middle_index]);
            end_index = middle_index - 1;
            case_search_size = end_index - start_index;
            middle_index = (end_index - start_index) + start_index;
            break;
          };
          default : {
            break;
          };
        }
      }
      find_area = (target == nums[middle_index]) + (2*(target > nums[middle_index])) + (3*(target < nums[middle_index]));
      case_search_size = end_index - start_index;
    }
  return found_index;
}
