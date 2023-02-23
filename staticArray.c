#include <stdlib.h>
#include "element.h"
#include "staticArray.h"

// For typedefs see header file

staticArr *statArr_new(int length) {
    staticArr *arr = malloc(sizeof(staticArr));
    arr->list = malloc((length+1) * sizeof(element));
    arr->capacity = length;
    arr->len = 0;
    return arr;
}

staticArr *statArr_init(int length, element *elements) {
    staticArr *arr = statArr_new(length);
    int i = 0;
    while (i < length && !El_isInvalid(&elements[i])) {
        arr->list[i] = elements[i];
        i++;
    }
    arr->len = i+1;
    return arr;
}

staticArr *statArr_copy(staticArr *arr) {
    staticArr *newArr = statArr_new(arr->len);
    for (int i = 0; i < arr->len; i++) newArr->list[i] = arr->list[i];
    return newArr;
}

void statArr_free(staticArr *arr) {
    free(arr->list);
    free(arr);
}

element statArr_peek(staticArr *arr) {
    return statArr_get(arr, 0);
}

element statArr_get(staticArr *arr, int index) {
    return arr->list[index];
}

void statArr_set(staticArr *arr, int index, element newValue) {
    arr->list[index] = newValue;
    if (arr->len <= index) arr->len = index+1;
}

int statArr_length(staticArr *arr) {
    return arr->len;
}

int statArr_recalcLength(staticArr *arr) {
    int i = 0;
    while (i < arr->capacity && !El_isInvalid(&arr->list[i])) i++;
    arr->len = i;
    return arr->len;
}

int statArr_contains(staticArr *arr, element el) {
    for (int i = 0; i < arr->len; i++) {
        if (El_eq(&arr->list[i], &el)) return 1;
    }
    return 0;
}

element *statArr_find(staticArr *arr, int (*fn) (element, int, staticArr*)) {
    for (int i = 0; i < arr->len; i++) {
        if (fn(arr->list[i], i, arr)) return &arr->list[i];
    }
    return NULL;
}

int statArr_findIndex(staticArr *arr, int (*fn) (element, int, staticArr*)) {
    for (int i = 0; i< arr->len; i++) {
        if (fn(arr->list[i], i, arr)) return i;
    }
    return -1;
}

int statArr_findIndexOf(staticArr *arr, element el) {
    for (int i = 0; i < arr->len; i++) {
        if (arr->list[i].data == el.data) return i;
    }
    return -1;
}

staticArr *statArr_map(staticArr *arr, element (*fn) (element, int, staticArr*)) {
    for (int i = 0; i < arr->len; i++) {
        arr->list[i] = fn(arr->list[i], i, arr);
    }
    return arr;
}

staticArr *statArr_immutableMap(staticArr *arr, element (*fn) (element, int, staticArr*)) {
    staticArr *newArr = statArr_new(arr->len);
    for (int i = 0; i < arr->len; i++) {
        newArr->list[i] = fn(arr->list[i], i, arr);
    }
    return newArr;
}

staticArr *statArr_filter(staticArr *arr, int (*fn) (element, int, staticArr*)) {
    int i, j;
    for (i = j = 0; i < arr->len; i++) {
        if (fn(arr->list[i], i, arr)) {
            arr->list[j] = arr->list[i];
            j++;
        }
    }
    arr->len = j+1;
    arr->list[arr->len] = El_getNull();
    return arr;
}

staticArr *statArr_immutableFilter(staticArr *arr, int (*fn) (element, int, staticArr*)) {
    staticArr *newArr = statArr_new(arr->capacity);
    int i, j;
    for (i = j = 0; i < arr->len; i++) {
        if (fn(arr->list[i], i, arr)) {
            newArr->list[j] = arr->list[i];
            j++;
        }
    }
    newArr->len = j+1;
    newArr->list[newArr->len] = El_getNull();
    return newArr;
}

void *statArr_fullReduce(staticArr *arr, void* (*firstEl) (element, int, staticArr*), void* (*fn) (void*, element, int, staticArr*)) {
    void *ptr = firstEl(arr->list[0], 0, arr);
    for (int i = 1; i < arr->len; i++) {
        ptr = fn(ptr, arr->list[i], i, arr);
    }
    return ptr;
}

element statArr_reduce(staticArr *arr, element (*fn) (element, element, int, staticArr*)) {
    element el = arr->list[0];
    for (int i = 1; i < arr->len; i++) {
        el = fn(el, arr->list[i], i, arr);
    }
    return el;
}