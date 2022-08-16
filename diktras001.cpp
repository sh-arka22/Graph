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
const int N = 1e4+10;

vector<pair<int,int>> graph[N];
vector<int> visited(N, 0);
set<pair<int,int>>st; //{wsf,u}  // in prims we use w->wsf

void dijktras(int src){
    st.insert({0,src});
    distance[src] = 0;

    while(st.size()){
        auto [v,wsf] = *st.begin();

        // if(visited[v]){
        //     cout<<"there is sa cycle";
        //     continue;
        // }

        // visited[v] = true;
        for(auto [child,w]: graph[v]){
            // if(visited[child]) continue;
            set.insert({wsf+w,child});
        }
    }

}

int main(){
    file_i_o();

    int v, e;
    for(int i=0; i<e; i++){
        int v, u, w;
        cin>>v>>u>>w;
        graph[v].push_back({u,w});

    }
}