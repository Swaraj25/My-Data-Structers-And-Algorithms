#include<iostream>
#include<vector>
#include<unordered_map>
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
    void bfs(int);
    void dfs(int);
};

void Graph::add_edge(int src, int dst){
    this->adj[src].push_back(dst);
    this->adj[dst].push_back(src);
}

void print_adj(Graph *g){
    umap adj = g->get_adj();
    umap::iterator itr;
    for(itr = adj.begin(); itr!= adj.end(); itr++){
        int src = itr->first;
        cout<<src;
        vector<int> nbrs;
        for(int nbr : nbrs){
            cout<<" -> "<<nbr<<;
        }
        cout<<"\n";
    }
}

int main(){
    Graph *g = new Graph();
    int edges;
    cin>>edges;
    int src, dst;
    while(edges--){
        cin>>src>>dst;
        g->add_edge(src,dst);
    }
    print_adj(g);
}