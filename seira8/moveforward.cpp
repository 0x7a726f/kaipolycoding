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
        int searchMF (int x);    /* επιστρέφει τη πρώτη θέση του x , το στέλνει μπροστά , αλλι΄ως 0*/
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

int list::searchMF(int x) {
    if(head == nullptr){return 0;}
    if(head->info == x){return 1;}
    node *prev = nullptr;
    node *curr = head;
    int pos = 1;
    while (curr != nullptr) {
        if (curr->info == x) {
            prev->next = curr->next;
            curr->next = head;
            head = curr;
            return pos;
        }
        prev = curr;
        curr = curr->next;
        pos++;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    list a;
    int n,s;
    int res = 0;
    cin >> n;
    for(int i = 0;i<n;i++){
        int k;int x;
        cin >> k >> x;
        a.add(k,x);
    }
    cin >> s;
    for(int i = 0;i<s;i++){
        int k;
        cin >> k;
        res+=a.searchMF(k);
    }
    cout << res << '\n';
}