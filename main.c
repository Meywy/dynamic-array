#include "array.h"
#include "menu.h"
#include <stdlib.h>

int main(void) {
    ARRAY arr = { NULL, 0 };
    run_menu(&arr);
    return 0;
}
