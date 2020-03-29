#include<iostream>

using namespace std;
int maxSize=10;//value can be changed depending on the need

int **add(int **A, int **B, int n, int multiplier){
    int **R;
    R = new int *[n];
    for(int i=0; i<n; i++){
        R[i] = new int[n];
        for(int j=0; j<n; j++){
            R[i][j] = A[i][j] + multiplier*B[i][j];
        }
    }
    return R;
}

int **multiply(int **A, int **B, int n){
    //I'm not sure about this part
    if(n<=1){
        A[0][0]*=B[0][0];
        return A;
    }

    int **A11, **A12, **A21, **A22, **B11, **B12, **B21, **B22;
    A11=new int *[n/2];
    A12=new int *[n/2];
    A21=new int *[n/2];
    A22=new int *[n/2];
    B11=new int *[n/2];
    B12=new int *[n/2];
    B21=new int *[n/2];
    B22=new int *[n/2];
    for(int i=0; i<n/2; i++){
        A11[i]=new int[n/2];
        B11[i]=new int[n/2];
        A12[i]=new int[n/2];
        B12[i]=new int[n/2];
        for(int j=0; j<n/2; j++){
            A11[i][j]=A[i][j];
            B11[i][j]=B[i][j];
        }
        for(int j=0; j<n/2; j++){
            A12[i][j]=A[i][n/2+j];
            B12[i][j]=B[i][n/2+j];
        }
    }
    for(int i=0; i<n/2; i++){
        A21[i]=new int[n/2];
        B21[i]=new int[n/2];
        A22[i]=new int[n/2];
        B22[i]=new int[n/2];
        for(int j=0; j<n/2; j++){
            A21[i][j]=A[n/2+i][j];
            B21[i][j]=B[n/2+i][j];
        }
        for(int j=0; j<n/2; j++){
            A22[i][j]=A[n/2+i][n/2+j];
            B22[i][j]=B[n/2+i][n/2+j];
        }
    }
    //step1 - O(n^2) time complexity
    int **S1 = add(B12, B22, n/2, -1);
    int **S2 = add(A11, A12, n/2, 1);
    int **S3 = add(A21, A22, n/2, 1);
    int **S4 = add(B21, B11, n/2, -1);
    int **S5 = add(A11, A22, n/2, 1);
    int **S6 = add(B11, B22, n/2, 1);
    int **S7 = add(A12, A22, n/2, -1);
    int **S8 = add(B21, B22, n/2, 1);
    int **S9 = add(A11, A21, n/2, -1);
    int **S10 = add(B11, B12, n/2, 1);

    //step2 T(n) = 7*T(n/2)
    int **P1 = multiply(A11, S1, n/2);
    int **P2 = multiply(S2, B22, n/2);
    int **P3 = multiply(S3, B11, n/2);
    int **P4 = multiply(A22, S4, n/2);
    int **P5 = multiply(S5, S6, n/2);
    int **P6 = multiply(S7, S8, n/2);
    int **P7 = multiply(S9, S10, n/2);

    A11 = add(P5, P4, n/2, 1);
    A12 = add(P2, P6, n/2, -1);
    int **C11 = add(A11, A12, n/2, -1);

    int **C12 = add(P1, P2, n/2, 1);
    int **C21 = add(P3, P4, n/2, 1);

    A11 = add(P5, P1, n/2, 1);
    A12 = add(P3, P7, n/2, 1);
    int **C22 = add(A11, A12, n/2, -1);

    for(int i=0; i<n/2; i++){
        for(int j=0; j<n/2; j++){
            A[i][j]=C11[i][j];
        }
        for(int j=0; j<n/2; j++){
            A[i][n/2+j]=C12[i][j];
        }
    }
    for(int i=0; i<n/2; i++){
        for(int j=0; j<n/2; j++){
            A[n/2+i][j]=C21[i][j];
        }
        for(int j=0; j<n/2; j++){
            A[n/2+i][n/2+j]=C22[i][j];
        }
    }
    return A;
}


int main(){
    int n, a;
    cin>>n;
    //setting matrices
    int **A, **B, **C;
    A = new int *[n];
    B = new int *[n];

    for(int i=0; i<n; i++){
        A[i] = new int[n];
        B[i] = new int[n];
    }

    for(int i = 0; i <n; i++){
        for(int j=0; j<n; j++){
            cin>>a;
            A[i][j]=a;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a;
            B[i][j]=a;
        }
    }
    C = multiply(A, B, n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<C[i][j] + " ";
        }
        cout<<endl;
    }
    return 0;
}
