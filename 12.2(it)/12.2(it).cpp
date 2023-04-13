#include <iostream>
using namespace std;
typedef int Info;

struct Elem
{
	Elem* link;
	Info info;
};

void enqueue(Elem*& first, Elem*& last, Info value);
int dequeue(Elem*& first, Elem*& last);
void print(Elem* first);
bool is_sublist(Elem* L1first, Elem* L2first);

void enqueue(Elem*& first, Elem*& last, Info value)
{
	Elem* tmp = new Elem; // 1
	tmp->info = value; // 2
	tmp->link = NULL; // 3
	if (last != NULL)
		last->link = tmp; // 4
	last = tmp; // 5
	if (first == NULL)
		first = tmp; // 6
}
int dequeue(Elem * &first, Elem * &last)
{
	Elem* tmp = first->link; // 1
	Info value = first->info; // 2
	delete first; // 3
	first = tmp; // 4
	if (first == NULL)
		last = NULL; // 5
	return value; // 6
}
void print(Elem * first) {

	Elem* current = first;

	while (current != NULL) {
		cout << current->info << " ";
		current = current->link;
	}
	cout << endl;
}

bool is_sublist(Elem* L1first, Elem* L2first) {

	Elem* current1 = L1first;
	Elem* current2 = L2first;

	while (current1 != NULL && current2 != NULL) {

		if (current1->info == current2->info) {
			current1 = current1->link;
		}

		current2 = current2->link;
	}

	return current1 == NULL;
}

int main()
{
	Elem* L2first = NULL,
		* L2last = NULL;

	for (int i = 1; i <= 10; i++)
	{
		enqueue(L2first, L2last, i);
	}

	cout << "L2: ";
	print(L2first);


	Elem* L1first = NULL,
		* L1last = NULL;

	for (int i = 4; i <= 7; i++)
	{
		enqueue(L1first, L1last, i);
	}

	cout << "L1: ";
	print(L1first);
	bool result = is_sublist(L1first, L2first);
	if (result == 1)
		cout << "yes";
	else
		cout << "no";
	while (L1first != NULL)
		dequeue(L1first, L1last);

	while (L2first != NULL)
		dequeue(L2first, L2last);

	return 0;
}