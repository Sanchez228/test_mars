#include <iostream>
#include <list>
class Node {
public:
	int data;
	Node* prev, * next;

public:
	Node(int data) {
		this->data = data;
		this->prev = this->next = NULL;
	}
};

class LinkedList {
public:
	Node* head, * tail;

public:
	LinkedList() {
		head = tail = NULL;
	}
	// Очистить список
	~LinkedList() {
		while (head != NULL)
			pop_front();
	}
	// Добавление элемента в конец списка
	Node* push_back(double data) {
		Node* ptr = new Node(data);
		ptr->prev = tail;
		if (tail != NULL)
			tail->next = ptr;
		if (head == NULL)
			head = ptr;
		tail = ptr;

		return ptr;

	}
	// Добавление элемента в начало списка
	Node* push_front(int data) {
		Node* ptr = new Node(data);
		ptr->next = head;
		if (head != NULL)
			head->prev = ptr;
		if (tail == NULL)
			tail = ptr;
		head = ptr;

		return ptr;

	}

	Node* getAt(int index) {
		Node* ptr = head;
		int n = 0;
		while (n != index) {
			if (ptr == NULL)
				return ptr;
			ptr = ptr->next;
			n++;
		}
		return ptr;
	}

	Node* operator [] (int index) {
		return getAt(index);
	}
	// Добавить элемент в заданую позицию
	Node* insert(int index, int data) {
		Node* right = getAt(index);
		if (right == NULL)
			return push_back(data);

		Node* left = right->prev;
		if (left == NULL)
			return push_front(data);

		Node* ptr = new Node(data);
		ptr->prev = left;
		ptr->next = right;
		left->next = ptr;
		right->prev = ptr;

		return ptr;
	}

	void pop_front() {
		if (head == NULL)
			return;
		Node* ptr = head->next;
		if (ptr != NULL)
			ptr->prev = NULL;
		else
			tail = NULL;
		delete head;
		head = ptr;
	}

	void pop_back() {
		if (tail == NULL)
			return;
		Node* ptr = tail->prev;
		if (ptr != NULL)
			ptr->next = NULL;
		else
			head = NULL;
		delete tail;
		tail = ptr;
	}
	//  Удалить элемент из заданой позиции
	void erase(int index) {
		Node* ptr = getAt(index);
		if (ptr == NULL)
			return;
		if (ptr->prev == NULL) {
			pop_front();
			return;
		}
		if (ptr->next == NULL) {
			pop_back();
			return;
		}

		Node* left = ptr->prev;
		Node* right = ptr->next;
		left->next = right;
		right->prev = left;

		delete ptr;
	}
	//Размер списка
	int get_size()
	{
		int size = 0;
		Node* currentNode = new Node(6);
		currentNode = head;

		while (currentNode != NULL)
		{
			size++;
			currentNode = currentNode->next;
		}

		return size;
	}
};
int main()
{
	LinkedList lst;


	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);
	lst.push_back(6);


	lst.insert(0, 10);
	lst.insert(7, 10);
	lst.insert(3, 10);

	lst.erase(2);

	for (Node* ptr = lst.head; ptr != NULL; ptr = ptr->next)
		std::cout << ptr->data << " ";
	std::cout << std::endl;



	// Размер списка
	int size = 0, i = 0;
	while (lst[i] != NULL) {
		i++;
		size++;
	}

	std::cout << "List Size:" << size << std::endl;

	for (int i = 0; i > 0; i++) {
		lst.push_back(i);
	}
	// Первый элемент
	std::cout << "First element:" << lst.head->data << std::endl;
	// Последний элемент 
	std::cout << "Last element:" << lst.tail->data << std::endl;
	// Элемент из заданной позиции
	std::cout << "Element from randome position:" << lst[3]->data << std::endl;

}