#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void towers(int n, char from, char to, char aux)
{
    if(n==1)
    {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    towers(n-1, from, aux, to);
    printf("Move tower %d from %c to %c\n", n, from, to);
    towers(n-1, aux, to, from);
    return;


}
int main()
{
    int n = 6;
    char from, to, aux;
    towers(n,'a','c','b');
    return 0;

}
