class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>indegree(n+1,0);
        vector<int>outdegree(n+1,0);
        for(vector vec:trust)
        {
            int a=vec[0];   //jo trust kar rha hai
            int b=vec[1];   //is par trust ho rha hai
            outdegree[a]++;  //ye trust kar rha hai, toh bahar ki taraf, jaayega toh iska count increase kar denge
            indegree[b]++;    //iss par, trust ho rha hai, toh iski taraf arrow aa rha hai,toh iska count increase kar denge
        }
        
// town judge vo hai,jo kisi par trust nahin karta (outdegree==0) aur uspar, khud ke alava uske, sab trust karte hai (out of n people, n-1 trust karte hain)        
        for(int i=1;i<=n;i++)
        {
            if(outdegree[i]==0 && indegree[i]==n-1)
            {
                return i;
            }
        }
        return -1;
    }
};