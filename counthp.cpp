include <bits/stdc++.h>
using namespace std;

void findAllPaths(
	int N, vector<vector<int> >& graph)
{

	int dp[N][(1 << N)];

	memset(dp, 0, sizeof dp);

	dp[0][1] = 1;

	for (int i = 2; i < (1 << N); i++) {

		if ((i & (1 << 0)) == 0)
			continue;

		if ((i & (1 << (N - 1)))
			&& i != ((1 << N) - 1))
			continue;

		for (int end = 0; end < N; end++) {

			if (i & (1 << end) == 0)
				continue;

			int prev = i - (1 << end);

			for (int it : graph[end]) {
				if ((i & (1 << it))) {
					dp[end][i] += dp[it][prev];
				}
			}
		}
	}

	cout << dp[N - 1][(1 << N) - 1];
}

int main()
{
	int N = 4;
	vector<vector<int> > graph(N);
	graph[1].push_back(0);
	graph[2].push_back(0);
	graph[2].push_back(1);
	graph[1].push_back(2);
	graph[3].push_back(1);
	graph[3].push_back(2);

	findAllPaths(N, graph);

	return 0;
}
