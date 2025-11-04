/*Create a student database of at least 5 SEIT students, each having:
• Roll Number (Integer)
• Name (String)
• SGPA (Float)
Perform the following operations on the array of structure:
a. Sort students by roll number (ascending order) using Bubble Sort.
b. Sort students alphabetically by name using Insertion Sort.
c. Sort students by SGPA in descending order using Quick Sort to get top 10 toppers.
d. Search for students by SGPA using Linear Search and display all matches.
e. Search for student(s) by name using non-recursive Binary Search, display all partial matches.
f. Display all Students
*/

#include<iostream>
#include<cstring>

using namespace std;
struct Student{
    // Node Structure
    string name;
    int roll_no;
    float SGPA; 
};

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

bool is_valid_SGPA(float SGPA){
    return (SGPA>=0 && SGPA<=10.0);
}
int partition(struct Student s[],int low,int high){
    // Partition function for Quick Sort
    float pivot=s[low].SGPA;
    int i=low+1;
    int j=high;
    while(i<=j){
        while(i<=high && (s[i].SGPA)>=pivot)i++;
        while(j>=low && (s[j].SGPA)<pivot)j--;
        // cout<<i<<' '<<j<<'\n';
        if(i<j)swap(s[i],s[j]);
    }
    swap(s[j],s[low]);
    return j;
}
class Class{
    public: 
        Class(struct Student s[],int n){
            for(int i=0;i<n;i++){
                // Input for each student
                // Validation
                bool flag1=false,flag2=true,flag3=false;
                do{
                    if(!flag1){
                        cout<<"Enter name of Student "<<(i+1)<<":";
                        cin>>s[i].name;
                        flag1=is_valid_name(s[i].name);
                    }
                    if(flag2){
                        cout<<"Enter Roll no. of Student "<<(i+1)<<":";
                        cin>>s[i].roll_no;
                        flag2=false;
                    }
                    if(!flag3){
                        cout<<"Enter SGPA of Student "<<(i+1)<<":";
                        cin>>s[i].SGPA;
                        flag3=is_valid_SGPA(s[i].SGPA);
                    }
                    if(!(flag1 && flag3))cout<<"Please enter valid details\n";
                }while(!(flag1 &&flag3));
            }
        }
        void display(struct Student s[],int n){
            // Display Student's Details
            for(int i=0;i<n;i++){
                cout<<"Name:"<<s[i].name<<'\n';
                cout<<"Roll No.:"<<s[i].roll_no<<'\n';
                cout<<"SGPA:"<<s[i].SGPA<<"\n\n";
            }
        }
        void linear_search(struct Student s[],int n,float key){
            //Find Student by SGPA
            bool flag=0;
            for(int i=0;i<n;i++){
                if(s[i].SGPA==key){
                    flag=1;
                    cout<<"Name:"<<s[i].name<<'\n';
                    cout<<"Roll No.:"<<s[i].roll_no<<'\n';
                    cout<<"SGPA:"<<s[i].SGPA<<"\n\n";
                    break;
                }
            }
            if(!flag){
                cout<<"No Record Found!!\n";
            }
        }
        void bubble_sort(struct Student s[],int n){
            // Sorting in ascending order by Roll Number
            for(int i=0;i<n;i++){
                for(int j=0;j<n-i-1;j++){
                    if(s[j].roll_no>s[j+1].roll_no)swap(s[j],s[j+1]);
                }
            }
        }
        void insertion_sort(struct Student s[],int n){
            // Sorting in ascending order by name
            for(int i=1;i<n;i++){
                int j=i-1;
                while(j>=0 && s[j].name>s[j+1].name){
                    swap(s[j],s[j+1]);
                    j--;
                }
            }
        }
        void quick_sort(struct Student s[],int n,int low,int high){
            // Quick sort algorithm to sort in descending order
            cout<<low<<' '<<high<<'\n';
            if(low<high){
                int pi=partition(s,low,high);
                quick_sort(s,n,low,pi-1);
                quick_sort(s,n,pi+1,high);
            }
        }
        void binary_search(struct Student s[],int n){
            // Sorting and then searching using binary search
            insertion_sort(s,n);
            string key;
            cout<<"Enter name to search:";
            cin>>key;
            int i=0,j=n-1;
            while(i<=j){
                int mid=(i+j)/2;
                if(s[mid].name>key)j=mid-1;
                else if(s[mid].name<key)i=mid+1;
                else{
                    cout<<"Name found!!\n";
                    return;
                }
            }
            cout<<"Name not found!!\n";
        }
};

