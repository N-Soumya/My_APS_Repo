#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
map<vector<int>, int> memo;
int n = arr.size();

int solve(int i, int j)
{
	if ((i > j) || (i >= n) || (j < 0))
		return 0;

	vector<int> k{ i, j };
	if (memo[k] != 0)
		return memo[k];

	int option1
		= arr[i]
		+ min(solve(i + 2, j), solve(i + 1, j - 1));

	int option2
		= arr[j]
		+ min(solve(i + 1, j - 1), solve(i, j - 2));

	memo[k] = max(option1, option2);
	return memo[k];
}

int optimalStrategyOfGame()
{

	memo.clear();
	return solve(0, n - 1);
}

int main()
{
	arr.push_back(8);
	arr.push_back(15);
	arr.push_back(3);
	arr.push_back(7);
	n = arr.size();
	cout << optimalStrategyOfGame() << endl;

	arr.clear();
	arr.push_back(2);
	arr.push_back(2);
	arr.push_back(2);
	arr.push_back(2);
	n = arr.size();
	cout << optimalStrategyOfGame() << endl;

	arr.clear();
	arr.push_back(20);
	arr.push_back(30);
	arr.push_back(2);
	arr.push_back(2);
	arr.push_back(2);
	arr.push_back(10);
	n = arr.size();
	cout << optimalStrategyOfGame() << endl;
  return 0;
}
