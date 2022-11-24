class Solution {
public:
    bool f=false;
    void dfs(int i, int j, string& word, int index, vector<vector<char>>& board)
    {
        if(index==word.size())
            f=true;
        
        if(i<0 || j<0 || i>board.size()-1 || j>board[0].size()-1 || board[i][j]!=word[index] || board[i][j]=='-1')
            return ;
        
        char x=board[i][j];
        board[i][j]='-1';
        dfs(i+1,j,word,index+1,board);
        dfs(i,j+1,word,index+1,board);
        dfs(i,j-1,word,index+1,board);
        dfs(i-1,j,word,index+1,board);
        board[i][j]=x;
        
    }
    bool exist(vector<vector<char>>& board, string word)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0])
                dfs(i,j,word,0,board);
            }
        }
        return f;
    }
};