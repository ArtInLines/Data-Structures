#ifndef ELEMENT_H
#define ELEMENT_H

typedef struct element {
    int data;
} element;

element El_getNull();

int El_isInvalid(element *el);

int El_eq(element *el1, element *el2);

int El_lt(element *el1, element *el2);

int El_gt(element *el1, element *el2);

int El_lte(element *el1, element *el2);

int El_gte(element *el1, element *el2);

int El_stringify(element *el, char *s);

int El_stringifyCapacity();

#endif // ELEMENT_H



#ifdef ELEMENT_IMPLEMENTATION

#ifndef INT_MAX
#include <limits.h>
#endif

#ifndef sprintf
#include <stdio.h>
#endif

element NULL_EL = {INT_MAX};

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

int El_lte(element *el1, element *el2){
	return (El_eq(el1, el2) || El_lt(el1, el2));
}

int El_gte(element *el1, element *el2) {
	return (El_eq(el1, el2) || El_gt(el1, el2));
}

int El_stringifyCapacityVal = 5;

int El_stringifyCapacity() {
	return El_stringifyCapacityVal;
}

// See: http://www.cplusplus.com/reference/cstdio/snprintf/
int El_stringify(element *el, char *s) {
	int formatVal = sprintf(s, "%i", el->data);
	return formatVal;
}

#endif // ELEMENT_IMPLEMENTATION