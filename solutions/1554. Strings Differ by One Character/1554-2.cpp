class Solution {
 public:
  bool differByOne(vector<string>& dict) {
    const int m = dict[0].length();
    vector<int> wordToHash;

    for (const string& word : dict)
      wordToHash.push_back(getHash(word));

    // Compute the hash without each letter.
    // e.g. hash of "abc" = 26^2 * 'a' + 26 * 'b' + 'c'
    //   newHash of "a*c" = hash - 26 * 'b'
    int coefficient = 1;
    for (int j = m - 1; j >= 0; --j) {
      unordered_map<int, vector<int>> newHashToIndices;
      for (int i = 0; i < dict.size(); ++i) {
        const string& word = dict[i];
        const int newHash =
            (wordToHash[i] -
             static_cast<long>(coefficient) * val(word[j]) % kHash + kHash) %
            kHash;
        if (const auto it = newHashToIndices.find(newHash);
            it != newHashToIndices.cend())
          for (const int index : it->second)
            // word[0..j) == dict[index][0..j) &&
            // word[j + 1..n) == dict[index][j + 1..n)
            if (equal(word.begin(), word.begin() + j, dict[index].begin()) &&
                equal(word.begin() + j + 1, word.end(),
                      dict[index].begin() + j + 1))
              return true;
        newHashToIndices[newHash].push_back(i);
      }
      coefficient = coefficient * kBase % kHash;
    }

    return false;
  }

 private:
  static constexpr long kBase = 26;
  static constexpr int kHash = 1'000'000'007;

  static constexpr int val(char c) {
    return c - 'a';
  }

  // Returns the hash of `s`. Assume the length of `s` is m.
  // e.g. getHash(s) = 26^(m - 1) * s[0] + 26^(m - 2) * s[1] + ... + s[m - 1].
  int getHash(const string& s) {
    int hash = 0;
    for (const char c : s)
      hash = (hash * kBase + val(c)) % kHash;
    return hash;
  }
};
