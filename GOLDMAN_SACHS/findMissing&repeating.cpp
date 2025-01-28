class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
       
       vector<int> ans;
        int n = arr.size();
        long long sum = 0;
        long long sum_of_squares = 0;
        long long expected_sum = 0;
        long long expected_sum_of_squares = 0;
        
        // Calculate the sum and sum of squares of the elements in the array
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            sum_of_squares += (long long)arr[i] * arr[i];
        }
        
        // Calculate the expected sum and sum of squares for numbers 1 to n
        for (int i = 1; i <= n; i++) {
            expected_sum += i;
            expected_sum_of_squares += (long long)i * i;
        }
        
        // Equation for (sum - expected_sum) and (sum_of_squares - expected_sum_of_squares)
        long long diff_sum = sum - expected_sum;
        long long diff_sum_of_squares = sum_of_squares - expected_sum_of_squares;
        
        // Use the difference to find the missing and repeating numbers
        long long x = (diff_sum + (diff_sum_of_squares / diff_sum)) / 2;
        long long y = x - diff_sum;
        
        ans.push_back((int)x);
        ans.push_back((int)y);
        
        return ans;
       
    }
};
