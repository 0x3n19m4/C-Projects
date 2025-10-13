#include <stdio.h>
#include <string.h>

int search(int *arr, int *target)
{
    int left, right, mid;
    int size = strlen(arr) - 1;

    if (target == 0)
        return 0;
        
    left, right = 1, size;

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    printf("%d\n", right);
}

int main()
{
    int arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 2;

    search(&arr, &target);
    return 0;
}
