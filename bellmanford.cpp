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
//lecture 9
void bellmanford(int edges[][], int src. int N){
    int *prev = new int[N];
    fill(prev,prev+N, 1e9);

    bool isNegativeCycle = false;
    for(int edgeCount = 1; edgeCount <= N; edgeCount++){
        int *curr = new int[N];
        for(int i = 0; i < N; i++) curr[i] = prev[i];
        bool isAnyUpdate = false;
        for(auto [u,v,w]: edges){
            if(prev[u] + w < curr[v]){
                curr[v] = prev[u] + w;
                isAnyUpdate = true;
            }
        }

        if(edgeCount == N and isAnyUpdate) isNegativeCycle = true;

        if(isAnyUpdate == false){
            break;
            // means there wont be any update forward
        }
        delete[] curr;
    }
}

int main(){
    file_i_o();
    
}