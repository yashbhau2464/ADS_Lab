#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
class lms{
    public:
int id, price, copies;
string title, author,publisher, isbn;
lms *next;
void accept();
void display();
void search();
void update();
void Delete();
void sort();
void count();
void swapdata(lms *a,lms *b);
}*start, *end1;

void lms:: accept(){
lms *newnode;
newnode=new lms;
cout<<endl<<"Enter book id: ";
cin>>newnode->id;
cout<<endl<<"Enter book title: ";
cin>>newnode->title;
cout<<endl<<"Enter author name: ";
cin>>newnode->author;
cout<<endl<<"Enter publisher name: ";
cin>>newnode->publisher;
cout<<endl<<"Enter price: ";
cin>>newnode->price;
cout<<endl<<"Enter ISBN number: ";
cin>>newnode->isbn;
cout<<endl<<"Enter number of copies available: ";
cin>>newnode->copies;
newnode->next=NULL;
if(start==NULL){
    end1=start=newnode;
}
else{
    end1->next=newnode;
    end1=newnode;
}

}
void lms:: display(){
    cout<<"\n--------------Library Data---------------\n"<<endl;
    lms *temp=start;
    if(temp==NULL){
        cout<<"\nList is empty.";
    }
    else{   cout << setw(10) << left <<"Book ID";
            cout << setw(20) << left <<"Book name";
            cout << setw(20) << left <<"Author";
            cout << setw(20) << left <<"Publisher";
            cout << setw(10) << left <<"Price";
            cout << setw(10) << left <<"ISBN";
            cout << setw(10) << left <<"Copies"<<endl;
            while(temp!=NULL){
            cout<<endl;
            cout << setw(10) << left <<temp->id;;
            cout << setw(20) << left <<temp->title;;
            cout << setw(20) << left <<temp->author;
            cout << setw(20) << left <<temp->publisher;
            cout << setw(10) << left <<temp->price;
            cout << setw(10) << left <<temp->isbn;
            cout << setw(10) << left <<temp->copies<<endl;
            temp=temp->next;
            }
    }
}
void lms:: search(){
    int bid,flag=0;
    lms *temp=start;
    
    cout<<"\nEnter the id of the book you want to search: ";
    cin>>bid;
    while(temp!=NULL){
        if(bid==temp->id){
            flag=1;
            break;
        }
        temp=temp->next;
        
    }
    if(flag==1){
        cout<<"\nBook found."<<endl;
            cout << setw(10) << left <<"Book ID";
            cout << setw(20) << left <<"Book name";
            cout << setw(20) << left <<"Author";
            cout << setw(20) << left <<"Publisher";
            cout << setw(10) << left <<"Price";
            cout << setw(10) << left <<"ISBN";
            cout << setw(10) << left <<"Copies"<<endl;
            cout<<endl;
            cout << setw(10) << left <<temp->id;;
            cout << setw(20) << left <<temp->title;;
            cout << setw(20) << left <<temp->author;
            cout << setw(20) << left <<temp->publisher;
            cout << setw(10) << left <<temp->price;
            cout << setw(10) << left <<temp->isbn;
            cout << setw(10) << left <<temp->copies<<endl;
            //temp=temp->next;
    }
    else{
        cout<<"\nBook not found";
    }
    
}
void lms:: update(){
    lms *temp=start;
    int bid,ch3,price1,copies1,flag1=0;
    string isbn1, title1, author1,publisher1;
            cout<<"\nEnter the book ID whose details you want to update: ";
            cin>>bid;
            while(temp!=NULL){
                if(temp->id==bid){
                    flag1=1;
                    break;
                }
                temp=temp->next;
            }
            if(flag1==0){
                cout<<"\nBook ID not found.";
            }
            else{
                cout<<"\nWhat do you want to update?\n1.Book name\n2.Author\n3.Publisher name\n4.Price\n5.ISBN number\n6.Number of copies\nEnter your choice: ";
            cin>>ch3;
            switch(ch3){
                case 1:
                cout<<"\nEnter new book name: ";
                cin>>title1;
                        temp->title=title1;
                break;

                case 2:
                cout<<"\nEnter new author: ";
                cin>>author1;
                
                        temp->author=author1;
                    
                break;

                case 3:
                cout<<"\nEnter new publisher name: ";
                cin>>publisher1;
                
                        temp->publisher=publisher1;
                    
                break;

                case 4:
                cout<<"\nEnter new price: ";
                cin>>price1;
                
                        temp->price=price1;
                    
                break;

                case 5:
                cout<<"\nEnter new ISBN number: ";
                cin>>isbn1;
                
                        temp->isbn=isbn1;
                    
                break;

                case 6:
                cout<<"\nEnter new number of copies: ";
                cin>>copies1;
                
                        temp->copies=copies1;
                    
                break;
                default:
                cout<<"\nInvalid choice.";
                break;
            }
            cout<<"\nData updated.";
            }
}
void lms:: Delete(){
    int bid;
    cout<<"\nEnter the book ID of the book you want to delete: ";
    cin>>bid;
    lms *temp=start;
    //delete first node
    if(start->id==bid){
        start=temp->next;
        delete temp;
    }
    //delete any node
    else{
    while(temp!=0){
        if (temp->next->id==bid){
            delete temp->next;
            temp->next=temp->next->next;
            break;
        }
        temp=temp->next;
    }
    }
    cout<<"\nBook record deleted";
}
void lms:: sort(){
    lms *i, *j;
    for (i = start; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->id > j->id) {
                swapdata(i, j);
            }
        }
    }
    cout << "\nBooks sorted by ID." << endl;
}

void lms::swapdata(lms *a, lms *b) {
    lms temp;
    temp.id = a->id;
    temp.title = a->title;
    temp.author = a->author;
    temp.publisher = a->publisher;
    temp.price = a->price;
    temp.isbn = a->isbn;
    temp.copies = a->copies;

    a->id = b->id;
    a->title = b->title;
    a->author = b->author;
    a->publisher = b->publisher;
    a->price = b->price;
    a->isbn = b->isbn;
    a->copies = b->copies;

    b->id = temp.id;
    b->title = temp.title;
    b->author = temp.author;
    b->publisher = temp.publisher;
    b->price = temp.price;
    b->isbn = temp.isbn;
    b->copies = temp.copies;
}

void lms:: count(){
    lms *temp=start;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    cout<<"\nTotal number of distinct books: "<<cnt<<endl;
}
int main(){
    lms *ptr;
    int ch;
    char ch1;
    do{
    cout<<"\n\nWhat do you want to do?: \n1.Accept data\n2.Display data\n3.Search book\n4.Update\n5.Delete\n6.Count number of distinct books\n7.Sort\n8.Exit\n\nEnter your choice: ";
    cin>>ch;
    switch(ch){
        case 1:
        cout<<"\n--------------Enter data---------------\n"<<endl;
        ptr->accept();
        break;
        case 2:
        ptr->display();
        break;
        case 3:
        ptr->search();
        break;
        case 4:
        ptr->update();
        break;
        case 5:
        ptr->Delete();
        break;
        case 6:
        ptr->count();
        break;
        case 7:
        ptr->sort();
        break;
        case 8:
        exit(0);
        default:
        cout<<"\nInvalid choice.";
        break;
    }
    cout<<"\nDo you want to continue?(y/n): ";
    cin>>ch1;
    }while(ch1=='y'||ch1=='Y');
    return 0;
}