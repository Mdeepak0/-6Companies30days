class KthLargest {
public:
    int k;
     priority_queue<int, vector<int>,greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        this->k = k; 
       for(int &num : nums){
        pq.push(num);
        if(pq.size() > k) pq.pop();
       }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k) pq.pop();
        return pq.top();
    }
};
