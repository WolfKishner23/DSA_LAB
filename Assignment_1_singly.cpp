/*
    "Efficient Data Management Using Linked Lists: Implementing
Dynamic Operations for Contact Management System"
Utilize Singly and Doubly Linked Lists to manage a Contact
Management System. The system will support key operations such as:
• Creating a contact list dynamically.
• Adding new contacts efficiently.
• Deleting contacts when no longer needed.
• Searching for specific contacts based on name or number.
• Reversing the contact list for alternate viewing orders.
• Traversing through the list to display all stored contacts.
*/
#include<iostream>
using namespace std;

typedef struct Contact_Node{
    string name;
    string email;
    long long contact;
    Contact_Node* next;
} CNode;

bool is_valid_number(long long contact){
    //function to check contact number
    string s=to_string(contact);
    int n=s.length();
    return (n==10); 
}
bool is_valid_name(string name){
    //function to check name
    int n=name.length();
    for(int i=0;i<n;i++){
        if(!isalpha(name[i])){
            return false;
        }
    }
    return true;
}

bool is_valid_email(string email){
    //function to check email
    int n=email.length();
    int f1=0,f2=0;
    int temp=0;
    for(int i=0;i<n;i++){
        if(email[i]=='@'){
            f1++;
            temp=i;
        }
    }
    if(f1!=1)return false; // only 1 @ required
    for(int i=temp;i<n;i++){
        if(email[i]=='.')f2++;
    }
    return (f2==1); // only 1 . required after @
}
class Contact_List{
    CNode *head=NULL;
    public:
        CNode* get_node(){
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
        void create(){
            //create the intial singly linked list
            cout<<"Enter No. of Nodes to Add:";
            int num;
            cin>>num;
            for(int i=0;i<num;i++){
                insert_end();
            }
            cout<<"List Created!!\n";
        }
        void insert_beg(){
            //insert node at the beginning of singly linked list
            CNode* New_Node=get_node();
            if(head==NULL){ // If list is empty
                head=New_Node;
            }
            else{
                New_Node->next=head;
                head=New_Node;
            }
            cout<<"Inserted Node at beginning!!\n";
        }
        void insert_end(){
            //insert node at the end of singly linked list
            CNode* New_Node=get_node();
            if(head==NULL){
                head=New_Node;
            }
            else{
                CNode* temp=head;
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=New_Node;
            }
            cout<<"Inserted Node at end!!\n";
        }
        void insert_position(){
            //insert node at the given position of singly linked list
            int pos;
            cout<<"Enter Position for node to be inserted:";
            cin>>pos;
            if(pos==1){
                cout<<"Invalid Position.\n";
                return;
            }
            else{
                CNode* temp=head;
                for(int i=1;i<pos-1;i++){
                    if(temp->next==NULL){
                        cout<<"Invalid Position.\n";
                        return;
                    }
                    temp=temp->next;
                }
                CNode* New_Node=get_node();
                New_Node->next=temp->next;
                temp->next=New_Node;
                
            }
        }
        void delete_node(){
            // delete contact number from list
            long long key;
            cout<<"Enter Contact Number to delete:";
            cin>>key;
            CNode* temp=head;
            CNode* prev=head;
            while(temp!=NULL && temp->contact!=key){
                prev=temp;
                temp=temp->next;
            }
            if(temp==NULL){
                cout<<"Data not found!!";
            }
            else{
                if(temp==head){
                    head=head->next;
                    delete temp;
                }
                else{
                    prev->next=temp->next;
                    delete temp;
                }
                cout<<"Contact Number Deleted!!\n";
            }
        }
        void search(){
            //search for contact number
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
        void reverse(){
            //reverse singly linked list
            if(head==NULL){
                cout<<"List is empty!!\n";
                return;
            }
            CNode* prev,*current,*next;
            prev=NULL;
            current=head;
            next=current->next;
            while(next!=NULL){
                current->next=prev;
                prev=current;
                current=next;
                next=current->next;
            }
            current->next=prev;
            head=current;
        }
        void display(){
            //dispaly singly linked list
            CNode* temp=head;
            int pos=1;
            while(temp!=NULL){
                cout<<"Node "<<pos<<":\n";
                cout<<"Name:"<<temp->name<<'\n'<<"Contact No.:"<<temp->contact<<"\nEmail:"<<temp->email<<"\n\n";
                pos++;
                temp=temp->next;
            }
        }
        ~Contact_List(){
            //Destructor to free the dynamically allocated memory
            CNode* temp=head;
            while(temp!=NULL){
                temp=head->next;
                delete head;
            }
            cout<<"Contact List Destroyed\n";
        }
};
int main(){
    Contact_List list;
    list.create();
    int choice;
    do {
        cout<<"\n---- Contact List Menu ----\n";
        cout<<"1.Insert at Beginning\n";
        cout<<"2.Insert at End\n";
        cout<<"3.Insert at Position\n";
        cout<<"4.Delete Contact by Contact Number\n";
        cout<<"5.Search by Contact No.\n";
        cout<<"6.Reverse List\n";
        cout<<"7.Display List\n";
        cout<<"0.Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch (choice) {
            case 1:
                list.insert_beg();
                break;
            case 2:
                list.insert_end();
                break;
            case 3:
                list.insert_position();
                break;
            case 4:
                list.delete_node();
                list.display();
                break;
            case 5:
                list.search();
                break;
            case 6:
                list.reverse();
                cout<<"List reversed.\n";
                list.display();
                break;
            case 7:
                list.display();
                break;
            case 0:
                cout<<"Exiting...\n";
                break;
            default:
                cout<<"Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}

/*
Output:
Enter No. of Nodes to Add:5
Enter Name,Email,Contact No.:Alice
alice@gmail.com
9876543210
Inserted Node at end!!
Enter Name,Email,Contact No.:Bob
bob@gmail.com
9123456789
Inserted Node at end!!
Enter Name,Email,Contact No.:Charlie
charlie@gmail.com
9988776655
Inserted Node at end!!
Enter Name,Email,Contact No.:David
david@gmail.com
9001122334
Inserted Node at end!!
Enter Name,Email,Contact No.:Eva
eva@gmail.com
9112233445
Inserted Node at end!!
List Created!!

---- Contact List Menu ----
1.Insert at Beginning
2.Insert at End
3.Insert at Position
4.Delete Contact by Contact Number
5.Search by Contact No.
6.Reverse List
7.Display List
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


---- Contact List Menu ----
1.Insert at Beginning
2.Insert at End
3.Insert at Position
4.Delete Contact by Contact Number
5.Search by Contact No.
6.Reverse List
7.Display List
0.Exit
Enter choice: 5
Enter Contact No. to search:9988776655
Contact Number Found at Position 3

---- Contact List Menu ----
1.Insert at Beginning
2.Insert at End
3.Insert at Position
4.Delete Contact by Contact Number
5.Search by Contact No.
6.Reverse List
7.Display List
0.Exit
Enter choice: 4
Enter Contact Number to delete:9001122334
Contact Number Deleted!!
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
Name:Eva
Contact No.:9112233445
Email:eva@gmail.com


---- Contact List Menu ----
1.Insert at Beginning
2.Insert at End
3.Insert at Position
4.Delete Contact by Contact Number
5.Search by Contact No.
6.Reverse List
7.Display List
0.Exit
Enter choice: 6
List reversed.
Node 1:
Name:Eva
Contact No.:9112233445
Email:eva@gmail.com

Node 2:
Name:Charlie
Contact No.:9988776655
Email:charlie@gmail.com

Node 3:
Name:Bob
Contact No.:9123456789
Email:bob@gmail.com

Node 4:
Name:Alice
Contact No.:9876543210
Email:alice@gmail.com


---- Contact List Menu ----
1.Insert at Beginning
2.Insert at End
3.Insert at Position
4.Delete Contact by Contact Number
5.Search by Contact No.
6.Reverse List
7.Display List
0.Exit
Enter choice: 0
Exiting...
*/