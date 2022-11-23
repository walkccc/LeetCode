class Solution {
 public:
  int fourSumCount(vector<int>& A, vector<int>& B,
                   vector<int>& C, vector<int>& D) {
    int ans = 0;
    unordered_map<int, int> count;

    for (const int a : A)
      for (const int b : B)
        ++count[a + b];

    for (const int c : C)
      for (const int d : D)
        if (count.count(-c - d))
          ans += count[-c - d];

    return ans;
  }
};
