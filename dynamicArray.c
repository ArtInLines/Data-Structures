#include <stdlib.h>
#include "element.h"
#include "dynamicArray.h"

// For typedefs see header file

dynamicArr *dynArr_new(int length) {
    dynamicArr *arr = malloc(sizeof(dynamicArr));
    arr->len = length;
    arr->capacity = length;
    arr->list = malloc((length+1) * sizeof(element));
    return arr;
}

element dynArr_peek(dynamicArr *arr) {
    return dynArr_get(arr, 0);
}

element dynArr_get(dynamicArr *arr, int index) {
    return arr->list[index];
}

element *dynArr_getRef(dynamicArr *arr, int index) {
    return &arr->list[index];
}

void dynArr_set(dynamicArr *arr, int index, element newValue) {
    arr->list[index] = newValue;
}

int dynArr_length(dynamicArr *arr) {
    return arr->len;
}

dynamicArr *dynArr_removeAt(dynamicArr *arr, int index) {
    arr->len--;
    if (arr->capacity >= 2 * arr->len) {
        dynamicArr *newArr = dynArr_new(arr->len);
        int i;
        for (i = 0; i < index; i++) newArr->list[i] = arr->list[i];
        for (i = index; i < arr->len; i++) newArr->list[i] = arr->list[i+1];
        
        free(arr->list);
        free(arr);
        return newArr;
    } else {
        for (int i = index; i < arr->len; i++) arr->list[i] = arr->list[i+1];
        return arr;
    }
}

dynamicArr *dynArr_insert(dynamicArr *arr, int index, element el) {
    if (arr->capacity > arr->len) {
        arr->len++;
        for (int i = index; i < arr->len; i++) arr->list[i+1] = arr->list[i];
        arr->list[index] = el;
        return arr;
    } else {   
        dynamicArr *newArr = malloc(sizeof(dynamicArr));
        newArr->capacity = arr->capacity * 2;
        newArr->len = arr->len+1;
        int i;
        for (i = 0; i < index; i++) newArr->list[i] = arr->list[i];
        newArr->list[index] = el;
        for (i = index; i < arr->len; i++) newArr->list[i+1] = arr->list[i];
        
        free(arr->list);
        free(arr);
        return newArr;
    }
}

dynamicArr *dynArr_push(dynamicArr *arr, element el) {
    return insert(arr, arr->len, el);
}

element dynArr_pop(dynamicArr *arr) {
    element el = arr->list[arr->len-1];
    dynArr_removeAt(arr, arr->len-1);
    return el;
}

int dynArr_contains(dynamicArr *arr, element el) {
    for (int i = 0; i < arr->len; i++) {
        if (El_eq(&arr->list[i], &el)) return 1;
    }
    return 0;
}

int dynArr_indexOf(dynamicArr *arr, element el) {
    for (int i = 0; i < arr->len; i++) {
        if (El_eq(&arr->list[i], &el)) return i;
    }
    return -1;
}

int dynArr_findIndexOf(dynamicArr *arr, int (*fn) (element, int, dynamicArr*)) {
    for (int i = 0; i < arr->len; i++) {
        if (fn(arr->list[i], i, arr)) return i;
    }
    return -1;
}

element *dynArr_find(dynamicArr *arr, int (*fn) (element, int, dynamicArr*)) {
    for (int i = 0; i < arr->len; i++) {
        if (fn(arr->list[i], i, arr)) return &arr->list[i];
    }
    return NULL;
}

dynamicArr *dynArr_map(dynamicArr *arr, element (*fn) (element, int, dynamicArr*)) {
    for (int i = 0; i < arr->len; i++) {
        arr->list[i] = fn(arr->list[i], i, arr);
    }
    return arr;
}

dynamicArr *dynArr_immutableMap(dynamicArr *arr, element (*fn) (element, int, dynamicArr*)) {
    dynamicArr *newArr = dynArr_new(arr->len);
    for (int i = 0; i < arr->len; i++) {
        newArr->list[i] = fn(arr->list[i], i, arr);
    }
    return newArr;
}

dynamicArr *dynArr_filter(dynamicArr *arr, int (*fn) (element, int, dynamicArr*)) {
    // TODO
}

element dynArr_reduce(dynamicArr *arr, element (*fn) (element, element, int, dynamicArr*)) {
    // TODO
}

void *dynArr_fullReduce(dynamicArr *arr, void* (*firstEl) (element, int, dynamicArr*), void* (*fn) (element, element, int, dynamicArr*)) {
    // TODO
}