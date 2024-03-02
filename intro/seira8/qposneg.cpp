#include <iostream>
using namespace std;
class queue {
    public:
        queue();              /* κατασκευαστής:  κατασκευάζει μία κενή ουρά */
        bool empty();         /* ελέγχει αν η ουρά είναι κενή */
        void enqueue(int x);  /* εισάγει ένα στοιχείο στην ουρά */
        int dequeue();        /* αφαιρεί ένα στοιχείο από μια μη κενή ουρά */
        int peek();           /* επιστρέφει (χωρίς να αφαιρεί) το πρώτο στοιχείο μιας μη κενής ουράς */
    private:
        struct node{
        int info;
        node *next;
        };
        node *front, *rear;
};

queue::queue(){
    front = nullptr;
    rear = nullptr;
}

bool queue::empty(){
    return front == nullptr;
}

void queue::enqueue(int x){
    node *p = new node;
    p->info = x;
    p->next = nullptr;
    if(front == nullptr){
        front = p;
    }
    else{
        rear->next = p;
    }
    rear = p;
}

int queue::dequeue(){
    node *p = front;
    int result = front->info;
    if(front == rear){
        rear = nullptr;
    }
    front = front->next;
    delete p;
    return result;
}

int queue::peek(){
    return front->info;
}

int main(){
    ios_base::sync_with_stdio(false);
    int positives = 0;
    int negatives = 0;
    queue listpos,listneg;
    int curr;
    while(cin >> curr){
        if(curr > 0){
            listpos.enqueue(curr);
            positives++;
        }
        else{
            listneg.enqueue(curr);
            negatives++;
        }
    }
    if(positives!=negatives){cout<<"no"<< '\n';}
    else{
        bool result = true;
        while(!listneg.empty()){
            if(listpos.dequeue()!= abs(listneg.dequeue())){result = false;break;}
        }
        result ? cout << "yes\n" : cout << "no\n";
    }
}
