#include "threading.h"

void *funky_thread()
{
	printf("threaded process\n");
	pthread_exit(NULL);
}

int main()
{
	pthread_t thread = 0;
	pthread_create(&thread, NULL, &funky_thread, NULL);
	pthread_join(thread, NULL);
	//pthread_exit(NULL); 
}
