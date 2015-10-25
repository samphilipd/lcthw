#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void die(const char *message)
{
    if (errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

// a typedef creates a fake type, in this case for a function pointer
typedef int(*compare_cb)(int a, int b);
typedef void(*sort_f)(int *numbers, size_t count, compare_cb cmp);

// A classic bubble sort function that uses compare_cb to do the sorting
void bubble_sort(int *numbers, size_t count, compare_cb cmp)
{
    int temp = 0;
    int i = 0;
    int j = 0;

    for (i = 0; i < count; ++i) {
        for (j = 0; j < count - 1; ++j) {
            if (cmp(numbers[j], numbers[j+1]) > 0) {
                temp = numbers[j+1];
                numbers[j+1] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
}

// swaps two integers pointed at by x and y
void swap(int *x, int*y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

// A simple quicksort
void quick(int *numbers, compare_cb cmp, int start, int end)
{
    if (start < end) {
        int pivot = numbers[start];
        int l = start + 1;
        int r = end;
        while (l < r) {
            if (cmp(numbers[l], pivot) <= 0) {
                ++l;
            } else if (cmp(numbers[r], pivot) >= 0) {
                --r;
            } else {
                swap(&numbers[l], &numbers[r]);
            }
        }
        if (cmp(numbers[l], pivot) <= 0) {
            swap(&numbers[l], &numbers[start]);
            --l;
        } else {
            --l;
            swap(&numbers[l], &numbers[start]);
        }
        quick(numbers, cmp, start, l);
        quick(numbers, cmp, r, end);
    }
}

void quicksort(int *numbers, size_t count, compare_cb cmp)
{
    quick(numbers, cmp, 0, count-1);
}

int sorted_order(int a, int b)
{
    return a - b;
}

int reverse_order(int a, int b)
{
    return b - a;
}

int strange_order(int a, int b)
{
    if (a == 0 || b == 0) {
        return 0;
    } else {
        return a % b;
    }
}

// Used to test that we are sorting correctly by doing the sort and printing
// the result
void test_sorting(int *numbers, int count, sort_f sort, compare_cb cmp)
{
    int i = 0;
    int *target = malloc(count * sizeof(int));
    if (!target) die("Memory error.");
    memcpy(target, numbers, count * sizeof(int));

    sort(target, count, cmp);

    for (i = 0; i < count; ++i) {
        printf("%d ", target[i]);
    }
    printf("\n");

    free(target);

    // BREAKAGE
    // unsigned char *data = (unsigned char *) cmp;

    // printf("function bytecode: ");
    // for (i = 0; i < 25; ++i) {
    //     printf("%02x:", data[i]);
    // }

    printf("\n");
}

int main(int argc, char *argv[])
{
    if (argc < 2) die("USAGE: ex184 3 1 5 6");

    int count = argc - 1;
    int i = 0;
    char **inputs = argv + 1; // pointer to (pointer to array)s of input chars

    int *numbers = malloc(count * sizeof(int));
    if (!numbers) die("Memory error.");

    for(i = 0; i < count; ++i) {
        numbers[i] = atoi(inputs[i]);
    }

    test_sorting(numbers, count, quicksort, sorted_order);
    test_sorting(numbers, count, quicksort, reverse_order);
    test_sorting(numbers, count, quicksort, strange_order);

    test_sorting(numbers, count, bubble_sort, sorted_order);
    test_sorting(numbers, count, bubble_sort, reverse_order);
    test_sorting(numbers, count, bubble_sort, strange_order);

    // BREAKAGE
    // test_sorting(numbers, count, NULL);
    // END BREAKAGE

    free(numbers);

    return 0;

}
