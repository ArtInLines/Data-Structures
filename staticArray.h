typedef struct staticArr {
    int len;
    int capacity;
    element* list;
} staticArr;

// TODO: Add dynamic length attribute

// Functions declared in C-File

staticArr *statArr_new(int length);

staticArr *statArr_init(int length, element *elements);

staticArr *statArr_copyArr(staticArr *arr);

void statArr_free(staticArr *arr);

element statArr_peek(staticArr *arr);

element statArr_get(staticArr *arr, int index);

void statArr_set(staticArr *arr, int index, element newValue);

int statArr_length(staticArr *arr);

int statArr_recalcLength(staticArr *arr);

int statArr_contains(staticArr *arr, element el);

element *statArr_find(staticArr *arr, int (*fn) (element, int, staticArr*));

int statArr_findIndex(staticArr *arr, int (*fn) (element, int, staticArr*));

int statArr_findIndexOf(staticArr *arr, element el);

staticArr *statArr_map(staticArr *arr, element (*fn) (element, int, staticArr*));

staticArr *statArr_immutableMap(staticArr *arr, element (*fn) (element, int, staticArr*));

staticArr *statArr_filter(staticArr *arr, int (*fn) (element, int, staticArr*));

staticArr *statArr_immutableFilter(staticArr *arr, int (*fn) (element, int, staticArr*));

void *statArr_fullReduce(staticArr *arr, void* (*firstEl) (element, int, staticArr*), void* (*fn) (void*, element, int, staticArr*));

element statArr_reduce(staticArr *arr, element (*fn) (element, element, int, staticArr*));