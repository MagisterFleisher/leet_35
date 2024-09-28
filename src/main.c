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
  int array4[3] = { 0, 1, 6  };
  int array5[3] = { -1, 0, 7 };
  int array6[4] = { -1, 1, 6  };
  int array7[4] = { -1, 0, 1, 6  };
  int array8[6] = { -2, -1, 0, 2, 7};
  int array9[6] = { -2, -1, 1, 2, 7};
  int array10[7] = { -2, -1, 0, 1, 2, 7};
  int array11[7] = { -2, -1, 1, 2, 7, 8};

  int *nums[] = { array0, array1, array2, array4, 
    array5, array6, array7, array8, array9, array10, array11 };
  int numsSize[11] = { 1, 2, 2, 3, 3, 4, 4, 6, 6, 7, 7 };

  int target[4] = { 0, 1, 5, 11 };
  int target0 = 11;

  for(uint_fast8_t index0 = 0; index0 < 11; index0++) {
      printf("array%d\tindex: %d\n", index0, binaryLocate(nums[index0], numsSize[index0], target0)); }
  return error;

}