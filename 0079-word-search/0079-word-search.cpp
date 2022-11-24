class Solution {
public:
    bool dfs(int i,int x,int y,vector<vector<char>>& board, string word)
    {
        if(i==word.size())
            return true;
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y]=='.' || board[x][y]!=word[i])
            return false;
        
        char temp=board[x][y];
        board[x][y]='.';    //mark it as visited
        if(dfs(i+1,x+1,y,board,word) ||
            dfs(i+1,x-1,y,board,word) ||
            dfs(i+1,x,y+1,board,word) ||
            dfs(i+1,x,y-1,board,word))
        {    
            return true;
        }
        board[x][y]=temp;
        
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word=="")
            return false;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(dfs(0,i,j,board,word))
                    return true;
            }
        }
        return false;
    }
};