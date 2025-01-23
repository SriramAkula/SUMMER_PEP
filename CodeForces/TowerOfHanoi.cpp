#include <iostream>
using namespace std;

int TOH(int n,int S,int A,int D){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    int m=0;
    m+=TOH(n-1,S,D,A);
    m++;
    m+=TOH(n-1,A,S,D);
    return m;
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    int totalMoves = TOH(n, 1, 2, 3);
    cout << "Total number of moves required: " << totalMoves << endl;

    return 0;
}