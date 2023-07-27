class Solution {
 public:
  int primePalindrome(int n) {
    if (n <= 2)
      return 2;
    if (n == 3)
      return 3;
    if (n <= 5)
      return 5;
    if (n <= 7)
      return 7;
    if (n <= 11)
      return 11;

    int nLength = to_string(n).length();

    while (true) {
      for (const int num : getPalindromes(nLength))
        if (num >= n && isPrime(num))
          return num;
      ++nLength;
    }

    throw;
  }

 private:
  vector<int> getPalindromes(int n) {
    vector<int> palindromes;
    const int length = n / 2;

    for (int i = pow(10, length - 1); i < pow(10, length); ++i) {
      const string s = to_string(i);
      string reversedS = s;
      reverse(reversedS.begin(), reversedS.end());
      for (int j = 0; j < 10; ++j)
        palindromes.push_back(stoi(s + to_string(j) + reversedS));
    }

    return palindromes;
  }

  bool isPrime(int num) {
    for (int i = 2; i < sqrt(num) + 1; ++i)
      if (num % i == 0)
        return false;

    return true;
  }
};
