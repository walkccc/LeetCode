class Solution {
 public:
  vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    const int n = A.size();
    int prefixCommon = 0;
    vector<int> ans;
    vector<int> count(n + 1);

    for (int i = 0; i < A.size(); ++i) {
      if (++count[A[i]] == 2)
        ++prefixCommon;
      if (++count[B[i]] == 2)
        ++prefixCommon;
      ans.push_back(prefixCommon);
    }

    return ans;
  }
};
