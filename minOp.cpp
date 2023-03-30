#include <bits/stdc++.h>
using namespace std;

int minOperation(int k)
{

	vector<int> dp(k + 1, 0);

	for (int i = 1; i <= k; i++) {

		dp[i] = dp[i - 1] + 1;

		
		if (i % 2 == 0) {
			dp[i]
				= min(dp[i],
					dp[i / 2] + 1);
		}
	}
	return dp[k];
}


int main()
{
	int K = 12;
	cout << minOperation(k);
}
