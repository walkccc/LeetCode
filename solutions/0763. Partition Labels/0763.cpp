class Solution {
 public:
  vector<int> partitionLabels(string S) {
    vector<int> ans;
    vector<int> rightmost(128);

    for (int i = 0; i < S.length(); ++i)
      rightmost[S[i]] = i;

    int l = 0;  // first index of current running string
    int r = 0;  // right most so far

    for (int i = 0; i < S.length(); ++i) {
      r = max(r, rightmost[S[i]]);
      if (r == i) {
        ans.push_back(i - l + 1);
        l = i + 1;
      }
    }

    return ans;
  }
};
