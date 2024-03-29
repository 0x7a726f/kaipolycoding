#include <iostream>
#include <stdexcept>
#include <iomanip>
using namespace std;
class ChessBoardArray{
    protected:
        int dim;
        int MatrixSize;
        int diff;
        int * matrix;
        unsigned int loc(int i, int j) const throw(out_of_range){
            if((i - diff >= dim || i < diff) || (j - diff >= dim || j < diff) || (i+j)%2==1){throw out_of_range("Invalid matrix location");}
            else{return ((i-diff)*dim + j - diff)/2;}
        }
        class Row{
            public:
                Row(ChessBoardArray &a, int i) : Board(a) , row(i) {}

                int & operator [] (int i) const {return Board.select(row,i);}
            private:
                ChessBoardArray &Board;
                int row;
        };
        class ConstRow{
            public:
                ConstRow(const ChessBoardArray &a, int i) : Board(a) , row(i) {}

                int operator [] (int i) const {return Board.select(row,i);}
            private:
                const ChessBoardArray &Board;
                int row;
        };
    public:
        ChessBoardArray(unsigned size = 0, unsigned base = 0){
            dim = size;diff = base;MatrixSize = (size*size+1)/2;
            matrix = new int[MatrixSize];
            for(int i = 0;i<MatrixSize;++i){matrix[i] = 0;}
        }

        ChessBoardArray(const ChessBoardArray &a){
            dim = a.dim;diff = a.diff;MatrixSize = a.MatrixSize;
            matrix = new int[MatrixSize];
            for(int i = 0;i<MatrixSize;++i){matrix[i] = a.matrix[i];}
        }

        ~ChessBoardArray(){delete [] matrix;}

        ChessBoardArray & operator = (const ChessBoardArray &a){
            delete [] matrix;
            dim = a.dim;diff = a.diff;MatrixSize = a.MatrixSize;
            matrix = new int[MatrixSize];
            for(int i = 0;i<MatrixSize;++i){matrix[i] = a.matrix[i];}
            return *this;
        }

        int & select(int i, int j){return matrix[loc(i,j)];}

        int select(int i, int j) const {return matrix[loc(i,j)];}

        const Row operator [] (int i){return Row(*this,i);}

        const ConstRow operator [] (int i) const {return ConstRow(*this,i);}

        friend ostream & operator << (ostream &out, const ChessBoardArray &a){
            for(int i = a.diff;i<a.dim + a.diff;++i){
                for(int j = a.diff;j<a.dim + a.diff;++j){
                    out << setw(4);
                    (i + j)%2 == 0 ? out << a.select(i,j) : out << "0";
                }
                out << '\n';
            }
            return out;
        }
};
