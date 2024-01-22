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


// 2

#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int n;
int result;

void dfs(int graph[][100], int *visited, int src, int cost, int count) {
    if (count == n) {
        if (graph[src][0] != 0)
            result = min(result, cost + graph[src][0]);
        return;
    }

    int i;
    for (i = 0; i < n; i++) {
        if (graph[src][i] != 0 && visited[i] == 0) {
            visited[i] = 1;
            dfs(graph, visited, i, cost + graph[src][i], count+1);
            visited[i] = 0;
        }
    }
}

int main() {
    int graph[100][100], visited[100];
    int i, j, t;
    cin>> t;

    while (t--) {
        cin>> n;
        for (i = 0; i < n; i++) {
            visited[i] = 0;
            for (j = 0; j < n; j++) 
                cin>> graph[i][j];
        }

        result = INT_MAX;
        visited[0] = 1;
        int src = 0, count = 1, cost = 0;
        dfs(graph, visited, src, cost, count);
        cout<< result << "\n";
    }

    return 0;
}

