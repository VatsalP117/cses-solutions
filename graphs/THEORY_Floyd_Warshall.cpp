// Calculate shortest path from every node to every other node (multi source shortest path algorithm)
// helps detect negative cycles as well
// Go via every node/vertex
// eg: A[0][1]=>shortest path from 0 to 1
//             => A[0][2]+A[2][1]
//             => A[0][3]+A[3][1]
//             => A[0][4]+A[4][1]
//             and so on and uska minimum value le lena
//dynammic programming right? we would need pre computed values available
//to apply this algo to undirected , convert to directed dono pe edge lagake
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void shortest_distance(vector<vector<int>>&matrix){
	    
	    //adjancency matrix hai input mai
	    int n = matrix.size();
	    //first convert the input matrix to a cost matrix 
	    //i.e a se b jaane kitna distance lagegega DIRECT Route se
	    //-1 ko 1e9 kar diya (means unreachable) to makr calculations easy
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == -1) {
					matrix[i][j] = 1e9;
				}
				if (i == j) matrix[i][j] = 0;
				//cost of going from node a to a =0
			}
		}
		//if cost of any i s.t cost[i][i] <0 to negative cycle
        //now try to go from every node to every other node via a node
		for (int via = 0; via< n; via++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					matrix[i][j] = min(matrix[i][j],
					                   matrix[i][via] + matrix[via][j]);
				}
			}
		}



        //vo 1e9 ko bas vapas -1 mai convert kar diya kyuki question mai bola h lite lo
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 1e9) {
					matrix[i][j] = -1;
				}
			}
		}
	}