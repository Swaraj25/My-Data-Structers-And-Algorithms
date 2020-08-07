#include<iostream>
#include "Graph.cpp"
using namespace std;
void print_adj(Graph *g){
    umap adj = g->get_adj();
    umap::iterator itr;
    for(itr = adj.begin(); itr!= adj.end(); itr++){
        int src = itr->first;
        cout<<src;
        vector<int> nbrs = itr->second;
        for(int nbr : nbrs){
            cout<<" -> "<<nbr;
        }
        cout<<"\n";
    }
}
int main(){
    freopen("inp.txt","r",stdin);
    freopen("op.txt","w",stdout);
    Graph *g = new Graph();
    int edges;
    cin>>edges;
    int src, dst;
    while(edges--){
        cin>>src>>dst;
        g->add_edge(src,dst);
    }
    print_adj(g);
    cin>>src;
    g->bfs(src,edges);
}