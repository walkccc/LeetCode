class Solution {
 public:
  vector<string> findStrobogrammatic(int n) {
    return helper(n, n);
  }

 private:
  vector<string> helper(int n, int k) {
    if (n == 0)
      return {""};
    if (n == 1)
      return {"0", "1", "8"};

    vector<string> ans;

    for (const string& inner : helper(n - 2, k)) {
      if (n < k)
        ans.push_back("0" + inner + "0");
      ans.push_back("1" + inner + "1");
      ans.push_back("6" + inner + "9");
      ans.push_back("8" + inner + "8");
      ans.push_back("9" + inner + "6");
    }

    return ans;
  }
};
