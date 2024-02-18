class Solution {
 public:
  int maxDistance(vector<int>& colors) {
    // The maximum distance always includes either the first or the last house.
    const int n = colors.size();
    int i = 0;      // the leftmost index, where colors[i] != colors[-1]
    int j = n - 1;  // the rightmost index, where colors[j] != colors[0]
    while (colors[i] == colors.back())
      ++i;
    while (colors[j] == colors.front())
      --j;
    return max(n - 1 - i, j);
  }
};
