class Solution {
public:
    bool check(vector<vector<char>>& board,int x,int y,string word,int index)
    {
        if(index==word.size())
            return true;
        if(x<0 || x>=board.size() || y<0 || y>=board[0].size() || board[x][y]=='.' || board[x][y]!=word[index])
            return false;
        char c=board[x][y];
        board[x][y]='.';
        if(check(board,x+1,y,word,index+1) || 
                 check(board,x-1,y,word,index+1) || 
                 check(board,x,y+1,word,index+1) || 
                 check(board,x,y-1,word,index+1))
        {
            return true;
        }
        board[x][y]=c;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(check(board,i,j,word,0))
                    return true;
            }
        }
        return false;
    }
};