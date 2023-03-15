class Solution {
 public:
  int minimumPartition(string s, int k) {
    int ans = 1;
    long curr = 0;

    for (const char c : s) {
      curr = curr * 10 + c - '0';
      if (curr > k) {
        curr = c - '0';
        ++ans;
      }
      if (curr > k)
        return -1;
    }

    return ans;
  }
};
