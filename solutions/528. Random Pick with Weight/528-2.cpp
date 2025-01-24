class Solution {
 public:
  Solution(vector<int>& w) : prefix(w.size()) {
    partial_sum(w.begin(), w.end(), prefix.begin());
  }

  int pickIndex() {
    const int target = rand() % prefix.back();
    return ranges::upper_bound(prefix, target) - prefix.begin();
  }

 private:
  vector<int> prefix;
};
