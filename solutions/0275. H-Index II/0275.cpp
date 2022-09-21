class Solution {
 public:
  int hIndex(vector<int>& citations) {
    int l = 0;
    int r = citations.size();

    while (l < r) {
      const int m = (l + r) / 2;
      if (citations[m] >= citations.size() - m)
        r = m;
      else
        l = m + 1;
    }

    return citations.size() - l;
  }
};
