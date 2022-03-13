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

// Stringify

int El_stringify(element *el, char *s);

int El_stringifyCapacity();