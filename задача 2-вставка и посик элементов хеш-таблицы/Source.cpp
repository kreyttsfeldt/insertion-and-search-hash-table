#include <iostream>
#include <cmath>
using namespace std;
class List
{
public:
	List()
	{
		Size = 0;
		head = nullptr;
	}
	void push_back(int data);
	int GetSize() { return Size; }
private:
	class Node
	{
	public:
		Node * pNext;
		int data;

		Node(int data = int(), Node *pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node *head;
};
void List::push_back(int data)
{
	if (head == nullptr)
	{
		head = new Node(data);
	}
	else
	{
		Node *current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node(data);

	}

	Size++;
}

int hash1(int data, List *mass[])
{
	if (mass[data % 10] == NULL)
	{
		List ptr;
		mass[data % 10]=&ptr;
		ptr.push_back(data);
		return data % 10;
	}
	else
	{
		int i = 1;
		while (mass[(data  + i) % 10] != NULL)
		{
			i++;
		}
		List ptr;
		ptr.push_back(data);
		return (data + i) % 10;
	}
}
void poisk(int data, List *mass[])
{
	if (mass[data % 10] = NULL)
	{
		List ptr=*mass[data % 10];

	}
}
int main()
{
	List* mass[10];
	for (int i = 0; i < 10; i++) mass[i]=NULL;
	cout << hash1(1, mass) << endl;
	cout << hash1(3, mass) << endl;
	cout << hash1(5, mass) << endl;
	cout << hash1(7, mass) << endl;
	cout << hash1(9, mass) << endl;
	cout << hash1(64, mass) << endl;
	cout << hash1(23, mass) << endl;
	cout << hash1(74, mass) << endl;
	cout << hash1(97, mass) << endl;
	cout << hash1(255, mass) << endl;
	system("pause");
	return 0;
}