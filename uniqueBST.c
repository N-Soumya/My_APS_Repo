#include <stdio.h>


int dp[20];


int numberOfBST(int n)
{

	
	if (n <= 1)
		return 1;

	
	if (dp[n])
		return dp[n];
	for (int i = 1; i <= n; i++)
		dp[n] += numberOfBST(i - 1) * numberOfBST(n - i);
	return dp[n];
}


int main()
{
	int N = 3;


	printf("Number of structurally Unique BST with %d keys "
		"are : %d",
		N, numberOfBST(N));
	return 0;
}


