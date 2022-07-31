// Problem Link - 
/* By Arkajyoti Saha */
// #include<bits/stdc++.h>
/** 
 * Any cycle related question this bfs should be used 
*/


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

    int rad = 0;

    queue<int>que;
    que.push(src);
    while(que.size()){
        cout<<"radius: "<<rad<<"->";
        int sz = que.size();
        while(sz--){
            int parrent = que.front();
            que.pop();
            if(visited[parrent]){
                cout << "cycle prasent";
                continue;
            }
            cout<<parrent<<", ";
            visited[parrent] = 1;  // mark parent
            for(int child: graph[parrent]){
                if(visited[child])
                    continue;
                que.push(child);
            }
        }
        rad++;
        cout<<endl;
    }
}

int main(){
    file_i_o();
    int v,e;
    cin>>v>>e;

    for(int i=0;i<e;i++){
        int v, u;
        cin>>v>>u;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    BFStypeOne(0);
}





