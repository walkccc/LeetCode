class Solution {
 public:
  vector<int> mostVisited(int n, vector<int>& rounds) {
    // Case 1: If start <= end, [start, end] is the most visited.
    //
    //      s --------- n
    // 1 -------------- n
    // 1 ------ e
    //
    // Case 2: If start > end, [1, end] and [start, n] are the most visited.
    //
    //             s -- n
    // 1 -------------- n
    // 1 ------ e
    const int start = rounds.front();
    const int end = rounds.back();
    vector<int> ans;
    for (int i = 1; i <= n; ++i)
      if (start <= end) {
        if (start <= i && i <= end)
          ans.push_back(i);
      } else {  // start > end
        if (i >= start || i <= end)
          ans.push_back(i);
      }
    return ans;
  }
};
