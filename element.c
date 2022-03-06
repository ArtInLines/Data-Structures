#include "element.h"
#include <stdlib.h>


const element NULL_EL = {INT_MAX};


element getNullEL() {
    return NULL_EL;
}

int isInvalidEl(element el) {
    return cmpElements(el, NULL_EL);
}

int cmpElements(element el1, element el2) {
    return (el1.data == el2.data);
}