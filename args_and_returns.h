#include <stdio.h> // printf
#include <stdlib.h> // exit 
#include <pthread.h> // pthread_t, pthread_join, pthread_exit, etc..
#include <string.h> // strcpy 
#include <malloc.h> // malloc

struct thread_data {
	int thread_id;
	int sum;
	char *message;
};

/* SUMMARY
Create independent threads each of which will execute function 
Wait till threads are complete before main continues. Unless
we wait, we run the risk of executing an exit which wil terminate
the process and all threads before the threads have completed.*/
void pass_single_argument();

/* SUMMARY
Create a thread_data struct and assign its variables. Malloc for the char*.
Create the thread and pass the struct by casting it to a void* and passing the address
pthread_join is intended to prevent main from ending before the thread. Likely not required here.
Exit.  */
void pass_multiple_arguments(); 

/* SUMMARY
Initializes a thread_data pointer and its local variables, then them prints to console.
<params>  
1. void* thread_arg: cast to a thread_data struct and fill local vars*/
void *print_hello(void *thread_arg);

/* SUMMARY
Test function. Prints to console.
<params>
1. void *ptr: cast to char and stored in local variable */
void *print_message_function(void *ptr);

/* SUMMARY
Allocate memory for the char* .
Cast the char* to a void* to return type.
<params>
1. void *args: not sure.*/
void *hello_return(void* args);

/* SUMMARY
Create a new thread that runs hello_return w/o arguments.
Wait until thread completes. Assign return value to str */
void return_from_join();