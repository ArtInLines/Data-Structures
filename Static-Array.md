# Descrpition

A static Array is a contiguous chunk of memory.

The static Array's size is fixed in place and thus the removal/insertion of new elements is impossible. The main advantage of a static array is the constant time needed for random access. This, however, restricts all elements in the array to be the same size in memory. To store different data types in a static array, some sort of type-union is necessary.

# Main Interface

-   get index
-   set index value

# Implementation

...

# Properties

| Name     | Implementation |
| -------- | -------------- |
| Ordered  | Yes            |
| Iterable | Yes            |
| Sorted   | No             |
| Unique   | No             |

# Operations

Every data structure implemeted here will be judged by its implementation of the following operations and their associated time & space complexity.

| Name          | Time / Space Complexity | Aliases | Notes                                         |
| ------------- | ----------------------- | ------- | --------------------------------------------- |
| Instance      | -                       | -       | -                                             |
| Copy          | O(n)                    | -       | -                                             |
| Free          | -                       | -       | -                                             |
| Peek          | O(1)                    | -       | -                                             |
| Random Access | O(1)                    | -       | -                                             |
| Push          | O(1)                    | -       | Only possible, if there's still space avaible |
| Insert        | O(n)                    | -       | Only possible, if there's still space avaible |
| Pop           | O(1)                    | -       | -                                             |
| Remove        | O(n)                    | -       | -                                             |
| Contains      | O(n)                    | -       | -                                             |
| IndexOf       | O(n)                    | -       | -                                             |
| Find          | O(n)                    | -       | -                                             |
| Map           | O(n)                    | -       | -                                             |
| Filter        | O(n)                    | -       | -                                             |
| Reduce        | O(n)                    | -       | -                                             |
| Length        | O(1)                    | -       | Recalculating the length takes O(n)           |
