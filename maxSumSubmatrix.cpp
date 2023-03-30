#include <iostream>
#include <vector>
#include <climits>
using namespace std;
 
void printVector(vector<int> const &input)
{
    cout << "[";
    for (int i = 0; i < input.size(); i++) {
        cout << input[i];
        if (i < input.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]\n";
}
 
int findMaxSumSubmatrix(vector<vector<int>> const &mat)
{
   
    if (mat.size() == 0) {
        return 0;
    }
 
   
    int M = mat.size();
    int N = mat[0].size();
 
    int S[M+1][N+1];
 
    for (int i = 0; i <= M; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            if (i == 0 || j == 0) {
                S[i][j] = 0;
            }
            else {
                S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + mat[i-1][j-1];
            }
        }
    }
 
    int maxSum = INT_MIN;
    int rowStart, rowEnd, colStart, colEnd;
 
    
    for (int i = 0; i < M; i++)
    {
        for (int j = i; j < M; j++)
        {
            for (int m = 0; m < N; m++)
            {
                for (int n = m; n < N; n++)
                {
                    
                    int submatrix_sum = S[j+1][n+1] - S[j+1][m] - S[i][n+1] + S[i][m];
 
                  
                    if (submatrix_sum > maxSum)
                    {
                        maxSum = submatrix_sum;
                        rowStart = i;
                        rowEnd = j;
                        colStart = m;
                        colEnd = n;
                    }
                }
            }
        }
    }
 
    cout << "The maximum sum submatrix is\n\n";
    for (int i = rowStart; i <= rowEnd; i++) {
        vector<int> row;
        for (int j = colStart; j <= colEnd; j++) {
            row.push_back(mat[i][j]);
        }
        printVector(row);
    }
 
    return maxSum;
}
 
int main()
{
    
    vector<vector<int>> mat =
    {
        { -5, -6, 3, 1, 0 },
        { 9, 7, 8, 3, 7 },
        { -6, -2, -1, 2, -4 },
        { -7, 5, 5, 2, -6 },
        { 3, 2, 9, -5, 1 }
    };
 
  
    cout << "\nThe maximum sum is " << findMaxSumSubmatrix(mat);
 
    return 0;
}
