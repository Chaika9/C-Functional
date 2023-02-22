#include <functional.h>
#include <stdio.h>
#include <ctype.h>

int main(void) {
    {
        int array[] = {1, 2, 3, 4, 5};
        fmap(lambda(int, (int x) { return x * x; }), array);
        printf("result = [%d, %d, %d, %d, %d]\n", array[0], array[1], array[2], array[3], array[4]);
    }

    {
        auto max = lambda(float, (float x, float y) {
            return x > y ? x : y;
        });

        float array[] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 9.0f, 8.0f, 7.0f};
        float result = foldl(max, array, 5.0f);
        printf("result = %f\n", result);
    }

    {
        float array[] = {4.0f, 2.0f, 4.0f};
        float result = foldl(lambda(float, (float acc, float element) { return acc / element; }), array, 64.0f);
        printf("result = %f\n", result);
    }

    {
        float array[] = {8.0f, 12.0f, 24.0f, 4.0f};
        float result = foldr(lambda(float, (float a, float b) { return a / b; }), array, 2.0f);
        printf("result = %f\n", result);
    }

    {
        char value[] = "3942";

        int result = foldl(lambda(int, (int acc, char c) {
            return isdigit(c) ? acc * 10 + (c - '0') : acc;
        }), value, 0);
        printf("result = %d\n", result);
    }
    return 0;
}
