#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

void insert(Node*& head, int val) {                //T&S=O(1)
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void displayList(Node* head) {             //T=O(n)       S=O(1)
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

pair<Node*, Node*> splitDoublyList(Node* head) {         //T=O(n)        S=O(1)
    if (!head || !head->next) {
        return {head, nullptr};
    }

    Node* slow = head;
    Node* fast = head->next;

   
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* firstHalfEnd = slow;
    Node* secondHalfStart = slow->next;
    firstHalfEnd->next = nullptr;
    secondHalfStart->prev = nullptr;

    return {head, secondHalfStart};
}

int main() {
    Node* head = nullptr;

    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);

    cout << "Original Doubly Linked List: ";
    displayList(head);

    pair<Node*, Node*> halves = splitDoublyList(head);

    cout << "First Half: ";
    displayList(halves.first);

    cout << "Second Half: ";
    displayList(halves.second);

    return 0;
}
