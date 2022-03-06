#include <stdlib.h>
#include "element.h"
#include "dynamicArray.h"

// For typedefs see header file

dynamicArr *dynamicArray(int length) {
    dynamicArr *arr = malloc(sizeof(dynamicArr));
    arr->len = length;
    arr->capacity = length;
    arr->list = malloc((length+1) * sizeof(element));
    return arr;
}

element peek(dynamicArr *arr) {
    return get(arr, 0);
}

element get(dynamicArr *arr, int index) {
    return arr->list[index];
}

void set(dynamicArr *arr, int index, element newValue) {
    arr->list[index] = newValue;
}

int length(dynamicArr *arr) {
    return arr->len;
}

dynamicArr *removeAt(dynamicArr *arr, int index) {
    arr->len--;
    if (arr->capacity >= 2 * arr->len) {
        dynamicArr *newArr = dynamicArray(arr->len);
        int i;
        for (i = 0; i < index; i++) newArr->list[i] = arr->list[i];
        for (i = index; i < arr->len; i++) newArr->list[i] = arr->list[i+1];
        
        free(arr->list);
        free(&arr);
        return newArr;
    } else {
        for (int i = index; i < arr->len; i++) arr->list[i] = arr->list[i+1];
        return arr;
    }
}

dynamicArr *insert(dynamicArr *arr, int index, element el) {
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
        free(&arr);
        return newArr;
    }
}

dynamicArr *push(dynamicArr *arr, element el) {
    return insert(arr, arr->len, el);
}

element pop(dynamicArr *arr) {
    element el = arr->list[arr->len-1];
    removeAt(arr, arr->len-1);
    return el;
}

int contains(dynamicArr *arr, element el) {
    for (int i = 0; i < arr->len; i++) {
        if (cmpEl(arr->list[i], el)) return 1;
    }
    return 0;
}

int indexOf(dynamicArr *arr, element el) {
    for (int i = 0; i < arr->len; i++) {
        if (cmpEl(arr->list[i], el)) return i;
    }
    return -1;
}

int findIndexOf(dynamicArr *arr, int (*fn) (element, int, dynamicArr*)) {
    for (int i = 0; i < arr->len; i++) {
        if (fn(arr->list[i], i, arr)) return i;
    }
    return -1;
}

element *find(dynamicArr *arr, int (*fn) (element, int, dynamicArr*)) {
    for (int i = 0; i < arr->len; i++) {
        if (fn(arr->list[i], i, arr)) return &arr->list[i];
    }
    return NULL;
}

dynamicArr *map(dynamicArr *arr, element (*fn) (element, int, dynamicArr*)) {
    for (int i = 0; i < arr->len; i++) {
        arr->list[i] = fn(arr->list[i], i, arr);
    }
    return arr;
}

dynamicArr *immutableMap(dynamicArr *arr, element (*fn) (element, int, dynamicArr*)) {
    dynamicArr *newArr = dynamicArray(arr->len);
    for (int i = 0; i < arr->len; i++) {
        newArr->list[i] = fn(arr->list[i], i, arr);
    }
    return newArr;
}

dynamicArr *filter(dynamicArr *arr, int (*fn) (element, int, dynamicArr*)) {
    // TODO
}

element reduce(dynamicArr *arr, element (*fn) (element, element, int, dynamicArr*)) {
    // TODO
}

void *fullReduce(dynamicArr *arr, void* (*firstEl) (element, int, dynamicArr*), void* (*fn) (element, element, int, dynamicArr*)) {
    // TODO
}