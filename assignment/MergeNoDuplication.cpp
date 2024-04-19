using namespace std;
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <unordered_set>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insert(Node*& head, int val) {             //O(1)
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        newNode->next = head;
    }
    else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}
void sortCircularList(Node*& head) {               //T=O(n^2)        S=O(1)
    if (!head || !head->next) return;

    Node* current = head;
    do {
        Node* nextNode = current->next;
        do {
            if (current->data > nextNode->data) {
                int temp = current->data;
                current->data = nextNode->data;
                nextNode->data = temp;
            }
            nextNode = nextNode->next;
        } while (nextNode != head);
        current = current->next;
    } while (current->next != head);
}

Node* mergeCircularLists(Node* head1, Node* head2) {              //T&S=O(n+m)
    if (!head1) return head2;
    if (!head2) return head1;

    Node* result = nullptr;
    Node* current = nullptr;

    unordered_set<int> seen;

    Node* temp1 = head1;
    Node* temp2 = head2;

    do {                                               //O(n)
        if (seen.find(temp1->data) == seen.end()) {
            seen.insert(temp1->data);
            insert(result, temp1->data);
        }

        temp1 = temp1->next;
    } while (temp1 != head1);

    do {                                           //O(m)
        if (seen.find(temp2->data) == seen.end()) {
            seen.insert(temp2->data);
            insert(result, temp2->data);
        }

        temp2 = temp2->next;
    } while (temp2 != head2);
    sortCircularList(result);
    return result;
}

void displayCircularList(Node* head) {               //O(n)
    if (!head) return;

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;

    insert(list1, 1);
    insert(list1, 2);
    insert(list1, 4);
    insert(list1, 5);
    insert(list1, 30);

    insert(list2, 3);
    insert(list2, 4);
    insert(list2, 20);
    insert(list2, 50);

    cout << "List 1: ";
    displayCircularList(list1);

    cout << "List 2: ";
    displayCircularList(list2);

    Node* result = mergeCircularLists(list1, list2);

    cout << "Merged List Without Duplicates: ";
    displayCircularList(result);

    return 0;
}


