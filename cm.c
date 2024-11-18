// #include <stdio.h>

// typedef struct
// {
// 	char *name;
// 	int age;
// } person;

// void print_person(person user)
// {
// 	printf("Name: %s \n", user.name);
// 	printf("Age: %d \n", user.age);
// }

// int main(void)
// {
// 	person tom = {.name = "Tom", .age=38};
// 	print_person(tom);
// 	return 0;
// }

// #include <stdio.h>

// int main()
// {
// 	int number;
// 	int i;
// 	int remained;
// 	int quotient;

// 	printf("Enter a number: ");
// 	scanf("%d", &number);

// 	quotient = number / 2;

// 	while (number != 0)
// 	{
// 		remained = number % 2;
// 		quotient = quotient / 2; 
// 		printf("%d", quotient);
// 	}
// }

// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//     double *ptr = malloc(sizeof(double)); 
//     if (ptr)
//     {
//         *ptr = 3.1415;
//         printf("ptr = %f \n", *ptr);
//     }
//     free(ptr);

//     long *pty = malloc(sizeof(long));
//     if (pty)
//     {
//         *pty = 8;
//         printf("pty = %d \n", *pty);
//     }
//     free(pty);
// }

// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
//     int **table;
//     int *rows;

//     int rowscount;
//     int d;

//     printf("Rows count = ");
//     scanf("%d", &rowscount);

//     table = calloc(rowscount, sizeof(int*));
//     rows = malloc(sizeof(int)*rowscount);

//     for (int i = 0; i<rowscount; i++)
//     {
//         printf("\nColumns count for %d= ", i);
//         scanf("%d", &rows[i]);
//         table[i] = calloc(rows[i], sizeof(int));

//         for (int j = 0; j<rows[i]; j++)
//         {
//             printf("table[%d][%d] = ", i, j);
//             scanf("%d", i, j);
//             table[i][j] = d;
//         }
//     }
//     printf("\n");

//     for (int i = 0; i<rowscount; i++)
//     {
//         printf("\n");

//         for (int j = 0; j<rows[i]; j++)
//         {
//             printf("%d \t", table[i][j]);
//         }
//         free(table[i]);
//     }

//     free(table);
//     free(rows);

//     return 0;
// }