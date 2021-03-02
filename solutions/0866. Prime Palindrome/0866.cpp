class Solution {
 public:
  int primePalindrome(int N) {
    if (N <= 2)
      return 2;
    if (N == 3)
      return 3;
    if (N <= 5)
      return 5;
    if (N <= 7)
      return 7;
    if (N <= 11)
      return 11;

    int n = to_string(N).length();

    while (true) {
      for (const int num : getPalindromes(n))
        if (num >= N && isPrime(num))
          return num;
      ++n;
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
      reverse(begin(reversedS), end(reversedS));
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
