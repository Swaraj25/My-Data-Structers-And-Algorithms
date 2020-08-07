#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#define umap unordered_map <int, vector<int> >
using namespace std;

class Graph{
    private:
    umap adj;
    public:
    Graph(){

    }
    umap get_adj(){
        return adj;
    }
    void add_edge(int,int);
    void bfs(int, int);
    void dfs(int, int);
};

void Graph::add_edge(int src, int dst){
    this->adj[src].push_back(dst);
    this->adj[dst].push_back(src);
}

void Graph::bfs(int src,int edges){
    unordered_map<int, bool> visited;
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while(!q.empty()){
        int node = q.front();
        cout<<node<<" ";
        q.pop();
        vector<int> nbrs = this->adj[node];
        for(int nbr:nbrs){
            if(!visited[nbr]){
                visited[nbr] = true;
                q.push(nbr);
            }
        }
    }
} 