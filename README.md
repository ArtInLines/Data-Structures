# Properties

| Name     | Description                                                                 |
| -------- | --------------------------------------------------------------------------- |
| Ordered  | Whether all elements in the data structure are orderd from beginning to end |
| Sorted   | Whether the elements in the data structure have to be sorted                |
| Unique   | Whether duplicate elements are allowed in the data structure                |
| Iterable | Whether one can iterate over all stored elements                            |

# Operations

Every data structure implemeted here will be judged by its implementation of the following operations and their associated time & space complexity.

| Name          | Description                                                                                             |
| ------------- | ------------------------------------------------------------------------------------------------------- |
| Instance      | Create a new instance of the data structure                                                             |
| Copy          | Copying the entire data structure                                                                       |
| Free          | Deallocating all the memory used - unnecessary for implementations with garbage collection              |
| Peek          | Accessing a specific element (usually the head / tail)                                                  |
| Random Access | Accessing an arbitrary element                                                                          |
| Push          | Adding a new element at a specific position (usually the end / beginning)                               |
| Insert        | Inserting a new element at an arbitrary position                                                        |
| Pop           | Removing and returning a specific element (usually the head / tail)                                     |
| Remove        | Removing an arbitrary element                                                                           |
| Contains      | Returns true if the specified element is contained in the data structure's instance and false otherwise |
| IndexOf       | Returns the index of the specified element - only necessary for certain data structures                 |
| Find          | Find an element in the data structure's instance using a user-defined function                          |
| Map           | Map each element to a new value using a user-defined function                                           |
| Filter        | Filter elements using a user-defined function                                                           |
| Reduce        | Reduce the collection's values to a single data type using a user-defined function                      |
| Length        | Determine the current length of the data structure's instance                                           |
