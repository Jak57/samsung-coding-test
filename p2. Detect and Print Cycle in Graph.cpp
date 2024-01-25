// 1. Detect and Print Cycle in Directed Graph

// https://github.com/rsenwar/Samsung-Interview-Problems/blob/master/11.%20Detect%20Cycle%20in%20Directed%20Graph/DetectCycle.cpp
// https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/detect-cycle-in-directed-graph


#include<iostream>
#include<algorithm>
using namespace std;

int n, graph[100][100];
int visited[100];
int stack[100], top = -1;
int globalSum = 999999;
int ans[200], ansSize = -1;

void detectCycle(int current) {
    int i;

    if (visited[current] == 1 && top != -1) {
        int localSum = stack[top];
        for (i = top-1; i >= 0 && stack[i] != current; i--) {
            localSum += stack[i];
        }

        if (i != -1 && localSum < globalSum) {
            globalSum = localSum;
            ansSize = -1;
            ans[++ansSize] = stack[top];

            for (i = top-1; i >= 0 && stack[i] != current; i--) {
                ans[++ansSize] = stack[i];
            }
        }
        return;

    } else {
        int i;
        visited[current] = 1;
        for (i = 1; i <= n; i++) {
            if (graph[current][i] == 1) {
                stack[++top] = i;
                detectCycle(i);
                top--;
            }
        }
        visited[current] = 0;
    }
}

int main() {
    int m, i, j;
    cin>> n >> m;
    while(m--) {
        cin>> i >> j;
        graph[i][j] = 1;
    }

    for (i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            stack[++top] = i;
            detectCycle(i);
            top--;
        }
    }

    sort(ans, ans + ansSize + 1);
    for (i = 0; i <= ansSize; i++)
        cout<< ans[i] << " ";
    cout<< "\n";

    return 0;
}

// 2

#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;

int n, m;
int graph[100][100];
int stack[100], top = -1;
int global_sum;
int answer[100];
int ansSize;

void dfs(int *visited, int src) {
    int i, top_item, local_sum;

    if (visited[src] == 1 && top != -1) {
        vector<int> tmp;
        top_item = stack[top];
        tmp.push_back(top_item);
        local_sum = top_item;

        for (i = top-1; i >= 0 && stack[i] != top_item; i--) {
            tmp.push_back(stack[i]);
            local_sum += stack[i];
        }

        if (local_sum < global_sum) {
            global_sum = local_sum;
            ansSize = -1;

            for (i = 0; i < tmp.size(); i++) 
                answer[++ansSize] = tmp[i];
        }

        return;
    } else {
        visited[src] = 1;
        for (i = 1; i <= n; i++) {
            if (graph[src][i] == 1) {
                stack[++top] = i;
                dfs(visited, i);
                top--;
            }
        }
        visited[src] = 0;
    }
}

int main() {
    int i, j, u, v;
    int visited[100];
    cin>> n >> m;

    for (i = 0; i < m; i++) {
        cin>> u >> v;
        graph[u][v] = 1;
    }

    for (i = 1; i <= n; i++) {
        visited[i] = 0;
    }

    global_sum = INT_MAX;
    for (i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            stack[++top] = i;
            dfs(visited, i);
            top--;
        }
    }
    
    sort(answer, answer+ansSize+1);
    for (i = 0; i <= ansSize; i++)
        cout<< answer[i] << " ";

    return 0;
}
