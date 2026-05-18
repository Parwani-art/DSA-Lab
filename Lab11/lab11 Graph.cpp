#include <iostream>
using namespace std;

#define MAXVERTEXS 50

struct Edge
{
    int adj;
    int weight;
};

class WeightedGraph 
{
private:
    Edge edges[MAXVERTEXS][MAXVERTEXS];
    int numVertices;

public:
    WeightedGraph(int n);
    void addEdge(int from, int to, int weight);
    void removeEdge(int from, int to);
    bool isAdjacent(int from, int to);
    int getWeight(int from, int to);
    void display();
};

// Constructor
WeightedGraph::WeightedGraph(int n) 
{
    numVertices = n;
    for (int i = 0; i < numVertices; i++)
        for (int j = 0; j < numVertices; j++)
        {
            edges[i][j].adj = 0;
            edges[i][j].weight = 0;
        }
    cout << "Graph created with " << numVertices << " vertices." << endl;
}

void WeightedGraph::addEdge(int from, int to, int weight)
{
    if (from >= 0 && from < numVertices && to >= 0 && to < numVertices)
    {
        edges[from][to].adj = 1;
        edges[from][to].weight = weight;
    }
    else
    {
        cout << "Invalid vertex index!" << endl;
    }
}

void WeightedGraph::removeEdge(int from, int to)
{
    if (from >= 0 && from < numVertices && to >= 0 && to < numVertices) 
    {
        edges[from][to].adj = 0;
        edges[from][to].weight = 0;
    }
    else 
    {
        cout << "Invalid vertex index!" << endl;
    }
}

// Check if edge exists
bool WeightedGraph::isAdjacent(int from, int to)
{
    if (from >= 0 && from < numVertices && to >= 0 && to < numVertices)
        return (edges[from][to].adj == 1);
    return false;
}


int WeightedGraph::getWeight(int from, int to)
{
    if (from >= 0 && from < numVertices && to >= 0 && to < numVertices)
    {
        if (edges[from][to].adj == 1)
            return edges[from][to].weight;
        else
        {
            cout << "No edge exists between " << from << " and " << to << endl;
            return -1;
        }
    }
    return -1;
}

// Display adjacency matrix with weights
void WeightedGraph::display()
{
    cout << "\nAdjacency Matrix (with weights):" << endl;
    cout << "  ";
    for (int i = 0; i < numVertices; i++)
        cout << " " << i;
    cout << endl;

    for (int i = 0; i < numVertices; i++)
    {
        cout << i << " ";
        for (int j = 0; j < numVertices; j++)
        {
            if (edges[i][j].adj)
                cout << " " << edges[i][j].weight;
            else
                cout << " 0";
        }
        cout << endl;
    }
}


int main()
{
    cout << "-------------------------------------" << endl;
    cout << "WEIGHTED GRAPH USING ADJACENCY MATRIX" << endl << endl;

    WeightedGraph g(4);

    cout << "\nAdding weighted edges:" << endl;
    cout << "0->1 (weight 5)" << endl;
    cout << "0->2 (weight 3)" << endl;
    cout << "1->2 (weight 2)" << endl;
    cout << "1->3 (weight 4)" << endl;
    cout << "2->3 (weight 1)" << endl;

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 4);
    g.addEdge(2, 3, 1);

    g.display();

    cout << "\nChecking adjacency:" << endl;
    cout << "0->1: " << (g.isAdjacent(0, 1) ? "Yes" : "No")
        << ", weight = " << g.getWeight(0, 1) << endl;
    cout << "1->0: " << (g.isAdjacent(1, 0) ? "Yes" : "No") << endl;
    cout << "2->3: " << (g.isAdjacent(2, 3) ? "Yes" : "No")
        << ", weight = " << g.getWeight(2, 3) << endl;

    cout << "\nRemoving edge 1->2" << endl;
    g.removeEdge(1, 2);
    cout << "After removal:";
    g.display();

    return 0;
}