class Solution {
 public:
  int countTriplets(vector<int>& A) {
    constexpr int kMax = 1 << 16;
    int ans = 0;
    vector<int> count(kMax);  // {A[i] & A[j]: times}

    for (const int a : A)
      for (const int b : A)
        ++count[a & b];

    for (const int a : A)
      for (int i = 0; i < kMax; ++i)
        if (!(a & i))
          ans += count[i];

    return ans;
  }
};
