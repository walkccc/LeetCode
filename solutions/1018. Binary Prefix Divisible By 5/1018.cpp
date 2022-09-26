class Solution {
 public:
  vector<bool> prefixesDivBy5(vector<int>& A) {
    vector<bool> ans;
    int num = 0;

    for (int a : A) {
      num = (num * 2 + a) % 5;
      ans.push_back(num % 5 == 0);
    }

    return ans;
  }
};
