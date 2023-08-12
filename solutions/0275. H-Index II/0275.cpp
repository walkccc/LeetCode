class Solution {
 public:
  int hIndex(vector<int>& citations) {
    const int n = citations.size();
    int l = 0;
    int r = n;

    while (l < r) {
      const int m = (l + r) / 2;
      if (citations[m] >= n - m)
        r = m;
      else
        l = m + 1;
    }

    return n - l;
  }
};
