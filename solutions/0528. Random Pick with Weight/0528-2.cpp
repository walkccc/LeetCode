class Solution {
 public:
  Solution(vector<int>& w) : prefix(w.size()) {
    partial_sum(begin(w), end(w), begin(prefix));
  }

  int pickIndex() {
    const int target = rand() % prefix.back();
    return upper_bound(begin(prefix), end(prefix), target) - begin(prefix);
  }

 private:
  vector<int> prefix;
};
