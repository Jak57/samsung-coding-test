// https://github.com/s-kachroo/SamsungPractice/blob/master/mr%20lee.cpp
#include<iostream>
#include<algorithm>
using namespace std;

int n, result;

void minCostPath(int arr[][100], bool *visited, int count, int cost, int src) {
    // base case
    if (count == n-1) {
        if (arr[src][0] != 0) {
            result = min(result, cost + arr[src][0]);
        }
        return;
    }

    // main case
    int i;
    for (i = 0; i < n; i++) {
        if (arr[src][i] != 0 && visited[i] == false) {
            visited[i] = true;
            minCostPath(arr, visited, count+1, cost + arr[src][i], i);
            visited[i] = false;
        }
    }
}

int main() {
    int t, i, j;
    int arr[100][100];
    bool visited[100];
    cin>> t;

    while (t--) {
        cin>> n;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) 
                cin>> arr[i][j];
        }
        
        result = INT_MAX;
        for (i = 0; i < n; i++) 
            visited[i] = false;
        visited[0] = true;

        minCostPath(arr, visited, 0, 0, 0);
        cout<< result << "\n";
    }

    return 0;
}
