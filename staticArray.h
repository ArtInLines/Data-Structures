typedef struct el {
    char data;
} element;

typedef struct statArr {
    int len;
    element* list;
} staticArr;

int cmpElements(element el1, element el2) {
    if (el1.data == el2.data) return 1;
    else return 0;
};

// TODO: Add null_el
// TODO: Add dynamic length attribute

// Functions declared in C-File

staticArr *staticArray(int length);

staticArr *copyArr(staticArr *arr);

void freeArr(staticArr *arr);

element peek(staticArr *arr);

element get(staticArr *arr, int index);

void set(staticArr *arr, int index, element newValue);

int length(staticArr *arr);

int contains(staticArr *arr, element el);

element *find(staticArr *arr, int (*fn) (element, int, staticArr*));

int findIndex(staticArr *arr, element el, int (*fn) (element, int, staticArr*));

int findIndexOf(staticArr *arr, element el);

staticArr *map(staticArr *arr, element (*fn) (element, int, staticArr*));

staticArr *immutableMap(staticArr *arr, element (*fn) (element, int, staticArr*));

staticArr *filter(staticArr *arr, int (*fn) (element, int, staticArr*));

void *fullReduce(staticArr *arr, void* (*firstEl) (element, int, staticArr*), void* (*fn) (void*, element, int, staticArr*));

element reduce(staticArr *arr, element (*fn) (element, element, int, staticArr*));