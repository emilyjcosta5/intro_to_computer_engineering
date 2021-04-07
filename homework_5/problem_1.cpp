#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
#include <iostream>
#include <limits.h> 
#include <stdio.h> 
#include <unordered_map>

void print_path(int path[], int i){
    if(path[i]==-1) return;
    std::cout << i;
    print_path(path, path[i]);
}

void print_solution(int result, int path[], int building1){
    std::cout << "Shortest Distance between the two buildings: " << result << std::endl;
    //print_path(path, building1);
}

int** read_csv(std::string filename, int number_vertices){
    // Create an input filestream
    std::ifstream inf;
    inf.open(filename);
    if(inf.fail()){
        std::cerr << "Error: Could not open input file" << std::endl;
        exit(1);
    }
    // Create adjacency matrix and fill with 0's
    int** result = 0;
    result = new int*[number_vertices];
    for(int i=0; i<number_vertices; i++){
        result[i] = new int[number_vertices];
        for(int j=0; j<number_vertices; j++) 
            result[i][j] = 0;
    }
    // Read data, line by line
    int v0 = 0;
    int v1 = 0;
    int distance = 0;
    int col = 0;
    std::string line, v;
    int val;
    while(std::getline(inf, line)){
        std::stringstream ss(line);
        col = 0;
        // Extract each integer
        while(std::getline(ss, v, ',')){
            val = std::stoi(v);
            if(col==0) v0 = val;
            else if(col==1) v1 = val;
            else distance = val;
            col++;
        }
        //std::cout << v0 << ' ' << v1 << ' ' << distance << std::endl;
        result[v0][v1] = distance;
        result[v1][v0] = distance;
    }
    // Close file
    inf.close();
    return result;
}

// Helper function for D algo
int min_distance(int distances[], bool s[], int N){ 
	int min = INT_MAX, min_index; 
	for (int n=0; n<N; n++) 
		if (s[n]==false && distances[n]<=min) 
			min=distances[n], min_index=n; 
	return min_index; 
} 

// Function that implements Dijkstra's single source shortest path algorithm 
// for a graph represented using adjacency matrix representation 
void dijkstra(int **map, int building0, int building1, int N){ 
    /*
    Implements Dijkstra's shortest path algorithm.

    Parameters
    ---------
    map: double array
        Holds the adjacency matrix
    building0: int
        Source building. Where the path starts.
    building1: int
        Destination building. Where the path ends.
    N: int
        Number of vertices in the map.

    Returns
    -------
    Shortest ddistance from building0 to building1.
    */
	// Create and initialize arrays to hold data, include array to hold shortest path info.
	int distances[N];
	bool s[N];
    int path[N]; 
	for (int i=0; i<N; i++){
		distances[i] = INT_MAX;
        s[i] = false; 
        path[0] = -1;
    }
	// Distance from building0 to building0 is 0. Duh.
	distances[building0] = 0; 
	// Find the shortest path to all buildings 
    //int m = 0;
	for (int i=0; i<N-1; i++) { 
		int u = min_distance(distances, s, N); 
        //std::cout << u << ' ';
        //m = u;
		s[u] = true; 
		for (int n=0; n<N; n++) 
			if (!s[n] && map[u][n] && distances[u]+map[u][n]<distances[n]){
                //path[n] = m;
                //std::cout << path[n] << std::endl;
				distances[n] = distances[u] + map[u][n]; 
            }
	} 
    // Only return value of building 1, our destination.
    int result =  distances[building1];
    //for(int j=0; j<N; j++){
    //    std::cout << path[j] << ' ';
    //}
    print_solution(result, path, building1);
} 

int main() {
    // Create data strucure to map vertices to building number.
    std::unordered_map<std::string, int> vertices;
    vertices["23G"] = 0;
    vertices["23H"] = 1;
    vertices["28"] = 2;
    vertices["29"] = 3;
    vertices["31"] = 4;
    vertices["33"] = 5;
    vertices["34"] = 6;
    vertices["35"] = 7;
    vertices["40"] = 8;
    vertices["41"] = 9;
    vertices["42"] = 10;
    vertices["43"] = 11;
    vertices["54"] = 12;
    vertices["55"] = 13;
    vertices["57"] = 14;

    // Get input from user
    std::string b0 = "";
    std::string b1 = "";
    std::cout << "Enter start building: ";
    std::cin >> b0;
    std::cout << "Enter end building: ";
    std::cin >> b1;

    int number_vertices = 22;
    int **adjacency_matrix;
    adjacency_matrix = read_csv("/home/emily/Documents/data_structures/homework_5/neu_graph.txt", number_vertices);
    /* // Print adjacency matrix
    for(int i=0; i<number_vertices; i++){
      for(int j=0; j<number_vertices; j++){
        std::cout << adjacency_matrix[i][j] << ' ';
      }
      std::cout << std::endl;
    } */ 
    dijkstra(adjacency_matrix, vertices.at(b0), vertices.at(b1), number_vertices);
    return 0;
}
