#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void temp(void) {
  (void) printf("%s] %s) %d- Hello, Header!\n", __FILE__, __func__, __LINE__);
  return;
}


/* Binary search */

int searchInsert(int* nums, int numsSize, int target) {
  enum case_enum {
    LARGEST = 2,
    SMALLEST = 1,
    OTHER = 0
  };
  /* 
    Find length 
      numsSize
  */
  const uint16_t num_size = (uint16_t) numsSize;

  /* 
    Degenerate case:
    numsSize = 0
    answer either 0 or error
  */
  if(0 == num_size) {
    return 0;
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
  const bool target_smallerOrEqual_than_all = (target <= nums[0]);
  const bool target_largerOrEqual_than_all = (target > nums[(num_size -1)]);
  const uint16_t case_values = ((uint16_t) target_smallerOrEqual_than_all) + (2* ((uint16_t) target_largerOrEqual_than_all)); 
  /* 
    Non basic cases:
    1) Binary search
    2) Parallel binary search
  */
  switch(case_values) {
    case SMALLEST : {
      (void) printf("%s] %s) %d- CASE: smallest.\n", __FILE__, __func__, __LINE__);
      return 0;
      break;
    };
    case LARGEST : {
      (void) printf("%s] %s) %d- CASE: largest.\n", __FILE__, __func__, __LINE__);
      return num_size;
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
      break;
    };
    default: {
      /* shouldn't reach */
      (void) printf("%s] %s) %d- Error reaching correct case.\n", __FILE__, __func__, __LINE__);
      exit(EXIT_FAILURE);
      break;
    }
  }

  return target;
}
