class Solution {
 public:
  vector<int> getNoZeroIntegers(int n) {
    for (int A = 1; A < n; ++A) {
      int B = n - A;
      if (to_string(A).find('0') == string::npos &&
          to_string(B).find('0') == string::npos)
        return {A, B};
    }

    throw;
  }
};
