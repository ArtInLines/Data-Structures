#include <stdlib.h>
#include "dynamicArray.h";

// For typedefs see header file

dynamicArr *dynamicArray(int length) {
    dynamicArr *arr = malloc(sizeof(dynamicArr));
    arr->len = length;
    arr->capacity = length;
    arr->list = malloc((length+1) * sizeof(element));
    return arr;
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