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

element peek(staticArr *arr) {
    return arr->list[0];
}

element get(staticArr *arr, int index) {
    return arr->list[index];
}

void set(staticArr *arr, int index, element newValue) {
    arr->list[index+1] = newValue;
}

int length(staticArr *arr) {
    // TODO: Change length attribute to be dynamic
    // TODO: Add a capacity attribute to achieve that
    return arr->len;
}

int contains(staticArr *arr, element el) {
    for (int i = 0; i < arr->len; i++) {
        if (cmpElements(arr->list[i], el)) return 1;
    }
    return 0;
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

staticArr *map(staticArr *arr, element (*fn) (element, int, staticArr*)) {
    for (int i = 0; i < arr->len; i++) {
        arr->list[i] = fn(arr->list[i], i, arr);
    }
    return arr;
}

staticArr *immutableMap(staticArr *arr, element (*fn) (element, int, staticArr*)) {
    staticArr *newArr = staticArray(arr->len);
    for (int i = 0; i < arr->len; i++) {
        newArr->list[i] = fn(arr->list[i], i, arr);
    }
    return newArr;
}

staticArr *filter(staticArr *arr, int (*fn) (element, int, staticArr*)) {
    // TODO: Implement once there is a dynamic length attribute!
}

void *fullReduce(staticArr *arr, void* (*firstEl) (element, int, staticArr*), void* (*fn) (void*, element, int, staticArr*)) {
    void *ptr = firstEl(arr->list[0], 0, arr);
    for (int i = 1; i < arr->len; i++) {
        ptr = fn(ptr, arr->list[i], i, arr);
    }
    return ptr;
}

element reduce(staticArr *arr, element (*fn) (element, element, int, staticArr*)) {
    element el = arr->list[0];
    for (int i = 1; i < arr->len; i++) {
        el = fn(el, arr->list[i], i, arr);
    }
    return el;
}