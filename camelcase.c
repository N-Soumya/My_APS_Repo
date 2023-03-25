#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define size 30

int count_words(char[]);

int main()
{
   char str[size];

   printf("Enter string\n");

   scanf("%s",str);

   printf("\nNo. of words : %d",count_words(str));

}

int count_words(char s[size])
{
   int i,ctr=1;

   for(i=0;i<strlen(s);i++)
    {

     if(isupper(s[i]))
     {
        ctr++;
        printf("\n");
     }
        printf("%c",s[i]);
    }

  return ctr;
}
