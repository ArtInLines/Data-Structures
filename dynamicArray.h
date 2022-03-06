typedef struct dynamicArr {
    int len;
    int capacity;
    element* list;
} dynamicArr;

// Functions defined in C-File

dynamicArr *dynamicArray(int length);

element get(dynamicArr *arr, int index);

void set(dynamicArr *arr, int index, element newValue);

int length(dynamicArr *arr);

dynamicArr *removeAt(dynamicArr *arr, int index);

dynamicArr *insert(dynamicArr *arr, int index, element el);

dynamicArr *push(dynamicArr *arr, element el);

element pop(dynamicArr *arr);

element peek(dynamicArr *arr);

element get(dynamicArr *arr, int index) {
    return arr->list[index];
}

int contains(dynamicArr *arr, element el);

int indexOf(dynamicArr *arr, element el);

int findIndexOf(dynamicArr *arr, int (*fn) (element, int, dynamicArr*));

element *find(dynamicArr *arr, int (*fn) (element, int, dynamicArr*));

dynamicArr *map(dynamicArr *arr, element (*fn) (element, int, dynamicArr*));

dynamicArr *immutableMap(dynamicArr *arr, element (*fn) (element, int, dynamicArr*));

dynamicArr *filter(dynamicArr *arr, int (*fn) (element, int, dynamicArr*));

element reduce(dynamicArr *arr, element (*fn) (element, element, int, dynamicArr*));

void *fullReduce(dynamicArr *arr, void* (*firstEl) (element, int, dynamicArr*), void* (*fn) (element, element, int, dynamicArr*));