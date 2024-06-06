class Solution {
 public:
  vector<int> selfDividingNumbers(int left, int right) {
    vector<int> ans;

    for (int num = left; num <= right; ++num)
      if (selfDividingNumbers(num))
        ans.push_back(num);

    return ans;
  }

 private:
  bool selfDividingNumbers(int num) {
    for (int n = num; n > 0; n /= 10)
      if (n % 10 == 0 || num % (n % 10) != 0)
        return false;
    return true;
  }
};
