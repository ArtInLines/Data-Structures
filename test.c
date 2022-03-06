#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "element.h"
#include "staticArray.h"
#include "dynamicArray.h"


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


void main() {
    int len = 100;
    staticArr *statArr = statArr_new(len);
    statArr_map(statArr, myMap);
    
    srand(time(NULL));
    printf("Some random elements in the array: %i - %i - %i\n", statArr_get(statArr, rand() % len).data, statArr_get(statArr, rand() % len).data, statArr_get(statArr, rand() % len).data);
    
    printf("Reduced: %i\n", statArr_reduce(statArr, myReduce).data);
    statArr_free(statArr);
}