#include "threading.h"

void* threaded_proc()
{
    printf("here's a thread.");
}

// examples:
void creating_a_thread_example()
{
    pthread_t thread = 0;    
    pthread_create(&thread, NULL, threaded_proc, NULL);
    pthread_join(thread, NULL);
    pthread_exit(NULL);
}