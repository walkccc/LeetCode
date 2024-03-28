class Solution {
 public:
  int shortestSequence(vector<int>& rolls, int k) {
    int ans = 1;  // the the next target length
    unordered_set<int> seen;

    for (const int roll : rolls) {
      seen.insert(roll);
      if (seen.size() == k) {
        // Have all combinations that form `ans` length, and we are going to
        // extend the sequence to `ans + 1` length.
        ++ans;
        seen.clear();
      }
    }

    return ans;
  }
};
