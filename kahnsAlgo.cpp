vector<int>topoSort;
int indeg [v]; //calculating infdegree
const int N = 10e4+5;
vector<int> graph[N];

int main(){
    fill(indeg,indeg+v,0);

    /**
     * indegree calculation
     */
    for(auto edgeList: graph){
        for(auto u: edgeList){
            indeg[u]++;
        }
    }

    queue<int> que;

    /**
     * pushing the vertex on the que whos indregree is 0
     */
    for(int i=0;i<v;i++){
        if(indeg[i] == 0){
            que.push(i);
        }
    }
    int level = 0;
    /**
     * traversing the graph
     */
    while(que.size()){
        int sz = que.size();
        while(sz--){
            int v = que.front();
            topoSort.push_back(v);
            que.pop();
            for(auto child:graph[v]){
                //if indegree of the child if becomes 0 after -- we push in the queue
                if(--indeg[child] == 0){
                    que.push(child);
                }
            }
        }
        level ++;
    }
    /**
     * if the size of the topoSorted array != the no of vertex so there is a cycle hence cannot be toposorted here
     */
    return topoSort.size() != v ? false : true;
}