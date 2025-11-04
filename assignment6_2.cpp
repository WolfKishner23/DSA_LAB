#include <iostream>
using namespace std;

#define SIZE 10

class Node {
public:
    string username;
    string password;
    Node* next;

    Node(string uname,string pass) {
        username=uname;
        password=pass;
        next=NULL;
    }
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head=NULL;
    }

    void insert(string name, string pass) {
        Node* newNode=new Node(name, pass);

        if(head==NULL) {
            head=newNode;
            return;
        }

        Node* temp=head;
        while(temp->next!=NULL)
            temp=temp->next;

        temp->next=newNode;
    }

    void search(string name) {
        Node* temp=head;

        while(temp!=NULL) {
            if (temp->username == name) {
                cout<<"Username:"<< temp->username 
                     <<", Password:"<<temp->password<<endl;
                return;
            }
            temp=temp->next;
        }

        cout<<"Nothing found\n";
    }

    void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout<< temp->username<< " : " << temp->password << " -> ";
            temp=temp->next;
        }

        cout<<"NULL";
    }
};

class HashTable {
    LinkedList table[SIZE];

public:
    void insert() {
        string uname, pass, hashed = "";
        cout<<"Enter username: ";
        cin>>uname;
        cout<<"Enter password: ";
        cin>>pass;

        // Simple password hashing (shift each character by +1)
        for (char c:pass)
            hashed+=char(c + 1);

        int value=0;
        for (char c:uname)
            value += c;

        int index=value % SIZE;
        table[index].insert(uname, hashed);
    }

    void search() {
        string uname;
        cout << "Enter username to search: ";
        cin >> uname;

        int value = 0;
        for (char c : uname)
            value += c;

        int index = value % SIZE;
        table[index].search(uname);
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << i << ": ";
            table[i].display();
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;
    int choice;

    cout << "==== HASH TABLE USING CHAINING ====\n";

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Display\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: ht.insert(); break;
            case 2: ht.search(); break;
            case 3: ht.display(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice!=0);

    return 0;
}
