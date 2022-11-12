class MedianFinder {
public:
    priority_queue<int> low;
    priority_queue<int,vector<int>,greater<int>> high;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(low.empty() || num<low.top())
            low.push(num);
        else
            high.push(num);
        if(low.size()<high.size())
        {
            low.push(high.top());
            high.pop();
        }
        else if(low.size()>high.size()+1)
        {
            high.push(low.top());
            low.pop();
        }
    }
    
    double findMedian() {
        if(low.size()>high.size())
            return low.top();
        else
            return (low.top()+high.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */