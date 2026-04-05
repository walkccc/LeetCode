class Solution {
 public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    ranges::sort(g);
    ranges::sort(s);

    int i = 0;
    for (const int cookie : s)
      if (i < g.size() && g[i] <= cookie)
        ++i;

    return i;
  }
};
