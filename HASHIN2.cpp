#include<iostream>
#include<string.h>
using namespace std;

class Hashfuntion{
    private:
    typedef struct{
        long key;
        char name[20];
    }hash;
    hash h[10];
    public:
    Hashfuntion();
    void insert();
    void display();
    int find(long);
    void Delete(long);

};
Hashfuntion::Hashfuntion(){
    for(int i=0;i<10;i++){
        h[i].key = -1;
        strcpy(h[i].name,"NULL");
    }
}
int Hashfuntion::find(long k){
    int i;
    for(i=0;i<10;i++){
        if(h[i].key==k){
            cout<<"\nKey is found at "<<i<<" location with value "<<h[i].name<<"\n";
            return i;
        }

    }
    if(i==10){
        return -1;
    }
}

void Hashfuntion::display(){
    cout<<"\n\tKey\tValue\n";
    for(int i=0;i<10;i++){
        cout<<"\t"<<h[i].key<<"\t"<<h[i].name<<"\n";
    }
}

void Hashfuntion::Delete(long k){
    int ind = find(k);
    if(ind==-1){
        cout<<"\nKey not found\n";

    }
    else{
        h[ind].key = -1;
        strcpy(h[ind].name,"NULL");
        cout<<"\nDeleted Successfully\n";
    }
}

void Hashfuntion::insert(){
    long n,tempn;
    int hi,cond=0;
    char m[20],tempm[20];
    cout<<"Enter Telephone : ";
    cin>>n;
    cout<<"Enter Name : ";
    cin>>m;
    hi = n%10;
    if(h[hi].key==-1){
        h[hi].key=n;
        strcpy(h[hi].name,m);
        cond=1;
    }
    else{
        if(h[hi].key%10!=hi){
            tempn = h[hi].key;
            strcpy(tempm,h[hi].name);
            h[hi].key = n;
            strcpy(h[hi].name,m);
            for(int i=hi+1;i<10;i++){
                if(h[i].key==-1){
                    h[i].key = tempn;
                    strcpy(h[i].name,tempm);
                    cond=1;
                    break;
                }
            }
            for(int i=0;i<hi && cond==0;i++){
                if(h[i].key==-1){
                    h[i].key = tempn;
                    strcpy(h[i].name,tempm);
                    cond=1;
                    break;
                }
            }
        }else{
            for(int i=hi+1;i<10;i++){
                if(h[i].key==-1){
                    h[i].key = n;
                    strcpy(h[i].name,m);
                    cond=1;
                    break;
                }
            }
            for(int i=0;i<hi && cond==0;i++){
                if(h[i].key==-1){
                    h[i].key = n;
                    strcpy(h[i].name,m);
                    cond=1;
                    break;
                }
            }
        }
    }
    if(cond==0) cout<<"\nTable is full\n";

}

int main()
{
    long k;
    int ch, index;
    char ans;
    Hashfuntion obj;
    do
    {
        cout << "\n\t***** Telephone (ADT) *****";
        cout << "\n\t1. Insert\n\t2. Display\n\t3. Find\n\t4. Delete\n\t5. Exit";
        cout << "\n\t..... Enter Your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            obj.insert();
            break;
        case 2:
            obj.display();
            break;
        case 3:
            cout << "\n\tEnter a Key Which You Want to Search: ";
            cin >> k;
            index = obj.find(k);
            if (index == -1)
            {
                cout << "\n\tKey Not Found";
            }
            break;
        case 4:
            cout << "\n\tEnter a Key Which You Want to Delete: ";
            cin >> k;
            obj.Delete(k);
            break;
        case 5:
            break;
        }
        cout << "\n\t..... Do You Want to Continue in Main Menu:y/n ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
}