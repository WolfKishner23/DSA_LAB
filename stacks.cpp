#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
        string data;
        Node *next;

        Node(string val){
            data=val;
            this->next = NULL;
        }
};

class Stack{
    Node *top;

    public:
        Stack(){
            top=NULL;
        }

        void pushElement(string val){
            Node *newNode = new Node(val);
            newNode->next = top;
            top=newNode;
        }

        void popElement(){
            Node *temp;

            if(top==NULL){
                cout << "Stack Underflow\n"; 
                return;
            }

            temp = top;
            top = top->next;
            delete temp;
        }

        string peekElement(){
            if(top==NULL){
                cout << "Stack is Empty\n";
                return 0;
            }

            return top->data;
        }

        void display(){
            if(top==NULL){
                cout << "Stack is Empty\n";
            }

            Node *temp;
            temp = top;

            cout << endl;
            int i=1;
            while(temp!=NULL){
                cout << i << ". " << temp->data << endl;
                temp = temp->next;
                i++;
            }
            cout << endl;
        }

        bool isEmpty() {
            return top == NULL;
        }                                                                                     
};


int main(){

    Stack s1, s2;

    int entries;
    cout << "Enter the number of entries: ";
    cin >> entries; 
    cin.ignore();

    for(int i=1; i<=entries; i++){
        string text;

        cout << "Entry no. " << i << " : ";
        getline(cin, text);

        s1.pushElement(text);
    }

    cout << "Stack has been initialised\n";

    while(true){
        int choice;
        cout << "------------------------------------\n";
        cout << "Press 1 for undo\n";
        cout << "Press 2 for redo\n";
        cout << "Press 3 for exit\n";
        cout << "Press 4 to display stack\n";
        cout << "------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice==1){
            if(s1.isEmpty()){
                cout << "Nothing to undo\n";
            } else{
                string undoElement = s1.peekElement();
                s2.pushElement(undoElement);
                s1.popElement();

                cout << "Latest element has been undo\n";
                cout << "Current stack status: ";
                s1.display();
            }
        } else if(choice == 2){
            if (s2.isEmpty()) { 
                cout << "Nothing to redo\n";
            } else {
                string redoElement = s2.peekElement();
                s1.pushElement(redoElement);
                s2.popElement();

                cout << "Latest element has been redo\n";
                cout << "Current stack status: ";
                s1.display();
            }            
        } else if(choice == 3){
            break;
        } else if(choice == 4){
            cout << "Current stack status: "; 
            s1.display();
        } else{
            cout << "Enter a valid choice";
            continue;
        }
    }

    return 0;
}