#include <iostream>
using namespace std;

void dfs(int** , int, int, int, int);

int main(){

    int col;
    int row;
    int** map;

    cout << "Enter the col" << endl;
    cin >> col;
    cout << "Enter the row" << endl;
    cin >> row;

    map = new int* [col];
    for(int i = 0; i < col; i++){
        map[i] = new int [row];
    }

    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            cout << "Enter the map[" << i << "][" << j << "] 1(W) or 0(.)" << endl;
            cin >> map[i][j];
        }
    }
    
    int answer = 0;
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            if(map[i][j] == 1){
                dfs(map, col, row, i, j);
                answer++;
            }
        }
    }
    
    for(int i = 0; i < col; i++){
        delete[] map[i];
    }
    delete[] map;

    cout << "answer is " << answer << "." << endl;
}

void dfs(int** map, int col, int row, int i, int j){

    map[i][j] = 0;

    for(int col_roop = -1; col_roop <= 1; col_roop++){
        for(int row_roop = -1; row_roop <= 1; row_roop++){

            int surround_col = i + col_roop;
            int surround_row = j + row_roop;

            if(0 <= surround_col  &&
               surround_col < col &&
               0 <= surround_row  &&
               surround_row < row &&
               map[surround_col][surround_row] == 1){

                    dfs(map, col, row, surround_col, surround_row);
            }
        }
    }
}