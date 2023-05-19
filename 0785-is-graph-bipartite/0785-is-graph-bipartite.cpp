class Solution {
    bool isBipartiteDFS(vector<vector<int>>& graph,int current_node,vector<int> &color,int current_color)
    {
        color[current_node]=current_color;  //current node ko current_coor se color kar diya
        for(int &v:graph[current_node]) //phir iske adjacent nodes par gaye
        {
            if(color[current_node]==color[v])   //agar dono ka color same hai,toh false
                return false;
            if(color[v]==-1)    //not visited
            {
                int colorOfV=1-current_color;   //adjacent node ka color
                if(isBipartiteDFS(graph,v,color,colorOfV)==false)   //ab uspe DFS maarenge,agar vhaan se false aaya toh false return kar denge
                    return false;
            }
        }
        return true;    //nahin toh last mein true return kar denge
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
       int V=graph.size();
        vector<int>color(V,-1);
	    int current_color=0;
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)    //abhi visit nahin hua,na hi color,toh DFS maarenge
	        {
	            if(isBipartiteDFS(graph,i,color,current_color)==false)
	            {
	                return false;
	            }
	        }
	    }
	    return true;
    }
};