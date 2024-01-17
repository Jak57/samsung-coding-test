// https://github.com/s-kachroo/SamsungPractice/blob/master/spaceship%20bomb.cpp
// https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/aeroplane-bombing

#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<climits>
using namespace std;

void updateMatrix(int row, char matrix[][100]) {
    if (row < 0)
        return;
  
    int upLimit = max(0, row-4);
    for (int i = row; i >= upLimit; i--) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == '2') {
                matrix[i][j] = '0';
            }
        }
    }
}

int findMaxPoints(int row, int col, int bombs, char matrix[][100]) {
    if (row <= 0 || col < 0 || col >= 5) {
        return 0;
    }

    int ans = 0;
    if (row > 0 && matrix[row-1][col] != '2') {
        ans = max(ans, (matrix[row-1][col] == '1' ? 1 : 0) + findMaxPoints(row-1, col, bombs, matrix));
    }

    if (row > 0 && col > 0 && matrix[row-1][col-1] != '2') {
        ans = max(ans, (matrix[row-1][col-1] == '1' ? 1 : 0) + findMaxPoints(row-1, col-1, bombs, matrix));
    }

    if (row > 0 && col < 4 && matrix[row-1][col+1] != '2') {
        ans = max(ans, (matrix[row-1][col+1] == '1' ? 1 : 0) + findMaxPoints(row-1, col+1, bombs, matrix));
    }

    if (ans == 0 && bombs > 0) {
        updateMatrix(row-1, matrix);
        ans = findMaxPoints(row, col, bombs-1, matrix);
    }
    return ans;
}

int main() {
    int T, t, i, j, k, result, n;
    char matrix[100][100];
    cin>> T;

    for (t = 1; t <= T; t++) {
        cin>> n;
        for (i = 0; i < n; i++) {
            for (j = 0; j < 5; j++) {
                cin>> matrix[i][j];
            }
        }

        result = findMaxPoints(n, 2, 1, matrix);
        printf("#%d %d\n", t, result);
    }
   
    return 0;
}


