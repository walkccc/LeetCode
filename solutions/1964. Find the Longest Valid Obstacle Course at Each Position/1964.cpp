class Solution {
 public:
  // Similar to 300. Longest Increasing Subsequence
  vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
    vector<int> ans;
    // tails[i] := the minimum tail of all the increasing subsequences having
    // length i + 1
    vector<int> tails;

    for (const int obstacle : obstacles)
      if (tails.empty() || obstacle >= tails.back()) {
        tails.push_back(obstacle);
        ans.push_back(tails.size());
      } else {
        const int index = firstGreater(tails, obstacle);
        tails[index] = obstacle;
        ans.push_back(index + 1);
      }

    return ans;
  }

 private:
  int firstGreater(const vector<int>& A, int target) {
    return ranges::upper_bound(A, target) - A.begin();
  }
};
