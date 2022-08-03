// Problem Link - 
/* By Arkajyoti Saha */
#include<bits/stdc++.h>
#define int   long long int
using namespace std;
void file_i_o(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}
//######################################################################################################################################################################
const int N = 1e5+10;
vector<int> graph[N];
int vis[N];
//no of vertices in a coneected graph
int dfs(int src){
    int cnt = 1;
    vis[src] = 1;
    for(int v:graph[src]){
        if(!vis[v]){
            cnt += dfs(v);
        }
    }
    return cnt;
}

int32_t main(){
    // file_i_o();
    int v, e;
	cin >> v >> e;

	for(int i=0;i<e;i++){
        int v, u;
        cin >> v >> u;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    int sum = 0, ans = 0;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            int size = dfs(i);
            ans += size * sum;
            sum += size;
        }
    }
    cout << ans << endl;
}