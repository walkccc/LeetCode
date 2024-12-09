class Solution {
 public:
  int convertArray(vector<int>& nums) {
    return min(cost(nums), cost(negative(nums)));
  }

 private:
  int cost(const vector<int>& nums) {
    int ans = 0;
    priority_queue<int> maxHeap;

    // Greedily make `nums` non-decreasing.
    for (const int num : nums) {
      if (!maxHeap.empty() && maxHeap.top() > num) {
        ans += maxHeap.top() - num, maxHeap.pop();
        maxHeap.push(num);
      }
      maxHeap.push(num);
    }

    return ans;
  }

  vector<int> negative(const vector<int>& nums) {
    vector<int> A(nums);
    for (int& a : A)
      a *= -1;
    return A;
  }
};
