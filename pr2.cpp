#include <iostream>
#include <string.h>
using namespace std;
struct node
{
    char label[10];
    int ch_count;           
    struct node *child[10]; 
} *root;                    
class BST
{
public:
    void create_tree();
    void display(node *r1);
    BST()
    {
        root = NULL;
    }
};
void BST::create_tree() {
    int tchapters, tsections, tsubsections;

    root = new node(); 
    cout << "Enter name of book: ";
    cin >> root->label;
    cout << "Enter no. of chapters in book: ";
    cin >> tchapters;
    root->ch_count = tchapters;

    for (int i = 0; i < tchapters; i++) {                             
        node* chapter = new node; // Store pointer to current chapter
        root->child[i] = chapter; 
        cout << "Enter Chapter name: ";
        cin >> chapter->label;
        cout << "Enter no. of sections in this Chapter: ";
        cin >> chapter->ch_count;

        for (int j = 0; j < chapter->ch_count; j++) { 
            node* section = new node; // Store pointer to current section
            chapter->child[j] = section;
            cout << "Enter section head: ";
            cin >> section->label;
            cout << "Enter no. of subsections in this section: ";
            cin >> section->ch_count;

            for (int k = 0; k < section->ch_count; k++) { 
                node* subsection = new node; // Store pointer to current subsection
                section->child[k] = subsection;
                cout << "Enter subsection head: ";
                cin >> subsection->label;
            }
        }
    }
}

void BST::display(node* r1) {
    if (r1 != NULL) {
        cout << "\n-----Book Hierarchy---";
        cout << "\n Book title :- " << r1->label;
        int tchapters = r1->ch_count; 
        for (int i = 0; i < tchapters; i++) {
            node* chapter = r1->child[i];
            cout << "\n Chapter " << i + 1 << " :- " << chapter->label;
            cout << "\n Sections :- ";
            int tsections = chapter->ch_count; 
            for (int j = 0; j < tsections; j++) {
                node* section = chapter->child[j];
                cout << "\n " << section->label;
                cout << "\n Subsections :- ";
                int tsubsections = section->ch_count; 
                for (int k = 0; k < tsubsections; k++) {
                    node* subsection = section->child[k];
                    cout << "\n " << subsection->label;
                }
            }
        }
    }
}

int main()
{
    int choice;
    BST bst;
    while (1)
    {
        cout << "\n-----------------" << endl;
        cout << "Book Tree Creation" << endl;
        cout << "-----------------" << endl;
        cout << "1.Create" << endl;
        cout << "2.Display" << endl;
        cout << "3.Quit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            bst.create_tree();
            break;
        case 2:
            bst.display(root);
            break;
        case 3:
            exit(1);
        default:
            cout << "Wrong choice" << endl;
        }
    }
}