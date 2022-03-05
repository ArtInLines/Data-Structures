#include <stdlib.h>
#include "staticArray.h";

// For typedefs see header file


staticArr *staticArray(int length) {
    staticArr *arr = malloc(sizeof(staticArr));
    arr->list = malloc((length+1) * sizeof(element));
    arr->len = length;
    return arr;
}

staticArr *copyArr(staticArr *arr) {
    staticArr *newArr = staticArray(arr->len);
    for (int i = 0; i < arr->len; i++) newArr->list[i] = arr->list[i];
    return newArr;
}

void freeArr(staticArr *arr) {
    free(arr->list);
    free(arr);
}

element get(staticArr *arr, int index) {
    return arr->list[index];
}

void set(staticArr *arr, int index, element newValue) {
    arr->list[index+1] = newValue;
}

int length(staticArr *arr) {
    return arr->len;
}

element *find(staticArr *arr, int (*fn) (element, int, staticArr*)) {
    for (int i = 0; i < arr->len; i++) {
        if (fn(arr->list[i], i, arr)) return &arr->list[i];
    }
    return NULL;
}

int findIndex(staticArr *arr, element el, int (*fn) (element, int, staticArr*)) {
    for (int i = 0; i< arr->len; i++) {
        if (fn(arr->list[i], i, arr)) return i;
    }
    return -1;
}

int findIndexOf(staticArr *arr, element el) {
    for (int i = 0; i < arr->len; i++) {
        if (arr->list[i].data == el.data) return i;
    }
    return -1;
}

