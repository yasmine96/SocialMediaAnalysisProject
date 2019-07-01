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