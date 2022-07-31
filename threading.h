#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

/* <SUMMARY>
 Create a threaded process.
 <params>
 1. pthread_t *thread: An int to id the thread 
 2. const pthread_attr_t *attr: Attributes include: detached state, 
 	scheduling policy, scope, stack addr or stack size, etc. 
 3. void* (*start_routine)(void*) A function to execute 
 4. void*arg: Takes arguments; can be NULL; can take some kind of argument struct
 <returns> integer. threaded process id. */
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void* (*start_routine)(void*), void*arg);

/* <SUMMARY>
Links the current process to another process. Useful for identifying completed or exited threads.
<params>
1. pthread_t thread: until this thread terminates, the calling thread is blocked.
2. void** value_ptr: if not NULL, the terminating thread will pass this argument to pthread_exit();
<returns> integer. */
int pthread_join(pthread_t thread, void **value_ptr);

/* <SUMMARY>
Called automatically. When called from main() will finish running the remaining
threads before terminating. Otherwise it takes all the threads down with it.
<params>
1. void** value_ptr: any successful join with the terminating thread is passed 
   to pthread_join which is then passed to this argument. */
void pthread_exit(void* value_ptr);

/* SUMMARY
Test function. Prints to console.
*/
void* threaded_proc();