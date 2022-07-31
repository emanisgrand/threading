#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int pthread_create(pthread_t* thread, const pthread_attr_t* attr, void* (*start_routine)(void*), void*arg);
int pthread_join(pthread_t thread, void **value_ptr);
void pthread_exit(void* value_ptr);
