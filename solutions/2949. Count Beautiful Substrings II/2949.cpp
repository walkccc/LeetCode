class Solution {
 public:
  // Same as 2947. Count Beautiful Substrings I
  int beautifulSubstrings(string s, int k) {
    const int root = getRoot(k);
    int ans = 0;
    int vowels = 0;
    int vowelsMinusConsonants = 0;
    // {(vowels, vowelsMinusConsonants): count}
    unordered_map<pair<int, int>, int, PairHash> prefixCount{{{0, 0}, 1}};

    for (const char c : s) {
      if (isVowel(c)) {
        vowels = (vowels + 1) % root;
        ++vowelsMinusConsonants;
      } else {
        --vowelsMinusConsonants;
      }
      const pair<int, int> prefix{vowels, vowelsMinusConsonants};
      ans += prefixCount[prefix]++;
    }

    return ans;
  }

 private:
  bool isVowel(char c) {
    static constexpr string_view kVowels = "aeiouAEIOU";
    return kVowels.find(c) != string_view::npos;
  }

  int getRoot(int k) {
    for (int i = 1; i <= k; ++i)
      if (i * i % k == 0)
        return i;
    throw;
  }

  struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
      return p.first ^ p.second;
    }
  };
};
