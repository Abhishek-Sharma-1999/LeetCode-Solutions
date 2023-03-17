class Trie {
public:
    struct trieNode
    {
        bool isEndofWord;
        trieNode *children[26];
    };
    
    trieNode *getNode() //ye nya node bnayega
    {
        trieNode *newNode=new trieNode();
        newNode->isEndofWord=false;  //ye abhi bna hai,toh iska endof word false hoga
        // children bhi iske saare NUll, honge kyunki ye abhi-abhi bna hai
        for(int i=0;i<26;i++)
        {
            newNode->children[i]=NULL;
        }
        return newNode;   //toh,jaise hi getNode() function call hoga,hme ek nya node mil jaayega
    }
    // ek root node hoga
    trieNode *root;
    
    Trie() {    //ye constructor hai,toh sabse pehle ye call hoga, toh
         root=getNode(); //root ko assign kar denge ek nya node, har cheez isi root se start hogi
    }
    
    void insert(string word) {
        trieNode *crawler=root;
        for(int i=0;i<word.length();i++)
        {
            char ch=word[i];
            int index=ch-'a';   // alphabet ke index nikal ka tareeka , jaise bat hai toh 'b' ka 1
            if(crawler->children[index]==NULL)  // agar index null hai,toh nya node bnayenge, us aplhabet ke index se
            {
                crawler->children[index]=getNode();
            }
            // ab crawler ko aage bda denge
            crawler=crawler->children[index];
        }
        // jab for loop khatam ho jayega , toh crawler last aplhabet ko point kar rha hoga, toh uske endofword ko true mark kar denge,ki yhaan par ye word khatam ho rha hai
        crawler->isEndofWord=true;
    }
    
    bool search(string word) {
        trieNode *crawler=root;
        for(int i=0;i<word.length();i++)
        {
            char ch=word[i];
            int index=ch-'a';   // alphabet ke index nikal ka tareeka , jaise bat hai toh 'b' ka 1
            if(crawler->children[index]==NULL)  // agar index null hai,toh matlab, jo word search kar rahe hain,vo hai hi nahin,toh false return kar denge
            {
                return false;
            }
            // ab crawler ko aage bda denge
            crawler=crawler->children[index];
        }
    // end mein crawler null nahin hona chaiye, jo is alphabet par hum hai,uska endofword true hona chaiye, matlab hme apna search kra hua word mil gya
        if(crawler!=NULL && crawler->isEndofWord==true)
            return true;
        // nahin toh return false
        return false;
    }
    
    bool startsWith(string prefix) {
        trieNode *crawler=root;
        int i;
        for(i=0;i<prefix.length();i++)
        {
            char ch=prefix[i];
            int index=ch-'a';   // alphabet ke index nikal ka tareeka , jaise bat hai toh 'b' ka 1
            if(crawler->children[index]==NULL)  // agar index null hai,toh matlab, jo prefix search kar rahe hain,vo hai hi nahin,toh false return kar denge
            {
                return false;
            }
            // ab crawler ko aage bda denge
            crawler=crawler->children[index];
        }
    // end mein prefix ki length ko traverse karne ke baad,agar i equal hua prefix ki length ke , toh matlab vo prefix present tha
        if(i==prefix.length())
            return true;
        // nahin toh return false
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */