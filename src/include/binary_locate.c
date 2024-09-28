

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
  uint_fast16_t start_index = 0;
  uint_fast16_t end_index = numsSize - 1;
  uint_fast8_t case_search_size = (end_index - start_index);
  uint_fast16_t middle_index = numsSize / 2;
  
  uint_fast8_t find_area = (target == nums[middle_index]) + (2*(target > nums[middle_index])) + (3*(target < nums[middle_index]));

/*   
 
  (void) printf("%d- middle_index: %ju\tstart_index: %ju\tend_index: %ju\tcase_search_size: %ju\tfind_area: %ju\n", 
    __LINE__, middle_index, start_index,end_index, case_search_size, find_area);
*/

  while(continue_searching) {
    if(case_search_size == 0) {
        /*
          1 VALUE IN ARRAY 
        */
        if(target == nums[middle_index]) {
          return middle_index;
        }
        if(target < nums[middle_index]) {
            return middle_index;
        }
        if(target > nums[middle_index]) {
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
            (void) printf("%d-\tfound at middle index: %ju\tmiddle index value: %d\n", __LINE__, middle_index, nums[middle_index]);
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
        find_area = (target == nums[middle_index]) + (2*(target > nums[middle_index])) + (3*(target < nums[middle_index]));
        case_search_size = end_index - start_index;
        //break;
      }
    }
/*       case 1 : {
    switch(case_search_size) {
      case 0 : { 
          //return found_index;
        break;
      };

          2 VALUES IN ARRAY
                if(target == nums[start_index]) {
          return 0;
        } else  {
          if(target == nums[end_index]) {
            return 1; 
            } else {
              return found_index;}
        }
        break;
      }; 
      default : {
      break;
    }
    //continue_searching = false;
  }
      */
  return found_index;
}
