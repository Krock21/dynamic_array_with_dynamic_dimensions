# dynamic_array_with_dynamic_dimensions
Dynamic array with dynamic dimensions on C++

Simple dynamic array of dynamic dimensions.

Let's say that D is number of dimensions and N is number of elements.

Then, with D = 1 we have arr = ```[element1, element2, ..., elementN]```

Then, with D = 2 we have arr = 

    [
         [element1, element2, ..., elementN]_1, 
         [element1, element2, ..., elementN]_2,
         ...,
         [element1, element2, ..., elementN]_N
     ]

And so on

Simple initialize function initializes array by strings with indicies of array.

With D = 2 we have arr =

    [
        [00, 01, ..., 0n],
        [10, 11, ..., 1n],
        ...,
        [n0, n1, ..., nn],
    ]

Simple print functions prints to stdout array in special format:

    DIMENSION NUMBER:
    SUBARRAY [0]
    SUBARRAY [1]
    SUBARRAY ...
    SUBARRAY [N]
