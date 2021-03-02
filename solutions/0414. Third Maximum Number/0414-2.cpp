class Solution {
 public:
  int thirdMax(vector<int>& nums) {
    priority_queue<int, vector<int>, greater<>> pq;  // min-heap
    unordered_set<int> seen;

    for (const int num : nums)
      if (!seen.count(num)) {
        seen.insert(num);
        pq.push(num);
        if (pq.size() > 3)
          pq.pop();
      }

    if (pq.size() == 2)
      pq.pop();

    return pq.top();
  }
};
