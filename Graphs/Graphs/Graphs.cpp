#include "Graph.h"
#include <iostream>

int main()
{
	Graph graph(10);
	graph.addEdge(2, 3);
	graph.addDirectedEdge(5, 7);
	cout << graph.getSize() << endl;
    cout << "true: " << endl;
	cout << graph.isEdge(2, 3) << endl;
	cout << graph.isDirectedEdge(5, 7) << endl;
    cout << "false: " << endl;
	cout << graph.isDirectedEdge(1, 6) << endl;
	cout << graph.isEdge(5, 7) << endl;
    return 0;
}

