#include "element.h"
#include <stdlib.h>


const element NULL_EL = {INT_MAX};


element El_getNull() {
    return NULL_EL;
}

int El_isInvalid(element *el) {
    return El_eq(el, &NULL_EL);
}

int El_eq(element *el1, element *el2) {
    return (el1->data == el2->data);
}

int El_lt(element *el1, element *el2) {
    return (el1->data < el2->data);
}

int El_gt(element *el1, element *el2) {
    return (el1->data > el2->data);
}

int EL_lte(element *el1, element *el2){
    return (El_eq(el1, el2) || El_lt(el1, el2));
}

int EL_gte(element *el1, element *el2) {
    return (El_eq(el1, el2) || El_gt(el1, el2));
}