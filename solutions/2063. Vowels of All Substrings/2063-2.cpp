class Solution {
 public:
  long long countVowels(string word) {
    long long ans = 0;

    for (int i = 0; i < word.length(); ++i)
      if (string("aeiou").find(word[i]) != string::npos)
        ans += (i + 1) * (word.length() - i);

    return ans;
  }
};
