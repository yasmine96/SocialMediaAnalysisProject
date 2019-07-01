<<<<<<< HEAD
#include<iostream>
#include<vector>
#include<assert.h>

using namespace std;
 
 
 
void add_edge(vector<vector<int> > &vect,int u, int v , int w) {       //function to add edge into the matrix
  
	 vect[u][v] = w;
	 vect[v][u] = w;
  
}
 
void Degree_Centrality(vector<vector<int> > &vect , int n , int m)
{
	vector <int> count (n , 0);
 
	
		for(int i=0; i<n; i++)
	    {
		 for(int j=0; j<n; j++)
		 {
			 if(vect[i][j]!=0)
			  count[i]++;	  
		 }
		  							
	  }
 
	
	
 
	for(int i=0; i<n; i++)
	{
		cout<<count[i]<<endl;
	}
}
 
 
int main()
{
int n,m;
cin>>n;
cin>>m;
assert( (2<=n<=1000000) && ((n-1)<=m<=n*(n-1)/2));

vector<vector<int> >  vect(n);

for ( int i = 0 ; i < n ; i++ )
   vect[i].resize(n);

 
 
int start;
int end;
int weight;
 
 
   for(int i=0; i<m; i++)
   {
	   cin>>start>>end>>weight;
 
	   add_edge(vect ,start, end , weight);
   }
 
  
  
 
   Degree_Centrality(vect , n , m);
 
 
int x;
cin>>x;
 
return 0;
}
=======
#include <iostream>
#include <vector>
#include <assert.h>
#include <cstdlib>
#include <functional>
#include <queue>
using namespace std;

typedef pair<int,int> ipair;
#define INF 0x3f3f3f3f

int Sum_short_distance (vector<int> dis);
vector<int> Shortest_Path_weight (int src, vector<vector<pair<int,int>>> adj_list);



int main (void)
{
  int node1, node2, weight;
  int n,m;

  cin>>n>>m;
  assert( (2<=n<=100) && ((n-1)<=m<=n*(n-1)/2));
  vector<vector<pair<int,int>>> adj_list (n,vector<pair<int,int>>());
  

  for (int i=0; i<m; i++)
  {
     cin>>node1>>node2>>weight;
	 adj_list[node1].push_back(make_pair(node2, weight));
	 adj_list[node2].push_back(make_pair(node1,weight));
  }


  for (int j=0; j<n; j++)
  {
   vector<int> Output = Shortest_Path_weight (j,adj_list);
   int sum = Sum_short_distance (Output);
   float final_distance = (n-1)/(float)sum ;
   cout<<final_distance<<endl;
  }
  
  
  return 0;
}

int Sum_short_distance (vector<int> dis)
{
   int sum = 0;
   for (int i=0; i<dis.size(); i++)
	   sum += dis[i];
   return sum ;
}


vector<int> Shortest_Path_weight (int src, vector<vector<pair<int,int>>> adj_list)
{
	//create a queue:
	std::priority_queue< pair<int,ipair>, vector<pair<int,ipair>>, greater<pair<int,ipair>> > q_nodes;

	int n = adj_list.size();
	vector<int> distance(n,INF);
	vector<int> path(n,-1);

	q_nodes.push(make_pair(0,make_pair(src,src)));

	while (! q_nodes.empty() )
	{
		pair<int, pair<int,int>> p = q_nodes.top();
		q_nodes.pop();
		int curr_node = p.second.first;
		int curr_prev_node = p.second.second;
		int curr_dis = p.first;  

		if (distance[curr_node] != INF)
			continue;

		distance[curr_node] = curr_dis;
		path[curr_node] = curr_prev_node;
		
		for (int i=0; i<adj_list[curr_node].size(); i++)
		{
			int next_node = adj_list[curr_node][i].first;
			int weight = adj_list[curr_node][i].second;
			if (distance[next_node] != INF)
				continue;	
			q_nodes.push(make_pair(curr_dis+weight, make_pair(next_node,curr_node)));
		}
	}

	return distance;
}


//int betwenness_centrality (int src, vector<vector<pair<int,int>>> adj_list)
//{
	//1.shortest paths that the src lies as an intermediate node:
	  /*Here function return vector of pairs (two nodes connected)*/

   //2.Make for loop of the last vector size "2" and then take each pair and calculate for it: 
	//2.1.Here function calculated total number of shortest paths between two nodes:

	//2.2.Here function calculated number of times that the src node lies as an intermaediate node in the previous shortest paths:
//}

/*
vector<int> Betweenness_Centrality(vector<vector<pair<int,int>>> adj_list)
{
	int nodes = adj_list.size();
	vector<int> g(nodes,0);
	for (int i=0; i<nodes; i++)
		g.push_back(betwenness_centrality(i,adj_list));
}
*/




>>>>>>> 3b378bc0512558e3c229290a88f7aa415c3fd255
