#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"

#define MIN 2
#define MAX 20

int clear_buffer(void) {
    int buffer = 0;
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        buffer++;
    }
    return buffer;
}

int find_amount(void) {
    int amount = 0;
    do {
        printf("Enter number of elements between %d and %d\n", MIN, MAX);
        if (scanf("%d", &amount) != 1) {
            clear_buffer();
            printf("You did not enter an integer. Try again\n");
            amount = 0;
            continue;
        }
        if (clear_buffer() != 0) {
            printf("You did not enter an integer. Try again\n");
            amount = 0;
        } else if (amount < MIN || amount > MAX) {
            printf("You did not enter a number between %d and %d. Try again\n", MIN, MAX);
        }
    } while (amount < MIN || amount > MAX);
    return amount;
}

void create_array(ARRAY *arr) {
    arr->count = find_amount();
    arr->data = malloc((size_t)arr->count * sizeof(int));
    if (arr->data == NULL) {
        printf("Array could not be created\n");
        arr->count = 0;
        return;
    }
    srand((unsigned)time(NULL));
    for (int i = 0; i < arr->count; ++i) {
        arr->data[i] = rand() % 99 + 1;
    }
}

void print_array(const ARRAY *arr) {
    printf("%d:", arr->count);
    for (int i = 0; i < arr->count; ++i) {
        printf("%4d", arr->data[i]);
    }
    printf("\n");
}

void add_element(ARRAY *arr, int value) {
    int *tmp = realloc(arr->data, ((size_t)arr->count + 1) * sizeof(int));
    if (tmp != NULL) {
        arr->data = tmp;
        arr->data[arr->count] = value;
        (arr->count)++;
    } else {
        puts("Error (re)allocating memory");
    }
}

void free_array(ARRAY *arr) {
    free(arr->data);
    arr->data = NULL;
    arr->count = 0;
}

void remove_element(ARRAY *arr, int index) {
    if (arr == NULL || arr->data == NULL || index < 0 || index >= arr->count) {
        puts("Invalid index");
        return;
    }
    for (int i = index; i < arr->count - 1; ++i) {
        arr->data[i] = arr->data[i + 1];
    }
    (arr->count)--;
    if (arr->count == 0) {
        free(arr->data);
        arr->data = NULL;
        return;
    }
    int *tmp = realloc(arr->data, (size_t)arr->count * sizeof(int));
    if (tmp != NULL) {
        arr->data = tmp;
    }
}

void insert_element(ARRAY *arr, int index, int value) {
    if (arr == NULL || index < 0 || index > arr->count) {
        puts("Invalid index");
        return;
    }

    int *tmp = realloc(arr->data, ((size_t)arr->count + 1) * sizeof(int));
    if (tmp == NULL) {
        puts("Error (re)allocating memory");
        return;
    }

    arr->data = tmp;
    for (int i = arr->count; i > index; --i) {
        arr->data[i] = arr->data[i - 1];
    }
    arr->data[index] = value;
    arr->count++;
}

