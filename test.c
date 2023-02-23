#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ELEMENT_IMPLEMENTATION
#include "element.h"
#include "staticArray.h"
#include "dynamicArray.h"
#include "binaryHeap.h"

/*
To compile:
gcc test.c element.c util.c staticArray.c dynamicArray.c binaryHeap.c -o test
*/

element myMap(element el, int i, staticArr *arr) {
    element newEl;
    newEl.data = i+1;
    return newEl;
}

element myReduce(element el1, element el2, int i, staticArr *arr) {
    element new;
    new.data = el1.data + el2.data;
    return new;
}


void test_dynArr() {
    char s[1000];
    int res;
    element el;
    binaryHeap *A = dynArr_new(0);
    int arr[9] = {1, 2, 3, 7, 4, 5, 6, 10, 22};

    for (int i = 0; i < 9; i++) {
        el.data = arr[i];
        dynArr_push(&A, el);
        printf("Length: %i, Capacity: %i\n", A->len, A->capacity);

        dynArr_stringify(A, s);
        printf("[%s]\n", s);
    }

    el.data = 0;
    dynArr_insert(&A, 0, el);
    printf("Length: %i, Capacity: %i\n", A->len, A->capacity);
    dynArr_stringify(A, s);
    printf("[%s]\n", s);

    dynArr_pop(&A);
    printf("Length: %i, Capacity: %i\n", A->len, A->capacity);
    dynArr_stringify(A, s);
    printf("[%s]\n", s);

    dynArr_removeAt(&A, 1);
    printf("Length: %i, Capacity: %i\n", A->len, A->capacity);
    dynArr_stringify(A, s);
    printf("[%s]\n", s);

    el.data = 10;
    res = dynArr_contains(A, el);
    printf("Contains %i? %i\n", el.data, res);

    el.data = -1;
    res = dynArr_contains(A, el);
    printf("Contains %i? %i\n", el.data, res);

    el.data = 7;
    res = dynArr_indexOf(A, el);
    printf("Index of %i? %i\n", el.data, res);
}


void test_binHeap() {
    char s[1000];
    element el;
    binaryHeap *A = binHeap_new(2);
    int arr[9] = {7, 10, 1, 5, 2, 6, 3, 0, 4};

    for (int i = 0; i < 9; i++) {
        el.data = arr[i];
        binHeap_insert(&A, el);

        binHeap_stringify(A, s);
        printf("%s\n\n", s);
    }

    el.data = 2;
    binHeap_insert(&A, el);
    binHeap_stringify(A, s);
    printf("%s\n\n", s);

    binHeap_poll(&A);
    binHeap_stringify(A, s);
    printf("%s\n\n", s);

    binHeap_poll(&A);
    binHeap_stringify(A, s);
    printf("%s\n\n", s);

    binHeap_remove(&A, 1);
    binHeap_stringify(A, s);
    printf("%s\n\n", s);

    el.data = 35;
    binHeap_replace(&A, 3, el);
    binHeap_stringify(A, s);
    printf("%s\n\n", s);
}


int main() {
    test_dynArr();
    printf("\n\n");
    test_binHeap();
	return 0;
}