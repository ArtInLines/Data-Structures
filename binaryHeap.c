#include <stdlib.h>
#include "element.h"
#include "util.h"
#include "dynamicArray.h"
#include "binaryHeap.h"

// See https://en.wikipedia.org/wiki/Heap_(data_structure)#Implementation for many explanations

element binHeap_min(binaryHeap *A) {
    return get(A, 0);
}

element binHeap_max(binaryHeap *A) {
    return get(A, A->len-1);
}

element binHeap_get(binaryHeap *A, int index) {
    return A->list[index];
}

int binHeap_size(dynamicArr *A) {
    return A->len;
}

int binHeap_isEmpty(dynamicArr *A) {
    return A->len == 0;
}

// TO ADD:

// Sift up
// Sift down
// Insert
// Replace
// Remove
// popMin aka extraxtMin
// popMax aka extractMax

int binHeap_getChildIndex(int index) {
    return 2*index + 1;
}

int binHeap_getParentIndex(int index) {
    return (int) (index - 1) / 2;
}

void binHeap_switchPositions(binaryHeap *A, int i, int j) {
    swapElements(&A->list[i], &A->list[j]);
}
