class Solution {
 public:
  int distinctEchoSubstrings(string text) {
    unordered_set<string> seen;

    for (int k = 1; k <= text.length() / 2; ++k) {  // target length
      int same = 0;
      for (int l = 0, r = k; r < text.length(); ++l, ++r) {
        if (text[l] == text[r])
          ++same;
        else
          same = 0;
        if (same == k) {
          seen.insert(text.substr(l - k + 1, k));
          // move the window thus leaving a char behind,
          // so we need to decrease the counter
          --same;
        }
      }
    }

    return seen.size();
  }
};
