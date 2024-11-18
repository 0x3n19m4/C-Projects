// #include <stdio.h>
// #include <stdlib.h>

// struct person
//     {
//         char* name;
//         int age;
//     };

// int main(void)
// {
    //MALLOC
    /*
    int *ptr = malloc(sizeof(int)); // выделяем память для одного int
    *ptr = 24;      // помещаем значение в выделенную память
 
    printf("%d \n", *ptr);
    free(ptr);
    */

    //ARRAYS
    /*
    int n = 4;
    int *ptr = malloc(sizeof(int));

    if (ptr)
    {
        ptr[0] = 1;
        ptr[1] = 2;
        ptr[2] = 3;
        ptr[3] = 5;

        for (int i = 0; i < n; i++)
        {
            printf("%d \n", ptr[i]);
        }
    }

    free(ptr);
    */
    
    //STRUCTURES
    // struct person *ptr = malloc(sizeof(struct person));
    // if(ptr)
    // {
    //     ptr->name = "Tom";
    //     ptr->age = 38;

    //     printf("%s : %d", ptr->name, ptr->age);
    // }

    // free(ptr);
    // return 0;

    //CALLOC
    // int *ptr = calloc(1, sizeof(int));
    // if(ptr)
    // {
    //     printf("Initial value: %d \n", *ptr);

    //     *ptr = 15;

    //     printf("New value: %d", *ptr);
    // }

    // free(ptr);
    // return 0;

    //ARRAYS
    // int n = 4;
    // int *ptr = calloc(n, sizeof(int));

    // if (ptr)
    // {
    //     ptr[0] = 1;
    //     ptr[1] = 2;
    //     ptr[2] = 3;
    //     ptr[3] = 5;

    //     for (int i = 0; i < n; i++)
    //     {
    //         printf("%d \n", ptr[i]);
    //     }
    // }

    // free(ptr);

    //REALLOC
//     int size = sizeof(int);
//     int *ptr = malloc(size);
//     if(ptr)
//     {
//         printf("Address: %p \t Size: %d\n", (void*)ptr, size);
//     }

//     size = 4 * sizeof(int);
//     int *ptr_new = realloc(ptr, size);
//     if(ptr_new)
//     {
//         printf("Real location\n");
//         printf("Address: %p \t Size: %d \n", (void*)ptr_new, size);
//         free(ptr_new);
//     }
//     else
//     {
//         free(ptr);
//     }
// }

// LOCAL

// #include <stdio.h>
// #include <stdlib.h>

// void createPointer()
// {
//     printf("Code block starts\n");
//     {
//         int* p = malloc(sizeof(int));
//         if (!p) return;
//         *p = 1;
//         printf("%d \n", (*p));
//         free(p);
//     }
//     printf("Code block ends\n");
// }

// int main()
// {
//     createPointer();
//     return 0;
// }

// STATIC:

// #include <stdio.h>
// #include <stdlib.h>

// int * createPointer()
// {
//     static int *p = NULL;
//     if(p==NULL)
//     {
//         p = malloc(sizeof(int));
//         *p = 1;
//     }
//     printf("%d \n", (*p));
//     (*p)++;
//     return p;
// }

// int main(void)
// {
//     int *ptr;
//     ptr=createPointer();
//     ptr=createPointer();
//     ptr=createPointer();
//     free(ptr);
//     return 0;
// }

// GLOBAL:

// #include <stdio.h>
// #include <stdlib.h>

// int* p = NULL;

// void createPointer()
// {
//     printf("%d \n", (*p));
//     (*p)++;
// }

// int main(void)
// {
//     p = malloc(sizeof(int));
//     *p = 1;

//     createPointer();
//     createPointer();
//     createPointer();

//     free(p);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// int *addArrays(int a[], int b[], int n)
// {
//     int *ptr = calloc(n, sizeof(int));

//     for (int i = 0; i < n; i++)
//         ptr[i] = a[i] + b[i];
    
//     return ptr;
// }

// int main(void)
// {
//     int a[] = {3,4,5,6,7};
//     int b[] = {1,1,1,1,1};
    
//     int n = sizeof(a)/sizeof(a[0]);
//     int *ptr = addArrays(a, b, n);

//     for (int i = 0; i < n; i++)
//         printf("%d \t", ptr[i]);
    
//     free(ptr);
//     return 0;
// }