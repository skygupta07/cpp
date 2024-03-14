#include <iostream>
#include <limits>
#include <list>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

vector <list <int> > graph;    // graph is represented as vector of list...
int v;  // no. of vertices declared globally else kaafi fn calls mai issey passs karna padta 
    

void addEdge(int a, int b, bool bidir = true){
    graph[a].push_back(b);  // a se b tak ek link establish kar di...
    if (bidir) graph[b].push_back(a);
}

void topoBFS(){
    vector <int> indegree(v,0); // vertices size ka banaya sabko zero se initialise kiya...
    // indegree vector banaya jisme ki index as element hai and actual elements are
    // represented by value in array

    for (int i=0; i<v; i++){
        for (auto neighbour : graph[i]){
            // i ---> neighbour ki taraf edge jaa rahi ho 
            indegree[neighbour]++;
        }
    }

    queue <int> qu;
    unordered_set <int> vis;
    for (int i=0; i<v; i++){
        if (indegree[i] == 0){
            qu.push(i);
            vis.insert(i);
        }
    }

    while (not qu.empty()){
        int node = qu.front();
        cout<<node<<" ";
        qu.pop();
        for (auto neighbour : graph[node]){
            if (not vis.count(neighbour)){
                indegree[neighbour]--;
                if (indegree[neighbour] == 0){
                    qu.push(neighbour);
                    vis.insert(neighbour);
                }
            }

        }
    }
}







int main(){
    cout<<"enter number of vertices of graph: ";
    cin>>v;
    int e;
    cout<<"enter number of edges: ";
    cin>>e;
    graph.resize(v ,list<int> ());

    cout<<"enter your edges..."<<endl;
    while (e--){
        int x,y;
        cin>>x>>y;
        addEdge(x,y,false);   
    }

    topoBFS();
    return 0;
} 





















/*
dependency resolution...
cyclic graph cannot be resolved for dependency...
helpful for dag (directed acyclic graph) # was asked in google

topological sorting used


-> indegree = how many incoming edges you have..
-> indegree = 0 hone ka matlab current node kisi aur pe depend nahi karta hai...
to phir usko queue mai daalo...

jab ek zero indegree wale node ko pakda tab...correspondingly uske neighbour ki ek 
dependency kam kar dena hai...

*/

/*
how to detect a given graph has DAG or not?
ans -> apply topological sort if it gives the whole vertices then the graph is DAG


*/