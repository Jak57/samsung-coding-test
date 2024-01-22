// https://github.com/s-kachroo/SamsungPractice/blob/master/mr%20kim.cpp
// https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/kim-and-refrigerators

#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<climits>
using namespace std;

int n, result;
int x[100], y[100];

int dist(int i, int j) {
    return (abs(x[i] - x[j]) + abs(y[i] - y[j]));
}

void optimalCost(bool *visited, int src, int count, int cost) {
    if (count == n) {
        result = min(result, cost + dist(src, n+1));
    }

    int i;
    for (i = 1; i <= n; i++) {
        if (visited[i] == false) {
            visited[i] = true;
            optimalCost(visited, i, count+1, cost + dist(src, i));
            visited[i] = false;
        }
    }
}

int main() {
    int t = 10, i, j, tc;
    bool visited[100];
    for (tc = 1; tc <= t; tc++) {
        cin>> n;
        cin>> x[0] >> y[0] >> x[n+1] >> y[n+1];
        for (i = 1; i <= n; i++)
            cin>> x[i] >> y[i];

        result = INT_MAX;
        for (i = 0; i < n+2; i++)
            visited[i] = false;

        optimalCost(visited, 0, 0, 0);
        printf("# %d %d\n", tc, result);
    }

    return 0;
}


// 2

#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<climits>
using namespace std;

int n;
int x[100], y[100];
int result;

int dist(int i, int j) {
    return (abs(x[i] - x[j]) + abs(y[i] - y[j]));
}

void dfs(int *visited, int src, int cost, int count) {
    if (count == n) {
        result = min(result, cost + dist(src, n+1));
        return;
    }
    int i;
    for (i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            dfs(visited, i, cost + dist(src, i), count+1);
            visited[i] = 0;
        }
    }
}

int main() {
    int t = 10, c, i, j;
    int visited[100];

    for (c = 1; c <= t; c++) {
        cin>> n;
        cin>> x[0] >> y[0] >> x[n+1] >> y[n+1];
        for (i = 1; i <= n; i++)
            cin>> x[i] >> y[i];

        for (i = 0; i < n+2; i++)
            visited[i] = 0;

        int src = 0, count = 0, cost = 0;
        result = INT_MAX;
        dfs(visited, src, cost, count);
        printf("# %d %d\n", c, result);
    }

    return 0;
}

