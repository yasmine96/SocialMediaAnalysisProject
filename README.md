# SocialMediaAnalysisProject
1.Team Info:
Group"62"

Members:Yasmeen Mostafa Hassan Elnaggar      Yasmeen Mohamed Mohamed ELsayed


CodeForces Team "Yasmines"



2.Work Distribution "Tasks":
Yasmeen Mohamed ELsayed-> Degree Centrality, Graph Visualization


Yasmeen Mostafa Hassan -> Closeness Centrality, Betweenness Centrality



3. Detailed Work and Install the requirements:
 3.1. Degree Centrality:
  -Firstly, main file which calculated the degree centrality of each node was written in Visual studio then tested it on the console with input taken into adjacent matrix of size n * n.
  

  -Secondly, The code was submitted on CodeForces  "degree_centrality_main.cpp"  and got score 14.5 from first submission, that there was a time limit exceed in the last two test cases.
  

  -Try to modify the code several times and submitted on CodeForces to gain the perfect result but we had always the same score even when we changed the input representation to an adjacent list of pair<int, int> to make the code more optimized.
  

  -Yesterday, On the 8th submission the code was accepted and got the perfect the score 15 points, the error caused by using endl in Cout not using "\n", that's why there is a time limit exceed error.
  


 3.2. Closeness Centrality:
  -Firstly, main file including the Closeness Centrality was written in C++ in visual studio then was tested and it was worked perfectly.


  -Secondly, The code was submitted on the CodeForces "Closeness_Centrality_main.cpp" and got the perfect score 15 points from the first submission.


  -The input of the graph "nodes & edges" was represented in an adjacent list of pair<int,int>, and the function of the closeness was written using Disjikstra algorithm to find the shortest path weight and also using Priority queue which was discussed in Section Slides "Tutorial 9".



 3.3. Betweeneess Centrality:
   -The first algorithm that was written of Betweeneess Centrality took more time to print the table that contained the shortest paths between each two nodes, the algorithm idea was to print the shortest paths for each node with all other nodes, and also the node itself in a recursive way and the input was represented in an adjacent matrix of n * n, but the problem was that we couldn't print the multiple shortest paths that existed between two nodes as it just printed one of them. 


   -Then we started to write different algorithm to solve the problem of multiple shortest paths, as the second algorithm had a function that found all paths between node and destination, and then passed all these paths into a function to calculate each path distance(weight), after that found a distance for each path and finally there was a function that returned the min distance "determine the shortest path" paths.
 
 
   -Finally, with the second algorithm the code was submitted on CodeForces and got a score of 10 from first submission, there was 3 errors of run time so we modified the code and then submitted again and got a score of 12 points, there was two errors of "Wrong answer" and one error of run time.


   -The graph input was represented by adjacent matrix of size n * n. 



  3.4. Graph Visualization:
   -We had decided to make a GUI using python libraries "networkx & matplotlib" to draw the connected directed weighted graph.


   -we installed Visual studio code, then from it we installed python ide and then libraries packages "networkx & matplotlib".


   -the input of the graph was taken into a text file and draw it using matplotlib, then we used form networkx library functions of Degree_Centarlity & Closeness_Centrality & Betweeneess_Centrality that calculate the final degree value of each node and then print these values on the gui that includes the drawn garph.

