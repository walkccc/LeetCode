class Solution {
 public:
  int shortestWay(string source, string target) {
    int ans = 0;

    for (int i = 0; i < target.length();) {
      const int prevIndex = i;
      for (int j = 0; j < source.length(); ++j)
        if (i < target.length() && source[j] == target[i])
          ++i;
      // All chars in source didn't match target[i]
      if (i == prevIndex)
        return -1;
      ++ans;
    }

    return ans;
  }
};
