class Solution {
    void dfs(int source,vector<vector<int>>& rooms,vector<bool>& visited)
    {
        visited[source]=true;
        for(int& node:rooms[source])
        {
            if(!visited[node])
            {
                dfs(node,rooms,visited);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> visited(n,false);
        dfs(0,rooms,visited);
        for(bool i:visited)
        {
            if(i==false)
            {
                return false;   //one room that we found and it is not visited
            }
        }
        return true;
    }
};