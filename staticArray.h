typedef struct el {
    char data;
} element;

typedef struct statArr {
    int len;
    element* list;
} staticArr;


staticArr staticArray(int length);

element get(staticArr arr, int index);

void set(staticArr arr, int index, element newValue);

int length(staticArr arr);