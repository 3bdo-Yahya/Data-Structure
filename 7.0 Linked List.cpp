#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
};
node* head = NULL;

//Insertion at the beginning
void insertatbegin(int data) {
	//create a link
	node* lk = new node();
	lk->data = data;
	// point it to old first node
	lk->next = head;
	//point first to new first node
	head = lk;
}

//Insertion at the end
void insertatend(int data) {
	//create a link
	node* lk = new node();
	lk->data = data;
	node* linkedlist = head;
	// point it to old first node
	while (linkedlist->next != NULL)
		linkedlist = linkedlist->next;
	//point first to new first node
	linkedlist->next = lk;
}

//Insertion at a given position
void insertafternode(node* list, int data) {
	node* lk = new node();
	lk->data = data;
	lk->next = list->next;
	list->next = lk;
}

//Deletion from the beginning
void deleteatbegin() {
	head = head->next;
}

//Deletion from the end
void deleteatend() {
	node* linkedlist = head;
	while (linkedlist->next->next != NULL)
		linkedlist = linkedlist->next;
	linkedlist->next = NULL;
}

//Deletion from a given position
void deletenode(int key) {
	node* temp = head, * prev = NULL;
	if (temp != NULL && temp->data == key) {
		head = temp->next;
		return;
	}
	// Find the key to be deleted
	while (temp != NULL && temp->data != key) {
		prev = temp;
		temp = temp->next;
	}
	// If the key is not present
	if (temp == NULL) return;
	// Remove the node
	prev->next = temp->next;
}

// display the list
void printList() {
	node* p = head;
	cout << "\n[";
	//start from the beginning
	while (p != NULL) {
		cout << " " << p->data << " ";
		p = p->next;
	}
	cout << "]";
}

int main() {
	insertatbegin(22);
	insertatbegin(4);
	insertafternode(head, 12);
	insertafternode(head->next->next, 30);
	insertatend(44);
	insertatend(50);

	cout << "Linked List: ";
	printList();

	deleteatbegin();

	deleteatend();

	deletenode(30);

	cout << "\n\nLinked List after deletion: ";
	printList();
}