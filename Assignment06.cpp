// Represent a given graph using adjacency list to perform DFS and BFS. Use the map of the area around the college as the graph. Identify the prominent landmarks as 
// nodes and perform DFS and BFS on that.

#include <iostream>
using namespace std;
#define MAXSIZE 50
#define MAX 50

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
	Node(int val)
	{
		data = val;
		next = NULL;
	}

	friend class Graph;
	friend class Queue;
};

template <typename T>
class Stack
{
private:
	T data[MAX];
	int Top;

public:
	Stack()
	{
		Top = -1;
	}

	bool isEmpty()
	{
		if (Top == -1)
		{
			return true;
		}
		return false;
	}

	bool isFull()
	{
		if (Top == MAX - 1)
		{
			return true;
		}
		return false;
	}

	void push(T element)
	{
		if (isFull())
		{
			cout << "Stack is Full !" << endl;
			return;
		}
		data[++Top] = element;
	}

	T pop()
	{
		if (isEmpty())
		{
			return 0;
		}
		else
		{
			int index = Top;
			Top--;
			return data[index];
		}
	}

	T top()
	{
		if (isEmpty())
		{
			return 0;
		}
		return data[Top];
	}
};

class Queue
{
private:
	Node *front;
	Node *rear;
	int size;

public:
	Queue()
	{
		front = NULL;
		rear = NULL;
		size = 0;
	}

	void push(int no)
	{
		Node *newn = new Node();
		newn->data = no;
		newn->next = NULL;

		if (front == NULL && rear == NULL)
		{
			front = newn;
			rear = newn;
		}
		else
		{
			rear->next = newn;
			rear = newn;
		}
		size++;
	}

	int pop()
	{
		int no = 0;
		Node *temp = front;

		if (front == NULL && rear == NULL)
		{
			cout << "Queue is empty\n";
			return -1;
		}

		if (front == rear)
		{
			no = front->data;
			delete front;
			front = NULL;
			rear = NULL;
		}
		else
		{
			no = front->data;
			front = front->next;
			delete temp;
		}

		size--;
		return no;
	}

	bool empty()
	{
		if(size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Display()
	{
		Node *temp = front;

		for (int i = 1; i <= size; i++)
		{
			cout << "|" << temp->data << "|-> ";
			temp = temp->next;
		}
		cout << "NULL\n";
	}

	int Count()
	{
		return size;
	}
};

class Graph
{
	int max_size;
	Node *arr[MAXSIZE];

public:
	Graph()
	{
		max_size = 0;
	}
	Graph(int max)
	{
		max_size = max;
		for (int i = 0; i < max_size; i++)
		{
			arr[i] = NULL;
		}
	}
	void addEdge(int src_vertex, int dest_vertex)
	{
		Node *newn1 = new Node;
		newn1->data = src_vertex;
		Node *newn2 = new Node;
		newn2->data = dest_vertex;
		Node *temp;

		if (arr[src_vertex] == NULL)
		{
			arr[src_vertex] = newn2;
		}
		else
		{
			temp = arr[src_vertex];
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newn2;
		}

		if (arr[dest_vertex] == NULL)
		{
			arr[dest_vertex] = newn1;
		}
		else
		{
			temp = arr[dest_vertex];
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newn1;
		}
	}

	void display()
	{
		for (int i = 0; i < max_size; i++)
		{
			cout << "Vertex " << i << " -> ";
			Node *temp = arr[i];
			while (temp != NULL)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
	}

	void BFS(int src_vertex)
	{
		Queue q;
		bool visited[max_size] = {};
		q.push(src_vertex);
		visited[src_vertex] = 1;
		while (!q.empty())
		{
			src_vertex = q.pop();
			cout << src_vertex << ", ";

			Node *temp = arr[src_vertex];
			while (temp != NULL)
			{
				if (visited[temp->data] == 0)
				{
					visited[temp->data] = 1;
					q.push(temp->data);
				}
				temp = temp->next;
			}
		}
	}

	void DFS(int src_vertex)
	{
		Stack<int> st;
		bool visited[max_size] = {};
		st.push(src_vertex);
		visited[src_vertex] = 1;
		while (!st.isEmpty())
		{
			src_vertex = st.top();
			st.pop();
			cout << src_vertex << ", ";

			Node *temp = arr[src_vertex];
			while (temp != NULL)
			{
				if (visited[temp->data] == 0)
				{
					visited[temp->data] = 1;
					st.push(temp->data);
				}
				temp = temp->next;
			}
		}
	}
};

int main()
{
	int vertices, v1, v2, src;
	char choice;
	cout << "Enter number of vertices\n";
	cin >> vertices;
	Graph g(vertices);
	do
	{
		cout << "\n----MENU----\n";
		cout << "1) Add Edge\n";
		cout << "2) Display\n";
		cout << "3) BFS\n";
		cout << "4) DFS\n";
		cout << "5) Exit\n";
		cout << "Enter your choice\n";
		cin >> choice;

		switch (choice)
		{
		case '1':
			cout << "Enter source vertex : \n";
			cin >> v1;
			cout << "Enter derstination vertex : \n";
			cin >> v2;
			g.addEdge(v1, v2);
			break;
		case '2':
			g.display();
			break;
		case '3':
			cout << "Enter source vertex\n";
			cin >> src;
			g.BFS(src);
			break;
		case '4':
			cout << "Enter source vertex\n";
			cin >> src;
			g.DFS(src);
			break;
		case '5':
			cout << "Thank you\n";
			break;
		default:
			cout << "Choose between (0-5)\n";
		}
	} while (choice != '5');

	return 0;
}
