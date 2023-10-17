class Solution {
 public:
  int captureForts(vector<int>& forts) {
    int ans = 0;

    for (int i = 0, j = 0; i < forts.size(); ++i)
      if (forts[i] != 0) {  // -1 or 1
        if (forts[i] == -forts[j])
          ans = max(ans, i - j - 1);
        j = i;
      }

    return ans;
  }
};
