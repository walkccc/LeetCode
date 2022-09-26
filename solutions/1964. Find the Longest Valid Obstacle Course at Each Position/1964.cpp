class Solution {
 public:
  vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
    vector<int> ans;
    // tail[i] := the minimum tail of all increasing subseqs having length i + 1
    // it's easy to see that tail must be an increasing array
    vector<int> tail;

    for (const int obstacle : obstacles)
      if (tail.empty() || obstacle >= tail.back()) {
        tail.push_back(obstacle);
        ans.push_back(tail.size());
      } else {
        const int index = firstGreater(tail, obstacle);
        tail[index] = obstacle;
        ans.push_back(index + 1);
      }

    return ans;
  }

 private:
  // find the first index l s.t A[l] > target
  // return A.size() if can't find
  int firstGreater(const vector<int>& A, int target) {
    return upper_bound(begin(A), end(A), target) - begin(A);
  }
};
