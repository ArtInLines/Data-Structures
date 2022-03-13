# Descrpition

A dynamic Array is a contiguous chunk of memory, with the ability to change its size.

This specification of a dynamic Array is implemented using static Arrays. Thus, random access is stil guaranteed, as well as the ability to increase/decrease in size.

# Interface

-   normal Array interface

# Main Implementation

Dynamic Arrays are Static Arrays, that can, when needed, increase or decrease in size. To do this, a new static array with a bigger/smaller length is created, which then gets all values of the old array copied into.

# Properties

| Name     | Implementation |
| -------- | -------------- |
| Iterable | Yes            |
| Ordered  | Yes            |
| Sorted   | No             |
| Unique   | No             |

# Operations

Every data structure implemeted here will be judged by its implementation of the following operations and their associated time & space complexity.

| Name          | Big O | Aliases | Notes |
| ------------- | ----- | ------- | ----- |
| Instance      | -     | -       | -     |
| Copy          | O(n)  | -       | -     |
| Free          | -     | -       | -     |
| Peek          | O(1)  | -       | -     |
| Random Access | O(1)  | -       | -     |
| Set Element   | O(1)  | -       | -     |
| Push          | O(n)  | -       | -     |
| Insert        | O(n)  | -       | -     |
| Pop           | O(n)  | -       | -     |
| Remove        | O(n)  | -       | -     |
| Contains      | O(n)  | -       | -     |
| IndexOf       | O(n)  | -       | -     |
| Find          | O(n)  | -       | -     |
| Map           | O(n)  | -       | -     |
| Filter        | O(n)  | -       | -     |
| Reduce        | O(n)  | -       | -     |
| Length        | O(1)  | -       | -     |
