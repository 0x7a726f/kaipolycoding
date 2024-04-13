#include <iostream>
using namespace std;
class lexicon{
    public:
        lexicon(){root = nullptr;}

        ~lexicon(){root = nullptr;}

        void insert(const string &s){insertf(root,s);}

        int lookup(const string &s) const{
            node *res = searchf(root,s);
            if(res == nullptr){return 0;}
            else{return res->counter;}
        }

        int depth(const string &s){
            depth_n = 0;
            if(depthf(root,s) != nullptr){return depth_n;}
            return -1;
        }

        void replace(const string &s1, const string &s2){
            node* s1_node = searchf(root,s1);node* s2_node = searchf(root,s2);
            if(s1_node != nullptr){
                if(s2_node != nullptr){
                    s2_node->counter += s1_node->counter;
                }
                else{
                    insertf(root,s2);
                    s2_node = searchf(root,s2);
                    s2_node->counter += s1_node->counter-1;
                }
                if(s1_node != root){
                    node *s1_parent = parentf(root,s1);
                    if(s1_node->left == nullptr && s1_node->right == nullptr){
                        s1_parent->left == s1_node ? s1_parent->left = nullptr : s1_parent->right = nullptr;delete s1_node;   
                    }
                    else if(s1_node->left != nullptr && s1_node->right == nullptr){
                        s1_parent->left == s1_node ? s1_parent->left = s1_node->left : s1_parent->right = s1_node->left;delete s1_node;
                    }
                    else if(s1_node->left == nullptr && s1_node->right != nullptr){
                        s1_parent->left == s1_node ? s1_parent->left = s1_node->right : s1_parent->right = s1_node->right;delete s1_node;
                    }
                    else{two_children(s1_node);}
                }
                else if(root->left == nullptr){root = root->right;}
                else if(root->right == nullptr){root = root->left;}
                else{two_children(root);}
            }
        }

        friend ostream & operator << (ostream &out, const lexicon &l){
            outf(out,l.root);
            return out;
        }
    private:
        struct node{
            string word;
            int counter;
            node *left = nullptr;
            node *right = nullptr;
        };
        node *root;
        void insertf(node*& t, string x){
            if(t == nullptr){
                t = new node;
                t->word = x;
                t->left = t->right = nullptr;
                t->counter = 1;
            }
            else if(t->word > x){insertf(t->left, x);}
            else if(t->word < x){insertf(t->right, x);}
            else{t->counter++;}
        }   
        node *searchf(node *t, string x) const {
            if(t == nullptr){return nullptr;}
            if(t->word == x){return t;}
            if(t->word > x){return searchf(t->left, x);} 
            else{return searchf(t->right, x);}
        }
        int depth_n; //only for the depth func
        node *depthf(node *t, string x){
            if(t == nullptr){return nullptr;}
            if(t->word == x){return t;}
            if(t->word > x){depth_n++;return depthf(t->left, x);} 
            else{depth_n++;return depthf(t->right, x);}
        }
        node *parentf(node *t, string x,node *parent = nullptr){
            if(t == nullptr){return nullptr;}
            if((t->left != nullptr && t->left->word == x) || (t->right != nullptr && t->right->word == x)){
                return t;
            }
            node *leftResult = parentf(t->left, x, t);
            if(leftResult != nullptr){return leftResult;}
            return parentf(t->right, x, t);
        }
        static void outf(ostream &out,node *t){
            if(t != nullptr){outf(out,t->left);out << t->word << " " << t->counter << '\n';outf(out,t->right);}
        }
        void two_children(node *p){
            node* max_Left = p->left;
            node* maxRLeftParent = p;
            while(max_Left->right != nullptr){maxRLeftParent = max_Left;max_Left = max_Left->right;}
            maxRLeftParent->right == max_Left ? maxRLeftParent->right = max_Left->left : maxRLeftParent->left = max_Left->left;
            p->word = max_Left->word;
            p->counter = max_Left->counter;
            delete max_Left;
        }
};
