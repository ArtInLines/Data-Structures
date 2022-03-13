#include "element.h"
#include "util.h"

void util_swapElements(element *el1, element *el2) {
    element tmp = *el1;
    *el1 = *el2;
    *el2 = tmp;
}