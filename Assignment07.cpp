// You have a business with several offices; you want to lease phone lines to connect them up with each other; and the phone company charges different amounts of money to 
// connect different pairs of cities. You want a set of lines that connects all your offices with a minimum total cost. Solve the problem by suggesting appropriate data structures.

#include <bits/stdc++.h>
using namespace std;
#define MAXV 20

class Graph
{
    int vertices;
    int parent[MAXV];
    int min_store[MAXV];
    bool mstSet[MAXV];
    int graph[MAXV][MAXV];

public:
    Graph(int max)
    {
        vertices = max;
        parent[0] = -1;
        for (int i = 0; i < vertices; i++)
        {
            min_store[i] = 999;
            mstSet[i] = false;
        }

        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                graph[i][j] = 0;
            }
        }
    }

    void addEdge(int src, int dest, int weight)
    {
        graph[src][dest] = weight;
        graph[dest][src] = weight;
    }

    void primMST()
    {
        min_store[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < vertices - 1; count++)
        {

            int min = INT_MAX, min_index;

            for (int v = 0; v < vertices; v++)
            {
                if (mstSet[v] == false && min_store[v] < min)
                {
                    min = min_store[v], min_index = v;
                }
            }

            int u = min_index;

            mstSet[u] = true;
            for (int v = 0; v < vertices; v++)
            {
                if (graph[u][v] && mstSet[v] == false && graph[u][v] < min_store[v])
                {
                    parent[v] = u, min_store[v] = graph[u][v];
                }
            }
        }

        cout << "Edge \tWeight\n";
        for (int i = 1; i < vertices; i++)
        {
            cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
        }
    }

    void display()
    {
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int vertices = 0;
    cout << "Enter number of vertices : \n";
    cin >> vertices;

    int src, dest, wght;
    char choice;

    Graph obj(vertices);

    do
    {
        cout << "\n----MENU----\n";
        cout << "1) Add Edge\n";
        cout << "2) Display\n";
        cout << "3) Print MST\n";
        cout << "4) Exit\n";
        cout << "Enter your choice\n";
        cin >> choice;

        switch (choice)
        {
        case '1':
            cout << "Enter src : \n";
            cin >> src;
            cout << "Enter dest : \n";
            cin >> dest;
            cout << "Enter weight : \n";
            cin >> wght;
            obj.addEdge(src, dest, wght);
            break;

        case '2':
            obj.display();
            break;

        case '3':
            obj.primMST();
            break;
        case '4':
            cout << "Thank you\n";
            break;
        default:
            cout << "Choose between (0-4)\n";
        }
    } while (choice != '4');

    return 0;
}
