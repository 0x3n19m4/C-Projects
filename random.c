#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        // Обмен значениями
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    int primes[50] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 
                     47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 
                     107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 
                     167, 173, 179, 181, 191, 193, 197, 199};

    // Инициализация генератора случайных чисел
    srand(time(0));

    // Перемешиваем массив
    shuffle(primes, 50);

    // Печать перемешанного массива
    for (int i = 0; i < 50; i++) {
        printf("%d ", primes[i]);
    }

    return 0;
}	
