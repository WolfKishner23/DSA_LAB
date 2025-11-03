#include <bits/stdc++.h>
using namespace std;

// ================= Priority Queue =================
class Node {
public:
    int data, priority;
    Node* next;

    Node(int data, int priority = 0) {
        this->data = data;
        this->priority = priority;
        this->next = nullptr;
    }
};

class PQ {
public:
    Node* front;

    PQ() {
        front = nullptr;
    }

    void enqueue(int d, int p) {
        Node* newNode = new Node(d, p);
        if (front == nullptr) {
            front = newNode;
        } else if (newNode->priority > front->priority) {
            newNode->next = front;
            front = newNode;
        } else {
            Node* temp = front;
            while (temp->next != nullptr && temp->next->priority >= newNode->priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    int peek() {
        if (front != nullptr)
            return front->data;
        else
            return -1;
    }

    int extract_max() {
        if (front == nullptr)
            return -1;
        Node* temp = front;
        int val = front->data;
        front = front->next;
        delete temp;
        return val;
    }

    bool isempty() {
        return front == nullptr;
    }

    void display() {
        if (isempty()) {
            cout << "Priority Queue is empty.\n";
            return;
        }
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << "(" << temp->priority << ") -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// ================= Dequeue =================
class DqNode {
public:
    int data;
    DqNode* next;
    DqNode* prev;

    DqNode(int d) {
        data = d;
        next = prev = nullptr;
    }
};

class Dequeue {
private:
    DqNode* front;
    DqNode* rear;

public:
    Dequeue() {
        front = rear = nullptr;
    }

    bool isempty() {
        return front == nullptr;
    }

    void enqueueFront(int d) {
        DqNode* newNode = new DqNode(d);
        if (isempty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void enqueueRear(int d) {
        DqNode* newNode = new DqNode(d);
        if (isempty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    void dequeueFront() {
        if (isempty()) {
            cout << "Nothing to remove\n";
            return;
        }
        DqNode* temp = front;
        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }
        delete temp;
    }

    void dequeueRear() {
        if (isempty()) {
            cout << "Nothing to remove\n";
            return;
        }
        DqNode* temp = rear;
        if (front == rear) {
            front = rear = nullptr;
        } else {
            rear = rear->prev;
            rear->next = nullptr;
        }
        delete temp;
    }

    void display() {
        if (isempty()) {
            cout << "Dequeue is empty.\n";
            return;
        }
        DqNode* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// ================= Main (Menu-Driven) =================
int main() {
    PQ pq;
    Dequeue dq;
    int mainChoice;

    do {
        cout << "\n==================== MENU ====================\n";
        cout << "1. Priority Queue Operations\n";
        cout << "2. Dequeue Operations\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice) {
            // ---------- PRIORITY QUEUE ----------
            case 1: {
                int choice;
                do {
                    cout << "\n---- Priority Queue ----\n";
                    cout << "1. Enqueue\n";
                    cout << "2. Extract Max\n";
                    cout << "3. Peek (Top Element)\n";
                    cout << "4. Display\n";
                    cout << "5. Back to Main Menu\n";
                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch (choice) {
                        case 1: {
                            int data, priority;
                            cout << "Enter data: ";
                            cin >> data;
                            cout << "Enter priority: ";
                            cin >> priority;
                            pq.enqueue(data, priority);
                            break;
                        }
                        case 2: {
                            int val = pq.extract_max();
                            if (val == -1)
                                cout << "Queue is empty.\n";
                            else
                                cout << "Extracted max element: " << val << endl;
                            break;
                        }
                        case 3:
                            if (!pq.isempty())
                                cout << "Top element: " << pq.peek() << endl;
                            else
                                cout << "Queue is empty.\n";
                            break;
                        case 4:
                            pq.display();
                            break;
                        case 5:
                            cout << "Returning to main menu...\n";
                            break;
                        default:
                            cout << "Invalid choice.\n";
                    }
                } while (choice != 5);
                break;
            }

            // ---------- DEQUEUE ----------
            case 2: {
                int choice;
                do {
                    cout << "\n---- Dequeue ----\n";
                    cout << "1. Enqueue Front\n";
                    cout << "2. Enqueue Rear\n";
                    cout << "3. Dequeue Front\n";
                    cout << "4. Dequeue Rear\n";
                    cout << "5. Display\n";
                    cout << "6. Back to Main Menu\n";
                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch (choice) {
                        case 1: {
                            int val;
                            cout << "Enter value: ";
                            cin >> val;
                            dq.enqueueFront(val);
                            break;
                        }
                        case 2: {
                            int val;
                            cout << "Enter value: ";
                            cin >> val;
                            dq.enqueueRear(val);
                            break;
                        }
                        case 3:
                            dq.dequeueFront();
                            break;
                        case 4:
                            dq.dequeueRear();
                            break;
                        case 5:
                            dq.display();
                            break;
                        case 6:
                            cout << "Returning to main menu...\n";
                            break;
                        default:
                            cout << "Invalid choice.\n";
                    }
                } while (choice != 6);
                break;
            }

            case 3:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (mainChoice != 3);

    return 0;
}