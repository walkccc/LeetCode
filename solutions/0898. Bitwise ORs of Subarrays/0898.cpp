class Solution {
 public:
  int subarrayBitwiseORs(vector<int>& arr) {
    vector<int> s;
    int l = 0;

    for (const int a : arr) {
      const int r = s.size();
      s.push_back(a);
      // s[l..r) are values generated in previous iteration
      for (int i = l; i < r; ++i)
        if (s.back() != (s[i] | a))
          s.push_back(s[i] | a);
      l = r;
    }

    return unordered_set<int>(begin(s), end(s)).size();
  }
};
