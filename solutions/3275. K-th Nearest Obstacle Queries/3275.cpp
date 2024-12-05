class Solution {
 public:
  vector<int> resultsArray(vector<vector<int>>& queries, int k) {
    vector<int> ans;
    priority_queue<int> maxHeap;

    for (const vector<int>& query : queries) {
      const int x = query[0];
      const int y = query[1];
      maxHeap.push(abs(x) + abs(y));
      if (maxHeap.size() > k)
        maxHeap.pop();
      ans.push_back(maxHeap.size() == k ? maxHeap.top() : -1);
    }

    return ans;
  }
};
