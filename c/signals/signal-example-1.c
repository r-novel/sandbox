#include <stdio.h>
#include <signal.h>

volatile sig_atomic_t br = 1;

void handler(int signum) {
  br = 0;
}

int main(int argc, char** argv) {
  if (signal(SIGINT, handler) == SIG_ERR)
    return 1;

  printf("Press break keyboard key combination to stop the program\n");

  while(br);
  
  printf("Received SIGINT, exit\n");

  return 0;
}