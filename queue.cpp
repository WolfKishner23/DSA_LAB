#include <iostream>
#include <iomanip>
using namespace std;

class Node{
    public:
        string data;
        int time;
        Node *next;

        Node(string data, int time){
            this->data = data;
            this->time = time;
            this->next = NULL;
        }

};

class Queue{
    private:
        Node *front, *rear;


    public:
        Queue(){
            front = NULL;
            rear = NULL;
        }

        void addTask(string val, int time){
            Node *newNode = new Node(val, time);

            newNode->next = NULL;

            if(rear==NULL){
                front = newNode;
                rear = newNode;
            } else{
                rear->next = newNode;
                rear = newNode;
            }
        }

        void removeTask(){
            if(front==NULL){
                cout << "Queue Underflow\n";
                return;
            }

            Node *temp;
            temp = front;
            front = front->next;

            if(front==NULL){
                rear=NULL;
            }

            delete temp;
        }

        bool isEmpty(){
            return front==NULL;
        }

        void peekTask(){
            if(front==NULL){
                cout << "Queue is empty";
                return;
            }

            cout << front->data;
        }

        void peekTime(){
            if(front==NULL){
                cout << "Queue is empty";
                return;
            }

            cout << front->time;
        }

        void display(){
            if(front==NULL){
                cout << "Queue is empty";
            }

            Node *temp;
            temp = front;

            cout << "\n----------------------------------------------------\n";
            cout << left << setw(8) << "Index" << setw(20) << "Task" << setw(15) << "Time(mins)" << endl;
            cout << "----------------------------------------------------\n";

            cout << endl;
            int i=1;
            while(temp!=NULL){
                cout << left << setw(8) << i << setw(20) << temp->data << setw(15) << temp->time << endl;
                temp = temp->next;
                i++;
            }
            cout << "----------------------------------------------------\n";
        }
};

int main(){

    Queue q;
    int idx=1;

    while(true){
        int choice;
        cout << "Press 1 to insert a task\n";
        cout << "Press 2 to execute a task\n";
        cout << "Press 3 to see the task status\n";
        cout << "Press 4 to exit\n";
        cout << "Enter: ";
        cin >> choice;

        

        if(choice==1){
            string task;
            int time;
            int wait=0;

            cout << "Enter the task " << idx << " : ";
            cin >> task;

            cout << "Enter time: ";
            cin >> time;

            idx++;

            q.addTask(task, time);

            if(idx==1){
                wait = 0;
            } else{
                wait += time;
            }

        } else if(choice == 2){

            if(q.isEmpty()){
                cout << "Nothing to execute\n";
            } else{
                q.removeTask();
                cout << "----------------------------------------------------\n";
                cout << "Topmost task has been executed\n";
                cout << "----------------------------------------------------\n\n";
            }
        } else if(choice == 3){

            if(q.isEmpty()){
                cout << "----------------------------------------------------\n";
                cout << "Nothing to display\n";
                cout << "----------------------------------------------------\n";
            } else{
                cout << "Task Status: " << endl;
                q.display();
            }
        } else if(choice == 4){
            break;
        }
    }


    return 0;
}