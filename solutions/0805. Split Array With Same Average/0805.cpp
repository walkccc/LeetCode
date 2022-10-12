class Solution {
 public:
  bool splitArraySameAverage(vector<int>& A) {
    const int n = A.size();
    const int sum = accumulate(begin(A), end(A), 0);
    if (!isPossible(sum, n))
      return false;

    vector<unordered_set<int>> sums(n / 2 + 1);
    sums[0].insert(0);

    for (const int a : A)
      for (int i = n / 2; i > 0; --i)
        for (const int num : sums[i - 1])
          sums[i].insert(a + num);

    for (int i = 1; i < n / 2 + 1; ++i)
      if (i * sum % n == 0 && sums[i].count(i * sum / n))
        return true;

    return false;
  }

 private:
  bool isPossible(int sum, int n) {
    for (int i = 1; i < n / 2 + 1; ++i)
      if (i * sum % n == 0)
        return true;
    return false;
  }
};
