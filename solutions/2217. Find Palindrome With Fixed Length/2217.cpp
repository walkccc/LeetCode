class Solution {
 public:
  vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
    const int start = pow(10, (intLength + 1) / 2 - 1);
    const int end = pow(10, (intLength + 1) / 2);
    const int mul = pow(10, intLength / 2);
    vector<long long> ans;

    for (const int q : queries)
      if (start + q > end)
        ans.push_back(-1);
      else
        ans.push_back(getKthPalindrome(q, start, mul, intLength));

    return ans;
  }

 private:
  long long getKthPalindrome(int q, int start, int mul, int intLength) {
    const long long prefix = start + q - 1;
    return prefix * mul + reverse(intLength & 1 ? prefix / 10 : prefix);
  }

  long long reverse(int num) {
    long long res = 0;
    while (num) {
      res = res * 10 + num % 10;
      num /= 10;
    }
    return res;
  }
};
