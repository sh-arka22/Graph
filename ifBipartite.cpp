// Problem Link - 
/* By Arkajyoti Saha */
// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue>
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
int visited[N];
//**************** BFS TYPE ONE ********************************
void BFStypeOne(int src){

    int rad = 0, clr = 0;
    bool ifCycle = false, isBipartite = true;
    //clr -1(not colored)  0(green)   1(red)
    queue<int>que;
    que.push(src);
    while(que.size()){
        int sz = que.size();
        while(sz--){
            int parrent = que.front();
            que.pop();
            if(visited[parrent] != -1){
                // cout << "cycle prasent";
                ifCycle = true;
                if(clr != visited[parrent])
                    isBipartite = false;
                continue;
            }
            cout<<parrent<<", ";
            visited[parrent] = clr; // i colored the parent
            for(int child: graph[parrent]){
                if(visited[child] == -1){
                    que.push(child);
                }
            }
        }
        clr = (clr+1)%2; //updated the next color
        rad++;
        cout<<endl;
    }

    if(ifCycle == false){
        cout<<"Bipartite bcs no cycle is prasent";
    }
    else{
        if(isBipartite){
            cout<<"Bipartite with Even length cycle";
        }
        else{
            cout<<"Non-Bipartite with Odd Length cycle";
        }
    }
}


int main(){
    file_i_o();
    int v,e;
    cin>>v>>e;
    fill(visited,visited+N, -1);
    for(int i=0;i<e;i++){
        int v, u;
        cin>>v>>u;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    BFStypeOne(0);
}





