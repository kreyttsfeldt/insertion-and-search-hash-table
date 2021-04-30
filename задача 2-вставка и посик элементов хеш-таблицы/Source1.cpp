#include <iostream>
#include <cmath>
using namespace std;
struct Node
{
	Node *next;
	int data;
};
class List
{

public:
	int find(int data);
	Node*head;
	List() { head = NULL; }
	void push_back(int data);
};
void List::push_back(int data)
{
	Node *temp = new Node;
	if (head == NULL)
	{
		temp->data = data;
		temp->next = NULL;
		head = temp;
	}
	else
	{
		temp = head;
		while (temp != NULL) temp = temp->next;
		Node* temp = new Node;
		temp->data = data;
		temp->next = NULL;
	}
}
int hash1(int data, Node *mass[])
{
	if (mass[data % 10] == NULL)
	{
		List ptr;
		ptr.push_back(data);
		mass[data % 10] = ptr.head;
		return data % 10;
	}
	else
	{
		int i = 1;
		while (mass[(data + i) % 10] != NULL)
		{
			i++;
		}
		List ptr;
		ptr.push_back(data);
		mass[(data + i) % 10] = ptr.head;
		return (data + i) % 10;
	}
}
int List::find(int data)
{
	Node *cur = head;
	while (cur != NULL)
	{
		if (cur->data == data) return 1;
		cur = cur->next;
	}
	return 0;
}
void poisk(int data, Node *mass[])
{
	for (int i = 0; i < 10; i++)
	{
		if (mass[i] != NULL)
		{
			List ptr;
			ptr.head = mass[i];
			if (ptr.find(data) == 1)
			{
				cout << "element naiden" << endl;
				return;
			}
		}
	}
	cout << "ne nayden" << endl;
}
int main()
{
	Node *mass[10];
	for (int i = 0; i < 10; i++) mass[i] = NULL;
	cout << hash1(1, mass) << endl;
	cout << hash1(3, mass) << endl;
	cout << hash1(5, mass) << endl;
	cout << hash1(7, mass) << endl;
	cout << hash1(64, mass) << endl;
	cout << hash1(23, mass) << endl;
	cout << hash1(9, mass) << endl;
	cout << hash1(74, mass) << endl;
	cout << hash1(97, mass) << endl;
	cout << hash1(255, mass) << endl;
	poisk(9, mass);
	poisk(1, mass);
	poisk(238, mass);
	poisk(97, mass);
	poisk(98, mass);
	system("pause");
	return 0;
}
