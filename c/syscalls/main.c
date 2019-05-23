#define _GNU_SOURCE
#include <sys/syscall.h>

static int write(int fd, const void* buf, unsigned int size) {
  long result;
  __asm__ __volatile__(
      "syscall"
      : "=a"(result)
      : "0"(__NR_write), "D"(fd), "S"(buf), "d"(size)
      : "cc", "rcx", "r11", "memory");
  return result;
}

static void exit(int code) {
  __asm__ __volatile__(
      "syscall"
      :
      : "a"(__NR_exit)
      : "cc", "rcx", "r11", "memory");
  __builtin_unreachable();
}

void _start() {
  char msg[] = "Hello, world without libc!\n";
  write(1, msg, sizeof(msg) - 1);
  exit(0);
}