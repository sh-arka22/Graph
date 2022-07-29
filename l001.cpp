#include<vector>
#include <iostream>
using namespace std;
int vis[10];
void file_i_o(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}

class Edge{
public:
    int u, w;
    Edge(int u, int w){
        this->u = u;
        this->w = w;
    }
};

void addEdge(vector<vector<Edge> > &graph,int u, int v, int w) {
    graph[v].push_back(Edge(u,w));
    graph[u].push_back(Edge(v,w));
}
//******************************************* QUESTIONS **********************************************
// O(2E)
void diaplay(vector<vector<Edge> > &graph, int V){
    for(int i=0;i<V;i++){
        cout<<i<<"->";
        for(auto e:graph[i]){
            cout<<"("<<e.u<<"/"<<e.w<<")"<<" ";
        }
        cout<<endl;
    }
}

int findEdge(vector<vector<Edge>> &graph, int v, int u){
    for(int i=0;i<graph[v].size();i++){
        Edge e = graph[v][i];
        if(e.u == u)
            return i;
    }
    return -1;
}

void removeEdge(vector<vector<Edge>> &graph, int u, int v){
    int idx1 = findEdge(graph,v,u);
    swap(graph[v][idx1],graph[v][graph[v].size()-1]); //swaped the current edge with last one
    graph[v].pop_back(); // poped the last one

    int idx2 = findEdge(graph,u,v);
    graph[u].erase(graph[u].begin()+idx2);
}

void removeVtx(vector<vector<Edge> > &graph, int v){
    for(int i = graph[v].size()-1;i>=0; i--){
        Edge e = graph[v][i];
        removeEdge(graph,v, e.u);
    }
}

// O(2E)
bool hasPath(vector<vector<Edge>> &graph, int src, int dest,int vis[]){
    if(src == dest)
        return true;

    bool res = false;
    vis[src] = 1;
    for(Edge e:graph[src]){
        if(vis[e.u] == 0){
            res = res or hasPath(graph,e.u,dest, vis);
        }
    }
    return res;
}


int allPaths (vector<vector<Edge> > &graph,int src,int dest, int vis[], string psf){
    if(src == dest){
        psf+=to_string(dest);
        cout<<psf<<endl;
        return 1;
    }
    int cnt = 0;
    vis[src] = 1;
    for(Edge e:graph[src]){
        if(vis[e.u] == 0){
            cnt = cnt + allPaths(graph,e.u,dest, vis, psf+to_string(src));
        }
    }
    vis[src] = 0;
    return cnt;
}

void preOrder(vector<vector<Edge>> &graph, int src, int dest, int vis, int wsf, string psf){
    cout<<src<<"->"<<(to_string(psf)+to_string(src)+"@"+to_string(wsf))<<endl;
    vis[src] = true;
    for(Edge e: graph[src]){
        if(!vis[e.u]){
            preOrder(graph, e.u, vis, wsf+e.w, psf+to_string(src));
        }
    }
    vis[src] = false;
}
//**************************************************************************
void constructGraph(vector<vector<Edge>> &graph, int V){
    addEdge(graph,0,1,10);
    addEdge(graph,0,3,10);
    addEdge(graph,1,2,10);
    addEdge(graph,2,3,40);

    addEdge(graph,2,7,2);
    addEdge(graph,2,8,4);
    addEdge(graph,7,8,3);

    addEdge(graph,3,4,2);
    addEdge(graph,4,5,2);
    addEdge(graph,4,6,3);
    addEdge(graph,5,6,3);
}
//************************************************************************************************
int main(){
    file_i_o();
    int V = 9;//total number of vertices
    vector<vector<Edge>> graph(V,vector<Edge>());
    constructGraph(graph,V);
    // removeEdge(graph,4,6);
    // removeVtx(graph,4);
    // diaplay(graph, V);
    int cnt = allPaths(graph,0,6, vis,"");
}

//******PRINTING THE GRAPH ************
// 0->(1/10) (3/10) 
// 1->(0/10) (2/10) 
// 2->(1/10) (3/40) (7/2) (8/4) 
// 3->(0/10) (2/40) (4/2) 
// 4->(3/2) (5/2) (6/3) 
// 5->(4/2) (6/3) 
// 6->(4/3) (5/3) 
// 7->(2/2) (8/3) 
// 8->(2/4) (7/3)

//***** after deleting the edge (4/6)
// 0->(1/10) (3/10) 
// 1->(0/10) (2/10) 
// 2->(1/10) (3/40) (7/2) (8/4) 
// 3->(0/10) (2/40) (4/2) 
// 4->(3/2) (5/2) 
// 5->(4/2) (6/3) 
// 6->(5/3) 
// 7->(2/2) (8/3) 
// 8->(2/4) (7/3)


//***********After deleting the vertx 4
// 0->(1/10) (3/10) 
// 1->(0/10) (2/10) 
// 2->(1/10) (3/40) (7/2) (8/4) 
// 3->(0/10) (2/40) 
// 4->
// 5->(6/3) 
// 6->(5/3) 
// 7->(2/2) (8/3) 
// 8->(2/4) (7/3) 

//*** All paths from 0->6
// 0123456
// 012346
// 03456
// 0346
// 4 -> total no of paths
