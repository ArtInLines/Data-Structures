#include <stdlib.h>
#include "element.h"
#include "util.h"
#include "dynamicArray.h"
#include "binaryHeap.h"

// See https://en.wikipedia.org/wiki/Heap_(data_structure)#Implementation for many explanations
// as well as https://youtu.be/RBSGKlAvoiM?t=5492

element binHeap_peek(binaryHeap *A) {
    return dynArr_get(A, 0);
}

element binHeap_poll(binaryHeap *A) {
    return binHeap_remove(A, 0);
}

element binHeap_get(binaryHeap *A, int index) {
    return dynArr_get(A, index);
}

int binHeap_size(dynamicArr *A) {
    return dynArr_length(A);
}

int binHeap_isEmpty(dynamicArr *A) {
    return dynArr_length(A) == 0;
}

int binHeap_lastLeafIndex(binaryHeap *A) {
    return dynArr_length(A) - 1;
}

// Returns element that was removed
element binHeap_remove(binaryHeap *A, int index) {
    binHeap_switchPositions(A, index, binHeap_lastLeafIndex(A));
    element res = dynArr_pop(A);
    binHeap_fullSiftdown(A, index);
    return res;
}

// Returns new index, that node ends up at
int binHeap_insert(binaryHeap *A, element node) {
    dynArr_push(A, node);
    return binHeap_fullSiftup(A, binHeap_lastLeafIndex(A));
}

// Faster than removing old element and then inserting new element
    // because the heap balance only has to be created once
    // and especially because the size of heap doesn't change, meaning the underlying dynamic array doesn't have to resize, which could be costly
// Returns new index, that node ends up at
int binHeap_replace(binaryHeap *A, int index, element node) {
    dynArr_set(A, index, node);
    if (index > 0 && El_lt(&node, &A->list[binHeap_getParentIndex(index)])) {
        return binHeap_fullSiftup(A, index);
    }
    else {
        return binHeap_fullSiftdown(A, index);
    }
}

// Siftup and siftdown use -1 for a natural end and other negative numbers for other ends (e.g. -2 means, there is no child/parent node)
// Usually simply checking if the return value is negative is all that is required to do

int binHeap_fullSiftup(binaryHeap *A, int index) {
    // index > 0 instead of >= 0, because we can't sift up further when we reached the top already
    while (index > 0) index = binHeap_siftup(A, index);
    return index;
}

int binHeap_siftup(binaryHeap *A, int index) {
    // Check if node is smaller than parent
    // If so switch node with parent
    // return -1 for no swap or new index otherwise
    int parentIndex = binHeap_getParentIndex(index);
    if (parentIndex < 0) return -2;
    if (El_gte(&A->list[index], &A->list[parentIndex])) return -1;
    binHeap_switchPositions(A, index, parentIndex);
    return parentIndex;
}

int binHeap_fullSiftdown(binaryHeap *A, int index) {
    // index >= 0, because we want to sift down until -1 is returned
    while (index >= 0) index = binHeap_siftdown(A, index);
    return index;
}

int binHeap_siftdown(binaryHeap *A, int index) {
    // Select smaller child node (default selecting left when there's a tie)
    // Check if parent is greater than selected child
    // If so switch parent with child
    // return -1 for no swap or new index otherwise
    int lastIndex, left, right, childIndex;
    lastIndex = binHeap_lastLeafIndex(A);
    left = binHeap_getLeft(index);
    if (left > lastIndex) return -2; // Only need to check for left child, because right child can't exist without left child
    right = binHeap_getRightChildIndex(index);
    childIndex = left; 
    if (right <= lastIndex) childIndex = El_lte(&A->list[left], &A->list[right]) ? left : right;
    
    if (El_lte(&A->list[index], &A->list[childIndex])) return -1;
    binHeap_switchPositions(A, index, childIndex);
    return childIndex;
}

// Get index functions aren't checking, whether there even is an element at that index, so that must be checked in any function using these methods!

int binHeap_getLeftChildIndex(int index) {
    return 2*index + 1;
}

int binHeap_getRightChildIndex(int index) {
    return 2*index + 2;
}

int binHeap_getParentIndex(int index) {
    return (int) (index - 1) / 2;
}

void binHeap_switchPositions(binaryHeap *A, int i, int j) {
    util_swapElements(&A->list[i], &A->list[j]);
}

int binHeap_contains(binaryHeap *A, element el) {
    return dynArr_contains(A, el);
}

int binHeap_indexOf(binaryHeap *A, element el) {
    return dynArr_indexOf(A, el);
}

int binHeap_findIndexOf(binaryHeap *A, int (*fn) (element, int, binaryHeap*)) {
    return dynArr_findIndexOf(A, fn);
}

element *binHeap_find(binaryHeap *A, int (*fn) (element, int, binaryHeap*)) {
    return dynArr_find(A, fn);
}