class Solution {
 public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(begin(g), end(g));
    sort(begin(s), end(s));

    int i = 0;
    for (int j = 0; j < s.size() && i < g.size(); ++j)
      if (g[i] <= s[j])
        ++i;

    return i;
  }
};
