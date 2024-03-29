#include <iostream>
using namespace std;
class list {
    public:
        list();                  /* κατασκευαστής:  κατασκευάζει μία κενή λίστα */
        bool empty();            /* ελέγχει αν η λίστα είναι κενή */
        int size();              /* επιστρέφει το μέγεθος της λίστας */
        void add(int k, int x);  /* εισάγει το στοιχείο x στη θέση k της λίστας */
        int get(int k);          /* επιστρέφει την τιμή του στοιχείου στη θέση k της λίστας */
        void remove(int k);      /* διαγράφει το στοιχείο στη θέση k της λίστας */
    private:
        struct node{
        int info;
        node *next = nullptr;
        };
        node *head;
};

list::list(){
    head = nullptr;
}

bool list::empty(){
    return head == nullptr;
}

int list::size(){
    if(head == nullptr){return 0;}
    node *p = head;
    int result = 0;
    for(p = head; p != nullptr; p = p->next){result++;}
    return result;
}

void list::add(int k, int x){
    if(head == nullptr){
        node *p = new node;
        p->info = x;
        p->next = nullptr;
        head = p;
    }
    else if(k == 1 && head != nullptr){
        node *p = new node;
        p->info = x;
        p->next = head;
        head = p;
    }
    else {
        node *q = head;
        node *p = new node;
        p->info = x;
        int i = 1;
        while(q->next != nullptr){
            if(i == k - 1){break;}
            q = q->next;
            i++;
        }
        p->next = q->next;
        q->next = p;
    }
}

int list::get(int k){
    if(head != nullptr && k == 1){return head->info;}
    else{
        node *q = head;
        int i = 1;
        while (q != nullptr && i < k) {
            q = q->next;
            i++;
        }
        return q->info;
    }
}

void list::remove(int k){
    if(head != nullptr){
        if(k == 1){node *q = head;head = head->next;delete q;}
        else{
            node *prev = head;
            int i = 1;
            while(i < k-1){prev = prev->next;i++;}
            node *q = prev->next;
            prev->next = prev->next->next;
            delete q;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    list a;
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        int k;int x;
        cin >> k >> x;
        a.add(k,x);
    }
    int d;
    cin >> d;
    for(int i = 0;i<d;i++){
        int del;
        cin >> del;
        a.remove(del);
    }
    int res;
    cin >> res;
    cout << a.size() << " " << a.get(res) << '\n';
}
