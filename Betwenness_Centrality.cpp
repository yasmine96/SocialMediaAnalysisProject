#include <iostream>
#include <vector>
#include <assert.h>
#include <cstdlib>
#include <functional>
#include <queue>
using namespace std;

/*Defines*/
typedef pair<int,int> ipair;
#define INF 0x3f3f3f3f
#define max 10000

/*Functions Prototypes*/
void Print_Paths_Recrusive (int src, int des, vector<bool> visited, vector<int> path, int index, vector<vector<int>> adj_matrix);
void Print_all_paths (int src, int des, vector<vector<int>> adj_matrix);
int path_distance (vector<int> nodes_path, vector<vector<int>> adj_matrix);
void Betweeneess_centrality (vector <pair<int,int>> src_des,vector<vector<int>> short_path,vector<vector<int>> adj_matrix);
float betweeneess_value (int index, int node,vector<pair<int,int>> src_des, vector<vector<int>> short_path, int paths);
int is_paths_above (int index,vector<pair<int,int>> src_des);

/*Global Variables */
int s  = 0;
int f = 0 ;
int l = 0;
vector<vector<int>> all (max, vector<int>());

int main (void)
{
  int node1, node2, weight;
  int n,m;

  cin>>n>>m;
  assert( (2<=n<=100) && ((n-1)<=m<=n*(n-1)/2));
  vector<vector<int>> adj_matrix(n,vector<int>(n,0));
  vector<pair<int,int>> Src_Des(max, pair<int,int>());
  vector<vector<int>> Short_Path(max, vector<int>());
 
  for (int i=0; i<m; i++)
  {
    cin>>node1>>node2>>weight;
	adj_matrix[node1][node2] = weight;
    adj_matrix[node2][node1] = weight;
  }

  Betweeneess_centrality (Src_Des,Short_Path,adj_matrix);

  

 // int value =  Betweenneess_Centrality (4,Src_Des,Short_Paths,adj_matrix);  
  //cout << "g(4) = "<< value <<"\n";
 return 0;
}



void Print_Paths_Recrusive (int src, int des, vector<bool> visited,vector<int> path, int index, vector<vector<int>> adj_matrix)
{
	int n = adj_matrix.size();  
	// Mark the current node and store it in path[] 
	visited[src] = true;
	path[index++] = src;

	// If current vertex is same as destination, then print current path[]
	if (src == des)
	{
		for (int i=0; i<index; i++)
			all[s].push_back(path[i]);
		s ++ ;
	}
	
	else  //Current vertex is not the destination
	{
		vector<int> adj = adj_matrix[src];
		for (int j=0; j<n; j++)
		{
			if ( (adj[j] != 0) && (!visited[j]) )
		          Print_Paths_Recrusive (j, des, visited, path, index, adj_matrix);
		}
	}
	index -- ;
	visited[src] = false;
}


void Print_all_paths (int src, int des, vector<vector<int>> adj_matrix)
{
	int n = adj_matrix.size();  int index = 0;
	vector<bool> visited (n,false);
	vector<int> path (n);

    Print_Paths_Recrusive (src, des, visited, path, index, adj_matrix) ;
}


int path_distance (vector<int> nodes_path, vector<vector<int>> adj_matrix)
{
   int distance = 0;
   int size = nodes_path.size();
   for (int i=0; i<size-1; i++)
   {
	   int src = nodes_path[i];    int des = nodes_path[i+1];
	   distance = distance + adj_matrix[src][des];
   }
   return distance;
}


vector<int> Min_distance_path (vector<int> distances,int min)
{
	vector<int> final_path_isa;
	int min_index = min ;
	for (int i=(min_index)+1; i<distances.size(); i++)
	{
		if (distances[i] < distances[min_index])
		   min_index = i;	   
	}
	for (int i=(min_index)+1; i<distances.size(); i++)
	{
	  if ( (distances[i] == distances[min_index]) && (i!=min_index) )
			final_path_isa.push_back(i);
	}

	final_path_isa.push_back(min_index);
	return final_path_isa;
}

bool node_is_intermediate (int node, vector<int>path)
{
	int size = path.size();
    for (int i=0; i<size; i++)
	{
		if ( (path[i] == node) && (i!=0) && (i!=size-1) )
			return true;
	}
	return false;
}

float betweeneess_value (int index, int node,vector<pair<int,int>> src_des, vector<vector<int>> short_path, int paths)
{
	int n = src_des.size();  //13
	int no_of_paths = paths;
	int no_of_node = 1;

	for (int i=index+1; i<n; i++)
	{
		if ( (src_des[i].first == src_des[index].first) && (src_des[i].second == src_des[index].second) )
		{
			l = i ;
			no_of_paths++;
			if (node_is_intermediate (node, short_path[i]))
				no_of_node ++;
		}
	}

	return (no_of_node/(float)no_of_paths);
}

int is_paths_above (int index,vector<pair<int,int>> src_des)
{
	int paths = 1;
	for (int i=0; i<index; i++)
	{
		if (  (src_des[i].first == src_des[index].first) && (src_des[i].second == src_des[index].second) )
			 paths ++ ;
	}
	return paths;
}

void Betweeneess_centrality (vector <pair<int,int>> src_des,vector<vector<int>> short_path,vector<vector<int>> adj_matrix)
{
	int n = adj_matrix.size();  //4
	int g = 0;
	float g_node = 0;;
	vector<vector<int>> all_paths;
	vector<int> paths_distances;
	vector<int> final_short_paths_isa;

	for (int node = 0; node<n; node++)
	{
	  for (int des = node+1; des<n; des++)
	  {
		  Print_all_paths (node, des, adj_matrix);	
		  int min = g;
		  for (g; g<s; g++)
		     paths_distances.push_back(path_distance (all[g],adj_matrix));

		  final_short_paths_isa = Min_distance_path (paths_distances, min);
		  int size = final_short_paths_isa.size();
		  for (int i=0; i<size; i++)
		  {
             src_des[f].first = node;    src_des[f].second = des;
			 short_path[f] = all[final_short_paths_isa[size-1-i]];
			 final_short_paths_isa.pop_back();
			 f++;
		  }
	  }
	}

	for (int vertex = 0; vertex<n; vertex++)
	{
	  for (l; l<f; l++)
	  {
		vector<int> path = short_path[l];
		if (node_is_intermediate(vertex,path))
		{
          int no_of_paths = is_paths_above (l,src_des); //1	
		  g_node = g_node + betweeneess_value (l, vertex, src_des, short_path, no_of_paths);
		}
	  }
	  cout<<g_node<<"\n";
	  g_node = 0;
	  l = 0;
   }
}



/*
void Betweeneess_Centrality (vector<vector<int>> adj_matrix)
{
  vector <pair<int,int>> Src_Des (max, pair<int,int>());
  vector<vector<int>> Short_Paths(max, vector<int>());


}


*/