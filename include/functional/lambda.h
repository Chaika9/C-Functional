/**
 * @file lambda.h
 * @brief Lambda function.
 * @note It's for test purposes only.
*/

#ifndef FUNCTIONAL_LAMBDA_H_
    #define FUNCTIONAL_LAMBDA_H_

    #define __lambda__(return_type, function_body) \
        ({ \
        return_type __fn__ function_body; \
        __fn__; \
        })

    /**
     * @brief Lambda function.
     * @param return_type Return type of the lambda function.
     * @param function_body Body of the lambda function.
     * @return Lambda function pointer.
     *
     * @code Example of usage
     * auto add = lambda(int, (int a, int b) { return a + b; });
     * printf("%d\n", add(1, 2)); // Result: 3
     * @endcode
    */
    #define lambda __lambda__

#endif
