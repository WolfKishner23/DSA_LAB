//to iplement hashing using linear probing 
#include <bits/stdc++.h>
using namespace std;


bool isvalidname(string name){
    if(name.empty()){
        return false;
    }
    for(char c:name){
    if(!isalpha(c)&& c!=' '){
        return false;
    }
}
    return true;
}


bool isvalidrollno(int r){
    return r>0;
}

struct Record{
    string name;
    string password;
    int roll_no;
    bool occupied;
};


class HashTable{
    Record Table[10];
    public:
    HashTable(){
        for(int i=0;i<10;i++){
            Table[i].occupied=false;
        }
    }
    int hash_function(string name){
        int sum=0;
        for(int i=0;i<name.length();i++){
            sum+=name[i];
        }
        return sum%10;
    }
    
    void insert(string name,string password,int roll_no){
        int index=hash_function(name);
        int start=index;
        while(Table[index].occupied){
            index=(index+1)%10;
            if(index==start){
                cout<<"HashTable Full,cannot insert";
                return;
            }}
            
            Table[index].name=name;
            Table[index].roll_no=roll_no;
            Table[index].password=password;
            Table[index].occupied=true;
        
    }
    
    void search(string name){
        int index=hash_function(name);
        int start=index;
        while(Table[index].occupied){
            if(Table[index].name==name){
                cout<<"Record found at index"<<index<<endl;
                cout<<Table[index].name;
                cout<<Table[index].password;
                cout<<Table[index].roll_no;
                
            }
            index=(index+1)%10;
            if(start==index){
                cout<<"No such record found";
                return;
            }
            
        }
    }
    
    void display(){
        for(int i=0;i<10;i++){
            if(Table[i].occupied){
                cout<<Table[i].name;
                cout<<Table[i].password;
                cout<<Table[i].roll_no;
            }
        }
    }
};



int main(){
    HashTable h;
    int choice;
    string name;
    string password;
    int roll_no;
    bool occupied;
    
    
    do{
        cout<<"Enter ur choice\n1.Insert\n2.Display\n3.Search\n4.Exit\nEnter ur choice";
        cin>>choice;
        
        
        switch(choice){
            case 1:
            cin>>name;
            if(!isvalidname(name)){
                cout<<"Invalid name pls try again";
                
            }
            cin>>roll_no;
            if(!isvalidrollno(roll_no)){
                cout<<"Invalid roll no ";
            
            }
            cin>>password;
            
            h.insert(name,password,roll_no);
            
            
            
            case 2:
            h.display();

            case 3:
            
            cin>>name;
            h.search(name);
            
            
        }
        
        
        
    }while(choice!=4);
    return 0;
}