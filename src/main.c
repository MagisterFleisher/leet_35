#include <stdio.h>
#include <stdint.h>
#include "include/binary_locate.h"

int main(int argument_count, char** argument_vector) {
  int error = 0;
  (void) printf("%s] %s) %d- argument_count: %d\n", __FILE__, __FUNCTION__, __LINE__, argument_count);
  (void) temp();

  int array0[1] = { 0 };
  int array1[2] = { -1, 0 };
  int array2[2] = { 5, 8};
  int array3[3] = { 0, 1, 6  };
  int array4[3] = { -1, 0, 7 };
  int array5[4] = { -1, 1, 6  };
  int array6[4] = { -1, 0, 1, 6  };
  int array7[5] = { -2, -1, 0, 2, 7};
  int array8[5] = { -2, -1, 1, 2, 7};
  int array9[6] = { -2, -1, 0, 1, 2, 7};
  int array10[6] = { -2, -1, 1, 2, 7, 8};
  int array11[7] = { -2, -1, 1, 2, 7, 8, 15};

  int *nums[] = { array0, array1, array2, array3, array4, 
    array5, array6, array7, array8, array9, array10, array11 };
  int numsSize[12] = { 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7 };

  int target[4] = { 0, 1, 5, 11 };

  int target0 = 3;

  for(uint_fast8_t index0 = 0; index0 < 12; index0++) {
    for(uint_fast8_t index1 = 0; index1 < 4; index1++) {
      printf("array%d\tnumsSize: %d\ttarget: %d\tindex: %d\n", index0, numsSize[index0], target[index1], binaryLocate(nums[index0], numsSize[index0], target[index1])); 
      }
  }
  
//  printf("\n\narray%d\tnumsSize: %d\ttarget: %d\nindex: %d\n\n\n", 5, numsSize[5], target0, binaryLocate(nums[5], numsSize[5], target0)); 
  
  return error;
}