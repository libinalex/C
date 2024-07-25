/*
1. connected graph
Let G=(V,E) be a undirected graph, where V is a vertex set and E is an edge set. A graph is connected when there is a path between every pair of vertices. Design an algorithm to determine whether the graph G is connected or not. Implement your algorithm in any programming language.

Example for connected graph


Input format

Number of vertices of the graph

Adjancency matrix of the graph

Output format

print yes( if graph is connected)

print  no ( if graph is disconnected)

Input
4
0 1 1 0
1 0 0 0
1 0 0 1
0 0 1 0

Expected output
yes

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> adj;

void dfs(int start, bool visited[]){
    visited[start]=true;
    for (int i = 0; i < adj[start].size(); i++)
    {
        if(adj[start][i]==1 && (!visited[i])){
            dfs(i,visited);
        }
    }
}

bool connected(int size){
    bool *vis=new bool[size];
    for (int u = 0; u < size; u++)
    {
        for (int i = 0; i < size; i++)
        {
            vis[i]=false;
        }
        dfs(u,vis);
        for (int i = 0; i < size; i++)

        {
            if(!vis[i]){
                return false;
            }
        }

    }
    return true;
}

int main(){
    int n; cin>>n;
    for (int i = 0; i < n; i++)
    {
        vector<int> tempvec;
        for (int i = 0; i < n; i++)
        {
            int x; cin>>x;
            tempvec.push_back(x);
        }
        adj.push_back(tempvec);
    }
    if(connected(n)){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
    return 0;
}
*/

/*
2. cycle
Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not.


in the given figure, 1-2-3-4 forms a cycle.

input format:

n // number of vertices

adjacency matrix

output

yes ( if cycle exists)

no (otherwise)

Input
4
0 1 0 0
1 0 1 1
0 1 0 1
0 1 1 0
Expected output
yes


#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int adj[n][n];
    int count = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            int x;
            cin>>x;
            if(x==1) 
                count+=1;
        }
    }
    if(count>(2*n-1)){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
}
*/

/*
3. complete graph
A graph G can be represented in a computer using Adjacency matrices or Adjacency list. We will use Adjacency matrices to represent a graph in a computer. An adjacency matrix, denoted by A = [aij], of a graph G where each entry aij = 1 if vertex vi is adjacent to vj and  aij=0 otherwise. The size of A is nxn, where n is the number of vertices of the graph.

A complete graph is a simple undirected graph in which every pair of distinct vertices is connected by a unique edge.

In graph theory , the degree of a vertex is the number of edges connecting it

Write a C code to check whether the given graph is complete or not and also print degree of each vertex of the given graph.

Input format

No.of vertices of the graph

Enter Adjacency matirx of the graph

Output format

yes / no   ( yes: if graph is complete, no: if graph is not complete)

Input
5
0 1 1 1 1
1 0 1 1 1
1 1 0 1 1
1 1 1 0 1
1 1 1 1 0
Expected output
yes

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int mat[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }

    bool ans = true;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if ((mat[i][j]==0 or mat[j][i]==0) and i!=j){
                ans=false;
                break;
            }
        }
    }

    if(ans==true){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }

    return 0;
}
*/

/*
4. MST
Given a weighted, undirected and connected graph G of V vertices and E edges. Write a program to find the sum of weights of the edges of the Minimum Spanning Tree.

input format:

n  // number of vertices

adjacency matrix

ouput format:

sum of weights of MST

Input
4
0 1 4 3
1 0 0 2
4 0 0 5
3 2 5 0
Expected output
7

#include <iostream>
using namespace std;

int n;

bool visitedAll(int* arr){
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            return false;
        }
    }
    return true;
}

int main(){
    cin>>n;
    int map[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    int a;
    int cost=0;
    int visited[]={1,0,0,0,0};
    while(!visitedAll(visited)){
        int key=100;
        int I=0,J=0;
        for(int i=0;i<n;i++){
            if(visited[i]==1){
                for(int j=0;j<n;j++){
                    if(i==j) continue;
                    if(map[i][j]<key && (visited[i]==0 || visited[j]==0) && map[i][j]!=0){
                        key=map[i][j];
                        I=i;
                        J=j;
                    }
                }
            }
        }
        visited[J]=1;
        cost+=key;
    }
    cout<<cost;
}
*/

/*
5. dijkstra
Given directed weighted graph ( adhacency matrix representation) , source 's' and destination 'd' vertices . Apply Dijkstra's algorithm to find the shortest path from s and d. Write a program to print the minimum distance.

input format:

n // number of vertices

s // source vertex

d  // destination vertex

adjacency matrix

output format:

min distance from s to d.

Input
5
1
5
0
10
3
0
0
0
0
1
2
0
0
4
0
8
2
0
0
0
0
7
0
0
0
9
0
Expected output
5
*/

/*
#include <iostream>
#include <climits>
using namespace std;

#define V 5
int parent[V];

int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union1(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskalMST(int cost[][V])
{
    int mincost = 0;
    for (int i = 0; i < V; i++)
        parent[i] = i;
    int edge_count = 0;
    while (edge_count < V - 1) {
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (find(i) != find(j) && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        union1(a, b);
        printf("Edge %d:(%d, %d) cost:%d \n",edge_count++, a, b, min);
        mincost += min;
    }
    printf("\n Minimum cost= %d \n", mincost);
}
int main()
{

    int cost[][V] = {
        { INT_MAX, 2, INT_MAX, 6, INT_MAX },
        { 2, INT_MAX, 3, 8, 5 },
        { INT_MAX, 3, INT_MAX, INT_MAX, 7 },
        { 6, 8, INT_MAX, INT_MAX, 9 },
        { INT_MAX, 5, 7, 9, INT_MAX },
    };
    kruskalMST(cost);

    return 0;
}
*/

/*
6. BFS
Given a directed graph (adjacency list) . write a program to do Breadth First Traversal of the given graph starting from  source vertex.

input format:

n  // number of vertices

s  // source vertex

adjacency list

output

BFS traversal.

Input
5
1
1 2 3 4
2
3 5
4
Expected output
1 2 3 4 5


#include <stdio.h>
#include <iostream>
#include <conio.h>
using namespace std;  
int a[20][20], q[20], visited[20], n, i, j, f = 0, r = -1;
void bfs(int v)
{
    for (i = 1; i <= n; i++)
        if (a[v][i] && !visited[i])
            q[++r] = i;
    if (f <= r)
    {
        visited[q[f]] = 1;
        bfs(q[f++]);
    }
}

int main()
{
    int v;
    cout << "Enter the number of vertices: " << endl;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        q[i] = 0;
        visited[i] = 0;
    }
    cout << "Enter graph data in matrix form:" << endl;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "Enter the starting vertex: " << endl;
    cin >> v;
    bfs(v);
    cout << "The node which are reachable are:" << endl;
    for (i = 1; i <= n; i++)
    {
        if (visited[i])
            cout << i;
        else
        {
            cout << "BFS is not possible. All nodes are not reachable!" << endl;
            break;
        }
    }
}
*/