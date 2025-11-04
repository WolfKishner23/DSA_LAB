#include<iostream>
using namespace std;

class CNode{
    public:
        string name,email;
        long long contact;
        CNode* prev=NULL;
        CNode* next=NULL;
};
bool is_valid_number(long long contact){
    //Function to check contact number
    string s=to_string(contact);
    int n=s.length();
    return (n==10);
}
bool is_valid_name(string name){
    //Function to check name 
    int n=name.length();
    for(int i=0;i<n;i++){
        if(!isalpha(name[i])){
            return false;
        }
    }
    return true;
}

bool is_valid_email(string email){
    //Function to check email
    int n=email.length();
    int f1=0,f2=0;
    int temp1=0;
    for(int i=0;i<n;i++){
        if(email[i]=='@'){
            f1++;
            temp1=i;
        }
    }
    if(f1!=1)return false;
    int temp2=0;
    for(int i=0;i<n;i++){
        if(email[i]=='.'){
            f2++;
            temp2=i;
        }
    }
    return (f2==1) && (temp2>temp1);
}
class double_linked_list{
    CNode* head=NULL;
    public:
        CNode* get_node(){
            // Creation of new node
            CNode *node=new CNode;
            bool flag=1;
            do{
                if(!flag)cout<<"Please enter valid details!!\n";
                cout<<"Enter Name,Email,Contact No.:";
                cin>>(node->name);
                cin>>(node->email);
                cin>>(node->contact);
                flag=is_valid_name(node->name) && is_valid_number(node->contact) && is_valid_email(node->email);
            }while(!flag);

            return node;
        }
        void insert_end(){
            // Insert node at the end of list
            CNode* add_node=get_node();
            if(head==NULL)head=add_node;
            else{
                CNode* temp=head;
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                add_node->prev=temp;
                temp->next=add_node;
            }
            cout<<"Inserted at end!!\n";
        }
        void reverse(){
            // Reverse a doubly linked list
            if(head==NULL){
                cout<<"List is empty!!\n";
                return;
            }
            CNode* current,*next;
            current=head;
            next=current->next;
            while(next!=NULL){
                current->next=current->prev;
                current->prev=next;
                current=next;
                next=current->next;
            }
            current->next=current->prev;
            current->prev=NULL;
            head=current;
            cout<<"Reversed!!\n";
        }
        void search(){
            //Search a contact number
            long long key;
            cout<<"Enter Contact No. to search:";
            cin>>key;
            int pos=1;
            CNode* temp=head;
            while(temp!=NULL){
                if(temp->contact==key){
                    cout<<"Contact Number Found at Position "<<pos<<'\n';
                    return;
                }
                pos++;
                temp=temp->next;
            }
            cout<<"Contact Number does not exist in List.";
        }
        void insert_between(){
            //Insert a node at a give valid position
            int pos;
            cout<<"Enter position to insert:";
            cin>>pos;
            if(pos==1){
                cout<<"Invalid Position\n";
                return;
            }
            CNode* temp=head;
            while(temp->next!=NULL && pos>1){
                temp=temp->next;
                pos--;
            }
            CNode* add_node=get_node();
            add_node->prev=temp->prev;
            (temp->prev)->next=add_node;
            add_node->next=temp;
            temp->prev=add_node;
            cout<<"Inserted at given position!!\n";
        }
        void insert_beg(){
            //Insert node at beginning of the list
            CNode* add_node=get_node();
            add_node->next=head;
            head->prev=add_node;
            head=add_node;
            cout<<"Inserted at beginning!!\n";
        }
        void create(){
            //Create the intial doubly linked list
            int n;
            cout<<"Enter number of nodes to add:";
            cin>>n;
            for(int i=0;i<n;i++){
                insert_end();
            }
            cout<<"Double LinkedList created!!";
        }
        void display(){
            //Display doubly linked list
            CNode* temp=head;
            int pos=1;
            while(temp!=NULL){
                cout<<"Node "<<pos<<":\n";
                cout<<"Name:"<<temp->name<<'\n'<<"Contact No.:"<<temp->contact<<"\nEmail:"<<temp->email<<"\n\n";
                pos++;
                temp=temp->next;
            }
        }
        void delete_node(){
            // delete contact number from list
            long long key;
            cout<<"Enter Contact Number to delete:";
            cin>>key;
            CNode* temp=head;
            while(temp!=NULL && temp->contact!=key){
                temp=temp->next;
            }
            if(temp==NULL){
                cout<<"Data not found!!";
                return;
            }
            if(temp==head){
                head=head->next;
                head->prev=NULL;
                delete temp;
            }
            else{
                (temp->prev)->next=temp->next;
                if(temp->next!=NULL)(temp->next)->prev=temp->prev;
                delete temp;
            }
            cout<<"Contact Number Deleted!!\n";
        }
        ~double_linked_list(){
            // Destructor to free the dynamically allocated memory
            CNode* temp=head;
            while(temp!=NULL){
                temp=head->next;
                delete head;
            }
            cout<<"Contact List Destroyed\n";
        }
};

