#include <iostream>


using namespace std;




//helper function that creates a random 3D Matrix
int*** ThreeDArrayRandomCreate(int p, int n, int m)
{
    int ***arr = 0;
    arr = new int**[p];
    for (int k = 0; k < p; k++) {
        /* code */
        arr[k] = new int*[n];
        for (int i = 0; i < n; i++) {
            /* code */
            arr[k][i] = new int[m];
            for (int j = 0; j < m; j++) {
                /* code */
                arr[k][i][j] = rand()%20;
            }
        }
    }
    return arr;
}

//helper function that prints out 3D Matrix
void print3dArray(int*** arr, int p, int n, int m)
{
    for (int k = 0; k < p; k++) {
        /* code */
        for (int i = 0; i < n; i++) {
            /* code */
            for (int j = 0; j < m; j++) {
                /* code */
                cout << arr[k][i][j] << " ";
            }
            cout << endl;
        }
        cout << "---------"<<endl;
    }
}

//Function to Flatten and sort a 3D Matrix into a 1D vector 
int* ThreeDArrayFlatten(int*** arr, int p, int n, int m)
{
    int q = p*n*m; //size of 1D vector
    int *flatten; 
    flatten = new int[q]; //declare 1D vector "flatten" 
    int y = 0; //index of 1D vector

    //access each element in 3D Matrix
    for (int k = 0; k < p; k++) {
        
        for (int i = 0; i < n; i++) {
            
            for (int j = 0; j < m; j++) {
                
                int val = arr[k][i][j];
                //Insertion Sort
                int hole = y;
                while(hole > 0 && flatten[hole-1] > val)
                {
                    flatten[hole] = flatten[hole-1];
                    hole--;
                }
                flatten[hole] = val;    //Insert element in correct position in 1D vector
                y++;
            }
        }
    }
    return flatten;
}

int main()
{
    //Test Run--------
    int m = 3;  //number of columns 1st coordinate
    int n = 3; //number of rows 2nd coordinate
    int p = 3;  //number of level 3rd coordinate 
    int q = n*m*p; //size of 1d vector
    int ***arr = ThreeDArrayRandomCreate(p,n,m); //Create Random 3*3*3 Matrix
    print3dArray(arr,p,n,m);    //Print Matrix
    int *flatten = ThreeDArrayFlatten(arr,p,n,m); //flatten matrix

    for (int i = 0; i < q; i++) {      //prints out flatten 1D vector
        /* code */
        cout << flatten[i] << " ";
    }
    //----------------
    
    return 0;
}

