// Problem Link - 
/* By Arkajyoti Saha */
#include<bits/stdc++.h>
using namespace std;
void file_i_o(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}
//######################################################################################################################################################################

const int N = 10e4+5;
vector<int> graph[N];
bool vis[N];
void topoDFS(int src, vector<int>&topoOrder){
    vis[src] = 1;
    for(int child:graph[src]){
        if(!vis[child]){
            topoDFS(child, topoOrder);
        }
    }
    topoOrder.push_back(src);
}

int main(){
    file_i_o();
    int v, e;
	cin >> v >> e;

    for(int i=0;i<e;i++){
        int v , u;
        cin >> v >>u;
        graph[v].push_back(u);
    }
    vector<int>topoOrder;
    for(int src = 0;src<v;src++){
        if(vis[src]) continue;
        topoDFS(src,topoOrder);
    }
}