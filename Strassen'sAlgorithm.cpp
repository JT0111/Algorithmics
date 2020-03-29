#include<iostream>

using namespace std;
int maxSize=10;//value can be changed depending on the need
int M1[maxSize][maxSize], M2[maxSize][maxSize], R[maxSize][maxSize];
int S1[maxSize/2][maxSize/2], S2[maxSize/2][maxSize/2], S3[maxSize/2][maxSize/2], S4[maxSize/2][maxSize/2], S5[maxSize/2][maxSize/2], S6[maxSize/2][maxSize/2], S7[maxSize/2][maxSize/2], S8[maxSize/2][maxSize/2], S9[maxSize/2][maxSize/2], S10[maxSize/2][maxSize/2];

void multiply(int n){

}

int main(){
    int n, a;
    cin>>n;
    //setting first matrix
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a;
            M1[i][j]=a;
        }
    }
    //setting second matrix
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a;
            M2[i][j]=a;
        }
    }
    multiply(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<R[i][j];
        }
    }
    return 0;
}
