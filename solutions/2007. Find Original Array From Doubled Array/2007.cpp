class Solution {
 public:
  vector<int> findOriginalArray(vector<int>& changed) {
    vector<int> ans;
    queue<int> q;

    ranges::sort(changed);

    for (const int num : changed)
      if (!q.empty() && num == q.front()) {
        q.pop();
      } else {
        q.push(num * 2);
        ans.push_back(num);
      }

    return q.empty() ? ans : vector<int>();
  }
};
