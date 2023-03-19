class BrowserHistory {
public:
    stack<string> forward_url;
    stack<string> back_url;
    string curr;
    // homepage- google.com (let's assume)
    BrowserHistory(string homepage) {   //currently is homepage par hain,toh ise curr mein daalenge
        curr=homepage;
    }
    // google.co -> leetcode.com
    // toh pehle curr(google) ko ek jagah store kraenge,kyunki in future back bhi aana pad sakta hai
    void visit(string url) {
        back_url.push(curr);
        curr=url;
        // jab bhi hum kisi bhi url par visit karenge, aage ki saare history ko remove karna hai, toh forward stack ko empty karna hai
        forward_url=stack<string>();    //yhaan ise ek new empty stack allocate kar diya
    }
    
    string back(int steps) {
// google<-leetcode <-youtube, hum youtube par hain, ab vapa jaana hai, toh pehle youtube vgrah ko store karva lenge
        while(steps>0 && !back_url.empty())
        {
            forward_url.push(curr);
            curr=back_url.top();
            back_url.pop();
            steps--;
        }
        return curr;
    }
    
    string forward(int steps) {
    // google->leetcode->youtube, humgoogle par hain, ab aage jaana hai, toh pehle google vgrah ko store karva lenge
        while(steps>0 && !forward_url.empty())
        {
            back_url.push(curr);
            curr=forward_url.top();
            forward_url.pop();
            steps--;
        }
        return curr;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */