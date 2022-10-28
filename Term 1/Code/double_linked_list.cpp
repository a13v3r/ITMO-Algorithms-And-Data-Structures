#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
struct Node {
	T value;
	Node* next = nullptr;
	Node* prev = nullptr;
};

template <class T>
struct LinkedList {
	Node<T>* first;
	Node<T>* last;
	LinkedList() {
		first = nullptr;
		last = nullptr;
	}
	void Push(T val) {
		Node<T>* new_node = new Node<T>;
		new_node->value = val;
		if (last == nullptr) {
			last = new_node;
			first = new_node;
			return;
		}
		new_node->prev = last;
		last->next = new_node;
		last = new_node;
	}
	void PopFirst() { // deleting first
		if (first->next == nullptr) {
			last = nullptr;
			first = nullptr;
			return;
		}
		first = first->next;
		first->prev = nullptr;
	}
	void PopLast() { // deleting last
		if (last->prev == nullptr) {
			last = nullptr;
			first = nullptr;
			return;
		}
		last = last->prev;
		last->next = nullptr;
	}
	void Insert(T val, uint64_t pos) { // pos = number of postinions after first
		if (last == nullptr) {
			Push(val);
			return;
		}
		Node<T>* new_node = new Node<T>;
		new_node->value = val;
		if (pos == 0) {
			new_node->next = first;
			first->prev = new_node;
			first = new_node;
			return;

		}
		Node<T>* point = first;
		while (pos > 1) {
			pos--;
			point = point->next;
		}

		if (point == last) {
			Push(val);
			return;
		}

		new_node->next = point->next;
		new_node->prev = point;
		point->next->prev = new_node;
		point->next = new_node;
	}
	void Delete(uint64_t pos) { // pos = number of postinions after first
		if (pos == 0) {
			PopFirst();
			return;
		}
		Node<T>* point = first;
		while (pos > 1) {
			pos--;
			point = point->next;
		}
		if (point->next == last) {
			PopLast();
			return;
		}
		point->next->next->prev = point;
		point->next = point->next->next;
	}
	T Front() {
		return first->value;
	}
	T Back() {
		return last->value;
	}
	T Get(uint64_t pos) {
		if (pos == 0) {
			return Front();
		}
		Node<T>* point = first;
		while (pos) {
			pos--;
			point = point->next;
		}
		return point->value;
	}
	T GetMax() {
		T maxel = first->value;
		Node<T>* point = first->next;
		while (point != first) {
			maxel = max(maxel, point->value);
			point = point->next;
		}
		return maxel;
	}
	T GetMin() {
		T minel = first->value;
		Node<T>* point = first->next;
		while (point != first) {
			minel = min(minel, point->value);
			point = point->next;
		}
		return minel;
	}
};

template <class T>
void CommandHandler() {
	cout << "Congratulations! You are using Cycle linked list!\n" <<
			"Using type is int.You can change it. \n" <<
			"Insert number of options, then:\n" <<
			"P value- push(value) moves last\n" <<
			"PF - pop first()\n" <<
			"PL - pop last()\n" <<
			"I value position- insert(value, position) position(>=0) - number of positions after first. If 0,than changes the first\n" <<
			"D position- delete(position) position(>=0) - number of positions after first. If 0,than deletes the first\n" <<
			"F - get front()\n" <<
			"B - get back()\n" <<
			"G position- get(position) position(>=0) - number of positions after first. If 0,than prints the first\n" <<
			"GMA - get max()\n" <<
			"GMI - get min()" << endl << endl;
	LinkedList<T> linked_list;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		if (a == "P") {
			T value;
			cin >> value;
			linked_list.Push(value);
		}
		else if (a == "PF") {
			linked_list.PopFirst();
		}
		else if (a == "PL") {
			linked_list.PopLast();
		}
		else if (a == "I") {
			T value;
			uint64_t pos;
			cin >> value >> pos;
			linked_list.Insert(value, pos);
		}
		else if (a == "D") {
			uint64_t pos;
			cin >> pos;
			linked_list.Delete(pos);
		}
		else if (a == "F") {
			cout << linked_list.Front() << endl;
		}
		else if (a == "B") {
			cout << linked_list.Back() << endl;
		}
		else if (a == "G") {
			uint64_t pos;
			cin >> pos;
			cout << linked_list.Get(pos) << endl;
		}
		else if (a == "GMA") {
			cout << linked_list.GetMax() << endl;
		}
		else if (a == "GMI") {
			cout << linked_list.GetMin() << endl;
		}
		else {
			cout << "Uncorrect option" << endl;
		}
	}
}

int main() {
	CommandHandler<int/*INSERT YOUR DATA TYPE HERE*/>();
}