#include "thread_funcs.h"

pthread_attr_t attr;

void *threadFn(void*arg)
{
	pthread_detach(pthread_self());
	sleep(1);
	printf("(threadFn)<-\n");
	pthread_exit(NULL);
}

void* calls(void* ptr)
{
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

void demo_detatch()
{
    pthread_t tid;
    int ret = pthread_create(&tid, NULL, threadFn, NULL);

    if (ret != 0)
    {
        perror(" Thread Creation Error\n");
        exit(1);
    }

    printf("(main) thread created.\n");
    pthread_exit(NULL);
}

void *dowork(void*threadid)
{
	long tid;
	size_t mystacksize;

	tid = (long)threadid;
	pthread_attr_getstacksize(&attr, &mystacksize);

	printf(" Thread %ld: stack size = %li bytes \n\n", tid, mystacksize);

	pthread_exit(NULL);	
}


void demo_stacksize_delta()
{
    pthread_t myThread;
    size_t stacksize;
    pthread_t myID;
    long t = 'V'; // cast and passed into the create process.

    // initialize the global thread attribute.
    pthread_attr_init(&attr); 
    pthread_attr_getstacksize(&attr, &stacksize); 
    printf("\n Default stack size: %li\n", stacksize);
    stacksize = 9000000;
    printf(" Amount of stack needed per thread = %li\n", stacksize);
    pthread_attr_setstacksize(&attr, stacksize);

    printf(" Creating thread with stack size = %li bytes\n", stacksize);

    myID = pthread_create(&myThread, &attr, dowork, (void*)t);

    if (myID) {
        printf(" ERROR; return code from pthread_create() is %lud\n", myID);
        exit(-1);
    }
    pthread_exit(NULL);
}