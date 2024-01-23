// https://github.com/s-kachroo/SamsungPractice/blob/master/wormhole%20DFS.cpp
// https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/warmholes

#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int n, result, temp;
int w[100][5];
int mask[100];

int dist(int sx, int sy, int tx, int ty) {
    return (abs(sx-tx) + abs(sy-ty));
}

void wormhole(int sx, int sy, int tx, int ty, int cost) {
    result = min(result, dist(sx, sy, tx, ty) + cost);

    int i;
    for (i = 0; i < n; i++) {
        if (mask[i] == 0) {
            mask[i] = 1;
            // lower end
            temp = dist(sx, sy, w[i][0], w[i][1]) + w[i][4] + cost;
            wormhole(w[i][2], w[i][3], tx, ty, temp);

            // upper end
            temp = dist(sx, sy, w[i][2], w[i][3]) + w[i][4] + cost;
            wormhole(w[i][0], w[i][1], tx, ty, temp);
            mask[i] = 0;
        }
    }
}

int main() {
    int t, i, j;
    int sx, sy, tx, ty;
    cin>> t;
    while (t--) {
        cin>> n;
        cin>> sx >> sy >> tx >> ty;
        for (i = 0; i < n; i++) {
            mask[i] = 0;
            for (j = 0; j < 5; j++)
                cin>> w[i][j];
        }

        result = INT_MAX;
        wormhole(sx, sy, tx, ty, 0);
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
int w[100][5];
int result;

int dist(int sx, int sy, int tx, int ty) {
    return ((abs(sx - tx)) + abs(sy - ty));
}

void dfs(int *visited, int sx, int sy, int tx, int ty, int cost) {
    result = min(result, dist(sx, sy, tx, ty) + cost);

    int i = 0;
    int temp;
    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;

            // lower end
            temp = dist(sx, sy, w[i][0], w[i][1]) + w[i][4] + cost;
            dfs(visited, w[i][2], w[i][3], tx, ty, temp);

            // upper end
            temp = dist(sx, sy, w[i][2], w[i][3]) + w[i][4] + cost;
            dfs(visited, w[i][0], w[i][1], tx, ty, temp);

            visited[i] = 0;
        }
    }

}

int main() {
    int i, j, t;
    int visited[100];
    int sx, sy, tx, ty;
    cin>> t;

    while (t--) {
        cin>> n;
        cin>> sx >> sy >> tx >> ty;
        for (i = 0; i < n; i++) {
            visited[i] = 0;
            for (j = 0; j < 5; j++)
                cin>> w[i][j];
        }
        result = INT_MAX;
        int cost = 0;
        dfs(visited, sx,sy, tx, ty, cost);
        cout<< result << "\n";
    }

    return 0;
}
