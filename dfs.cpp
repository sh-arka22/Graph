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
const int N = 1e5+10;
vector<int>graph[N];
int level[N];
int visited[N];

int allPathDfs(int src, int dst, string path){
    if(src==dst) {
        path += to_string(src);
        cout << path<<endl;
        return 1;
    }

    visited[src] = 1;
    int cnt = 0;
    for(int child: graph[src]){
        if(visited[child] == 0){
            cnt += allPathDfs(child,dst, path+to_string(src)+"->");
        }
    }
    visited[src] = 0;
    return cnt;
}


int main(){
    file_i_o();
    
    int v, e;
    cin>>v>>e;

    for(int i=0;i<e;i++){
        int v1, v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    int total = allPathDfs(0,6,"");
}

/**
7 8
0 1
1 2
2 3
3 5
5 6
4 5
0 4
3 4


0->1->2->3->5->6
0->1->2->3->4->5->6
0->4->5->6
0->4->3->5->6
 */