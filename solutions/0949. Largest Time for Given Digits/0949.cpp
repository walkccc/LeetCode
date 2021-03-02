class Solution {
 public:
  string largestTimeFromDigits(vector<int>& A) {
    string ans;

    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 4; ++j)
        for (int k = 0; k < 4; ++k) {
          if (i == j || i == k || j == k)
            continue;
          string hours = to_string(A[i]) + to_string(A[j]);
          string minutes = to_string(A[k]) + to_string(A[6 - i - j - k]);
          if (hours < "24" && minutes < "60")
            ans = max(ans, hours + ':' + minutes);
        }

    return ans;
  }
};
