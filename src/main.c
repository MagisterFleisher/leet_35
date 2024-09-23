#include <stdio.h>
#include "include/basic_header.h"

int main(int argument_count, char** argument_vector) {
  int error = 0;
  (void) printf("%s] %s) %d- argument_count: %d\n", __FILE__, __FUNCTION__, __LINE__, argument_count);
  (void) temp();
  return error;
}
