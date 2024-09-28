#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

void temp(void) {
  (void) printf("%s] %s) %d- Hello, Header!\n", __FILE__, __func__, __LINE__);
  return;
}

int binaryLocate(int* nums, int numsSize, int target) {
  assert(0 < numsSize );
  enum position_truth {
    AT_MIDDLE = 1,
    AT_GREATER = 2,
    AT_LESS = 3
  };
  int target_index = 0;
  if(0 == numsSize) {
    if(target > nums[0]) {
      return 1;
    } else {
      return 0;
    }
  } else {
    if(target <= nums[0]) { return 0;}
    uint16_t start_index = 0;
    uint16_t end_index = (numsSize - 1);
    uint16_t search_space = end_index - start_index;
    uint16_t middle_index = start_index + (search_space / 2);
    uint8_t switch_case = (target == nums[middle_index]) + (2 * (target > nums[middle_index]) + (3 * (target < nums[middle_index])));
    bool continue_searching = true;
    while(continue_searching) {
      switch(switch_case) {
        case AT_MIDDLE : {
          return middle_index;
          break; };
        case AT_GREATER : { 
          if(middle_index < end_index) {
            start_index = middle_index + 1;
          } else {
            return (middle_index + 1);
          }
          break; };
        case AT_LESS : { 
          if((start_index < middle_index) && (start_index < end_index)) {
            end_index = middle_index - 1;
          } else {
            return middle_index;
          }
          break; };
        default :  { 
          // shrug
          return middle_index;
          break; };
      }
      search_space = end_index - start_index;
      middle_index = start_index + (search_space / 2);
      switch_case = (target == nums[middle_index]) + (2 * (target > nums[middle_index]) + (3 * (target < nums[middle_index])));
      }
  }
  return target_index; 
}
