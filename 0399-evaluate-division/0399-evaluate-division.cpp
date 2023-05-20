class Solution {
public:
    void dfs(unordered_map<string,vector<pair<string,double>>> &adj,string src,string dest,unordered_set<string>&visited,double prod,double &ans)
    {
        if(visited.find(src)!=visited.end())    //pehle is variable ko visit kar chuke hain
            return;
        visited.insert(src);
        if(src==dest)   //agar destination parpahuncg gaye,matlab dono variable equal ho gaye
        {
            ans=prod;
            return;
        }
        for(auto p:adj[src])
        {
            string v=p.first;
            double val=p.second;
            dfs(adj,v,dest,visited,prod*val,ans);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=equations.size();
        unordered_map<string,vector<pair<string,double>>> adj;
        // making adjacency list
        for(int i=0;i<n;i++){
            string u=equations[i][0];   //pehla variable -a
            string v=equations[i][1];   //second variable
            double val=values[i];   //values array mein unki value (a/b)
            adj[u].push_back({v,val});  //a -> {b,val}
            adj[v].push_back({u,1.0/val});  // b->{a,1/val}
            // map mein hum dono values store karveyenge
        }
        vector<double>result;
        for(auto &query: queries)
        {
            string src=query[0];    //source
            string dest=query[1];   //destination
            double ans=-1.0;
            double prod=1.0;
            if(adj.find(src)!=adj.end())    //agar vo source/variable present hoga,tabhi dfs caal karenge
            {
                unordered_set<string>visited;
                dfs(adj,src,dest,visited,prod,ans);
            }
            result.push_back(ans);
        }
        return result;
    }
};