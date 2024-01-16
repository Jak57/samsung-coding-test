1.
// https://github.com/s-kachroo/SamsungPractice/blob/master/bipartite%20vertices%20with%20same%20colour.cpp

#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int graph[100][100], n;

bool bipartite(int src, int *color) {
    bool flag = true;
    int i;
    for (i = 0; i < n; i++) {
        if (graph[src][i] == 1) {
            if (color[i] == -1) {
                color[i] = 1 - color[src];
                flag = flag & bipartite(i, color);
            } else if (color[i] == color[src]) 
                return false;
        }
    }
    return flag;
}

int main() {
    int i, j;
    int color[100];
    cin>> n;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            cin>> graph[i][j];
    }

    for (i = 0; i < n; i++)
        color[i] = -1;

    for (i = 0; i < n; i++) {
        if (color[i] == -1) {
            color[i] = 0;
            if (!bipartite(i, color)) {
                cout<< -1 << "\n";
                return 0;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (color[i] == 0)
            cout<< i << " ";
    }
    cout<< "\n";

    return 0;
}

/*
4
0 1 0 1 
1 0 1 0 
0 1 0 1 
1 0 1 0 
--------
0 2
*/


2.
// https://www.geeksforgeeks.org/problems/bipartite-graph/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
class Solution {
public:
    bool bipartite(int src, int *color, vector<int>adj[]) {
        bool flag = true;
        int i;
        for (i = 0; i < adj[src].size(); i++) {
            int child = adj[src][i];
            if (color[child] == -1) {
                color[child] = 1 - color[src];
                flag = flag & bipartite(child, color, adj);
            } else if (color[src] == color[child])
                return false;
        }
        return flag;
    }
    
	bool isBipartite(int V, vector<int>adj[]){
	    int i, j;
	    int color[V];
	    for (i = 0; i < V; i++) {
	        color[i] = -1;
	    }
	    for (i = 0; i < V; i++) {
	        if (color[i] == -1) {
	            color[i] = 0;
	            if (!bipartite(i, color, adj))
	                return false;
	        }
	    }
	    return true;
	}
};
