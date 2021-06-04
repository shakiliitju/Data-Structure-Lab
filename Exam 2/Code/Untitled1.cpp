#include<bits/stdc++.h>
using namespace std;

#define MX 110
vector<int>graph[MX];
bool vis[MX];
int dist[MX];

void bfs(int source)
{
    queue<int>Q;
    vis[source] = 1;
    dist[source] = 0;
    Q.push(source);

    while(!Q.empty())
    {
        int node = Q.front();
        Q.pop();
        for(int i = 0; i<graph[node].size();i++)
        {
            int next = graph[node][i];
            if(vis[next]==0)
            {
                vis[next]=1;
                dist[next] = dist[node]+1;
                Q.push(next);
            }
        }
    }
}

int main()
{
    int nodes, edges,u,v,source;
    cout<< "Enter the number of nodes & edges : ";
    cin>>nodes>>edges;

    for(int i = 1; i<=edges; i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout<< "Enter source node : ";
    cin>>source;
    bfs(source);

    cout<< "From node "<< source<<endl;
    for(int i=1; i<=nodes;i++)
    {
        cout<< "Distance of "<<i<< " is : "<<dist[i]<<endl;
    }
    return 0;
}
