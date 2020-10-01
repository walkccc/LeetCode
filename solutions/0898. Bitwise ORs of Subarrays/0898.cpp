class Solution {
 public:
  int subarrayBitwiseORs(vector<int>& A) {
    // s(j) := A[i] | A[i + 1] | ... | A[j] for all 0 <= i <= j (fixed)
    vector<int> s;
    int l = 0;

    for (const int a : A) {
      const int r = s.size();
      s.push_back(a);
      // s[l..r) are the values generated in the previous iteration
      for (int i = l; i < r; ++i)
        if (s.back() != (s[i] | a))
          s.push_back(s[i] | a);
      l = r;
    }

    return unordered_set<int>(begin(s), end(s)).size();
  }
};