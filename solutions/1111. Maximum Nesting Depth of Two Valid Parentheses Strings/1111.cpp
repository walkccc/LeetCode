class Solution {
 public:
  vector<int> maxDepthAfterSplit(string seq) {
    vector<int> ans;
    int depth = 1;

    // Put all odd-depth parentheses in one group and even-depth parentheses in
    // the other group.
    for (const char c : seq)
      if (c == '(')
        ans.push_back(++depth % 2);
      else
        ans.push_back(depth-- % 2);

    return ans;
  }
};
