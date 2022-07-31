#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <malloc.h>

struct thread_data {
	int thread_id;
	int sum;
	char *message;
};

/* SUMMARY
Create independent threads each of which will execute function 
Wait till threads are complete before main continues. Unless
we wait, we run the risk of executing an exit which wil terminate
the process and all threads before the threads have completed.
*/
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
void *printHello(void *thread_arg);

/* SUMMARY
Test function. Prints to console.
<params>
1. void *ptr: cast to char and stored in local variable */
void *print_message_function(void *ptr);