#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void lcs(char s1[], char s2[])
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int m[len1+1][len2+1];
    int i,j;
    for(i=0; i<len1; i++)
        m[0][i] = 0;
    for(i=0; i<len2; i++)
        m[i][0] = 0;
    for(i=1; i<=len1; i++)
    {
        for(j=1; j<=len2; j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                m[i][j] = m[i-1][j-1] + 1;
            }
            else
            {

                if (m[i-1][j] > m[i][j-1])
                {
                     m[i][j] = m[i-1][j];
                }
                else
                    m[i][j] = m[i][j-1];
            }

        }
    }
    printf("Length of Longest Common Sequence: %d\n", m[len1][len2]);
}
int main()
{
    char s1[100], s2[100];
    printf("Enter string1");
    scanf("%s", s1);
    printf("Enter string 2\n");
    scanf("%s", s2);
    lcs(s1, s2);
}
