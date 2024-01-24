// https://github.com/s-kachroo/SamsungPractice/blob/master/research%20team.cpp

#include<iostream>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;

int n, graph[100][100];
int maxDist[100][100];

bool inLimit(int r, int c) {
    return ((r >= 1 && r <= n) && (c >= 1 && c <= n));
}

void bfs(int dist[][100], int r, int c) {
    int i;
    dist[r][c] = 0;
    queue< pair<int, int> > q;
    q.push(make_pair(r, c));

    while (!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();

        int x[4] = {-1, 0, 1, 0};
        int y[4] = {0, 1, 0, -1};

        for (i = 0; i < 4; i++) {
            int newX = r + x[i];
            int newY = c + y[i];

            if (inLimit(newX, newY) && dist[newX][newY] == -1 && graph[newX][newY] != 0) {
                dist[newX][newY] = dist[r][c] + 1;
                q.push(make_pair(newX, newY));
            }
        }
    }
}

int main() {
    int t, i, j, k, item, x, y, ans;
    int dist[100][100];

    cin>> t;
    while (t--) {
        cin>> n >> item;
        vector< pair<int, int> > p;

        for (i = 0; i < item; i++) {
            cin>> x >> y;
            p.push_back(make_pair(x, y));
        }

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                cin>> graph[i][j];
            }
        }

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++)
                maxDist[i][j] = -1;
        }

        ans = INT_MAX;
        for (i = 0; i < item; i++) {
            x = p[i].first;
            y = p[i].second;
            for (j = 1; j <= n; j++) {
                for (k = 1; k <= n; k++) 
                    dist[j][k] = -1;
            }

            bfs(dist, x, y);
            for (int x = 1; x <= n; x++) {
                for (int y = 1; y <= n; y++) {
                    maxDist[x][y] = max(maxDist[x][y], dist[x][y]);
                }
            }
        }

        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                if (maxDist[x][y] != -1) {
                    ans = min(ans, maxDist[x][y]);
                }
            }
        }
        cout<< ans << "\n";
    }

    return 0;
}
