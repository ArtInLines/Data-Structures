#include <stdlib.h>

typedef struct element {
    char data;
} element;

typedef struct dynamicArr {
    int len;
    int capacity;
    element* list;
} dynamicArr;


dynamicArr *dynamicArray(int length);

element get(dynamicArr *arr, int index);

void set(dynamicArr *arr, int index, element newValue);

int length(dynamicArr *arr);

dynamicArr *removeAt(dynamicArr *arr, int index);

dynamicArr *insert(dynamicArr *arr, int index, element el);

dynamicArr *push(dynamicArr *arr, element el);

element pop(dynamicArr *arr);