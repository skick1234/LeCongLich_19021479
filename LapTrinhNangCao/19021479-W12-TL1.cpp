#include <bits/stdc++.h>
using namespace std;

struct Node {
    int stt;
    Node *next;
    Node *prev;

    Node(int stt = NULL, Node *n = NULL) {
        stt = stt;
        next = n;
        prev = NULL;
    }
};
struct Doubly_Linked_List {
    Node *head;
    Node *tail;

    Doubly_Linked_List() {
        head = NULL;
        tail = NULL;
    }
    void print() {
        for (Node *p = head; p != NULL; p = p->next) {
            cout << p->stt << " ";
        }
        cout << endl;
    }
    void addFirst(int stt) {
        Node *newNode;
        newNode = new Node();
        newNode->stt = stt;
        newNode->prev = NULL;
        newNode->next = head;

        if (head == NULL)
            tail = newNode;
        else
            head->prev = newNode;
        head = newNode;
    }
    void addAfter(Node *node, int stt) {
        Node *newNode;
        newNode = new Node();
        newNode->stt = stt;
        newNode->prev = node;
        newNode->next = node->next;
        node->next = newNode;
        if (node->next == NULL)
            tail = newNode;
    }
    void addBefore(Node *node, int stt) {
        Node *newNode;
        newNode = new Node();
        newNode->stt = stt;
        newNode->next = node;
        newNode->prev = node->prev;
        node->prev = newNode;
        if (node->prev == NULL)
            head = newNode;
    }
    void addLast(int stt) {
        Node *newNode;
        newNode = new Node();
        newNode->stt = stt;
        newNode->prev = tail;
        newNode->next = NULL;
        if (tail == NULL)
            head = newNode;
        else
            tail->next = newNode;
        tail = newNode;
    }
    void deleteNode(Node *node) {
        if (node->prev == NULL) {
            head = node->next;
            head->prev = NULL;
        } else if (node->next == NULL) {
            tail = node->prev;
            tail->next = NULL;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        delete node;
    }
};

int main() {
	system("cls");
    Doubly_Linked_List list;
    int n, k;
    do {
        cout << "Nhap so nguoi choi > 1: ";
        cin >> n;
    } while (n <= 1);
    do {
        cout << "Nhap so dem > 0: ";
        cin >> k;
    } while (k <= 0);
	for (int i = 1; i <= n; i++)
		list.addLast(i);
    Node* current = list.head;
    cout << "So thu tu con lai sau moi luot la: " << endl;
    while (list.head != list.tail) {
        list.print();
        for (int i = 0; i < k; i++)
            current = (current == list.tail ? list.head : current->next);
        list.deleteNode(current->prev);
    }
    list.print();
    return 0;
}