// BELFPC
#include "args_and_returns.h"

void* hello_return(void* args);

int main()
{
    char* str;
    pthread_t thread; // thread identifier

    //create a new thread tha turns hello_return without arguments
    pthread_create(&thread, NULL, hello_return, NULL);

    // wait until the thread completes, assign return value to str
    pthread_join(thread, (void**) & str);
    printf("%s", str);

    return 0;
}
