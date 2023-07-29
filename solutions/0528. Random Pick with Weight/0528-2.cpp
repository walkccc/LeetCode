class Solution {
 public:
  Solution(vector<int>& w) : prefix(w.size()) {
    partial_sum(w.begin(), w.end(), prefix.begin());
  }

  int pickIndex() {
    const int target = rand() % prefix.back();
    return upper_bound(prefix.begin(), prefix.end(), target) - prefix.begin();
  }

 private:
  vector<int> prefix;
};
