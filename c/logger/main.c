#include "log.h"

int main(void) {
  log(info, "some information;\n");
  log(warning, "something wrong;\n");
  log(trace, "trace something;\n");
  log(debug, "debug information;\n");
  log(error, "error with something;\n");

  return 0;
}
