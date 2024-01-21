// https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/endoscope

1.
// Tree BFS

#include<iostream>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;

int n, m, graph[100][100], l;
int dist[100][100];

bool inLimit(int r, int c) {
    return ((r >= 0 && r < n) && (c >= 0 && c < m));
}

bool left(int status) {
    return (status == 1 || status == 3 || status == 6 || status == 7);
}

bool right(int status) {
    return (status == 1 || status == 3 || status == 4 || status == 5);
}

bool up(int status) {
    return (status == 1 || status == 2 || status == 4 || status == 7);
}

bool down(int status) {
    return (status == 1 || status == 2 || status == 5 || status == 6);
}

void bfs(int r, int c) {
    int d, status;
    dist[r][c] = 1;
    queue< pair<int, int> > q;
    q.push(make_pair(r, c));

    while (!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();

        d = dist[r][c];
        if (d == l)
            continue;

        status = graph[r][c];
        // left
        if (status == 1 || status == 3 || status == 6 || status == 7) {
            int status2 = graph[r][c-1];
            if (inLimit(r, c-1) && dist[r][c-1] == 0 && right(graph[r][c-1])) {
                dist[r][c-1] = dist[r][c] + 1;
                q.push(make_pair(r, c-1));
            }
        }

        // right
        if (status == 1 || status == 3 || status == 4 || status == 5) {
            if (inLimit(r, c+1) && dist[r][c+1] == 0 && left(graph[r][c+1])) {
                dist[r][c+1] = dist[r][c] + 1;
                q.push(make_pair(r, c+1));
            }
        }

        // down
        if (status == 1 || status == 2 || status == 5 || status == 6) {
            if (inLimit(r+1, c) && dist[r+1][c] == 0 && up(graph[r+1][c])) {
                dist[r+1][c] = dist[r][c] + 1;
                q.push(make_pair(r+1, c));
            }
        }

        // up
        if (status == 1 || status == 2 || status == 4 || status == 7) {
            if (inLimit(r-1, c) && dist[r-1][c] == 0 && down(graph[r-1][c])) {
                dist[r-1][c] = dist[r][c] + 1;
                q.push(make_pair(r-1, c));
            }
        }
    }
}

int main() {
    int t, i, j, k, c, x, y;
    cin>> t;
    for (c = 0; c < t; c++) {
        cin>> n >> m >> x >> y >> l;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++)
                cin>> graph[i][j];
        }

        if (graph[x][y] == 0) {
            cout<< 0 << "\n";
            continue;
        }

        for (i = 0; i < n; i++)  {
            for (j = 0; j < m; j++)
                dist[i][j] = 0;
        }

        bfs(x, y);
        int cnt = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (dist[i][j] > 0)
                    cnt++;
            }
        }
        cout<< cnt << "\n";
    }

    return 0;
}


2.

#include<iostream>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;

int n, m;
int graph[100][100];
int dist[100][100];
int len;

bool up(int s) {
    return (s == 1 || s == 2 || s == 4 || s == 7);
}

bool down(int s) {
    return (s == 1 || s == 2 || s == 5 || s == 6);
}

bool left(int s) {
    return (s == 1 || s == 3 || s == 6 || s == 7);
}

bool right(int s) {
    return (s == 1 || s == 3 || s == 4 || s == 5);
}

bool inLimit(int r, int c) {
    return ((r >= 0 && r < n) && (c >= 0 && c < m));
}

void bfs(int r, int c) {
    dist[r][c] = 1;
    queue< pair<int, int> > q;
    q.push(make_pair(r, c));

    while (!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();

        int d = dist[r][c];
        if (d == len)
            continue;

        // up
        if (inLimit(r-1, c) && up(graph[r][c]) && down(graph[r-1][c]) && dist[r-1][c] == 0) {
            dist[r-1][c] = dist[r][c] + 1;
            q.push(make_pair(r-1, c));
        }

        // down
        if (inLimit(r+1, c) && down(graph[r][c]) && up(graph[r+1][c]) && dist[r+1][c] == 0) {
            dist[r+1][c] = dist[r][c] + 1;
            q.push(make_pair(r+1, c));
        }

        // left
        if (inLimit(r, c-1) && left(graph[r][c]) && right(graph[r][c-1]) && dist[r][c-1] == 0) {
            dist[r][c-1] = dist[r][c] + 1;
            q.push(make_pair(r, c-1));
        }

        // right
        if (inLimit(r, c+1) && right(graph[r][c]) && left(graph[r][c+1]) && dist[r][c+1] == 0) {
            dist[r][c+1] = dist[r][c] + 1;
            q.push(make_pair(r, c+1));
        }
    }
}

int main() {
    int c, t, i, j;
    int x, y;
    cin>> t;

    for (c = 0; c < t; c++) {
        cin>> n >> m >> x >> y >> len;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++)
                cin>> graph[i][j];
        }

        if (graph[x][y] == 0) {
            cout<< 0 << "\n";
            continue;
        }

        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++)
                dist[i][j] = 0;
        }

        bfs(x, y);
        int cnt = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (dist[i][j] > 0)
                    cnt++;
            }
        }
        cout<< cnt << "\n";
    }

    return 0;
}
