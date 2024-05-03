#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int n, count=0;
class LMS{
    public:
    int bid, price, copies,ch2,flag=0,id,ch3;
    string author, bookName, publisher, ISBN;
    void accept();
    void display();
    void search();
    void update();
    void Delete();
    void sort();
}b[10];
void LMS:: accept(){
    cout<<"\nHow many books do you want to add?: ";
        cin>>n;
        for(int i=count;i<count+n;i++){
            cout<<"\nEnter book "<<i+1<<endl;
            cout<<"\nEnter book ID: ";
            cin>>b[i].bid;
            cout<<"\nEnter Book name: ";
            cin>>b[i].bookName;
            cout<<"\nEnter Author name: ";
            cin>>b[i].author;
            cout<<"\nEnter ISBN number: ";
            cin>>b[i].ISBN;
            cout<<"\nEnter publisher name: ";
            cin>>b[i].publisher;
            cout<<"\nEnter book price: ";
            cin>>b[i].price;
            cout<<"\nEnter number of copies available: ";
            cin>>b[i].copies;
            cout<<endl<<"--------book added---------"<<endl;
            cout<<endl<<endl;
        }
        count=count+n;
    //cout<<"\nAdding a new book "<<endl;
    
}
void LMS:: display(){
    cout<<"\n\n\t\t\t\t-----------Book record----------- "<<endl<<endl;
            cout << setw(10) << left <<"Book ID";
            cout << setw(20) << left <<"Book name";
            cout << setw(20) << left <<"Author";
            cout << setw(20) << left <<"Publisher";
            cout << setw(10) << left <<"Price";
            cout << setw(10) << left <<"ISBN";
            cout << setw(10) << left <<"Copies"<<endl;
            for(int i=0;i<count;i++){
                cout << setw(10) << left <<b[i].bid;
                cout << setw(20) << left <<b[i].bookName;
                cout << setw(20) << left <<b[i].author;
                cout << setw(20) << left <<b[i].publisher;
                cout << setw(10) << left <<b[i].price;
                cout << setw(10) << left <<b[i].ISBN;
                cout << setw(10) << left <<b[i].copies<<endl;
            }
}
void LMS::search(){
    cout<<"\nSearch by?\n1.Book ID\n2.Book name\n";
            
            cin>>ch2;
            if(ch2==1){
                int id,x;
                cout<<"\nEnter the book ID you want to search: ";
                cin>>id;
                for(int i=0;i<count;i++){
                    if(id==b[i].bid){
                        flag=1;
                        x=i;
                        break;
                    }

                }
                if(flag==0){
                    cout<<"\nBook not found"<<endl;
                }
                else{
                    cout<<"\nBook found\nID= "<<b[x].bid<<"\nBook name= "<<b[x].bookName<<"\nAuthor= "<<b[x].author<<endl;
                }
            }
            else if(ch2==2){
                int x;
                string nm;
                cout<<"\nEnter the book name you want to search: ";
                cin>>nm;
                for(int i=0;i<n;i++){
                    if(nm==b[i].bookName){
                        flag=1;
                        x=i;
                        break;
                    }

                }
                if(flag==0){
                    cout<<"\nBook not found"<<endl;
                }
                else{
                    cout<<"\nBook found\nID= "<<b[x].bid<<"\nBook name= "<<b[x].bookName<<"\nAuthor= "<<b[x].author<<endl;
                }
            }
            else{
                cout<<"\nInvalid choice"<<endl;
            }
}
void LMS:: update(){
    int isbn,p,cp;
    string bn,an,pn;
    cout<<"\nEnter the book ID whose details you want to update: ";
            cin>>id;
            cout<<"\nWhat do you want to update?\n1.Book name\n2.Author\n3.Book price\n4.ISBN\n5.Number of copies\n6.Publisher name\nEnter your choice: ";
cin>>ch3;
            switch(ch3){
                case 1:
                cout<<"\nEnter new book name: ";
                cin>>bn;
                for(int i=0; i<count;i++){
                    if(b[i].bid==id){
                        b[i].bookName=bn;
                        break;
                    }
                }
                break;
                case 2:
                cout<<"\nEnter new author name: ";
                cin>>an;
                for(int i=0; i<count;i++){
                    if(b[i].bid==id){
                        b[i].author=an;
                        break;
                    }
                }
                break;
                case 3:
                cout<<"\nEnter new price: ";
                cin>>p;
                for(int i=0; i<count;i++){
                    if(b[i].bid==id){
                        b[i].price=p;
                        break;
                    }
                }
                break;
                case 4:
                cout<<"\nEnter new ISBN number: ";
                cin>>isbn;
                for(int i=0; i<count;i++){
                    if(b[i].bid==id){
                        b[i].ISBN=isbn;
                        break;
                    }
                }
                break;
                case 5:
                cout<<"\nEnter updated number of copies: ";
                cin>>cp;
                for(int i=0; i<count;i++){
                    if(b[i].bid==id){
                        b[i].copies=cp;
                        break;
                    }
                }
                break;
                case 6:
                cout<<"\nEnter new publisher name: ";
                cin>>pn;
                for(int i=0; i<count;i++){
                    if(b[i].bid==id){
                        b[i].publisher=pn;
                        break;
                    }
                }
                break;
                default:
                cout<<"\nInvalid choice";
                break;
            }
}
void LMS:: Delete(){
    int id;
    cout<<"\n\nEnter the book ID which you want to delete: ";
    cin>>id;
    for(int i=0;i<count-1;i++){
        if(b[i].bid==id){
            b[i].id =b[i+1].bid;
            b[i].bookName =b[i+1].bookName;
            b[i].author =b[i+1].author;
            b[i].publisher =b[i+1].publisher;
            b[i].ISBN =b[i+1].ISBN;
            b[i].copies =b[i+1].copies;
            b[i].price =b[i+1].price;
            
        }
        count--;
        cout<<"\nRecord deleted.";
    }
}
void LMS:: sort(){
    LMS temp;
    for(int i=0;i<count-1;i++){
        for(int j=0;j<n;j++){
        if(b[i].bid>b[i+1].bid){
            temp=b[i];
            b[i]=b[i+1];
            b[i+1]=temp;
        }
        }
    }
    cout<<"\n--------Data sorted successfully--------"<<endl;
}
int main(){
    LMS l;
    int ch;
    char ch1;
    do{
    cout<<"\n\nWhat do you want to do?: \n1.Accept data\n2.Display data\n3.Search book\n4.Update\n5.Delete\n6.Sort\n7.Exit\n\nEnter your choice: ";
    cin>>ch;
    switch(ch){
        case 1:
        l.accept();
        break;

        case 2:
        l.display();
        break;

        case 3:
        l.search();
        break;

        case 4:
        l.update();
        break;

        case 5:
        l.Delete();
        break;

        case 6:
        l.sort();
        break;

        case 7:
        exit(0);
        break;

        default:
        cout<<"\n\nInvalid choice\n";
        //break;
    }
    cout<<"\nDo you want to continue?(y/n): ";
    cin>>ch1;
    }while(ch1!='n');
    return 0;
}