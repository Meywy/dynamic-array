#ifndef ARRAY_H
#define ARRAY_H

typedef struct {
    int *data;
    int count;
} ARRAY;

int clear_buffer(void);
int find_amount(void);
void create_array(ARRAY *arr);
void print_array(const ARRAY *arr);
void add_element(ARRAY *arr, int value);
void free_array(ARRAY *arr);
void remove_element(ARRAY *arr, int index);
void insert_element(ARRAY *arr, int index, int value);

#endif