int main(){
    double_linked_list ddl;
    int choice;
    ddl.create();
    do {
        cout<<"\n--- Contact Management Menu ---\n";
        cout<<"1.Insert Contact at Beginning\n";
        cout<<"2.Insert Contact at End\n";
        cout<<"3.Insert Contact at Position\n";
        cout<<"4.Delete Contact by Contact Number\n";
        cout<<"5.Search Contact by Contact Number\n";
        cout<<"6.Reverse Contact List\n";
        cout<<"7.Display Contact List\n";
        cout<<"0.Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch (choice) {
        case 1:
            ddl.insert_beg();
            break;
        case 2:
            ddl.insert_end();
            break;
        case 3:
            ddl.insert_between();
            break;
        case 4:
            ddl.delete_node();
            break;
        case 5:
            ddl.search();
            break;
        case 6:
            ddl.reverse();
            break;
        case 7:
            ddl.display();
            break;
        case 0:
            cout<<"Exiting...\n";
            break;
        default:
            cout<<"Invalid choice! Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}

/*
Output:
Enter number of nodes to add:5
Enter Name,Email,Contact No.:Alice 
alice@gmail.com
9876543210 
Inserted at end!!
Enter Name,Email,Contact No.:Bob
bob@gmail.com
9123456789
Inserted at end!!
Enter Name,Email,Contact No.:Charlie
charlie@gmail.com
9988776655
Inserted at end!!
Enter Name,Email,Contact No.:David
david@gmail.com
9001122334
Inserted at end!!
Enter Name,Email,Contact No.:Eva
eva@gmail.com
9112233445
Inserted at end!!
Double LinkedList created!!
--- Contact Management Menu ---
1.Insert Contact at Beginning
2.Insert Contact at End
3.Insert Contact at Position
4.Delete Contact by Contact Number
5.Search Contact by Contact Number
6.Reverse Contact List
7.Display Contact List
0.Exit
Enter choice: 7
Node 1:
Name:Alice
Contact No.:9876543210
Email:alice@gmail.com

Node 2:
Name:Bob
Contact No.:9123456789
Email:bob@gmail.com

Node 3:
Name:Charlie
Contact No.:9988776655
Email:charlie@gmail.com

Node 4:
Name:David
Contact No.:9001122334
Email:david@gmail.com

Node 5:
Name:Eva
Contact No.:9112233445
Email:eva@gmail.com


--- Contact Management Menu ---
1.Insert Contact at Beginning
2.Insert Contact at End
3.Insert Contact at Position
4.Delete Contact by Contact Number
5.Search Contact by Contact Number
6.Reverse Contact List
7.Display Contact List
0.Exit
Enter choice: 5
Enter Contact No. to search:9988776655
Contact Number Found at Position 3

--- Contact Management Menu ---
1.Insert Contact at Beginning
2.Insert Contact at End
3.Insert Contact at Position
4.Delete Contact by Contact Number
5.Search Contact by Contact Number
6.Reverse Contact List
7.Display Contact List
0.Exit
Enter choice: 4
Enter Contact Number to delete:9001122334
Contact Number Deleted!!

--- Contact Management Menu ---
1.Insert Contact at Beginning
2.Insert Contact at End
3.Insert Contact at Position
4.Delete Contact by Contact Number
5.Search Contact by Contact Number
6.Reverse Contact List
7.Display Contact List
0.Exit
Enter choice: 6
Reversed!!

--- Contact Management Menu ---
1.Insert Contact at Beginning
2.Insert Contact at End
3.Insert Contact at Position
4.Delete Contact by Contact Number
5.Search Contact by Contact Number
6.Reverse Contact List
7.Display Contact List
0.Exit
Enter choice: 0
Exiting...
*/