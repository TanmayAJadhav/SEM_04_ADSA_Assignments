// Implement all the functions of a dictionary (ADT) using hashing and handle collisions using separate chaining using linked list.Data: Set of (key, value) pairs,
// Keys are mapped to values, Keys must be comparable, Keys must be unique. Standard Operations: Insert (key, value), Find(key), Delete(key)

#include <iostream>
using namespace std;
#define MAXSIZE 100

class Info
{
	string word;
	string meaning;
	Info* next;

public:
	Info()
	{
		word = "";
		meaning = "";
		next = NULL;
	}
	Info(string n, string mean)
	{
		word = n;
		meaning = mean;
		next = NULL;
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
		obj.word = "", obj.meaning = "123456789", obj.next = NULL;
		for(int i = 0; i < MAXSIZE; i++)
		{
			arr[i] = obj;
		}
	}

	void Insert(string word, string mean)
	{
		if(count == MAXSIZE)
		{
			cout<<"Phone Book is full\n";
			return;
		}
		int sum = 0, id = 0;
		for(int i = 0; i < word.size(); i++)
		{
			 sum += word[i];
		}
		id = (sum/word.size());
		id = id%MAXSIZE;

//		cout<<id%MAXSIZE<<endl;

		Info *newn = new Info;
		newn->word = word;
		newn->meaning = mean;

		// cout<<word<<" :: "<<id<<endl;

		if(arr[id].next == NULL)
		{
			arr[id].next = newn;
			count++;
			cout<<word<<" record inserted\n";
		}
		else if(arr[id].next != NULL)
		{
			Info *temp = arr[id].next;
			while(temp->next != NULL)
			{
				cout<<temp->meaning<<endl;
				temp = temp->next;
			}
			temp->next = newn;
//			cout<<word<<" is here "<<temp->next->meaning<<endl;

			cout<<word<<" record inserted\n";
		}
	}

	string search(string contactname)
	{
		int sum = 0, id = 0;
		for(int i = 0; i < contactname.size(); i++)
		{
			 sum += contactname[i];
		}
		id = (sum/contactname.size());
		id = id%MAXSIZE;

		if(arr[id].next == NULL)
		{
			return "Not Found\n";
		}
		if(contactname == arr[id].next->word)
		{
			return arr[id].next->meaning;
		}
		else
		{
			Info *temp = arr[id].next;
//			cout<<temp->next<<endl;
			while((temp != NULL) && (temp->word != contactname))
			{
				temp = temp->next;
			}
			if(temp == NULL)
			{
				return "Not found\n";
			}
			return temp->meaning;
		}
	}

	void deleteRecord(string w)
	{
		int sum = 0, id = 0;
		for(int i = 0; i < w.size(); i++)
		{
			 sum += w[i];
		}
		id = (sum/w.size());
		id = id%MAXSIZE;

		if(arr[id].next == NULL)
		{
			cout<<"Not Inserted\n";
			return;
		}
		else
		{
			cout<<w<<endl;
			Info *temp = arr[id].next;
			if (temp->word == w)
			{
				arr[id].next = temp->next;
				delete temp;
			}
			else
			{
				while ((temp != NULL) && (temp->next->word != w))
				{
					temp = temp->next;
				}
				if (temp == NULL)
				{
					cout << "Not Inserted\n";
					return;
				}
				Info* Nodetodelete = temp->next;
				temp->next = temp->next->next;
				delete Nodetodelete;
				cout << w << " deleted\n";
			}
		}
	}
};

int main()
{
	char choice = '0';
	string word, meaning, getmeaning;
	HashTable obj;
	while (choice != '4') 
	{
		cout<<"----MENU----\n";
		cout<<"1) Add Key and word\n";
		cout<<"2) Find\n";
		cout<<"3) Delete\n";
		cout<<"4) Exit\n";
		cout<<"Enter your choice\n";
		cin>>choice;

		switch(choice)
		{
			case '1':
				cout << "Enter the keyword to add in : " << endl;
            	cin.ignore();
            	getline(cin, word);
				cout << "Enter the meaning of " << word << endl;
            	getline(cin, meaning);
            	obj.Insert(word, meaning);
				break;
			case '2':
				cout << "Enter the keyword to find in dictionary: " << endl;
            	cin.ignore();
            	getline(cin, word);
            	getmeaning = obj.search(word);
            	cout << word << " : " << getmeaning;
				break;
			case '3':
				cout << "Enter keyword to delete : " << endl;
        	    cin.ignore();
    	        getline(cin, word);
	            obj.deleteRecord(word);
				cout<<endl;
				break;
			case '4':
				cout<<"Thank you\n";
				break;	
			default:
				cout<<"Choose between (0-3)\n";	
		}
		
	}
	return 0;
}

