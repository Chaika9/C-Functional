# Functional Programming Concepts in C

*It's just for test purpose.*

This is a collection of functional programming concepts implemented in C.

## Example
```c
#include <functional.h>
#include <stdio.h>

int main(void) {
    int array[] = {1, 2, 3, 4, 5};
    float array[] = {4.0f, 2.0f, 4.0f};
    
    float result = foldl(lambda(float, (float acc, float element) { return acc / element; }), array, 64.0f);
    printf("result = %f\n", result);

    return 0;
}
```

**Output**
```
result = 0.500000
```

## Concepts

### Lambda

Lambda is a function that can be passed as an argument to another function.

#### Syntax
```c
lambda(return_type, (argument_type argument_name, ...) { function_body; })
```

### Fmap

fmap is a function that applies a function to each element of an array.

[Haskell fmap](https://hoogle.haskell.org/?hoogle=fmap)

#### Syntax
```c
fmap(function, array)
```

### Foldl

foldl is a function that applies a function to each element of an array and accumulates the result.

[Haskell foldl](https://hoogle.haskell.org/?hoogle=foldl)

#### Syntax
```c
foldl(function, array, initial_value)
```

### Foldr

foldr is a function that applies a function to each element of an array and accumulates the result.

[Haskell foldr](https://hoogle.haskell.org/?hoogle=foldr)

#### Syntax
```c
foldr(function, array, initial_value)
```
