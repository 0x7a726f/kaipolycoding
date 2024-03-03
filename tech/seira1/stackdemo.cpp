#include <iostream>  
using namespace std;  
template <typename T>  
class stack{  
    public:  
        stack(int size){ 
            cap = size; 
            top = 0;  
            matrix = new T[size];  
        };  
  
        stack(const stack &s){  
            cap = s.cap;
            top = s.top;  
            matrix = new T[cap];  
            for(int i = 0; i < top; i++){matrix[i] = s.matrix[i];}  
        };  
  
        ~stack(){delete[] matrix;};  
  
        const stack & operator =(const stack &s) {  
            delete[]matrix;
            cap = s.cap;
            top = s.top;
            matrix = new T[cap];
            for(int i = 0; i < top; i++){matrix[i] = s.matrix[i];}
            return *this;
        };
  
        bool empty(){return top == 0;};  
  
        void push(const T &x){matrix[top++] = x;};  
  
        T pop(){return matrix[--top];};  
  
        int size(){return top;};  
  
        friend ostream & operator <<(ostream &out, const stack &s){  
            out << "[";  
            for(int i = 0; i < s.top; i++){  
                out << s.matrix[i];  
                if(i < s.top - 1){out << ", ";}  
            }  
            return out  << "]";  
        };  
    private:  
        T *matrix;  
        int top;  
        int cap;
};
