#include "dijkstras.h"

int main(){
    Graph G;
    file_to_graph("src/large.txt", G);
    vector<int> previous;
    //cout << "Final previous array: ";
    //for (size_t i = 0; i < previous.size(); i++)
    //    cout << i << ":" << previous[i] << " ";
    //cout << endl;
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);
    for (int i = 0; i < G.numVertices; i++){
        vector<int> path = extract_shortest_path(distances, previous, i);
        if (path.empty()){
            cout << "No path found to " << i << endl;
            continue;
        }
        print_path(path, distances[i]);
    }
    return 0;
}