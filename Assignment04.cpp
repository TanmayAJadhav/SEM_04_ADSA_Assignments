// Consider telephone book database of N clients. Make use of a hash table implementation to quickly look up client‘s telephone number. Make use of two collision handling
// techniques and compare them using number of comparisons required to find a set of telephone numbers (use linear probing with replacement and without replacement)

#include <iostream>
using namespace std;
#define MAXSIZE 100

class Info
{
	string name;
	long long int num;

public:
	Info()
	{
		name = "";
		num = 0;
	}
	Info(string n, long long int number)
	{
		name = n;
		num = number;
	}
	friend class HashTable;
};

class HashTable
{
	Info arr[MAXSIZE];
	Info obj;
	int count;
public:
	HashTable()
	{
		count = 0;
		obj.name = "", obj.num = 123456778;
		for(int i = 0; i < MAXSIZE; i++)
		{
			arr[i] = obj;
		}
	}
	void Display()
	{

		for(int i = 0; i < MAXSIZE; i++)
		{
			cout<<arr[i].name<<endl;
		}
	}

	void Insert(string contactname, long long int number)
	{
		if(count == MAXSIZE)
		{
			cout<<"Phone Book is full\n";
			return;
		}
		int sum = 0, id = 0;
		for(int i = 0; i < contactname.size()/2; i++)
		{
			 sum += contactname[i];
		}
		id = (sum/contactname.size());
		id = id%MAXSIZE;

		if(arr[id].name == "")
		{
			arr[id].num = number;
			arr[id].name = contactname;
			count++;
			cout<<"record inserted\n";
		}
		else if(arr[id].name != "")
		{
			while(arr[id].name != "")
			{
				if(id == (MAXSIZE-1))
				{
					id = 0;
				}
				id++;
			}
			arr[id].num = number;
			arr[id].name = contactname;
			count++;
			cout<<"record inserted\n";
		}
	}

	long long int search(string contactname)
	{
		int sum = 0, id = 0;
		for(int i = 0; i < contactname.size()/2; i++)
		{
			 sum += contactname[i];
		}
		id = (sum/contactname.size());
		id = id%MAXSIZE;

		if(contactname == arr[id].name)
		{
			return arr[id].num;
		}
		else
		{
			int copyId = id;
			while(contactname != arr[id].name)
			{
				if(id == (MAXSIZE-1))
				{
					id = 0;
				}
				if(id == (copyId - 1))
				{
					return 0;
				}
				id++;
			}
			return arr[id].num;
		}

	}


};

int main()
{
	HashTable obj;

		long long int res = 0, number = 0;
	string contactname;
	char choice = '0';
	while (choice != '3')
	{
		cout<<"------Menu------\n";
		cout<<"1) Insert contact\n";
		cout<<"2) Search contact\n";
		cout<<"3) Exit\n";
		cout<<"Enter choice \n";\
		cin>>choice;
		switch(choice)
		{
		case '1':
			cout<<"Enter name \n";
			cin>>contactname;
			cout<<"Enter number \n";
			cin>>number;
			obj.Insert(contactname, number);
			break;

		case '2':
			cout<<"Enter name to search\n";
			cin>>contactname;
			res = obj.search(contactname);
			if(res == 0)
			{
				cout<<"No name present\n";
			}
			else
			{
				cout<<contactname<<" : "<<res<<endl;
			}
			break;
		case '3':
			cout<<"Thank you\n";
			break;	
		default:
			cout<<"Choose between (0-3)\n";		

		}

	}

	return 0;
}
