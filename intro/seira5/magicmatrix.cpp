#include <iostream>
using namespace std;
int matrix[151][151];
int sums[305];
int i,j,k;
int main(){
    int n;
    cin >> n;
    cin.ignore();

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            int temp;
            cin >> temp;
            matrix[i][j] = temp;    
        }
        cin.ignore();
    }
    int contains = 0;
    int skip = 0;
    for(i=0;i<n*n;i++){
        for(j=0;j<n;j++){
            if(skip == 1){break;}
            for(k=0;k<n;k++){
                int temp;
                temp = matrix[j][k];
                if(i == temp){contains += 1;skip = 0;break;}    
            }    
        }
    }
    if(contains != n*n){cout << "no" << endl;}
    else{
        for(i=0;i<n;i++){
            sums[i] = 0;
            for(j=0;j<n;j++){
                sums[i] += matrix[i][j];
            }
        }

        for(i=0;i<n;i++){
            sums[i+n] = 0;
            for(j=0;j<n;j++){
                sums[i+n] += matrix[j][i];
            }
        }

        sums[2*n] = 0;
        for(i=0;i<n;i++){
            sums[2*n] += matrix[i][i];
        }
        sums[2*n+1] = 0;
        for(i=0;i<n;i++){
            sums[2*n+1] += matrix[i][n-1-i];
        }

        bool result = true;
        for(i=0;i<2*n+1;i++){
            if(sums[i] != sums[i+1]){cout << "no" << endl;result = false;break;}
        }
        if(result == true){cout << "yes" << endl;}
    } 
}
