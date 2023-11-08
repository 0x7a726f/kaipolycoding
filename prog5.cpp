#include "pzhelp"
#include <iostream>
#include <iomanip>
REAL matrix[100][100];
REAL sthlesavg[100];
REAL grammesavg[100];
int i,j;
int main(){
    int n = READ_INT(); int m = READ_INT(); SKIP_LINE();/*Diastasteis pinaka*/

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            REAL temp = READ_REAL();
            matrix[i][j] = temp;    /*Gemisma pinaka*/
        }
        SKIP_LINE();
    }
    REAL sumgrammes = 0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            sumgrammes = sumgrammes + matrix[i][j];

        }
        grammesavg[i]=sumgrammes/m;
        sumgrammes = 0;
    }

    REAL resgrammes = 0;
    for(i=0;i<n;i++){
        resgrammes = resgrammes + grammesavg[i];
    }
    cout << fixed << setprecision(3) << resgrammes/n << endl;

    REAL sumsthles = 0;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            sumsthles = sumsthles + matrix[j][i];

        }

        sthlesavg[i]=sumsthles/n;
        sumsthles = 0;
    }

    REAL ressthles = 0;
    for(i=0;i<m;i++){
        ressthles = ressthles + sthlesavg[i];
    }
    cout << fixed << setprecision(3) << ressthles/m << endl;
}