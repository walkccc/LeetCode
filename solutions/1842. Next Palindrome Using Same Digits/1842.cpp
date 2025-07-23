class Solution {
 public:
  string nextPalindrome(string num) {
    const int n = num.length();
    vector<int> arr(n / 2);

    for (int i = 0; i < arr.size(); ++i)
      arr[i] = num[i] - '0';

    if (!ranges::next_permutation(arr).found)
      return "";

    string s;

    for (const int a : arr)
      s += '0' + a;

    if (n % 2 == 1)
      return s + num[n / 2] + reversed(s);
    return s + reversed(s);
  }

 private:
  string reversed(const string& s) {
    return {s.rbegin(), s.rend()};
  }
};
