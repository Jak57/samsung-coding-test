1.
// https://github.com/s-kachroo/SamsungPractice/blob/master/burst%20balloon%202.cpp
// https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/burst-balloons-1
#include<iostream>
#include<algorithm>
using namespace std;

int dp[100][100];

int mxPoint(int *arr, int n) {
    int i, j, len, k, leftValue, rightValue, before, after;
    for (len = 1; len <= n; len++) {
        for (i = 0; i <= n-len; i++) {
            j = i + len - 1;
            for (k = i; k <= j; k++) {
                leftValue = rightValue = 1;
                before = after = 0;

                if (i != 0)
                    leftValue = arr[i-1];
                if (j != n-1)
                    rightValue = arr[j+1];

                if (i != k) {
                    before = dp[i][k-1];
                }

                if (j != k) {
                    after = dp[k+1][j];
                }

                if (leftValue == 1 && rightValue == 1)
                    dp[i][j] = max(dp[i][j], before + leftValue * arr[k] * rightValue + after);
                else
                    dp[i][j] = max(dp[i][j], before + leftValue * rightValue + after);
            }
        }
    }
    return dp[0][n-1];
}

int main() {
    int i, mx, n;
    int arr[100];
    cin>> n;

    for (i = 0; i < n; i++)
        cin>> arr[i];

    mx = mxPoint(arr, n);
    cout<< mx << "\n";
    return 0;
}

2. 

#include<iostream>
#include<algorithm>
using namespace std;

int dp[100][100];

int mxPoint(int *arr, int n) {
    int i, j, len, k, leftValue, rightValue, before, after;
    for (len = 1; len <= n; len++) {
        for (i = 0; i <= n-len; i++) {
            j = i + len - 1;
            for (k = i; k <= j; k++) {
                leftValue = rightValue = 1;
                before = after = 0;

                if (i != 0)
                    leftValue = arr[i-1];
                if (j != n-1)
                    rightValue = arr[j+1];

                if (i != k) {
                    before = dp[i][k-1];
                }

                if (j != k) {
                    after = dp[k+1][j];
                }

                dp[i][j] = max(dp[i][j], before + leftValue * arr[k] * rightValue + after);
            }
        }
    }
    return dp[0][n-1];
}


int main() {
    int i, mx, n;
    int arr[100];
    cin>> n;

    for (i = 0; i < n; i++)
        cin>> arr[i];
    mx = mxPoint(arr, n);
    cout<< mx << "\n";
    return 0;
}

