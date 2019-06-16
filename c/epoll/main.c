#include <stdio.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <string.h>

#define MAX_EVENTS 5
#define READ_SIZE 10

int err(char* msg) {
  fprintf(stderr, "%s;\n", msg);
  return 1;
}

int main(int argc, char** argv) {
  int running = 1;
  int event_count;
  size_t bytes_read;
  char read_buffer[READ_SIZE + 1];
  struct epoll_event event, events[MAX_EVENTS];
  int epoll_fd = epoll_create1(0);
 
  if(epoll_fd == -1)
    err("failed to create epoll file descriptor");
 
  event.events = EPOLLIN;
  event.data.fd = 0;
 
  if(epoll_ctl(epoll_fd, EPOLL_CTL_ADD, 0, &event)) {
    close(epoll_fd);
    err("failed to add file descriptor to epoll");
  }
 
  while(running) {
    printf("\nPolling for input...\n");
    
    event_count = epoll_wait(epoll_fd, events, MAX_EVENTS, 30000);
    printf("%d ready events\n", event_count);
    
    for(int i = 0; i < event_count; i++) {
      printf("Reading file descriptor '%d' -- ", events[i].data.fd);
      
      bytes_read = read(events[i].data.fd, read_buffer, READ_SIZE);
      printf("%zd bytes read.\n", bytes_read);
      
      read_buffer[bytes_read] = '\0';
      printf("Read '%s'\n", read_buffer);
 
      if(!strncmp(read_buffer, "stop\n", 5))
        running = 0;
    }
  }
 
  if(close(epoll_fd))
    err("failed to close epoll file descriptor");

  return 0;
}