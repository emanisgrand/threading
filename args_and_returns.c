#include "args_and_returns.h"

void* hello_return(void* args)
{
    // allocate a new string on the heap with "Hello World!"
    char * hello = strdup("allocated on the heap.\n  [char* <-> (main)]\n");
    return (void *) hello;
}

void *printHello(void *thread_arg)
{
	struct thread_data *my_data;

	int taskid = 0, sum = 0;
	char hello_msg[255];

	my_data = (struct thread_data*) thread_arg;
	taskid = my_data->thread_id;
	sum=my_data->sum;
	strcpy(hello_msg, my_data->message);
	printf("taskid = %d, sum = %d, message = %s\n", taskid, sum, hello_msg);	
}

void *print_message_function(void *ptr)
{
    char *message;
    message = (char *) ptr;
    printf("%s \n", message);
}

void pass_single_argument()
{
    pthread_t thread1, thread2;
    char *message1 = "Thread 1";
    char *message2 = "Thread 2";
    int iret1 = 0, iret2 = 0;

    iret1 = pthread_create( &thread1, NULL, print_message_function, (void*) message1); // needs to be cast to void *
    iret2 = pthread_create( &thread2, NULL, print_message_function, (void*) message2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Thread 1 returns: %d\n", iret1);
    printf("Thread 2 returns: %d\n", iret2);
    pthread_exit(NULL);
    exit(0);
}

void pass_multiple_arguments()
{
    pthread_t my_thread;
    struct thread_data my_thread_data; 

    my_thread_data.message = malloc(sizeof(char) * 255);

    my_thread_data.thread_id = 10;
    my_thread_data.sum = 35;
    my_thread_data.message = "Ahyuk!";

    int my_id = pthread_create(&my_thread, NULL, printHello, (void*) &my_thread_data);
    pthread_join(my_thread, NULL);
    pthread_exit(NULL);
}
