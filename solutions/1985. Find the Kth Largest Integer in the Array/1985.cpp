class Solution {
 public:
  // Similar to 215. Kth Largest Element in an Array
  string kthLargestNumber(vector<string>& nums, int k) {
    auto compare = [](const string& a, const string& b) {
      return a.length() == b.length() ? a > b : a.length() > b.length();
    };
    priority_queue<string, vector<string>, decltype(compare)> minHeap(compare);

    for (const string& num : nums) {
      minHeap.push(num);
      if (minHeap.size() > k)
        minHeap.pop();
    }

    return minHeap.top();
  }
};
