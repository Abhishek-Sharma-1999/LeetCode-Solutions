class Solution {
public:
    //source-> jis position par abhi colour karna hai 
    void dfs(vector<vector<int>>& image, int sr, int sc,int row,int col, int newcolor,int source)
    {
        if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size() || image[sr][sc]!=source )
            return;
        image[sr][sc]=newcolor;
        
        dfs(image,sr-1,sc,row,col,newcolor,source); //Left
        dfs(image,sr+1,sc,row,col,newcolor,source); //Right
        dfs(image,sr,sc-1,row,col,newcolor,source); //Top
        dfs(image,sr,sc+1,row,col,newcolor,source); //Bottom
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int i=image.size(); //rows
        int j=image[0].size();  //columns
        
        int val=image[sr][sc];
        
        if(val==color)  //agar jo colour karna hai vo already ho rakha hai
            return image;
        
        dfs(image,sr,sc,i,j,color,val);
        return image;
    }
};