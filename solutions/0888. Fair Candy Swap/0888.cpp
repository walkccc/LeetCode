class Solution {
 public:
  vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    int diff =
        (accumulate(begin(A), end(A), 0) - accumulate(begin(B), end(B), 0)) / 2;
    unordered_set<int> set{begin(B), end(B)};

    for (int a : A)
      if (set.count(a - diff))
        return {a, a - diff};

    throw;
  }
};