int main(){
    int n;
    cout<<"Enter Number of Students:";
    cin>>n;
    struct Student s[n];
    Class obj(s,n);
    while(true){
        cout<<"Enter Operation No.\n";
        cout<<"1.Display Students\n";
        cout<<"2.Find Student with SGPA\n";
        cout<<"3.Sort According to Roll Number\n";
        cout<<"4.Sort According to Name\n";
        cout<<"5.Search for Name\n";
        cout<<"6.Display Toppers\n";
        cout<<"7.Exit\n";
        int choice;
        cin>>choice;
        
        switch(choice){
            case 1:
                obj.display(s,n);
                break;
            case 2:
                float key;
                cout<<"Enter SGPA to find:";
                cin>>key;
                obj.linear_search(s,n,key);
                break;
            case 3:
                obj.bubble_sort(s,n);
                cout<<"After Sorting according to Roll Number\n";
                obj.display(s,n);
                break;
            case 4:
                obj.insertion_sort(s,n);
                cout<<"After Sorting according to Name\n";
                obj.display(s,n);
                break;
            case 5:
                obj.binary_search(s,n);
                break;
            case 6:
                obj.quick_sort(s,n,0,n-1);
                cout<<"Displaying toppers:\n";
                for(int i=0;i<min(10,n);i++){
                    cout<<"Name:"<<s[i].name<<'\n';
                    cout<<"Roll No.:"<<s[i].roll_no<<'\n';
                    cout<<"SGPA:"<<s[i].SGPA<<"\n\n";
                }
                break;
            case 7:
                cout<<"Exiting, bye!!\n";
                exit(0);
            default:
                cout<<"Invalid Choice Entered!!\n";
        }
    }
    return 0;
}

/*
    Output:
    Enter Number of Students:5
Enter name of Student 1:Alice
Enter Roll no. of Student 1:1
Enter SGPA of Student 1:9.2
Enter name of Student 2:Bob
Enter Roll no. of Student 2:2
Enter SGPA of Student 2:8.5
Enter name of Student 3:Charlie
Enter Roll no. of Student 3:3
Enter SGPA of Student 3:7.8
Enter name of Student 4:David
Enter Roll no. of Student 4:4
Enter SGPA of Student 4:9.5
Enter name of Student 5:Eve
Enter Roll no. of Student 5:5
Enter SGPA of Student 5:8.9
Enter Operation No.
1.Display Students
2.Find Student with SGPA
3.Sort According to Roll Number
4.Sort According to Name
5.Search for Name
6.Display Toppers
7.Exit
5
Enter name to search:Eve
Name found!!
Enter Operation No.
1.Display Students
2.Find Student with SGPA
3.Sort According to Roll Number
4.Sort According to Name
5.Search for Name
6.Display Toppers
7.Exit
2
Enter SGPA to find:7.8
Name:Charlie
Roll No.:3
SGPA:7.8

Enter Operation No.
1.Display Students
2.Find Student with SGPA
3.Sort According to Roll Number
4.Sort According to Name
5.Search for Name
6.Display Toppers
7.Exit
4
After Sorting according to Name
Name:Alice
Roll No.:1
SGPA:9.2

Name:Bob
Roll No.:2
SGPA:8.5

Name:Charlie
Roll No.:3
SGPA:7.8

Name:David
Roll No.:4
SGPA:9.5

Name:Eve
Roll No.:5
SGPA:8.9

Enter Operation No.
1.Display Students
2.Find Student with SGPA
3.Sort According to Roll Number
4.Sort According to Name
5.Search for Name
6.Display Toppers
7.Exit
3
After Sorting according to Roll Number
Name:Alice
Roll No.:1
SGPA:9.2

Name:Bob
Roll No.:2
SGPA:8.5

Name:Charlie
Roll No.:3
SGPA:7.8

Name:David
Roll No.:4
SGPA:9.5

Name:Eve
Roll No.:5
SGPA:8.9

Enter Operation No.
1.Display Students
2.Find Student with SGPA
3.Sort According to Roll Number
4.Sort According to Name
5.Search for Name
6.Display Toppers
7.Exit
6
0 4
0 0
2 4
2 3
2 1
3 3
5 4
Displaying toppers:
Name:David
Roll No.:4
SGPA:9.5

Name:Alice
Roll No.:1
SGPA:9.2

Name:Eve
Roll No.:5
SGPA:8.9

Name:Bob
Roll No.:2
SGPA:8.5

Name:Charlie
Roll No.:3
SGPA:7.8

Enter Operation No.
1.Display Students
2.Find Student with SGPA
3.Sort According to Roll Number
4.Sort According to Name
5.Search for Name
6.Display Toppers
7.Exit
7
Exiting, bye!!
*/