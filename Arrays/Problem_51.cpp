N-queen Problem
----------------

class Solution {
public:
    vector<vector<string>>ans; 
    bool isSafe(int row, int col,vector<string>&board, int n){
        for(int i=0; i<n;i++){ // visit every row in current column
            if(board[i][col]=='Q') // if queen already present,we cannot place other queen
                return false;
        }
        
        for(int i = row-1, j=col-1 ; i>=0 && j>=0; i--,j--){  // check upper left diagonal
            if(board[i][j]=='Q')
                return false;
        }
        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){  //check upper right diagonal
            if(board[i][j]=='Q')
                return false;
        }
        return true;

    }
    void solve(int row, vector<string>&board, int n){ // function to place queen at every row
        if(row==n){  // base case
            ans.push_back(board);
            return;
        }
        for(int col = 0; col<n; col++){   // for current row placing the queen at every column
            if (isSafe(row,col,board,n)){   // if safe
                board[row][col]='Q';  // place the queen
                solve(row+1,board,n); // move to next row
                board[row][col]='.';  // backtrack

            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        solve(0, board, n);
        return ans;
        
    }
};


//Space complexity: 
//Auxillary space = O(N^2)
//Recursion Stack Alone: O(N)

//Time Complexity = O(N!)
