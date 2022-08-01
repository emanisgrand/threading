#include <pthread.h>
#include <stdio.h>

/* SUMMARY
Using pthread_self() to get current thread id */
void* calls(void* ptr);

/* SUMMARY 
Declare a thread & pass in the calls function with no args.
Print the thread id.*/
void join_main_w_calls();