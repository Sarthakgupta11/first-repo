#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void printdfs(int** edges,int n, int sv, bool* visited)
{
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<n;i++)
    {
        if(i==sv)
        {    
        continue;
        }
        if(edges[sv][i]==1)
        {
            if(visited[i])
            {
            continue;
            }
        printdfs(edges,n,i,visited);
        }
    }
}

void printbfs(int** edges,int n,int sv,bool* visited)
{
    queue<int> pendingvertices;
    pendingvertices.push(sv);
    visited[sv]=true;

    while(!pendingvertices.empty())
    {
        int currvertex = pendingvertices.front();
        pendingvertices.pop();
        cout<<currvertex<<endl;
        for(int i=0;i<n;i++)
        {
            if(i==currvertex)
            continue;

            if(edges[currvertex][i]==1 && !visited[i])
            {
                pendingvertices.push(i);
                visited[i]=true;
            }
        }
    }
}

void bfs(int** edges, int n)
{
    bool* visited = new bool[n];
    for(int i=0;i<n;i++)
    visited[i]=false;

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
    printbfs(edges,n,i,visited); 
        }
    }
    delete [] visited;
}


void dfs(int** edges, int n)
{
    bool* visited = new bool[n];
    for(int i=0;i<n;i++)
    visited[i]=false;

    for(int i=0;i<n;i++)
    {
        if(!visited[i]){
    printdfs(edges,n,i,visited); 
        }
    }
    delete [] visited;
}


int main()
{
int n,e;
cin>>n>>e;
int** edges= new int*[n];
for (int i = 0; i < n; i++)
{
    edges[i]= new int[n];
    for (int j = 0; j < n; j++)
    {
        edges[i][j]=0;
    }    
}
for(int i=0;i<e;i++)
{
    int f,s;
    cin>>f>>s;
    edges[f][s]=1;
    edges[s][f]=1;
}
/*bool* visited= new bool[n];
for(int i=0;i<n;i++)
visited[i]=false;*/

//printdfs(edges,n,0,visited);
cout<<endl;
//printbfs(edges,n,0);
cout<<endl;
bfs(edges,n);
cout<<endl;
dfs(edges,n);

//delete [] visited;
for(int i=0;i<n;i++)
delete [] edges[i];

delete [] edges;
return 0;
}