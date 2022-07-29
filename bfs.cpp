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

void bfs(int source){
    queue<int>mem;
    mem.push(source);
    visited[source] = 1;
    while(mem.size()){
        int parrent = mem.front();
        mem.pop();
        for(int child:graph[parrent]){
            if(!visited[child]){
                mem.push(child);
                visited[child] = 1;
                level[child] = level[parrent] + 1;
            }
        }
    }
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

    bfs(0);
    for(int i=0;i<v;i++){
        cout<<i<<"->";
        for(int j : graph[i]){
            cout<<"("<<j<<")"<<" ";
        }
        cout<<endl;
    }
}

/*
input
v e
7 8

0 1
1 2
2 3
3 5
5 6
4 5
0 4
3 4

output
0->(1) (4) 
1->(0) (2) 
2->(1) (3) 
3->(2) (5) (4) 
4->(5) (0) (3) 
5->(3) (6) (4) 
6->(5) 

*/
