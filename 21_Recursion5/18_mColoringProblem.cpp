#include <bits/stdc++.h>
using namespace std;

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:

    bool isSafe(int node, int color[], bool graph[101][101], int n, int col){
        for (int k = 0; k < n; k++){
            if (k != node && graph[k][node] == 1 && color[k] == col) 
                return false; 
        }
        return true;
    }

    bool solve(int node, int color[], int m, int N, bool graph[101][101]){
        if (node == N) return true;
        
        // हर रंग की जाँच करें
        for (int i = 1; i <= m; i++){
            if (isSafe(node, color, graph, N, i)){
                color[node] = i;    // काम करें
                if (solve(node + 1, color, m, N, graph)) 
                    return true;
                color[node] = 0;    // बैकट्रैक करें
            }
        }
        
        return false;
    }

    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int N) {
        int color[N] = {0}; // N -> number of nodes
        if (solve(0, color, m, N, graph)) 
            return true;
        return false;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
