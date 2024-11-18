#include <stdio.h>
#include <pthread.h>

//int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(routine) (void*), void *arg);

void* some_work(void* arg)
{
    for(int i = 0; i < 5; ++i)
    {
        puts(arg);
    }
    return NULL;
}

int main(void)
{
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, some_work, "Hello World");
    pthread_create(&thread2, NULL, some_work, "Hello METANIT");

    printf("End...\n");
    return 0;
}
