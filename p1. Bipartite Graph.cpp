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
