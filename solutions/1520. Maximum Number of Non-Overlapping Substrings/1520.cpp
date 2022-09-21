class Solution {
 public:
  vector<string> maxNumOfSubstrings(string s) {
    const int n = s.length();
    vector<string> ans;
    vector<int> leftmost(26, n);    // leftmost index of each letter
    vector<int> rightmost(26, -1);  // rightmost index of each letter

    for (int i = 0; i < n; ++i) {
      leftmost[s[i] - 'a'] = min(leftmost[s[i] - 'a'], i);
      rightmost[s[i] - 'a'] = i;
    }

    auto getNewRight = [&](int i) {
      int right = rightmost[s[i] - 'a'];
      for (int j = i; j <= right; ++j) {
        if (leftmost[s[j] - 'a'] < i)  // find a letter's first index < i
          return -1;
        right = max(right, rightmost[s[j] - 'a']);  // right expands dynamically
      }
      return right;
    };

    int right = -1;  // last substring's rightmost index
    for (int i = 0; i < n; ++i) {
      if (i == leftmost[s[i] - 'a']) {  // current index is the first appearance
        const int newRight = getNewRight(i);
        if (newRight == -1)
          continue;  // find a letter's first index < i
        if (i <= right && !ans.empty())
          ans.back() = s.substr(i, newRight - i + 1);
        else
          ans.push_back(s.substr(i, newRight - i + 1));
        right = newRight;
      }
    }

    return ans;
  }
};
