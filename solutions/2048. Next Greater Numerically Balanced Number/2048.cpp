class Solution {
 public:
  int nextBeautifulNumber(int n) {
    while (!isBalance(++n))
      ;
    return n;
  }

 private:
  bool isBalance(int num) {
    vector<int> count(10);
    while (num > 0) {
      if (num % 10 == 0)
        return false;
      ++count[num % 10];
      num /= 10;
    }
    for (int i = 1; i < 10; ++i)
      if (count[i] && count[i] != i)
        return false;
    return true;
  }
};
