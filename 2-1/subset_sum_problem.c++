#include <iostream>
using namespace std;

bool dfs(int*, int, int, int, int);

int main(){

    int* sequence;
    int n;
    int k;

    cout << "Enter the n." << endl;
    cin >> n;

    sequence = new int [n];
    for(int i = 0; i < n; i++){
        cout << "Enter the sequence[" << (i + 1) << "]." << endl;
        cin >> sequence[i];
    }

    cout << "Enter the k." << endl;
    cin >> k;

    cout << "Doing the Depth first search." << endl;
    if(dfs(sequence, n, k, 0, 0)){
        cout << "Yes!" << endl;
    }
    else{
        cout <<"No!" << endl;
    }
    delete[] sequence;
}

bool dfs(int* sequence, int n, int k, int i, int sum){
    
    if(i == n){
        return sum == k;
    }
    if(dfs(sequence, n, k, i + 1, sum)){
        return true;
    }

    if(dfs(sequence, n, k, i + 1, sum + sequence[i])){
        return true;
    }

    return false;
}