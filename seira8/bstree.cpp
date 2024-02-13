#include <iostream>
#include <vector>
using namespace std;
class bstree { 
    public: 
        bstree();             /* κατασκευαστής: κατασκευάζει ένα κενό ΔΔΑ */ 
        int height();         /* επιστρέφει το ύψος του ΔΔΑ (το κενό ΔΔΑ έχει ύψος 0) */ 
        void insert(int x);   /* εισάγει τον αριθμό x στο ΔΔΑ */
        int search(int x);    /* ψάχνει τον αριθμό x στο ΔΔΑ και επιστρέφει το επίπεδο στο οποίο βρίσκεται (η ρίζα βρίσκεται στο επίπεδο 1) ή 0 αν δεν υπάρχει */
        int min();            /* επιστρέφει το ελάχιστο στοιχείο του ΔΔΑ */
        int max();            /* επιστρέφει το μέγιστο στοιχείο του ΔΔΑ */
        void inorder();       /* εκτυπώνει τα στοιχεία του ΔΔΑ με ενδοδιατεταγμένη διάσχιση */
        void preorder();      /* εκτυπώνει τα στοιχεία του ΔΔΑ με προδιατεταγμένη διάσχιση */
        void postorder();     /* εκτυπώνει τα στοιχεία του ΔΔΑ με μεταδιατεταγμένη διάσχιση */
        struct node{
            int info;
            node *left = nullptr;
            node *right = nullptr;
        };
        node *root;
};

bstree::bstree(){
    root = nullptr;
}

int heightf(bstree::node* t){
    if(t == nullptr){return 0;}
    return 1 + max(heightf(t->left),heightf(t->right));
}
int bstree::height(){
    return heightf(root); 
}

void insertf(bstree::node*& t, int x){
    if(t == nullptr){
        t = new bstree::node;
        t->info = x;
        t->left = t->right = nullptr;
    }
    else if(t->info > x){insertf(t->left, x);}
    else if(t->info < x){insertf(t->right, x);}
}   
void bstree::insert(int x){
    insertf(root,x);
}

int depth;
bstree::node *searchf(bstree::node *t, int x) {
    if(t == nullptr){return nullptr;}
    if(t->info == x){return t;}
    if(t->info > x){depth++;return searchf(t->left, x);} 
    else{depth++;return searchf(t->right, x);}
}
int bstree::search(int x){
    depth = 1;
    if(root == nullptr){return 0;}
    if(searchf(root,x) != nullptr){return depth;}
    return 0;
}   

int bstree::min(){
    if(root->left == nullptr && root->right == nullptr){return root->info;}
    node* q = root;
    while(q->left->left != nullptr){q = q->left;}
    return q->left->info;
}

int bstree::max(){
    if(root->left == nullptr && root->right == nullptr){return root->info;}
    node* q = root;
    while(q->right->right != nullptr){q = q->right;}
    return q->right->info;
}

void inorderf(bstree::node *t){
    if(t != nullptr){inorderf(t->left);cout << t->info << " ";inorderf(t->right);}
}
void bstree::inorder(){inorderf(root);}

void preorderf(bstree::node *t){
    if(t != nullptr){cout << t->info << " ";preorderf(t->left);preorderf(t->right);}
}
void bstree::preorder(){preorderf(root);}

void postorderf(bstree::node *t){
    if(t != nullptr){postorderf(t->left);postorderf(t->right);cout << t->info << " ";}
}
void bstree::postorder(){postorderf(root);}

int main() {
    bstree tree;
    ios_base::sync_with_stdio(false);
    int n,s,temp;
    cin >> n;
    for(int i=0;i<n;i++){cin >> temp;tree.insert(temp);}
    cin >> s;
    vector <int> searchList;
    for(int i=0;i<s;i++){cin >> temp;searchList.push_back(temp);}
    cout << tree.height() << '\n';
    cout << tree.min() << " " << tree.max() << '\n';
    for(int i = 0;i<searchList.size()-1;i++){cout << tree.search(searchList[i]) << " ";}
    cout << tree.search(searchList[searchList.size()-1]) << '\n';
    tree.inorder();
    cout << "end" << '\n';
    tree.preorder();
    cout << "end" << '\n';
    tree.postorder();
    cout << "end" << '\n';
}