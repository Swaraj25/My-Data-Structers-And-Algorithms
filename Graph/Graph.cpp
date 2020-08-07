#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
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

void Graph::bfs(int src){
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
    cout<<"\n";
}

void Graph::dfs(int src){
    unordered_map<int, bool> visited;
    stack<int> st;
    visited[src] = true;
    st.push(src);
    while(!st.empty()){
        int node = st.top();
        cout<<node<<" ";
        st.pop();
        vector<int> nbrs = adj[node];
        for(int nbr:nbrs){
            if(!visited[nbr]){
                st.push(nbr);
                visited[nbr] = true;
            }
        }
    }
}