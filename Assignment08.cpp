#include <iostream>
using namespace std;
#define MAX 20

class Node
{
    int data;
    Node *next;

public:
    Node()
    {
        data = 0;
        next = NULL;
    }
    friend class Graph;
};

class Graph
{
    int max_size;
    Node *arr[MAX];

public:
    Graph(int max)
    {
        max_size = max;
        for (int i = 0; i < max_size; i++)
        {
            arr[i] = NULL;
        }
    }

    void addEdge(int src, int dest)
    {
        Node *newn = new Node;
        newn->data = dest;
        Node *temp;
        if (arr[src] == NULL)
        {
            arr[src] = newn;
        }
        else
        {
            temp = arr[src];
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
        }
    }

    void topological_sort(int vernum)
    {
        int indegree[max_size];
        for (int i = 0; i < max_size; i++)
        {
            indegree[i] = 0;
        }
        for (int i = 0; i < max_size; i++) 
        {
            Node *temp = arr[i];
            while (temp != NULL)
            {
                indegree[temp->data]++;
                temp = temp->next;
            }
        }

        while (true)
        {
            int current = 0;
            while ((indegree[current] != 0) && (current < max_size))
            {
                current++;
            }
            if (current < max_size )
            {
                cout << current << " ";
                indegree[current] = -1;
                Node *temp = arr[current];

                while (temp != NULL)
                {
                    indegree[temp->data]--;
                    temp = temp->next;
                }
            }
            else
            {
                break;
            }
        }
    }

    void display()
    {
        cout<<"Graph vertices are : \n";
        for (int i = 0; i < max_size; i++)
        {
            cout << "Vertex " << i << " : ";
            Node *temp = arr[i];
            while (temp != NULL)
            {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout<<"NULL"<< endl;
        }
    }
};

int main()
{
    Graph g(6);

    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 1);
    g.addEdge(3, 1);
    g.addEdge(5, 1);
    g.addEdge(1, 4);
    g.addEdge(5, 4);
    g.display();

    cout<<"After sorting : \n";
    g.topological_sort(7);

   // int vertices, v1, v2, src;
	// char choice;
	// cout << "Enter number of vertices\n";
	// cin >> vertices;
	// Graph g(vertices);
	// do
	// {
	// 	cout << "\n----MENU----\n";
	// 	cout << "1) Add Edge\n";
	// 	cout << "2) Display\n";
	// 	cout << "3) topological sort\n";
	// 	cout << "4) Exit\n";
	// 	cout << "Enter your choice\n";
	// 	cin >> choice;

	// 	switch (choice)
	// 	{
	// 	case '1':
	// 		cout << "Enter source vertex : \n";
	// 		cin >> v1;
	// 		cout << "Enter derstination vertex : \n";
	// 		cin >> v2;
	// 		g.addEdge(v1, v2);
	// 		break;
	// 	case '2':
	// 		g.display();
	// 		break;
	// 	case '3':
	// 		g.topological_sort(vertices);
	// 		break;;
	// 	case '4':
	// 		cout << "Thank you\n";
	// 		break;
	// 	default:
	// 		cout << "Choose between (0-4)\n";
	// 	}
	// } while (choice != '4');

    return 0;
}
