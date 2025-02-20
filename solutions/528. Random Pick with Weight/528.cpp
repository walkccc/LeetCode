class Solution {
 public:
  Solution(vector<int>& w) : prefix(w.size()) {
    partial_sum(w.begin(), w.end(), prefix.begin());
  }

  int pickIndex() {
    const int target = rand() % prefix.back();
    int l = 0;
    int r = prefix.size();

    while (l < r) {
      const int m = (l + r) / 2;
      if (prefix[m] > target)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

 private:
  vector<int> prefix;
};
