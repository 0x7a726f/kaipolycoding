#include "pzhelp"
#include <iostream>
int matrix[100][100];
int sthlesmax[100];
int grammesmax[100];
int i,j;
int main(){
    int n = READ_INT(); int m = READ_INT(); SKIP_LINE();/*Diastasteis pinaka*/

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            int temp = READ_INT();
            matrix[i][j] = temp;    /*Gemisma pinaka*/
        }
        SKIP_LINE();
    }
    
    for(i=0;i<m;i++){
        int x = matrix[0][i];
        for(j=0;j<n;j++){
            if(matrix[j][i] > x){x = matrix[j][i];} /*Elegxws kathe sthlhs gia ton megalytero ths*/

        }
        sthlesmax[i]=x;
    }

    int y = sthlesmax[0];

    for(i=0;i<m;i++){
        if(sthlesmax[i] < y){y = sthlesmax[i];} /*Elegxws tou pinaka twn megalyterwn kathe sthlhs gia na ton mikrotero*/
    }

    cout << y << endl;

    for(j=0;j<n;j++){
        int w = matrix[j][0];
        for(i=0;i<m;i++){
            if(matrix[j][i] < w){w = matrix[j][i];} /*Elegxws kathe grammhs gia ton mikrotero ths*/

        }
        grammesmax[j]=w;
    }

    int z = grammesmax[0];
    for(i=0;i<n;i++){
        if(grammesmax[i] > z){z = grammesmax[i];} /*Elegxws tou pinaka twn mikroterwn kathe grammhs gia na ton megalytero*/
    }
    cout << z;

}