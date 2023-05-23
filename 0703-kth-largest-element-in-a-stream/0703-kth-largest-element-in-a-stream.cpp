class KthLargest {
public:
     priority_queue<int,vector<int>,greater<int>>pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        //Min-heap
       K=k;
        for(int &i:nums)
        {
            pq.push(i);
            if(pq.size()>k)
                pq.pop();   //agar size k se bda ho gya,toh top ke element ko pop kar denge,hme vaise bhi kth lasgest(distict)chaiye,smaller elements ka kuch kaam bhi nahin hai
        }
    }
    
    int add(int val) {  //ismein value(element) ko daalna hai aur phir btana hai,kth largest kon sa hai
        pq.push(val);
        if(pq.size()>K)
            pq.pop();   //agar element daalne ke baad,size k se bda ho gya,toh top element pop kar denge(min-heap hai,toh top par smaller element hoga)
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */