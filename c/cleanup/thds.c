#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

static void __defer_unlock(pthread_mutex_t **mutex)
{
	printf("mutex has unlocked;\n");
	pthread_mutex_unlock(*mutex);
}

int counter = 0;
pthread_mutex_t	mtx_glob;
pthread_t tid[2];


void* perform(void *arg)
{
  pthread_mutex_t *mutex __attribute__((cleanup(__defer_unlock))) = &mtx_glob;
  pthread_mutex_lock(mutex);

  counter++;
  printf("task %d has started;\n", counter);

  for(int i = 0; i < (0xFFFF); ++i) {
  	sleep(0.5);
  }

  printf("task %d has been finished;\n", counter);

 	return NULL;
}

int main(void)
{
	int i = 0;
  int error;

  if (pthread_mutex_init(&mtx_glob, NULL) != 0) {
    printf("\n mutex init has failed;\n");
    return 1;
  }

  while (i < 2) {
	  error = pthread_create(&(tid[i]),
	                         NULL,
	                         &perform, NULL);
	  if (error != 0)
	    printf("\nthread can't be created :[%s]",
	          strerror(error));
	  i++;
  }

  pthread_join(tid[0], NULL);
  pthread_join(tid[1], NULL);

  pthread_mutex_destroy(&mtx_glob);

  return 0;
}
