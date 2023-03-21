#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

const long MAX = 200000;

long fib(long n)
{
    long arr[MAX];
    for (int i = 0; i < MAX; i++)
        arr[i] = 0;
        
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return (arr[n] = 1);
    if (arr[n])
        return arr[n];
 
    long k = (n & 1) ? (n + 1) / 2 : n / 2;
 
    arr[n]
        = (n & 1)
              ? (fib(k) * fib(k) + fib(k - 1) * fib(k - 1))
              : (2 * fib(k - 1) + fib(k)) * fib(k);
 
    return arr[n];
}

int main()
{
    long res = fib(32);
    printf("RESULT: %ld", res );
    return 0;
}
