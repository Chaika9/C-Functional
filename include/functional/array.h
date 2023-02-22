/**
 * @file array.h
 * @brief It contains the functions to work with arrays.
 * @note It's for test purposes only.
*/

#ifndef FUNCTIONAL_ARRAY_H_
    #define FUNCTIONAL_ARRAY_H_

    #include "auto.h"
    #include <stddef.h>
    #include <stdbool.h>

    #define __fmap__(function, array) \
        ({ \
        for (size_t __i__ = 0; __i__ < sizeof(array) / sizeof(array[0]); __i__++) \
            array[__i__] = function(array[__i__]); \
        })

    #define __foldl__(function, array, initial) \
        ({ \
        auto __acc__ = initial; \
        for (size_t __i__ = 0; __i__ < sizeof(array) / sizeof(array[0]); __i__++) \
            __acc__ = function(__acc__, array[__i__]); \
        __acc__; \
        })

    #define __foldr__(function, array, initial) \
        ({ \
        auto __acc__ = initial; \
        for (int __i__ = sizeof(array) / sizeof(array[0]) - 1; __i__ >= 0; __i__--) \
            __acc__ = function(array[__i__], __acc__); \
        __acc__; \
        })

    #define __elem__(element, array) \
        ({ \
        bool __is_element_of__ = false; \
        for (size_t __i__ = 0; __i__ < sizeof(array) / sizeof(array[0]); __i__++) \
            if (array[__i__] == element) { \
                __is_element_of__ = true; \
                break; \
            } \
        __is_element_of__; \
        })

    /**
     * @brief It applies the function to each element of the array.
     * @param function function to apply to each element of the array.
     * @param array array to apply the function to each element of it.
     *
     * @code Example of usage
     * int array[] = {1, 2, 3, 4, 5};
     * fmap(lambda(int, (int x) { return x * x; }), array); // Result: {1, 4, 9, 16, 25}
     * @endcode
    */
    #define fmap __fmap__

    /**
     * @brief It takes the second argument and the first item of the list and applies the function to them,
     * then feeds the function with this result and the second argument and so on.
     * @param function function to apply to each element of the array.
     * @param array array to apply the function to each element of it.
     * @param initial initial value of the accumulator.
     * @return the final value of the accumulator.
     * @note foldl is a left fold (folds from left to right).
     *
     * @code Example of usage
     * float array[] = {4.0f, 2.0f, 4.0f};
     * float sum = foldl(lambda(float, (float acc, float element) { return acc / element; }), array, 64.0f);
     * printf("%f", sum); // Result: 2.000000
     * @endcode
    */
    #define foldl __foldl__

    /**
     * @exemple foldl
     * @brief It takes the second argument and the last item of the list and applies the function,
     * then it takes the penultimate item from the end and the result, and so on.
     * @param function function to apply to each element of the array.
     * @param array array to apply the function to each element of it.
     * @param initial initial value of the accumulator.
     * @return the final value of the accumulator.
     * @note foldr is a right fold (folds from right to left).
     *
     * @code Example of usage
     * float array[] = {8.0f, 12.0f, 24.0f, 4.0f};
     * float sum = foldr(lambda(float, (float acc, float element) { return acc / element; }), array, 2.0f);
     * printf("%f", sum); // Result: 8.000000
     * @endcode
    */
    #define foldr __foldr__

    /**
     * @brief It checks if the element is an element of the array.
     * @param element element to check if it is an element of the array.
     * @param array array to check if the element is an element of it.
     * @return true if the element is an element of the array, false otherwise.
     *
     * @code Example of usage
     * int array[] = {1, 2, 3, 4, 5};
     * bool is_element_of = elem(3, array);
     * printf("%s", is_element_of ? "true" : "false"); // Result: true
    */
    #define elem __elem__

#endif
