class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
       
       vector<int> result;
    
    // Deque to store indices of useful elements for the current window
    deque<int> dq;
    
    // Traverse the array
    for (int i = 0; i < arr.size(); i++) {
        // Remove indices that are out of this window
        if (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }
        
        // Remove elements that are smaller than the current element
        // as they will not be the maximum if the current element is larger
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        
        // Add the current element at the back of the deque
        dq.push_back(i);
        
        // Once we have processed at least k elements, record the max of the window
        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }
    
    return result;
    }
};
