#include<iostream>
#include<string.h>
using namespace std;
struct node{
    char label[20];
    int count;
    struct node *child[10];
} *root;

class BST{
    public:
    void create();
    void display(node *r);
    BST(){
        root = NULL;
    }
};

void BST::create(){
    root = new node();
    cout<<"Enter book name : ";
    cin>>root->label;
    cout<<"Enter no of chapter : ";
    cin>>root->count;
    for(int i=0;i<root->count;i++){
        node *chapter = new node();
        root->child[i]=chapter;
        cout<<"Enter chapter "<<i+1<<" name : ";
        cin>>chapter->label;
        cout<<"Enter no of sections in chapter "<<i+1<<" : ";
        cin>>chapter->count;
        for(int j=0;j<chapter->count;j++){
            node* sections = new node();
            chapter->child[j] = sections;
            cout<<"Enter section "<<j+1<<" name : ";
            cin>>sections->label;
            cout<<"Enter no of sub-sections in sections "<<j+1<<" : ";
            cin>>sections->count;
            for(int k=0;k<sections->count;k++){
                node* subsection = new node();
                sections->child[k] = subsection;
                cout<<"Enter sub-section "<<j+1<<" name : ";
                cin>>subsection->label;
            }

        }
    }
}
void BST::display(node *r){
    cout<<"Book name : ";
    cout<<root->label<<endl;
    for(int i=0;i<root->count;i++){
        node *chapter = root->child[i];
        cout<<"Chapter "<<i+1<<" name : ";
        cout<<chapter->label<<endl;

        for(int j=0;j<chapter->count;j++){
            node* sections = chapter->child[j];
            cout<<"Section "<<j+1<<" name : ";
            cout<<sections->label<<endl;
            for(int k=0;k<sections->count;k++){
                node* subsection = sections->child[k];
                cout<<"Sub-section "<<j+1<<" name : ";
                cout<<subsection->label<<endl;
            }

        }
    }
}

int main()
{
    BST obj ;
    int ch;
    do{
        cout<<"\n1. Create a record\n2. Display a record\n3.Quit\nEnter your choice : ";
        cin>>ch;
    switch (ch)
    {
    case 1:
        obj.create();
        break;
    case 2:
        obj.display(root);
        break;
    case 3:
        break;
    
    default:
        break;
    }
    }while(ch!=3);
    return 0;
}
