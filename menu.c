#include <stdio.h>
#include "menu.h"

static int read_int(const char *prompt, int *out) {
    printf("%s", prompt);
    if (scanf("%d", out) != 1) {
        clear_buffer();
        return 0;
    }

    if (clear_buffer() != 0) return 0;
    return 1;
}

static void handle_add(ARRAY *arr) {
    int value = 0;
    if (!read_int("Enter value to add: ", &value)) {
        puts("Invalid value!");
        return;
    }
    add_element(arr, value);
}

static void handle_insert(ARRAY *arr) {
    int index = 0;
    int value = 0;
    if (!read_int("Enter Index: ", &index)) {
        puts("Invalid Index!");
        return;
    }
    if (!read_int("Enter value: ", &value)) {
        puts("Invalid value!");
        return;
    }
    insert_element(arr, index, value);
}

static void handle_remove(ARRAY *arr) {
    int index = 0;
    if (!read_int("Enter Index to remove: ", &index)) {
        puts("Invalid Index!");
        return;
    }
    remove_element(arr, index);
}

void print_menu(void) {
    puts("\n--- Array Menu ---");
    puts("1. Create array");
    puts("2. Print array");
    puts("3. Add element");
    puts("4. Insert element");
    puts("5. Remove element");
    puts("0. Exit");
    puts("--------------------");
}

void run_menu(ARRAY *arr) {
    int choice = -1;

    do {
        print_menu();
        if (!read_int("Choice: ", &choice)) {
            puts("Invalid Input!");
            choice = -1;
            continue;
        }

        switch(choice) {
            case 1:
                free_array(arr);
                create_array(arr);
                break;
            case 2:
                print_array(arr);
                break;
            case 3:
                handle_add(arr);
                break;
            case 4:
                handle_insert(arr);
                break;
            case 5:
                handle_remove(arr);
                break;
            case 0:
                free_array(arr);
                puts("Exiting!");
                break;
            default:
                puts("Unknow option!");
                break;
        }
    } while (choice != 0);
}
