#include <pthread.h> // pthread_detach, pthread_self, pthread_exit, pthread_join
#include <stdio.h>	// printf
#include <unistd.h> // sleep
#include <stdlib.h> // exit

/* 
Run pthread_detatch() with own thread id as argument.
Print to console and exit thread.
<params>
1. void*arg: arguments */
void *threadFn(void*arg);

/* 
Using pthread_self() to get current thread id 
<params>
1. void*ptr: arguments */
void* calls(void* ptr);

/*  
Declare a thread & pass in the calls() function with no args.
Print the thread id, join current thread with calls thread. */
void join_main_w_calls();

/* 
Create a thread with threadFn(), sleep, print to console from threadFn().
Contains handling in event of an error; exits. */
void demo_detatch();

/* Global variable used to set thread attributes. */
extern pthread_attr_t attr;

/* 
Display the size (in bytes) of the given thread's stack.
<params>
1. void *threadid: thread ID */
void *dowork(void*threadid);

/*
Display size (in bytes) of the default stacksize.
Change the stack size, create a thread with new stacksize as attr.
Print new thread's stacksize.*/
void demo_stacksize_delta();