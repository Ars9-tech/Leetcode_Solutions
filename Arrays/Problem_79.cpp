//Word Search
class Solution {
public:
    int r[4] = {-1,1,0,0};
    int c[4] = {0,0,-1,1};
    bool helper(int row, int col, vector<vector<char>>& board, int index, int n , int m, int size, string &word){
        if(index==size)
        return true;
        char ch = board[row][col];
        board[row][col]='$';
        for(int i = 0; i<4; i++){
            int ur = row + r[i];
            int uc = col+ c[i];
            if(ur>=0 && ur<n && uc>=0 && uc<m){
                if(board[ur][uc]==word[index]){
                    if (helper(ur, uc, board,index+1,n,m,size,word))
                    return true;
                }
            }
        }
        board[row][col]=ch;
        return false;


    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0]. size();
        char ch = word[0];
        int size = word.size();
        for(int i = 0; i<n ; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==ch){
                    if (helper(i, j, board,1,n,m,size, word)){
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
};

//Time Complexity:O(nxmx3^L) where n × m is the board size and L is the length of the word.
//Space complexity: O(L)
