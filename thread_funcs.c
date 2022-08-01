#include "thread_funcs.h"

void* calls(void* ptr)
{
	// using pthread self() to get current thread id
	printf("(calls)\tthread id = %d\n", pthread_self());
	pthread_exit(NULL);
	return NULL;
}

void join_main_w_calls()
{
    pthread_t thread;
    pthread_create(&thread, NULL, calls, NULL);
    printf("(main)\tthread id = %d\n", thread);
    pthread_join(thread, NULL);
}