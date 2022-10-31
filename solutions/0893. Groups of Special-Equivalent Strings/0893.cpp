class Solution {
 public:
  int numSpecialEquivGroups(vector<string>& A) {
    unordered_set<string> set;

    for (const string& s : A) {
      string even;
      string odd;
      for (int i = 0; i < s.length(); ++i)
        if (i % 2 == 0)
          even += s[i];
        else
          odd += s[i];
      sort(begin(even), end(even));
      sort(begin(odd), end(odd));
      set.insert(even + odd);
    }

    return set.size();
  }
};
