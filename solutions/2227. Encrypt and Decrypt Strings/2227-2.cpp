class Encrypter {
 public:
  Encrypter(vector<char>& keys, vector<string>& values,
            vector<string>& dictionary) {
    for (int i = 0; i < keys.size(); ++i)
      keyToValue[keys[i]] = values[i];

    for (const string& word : dictionary)
      ++encryptedCount[encrypt(word)];
  }

  string encrypt(string word1) {
    string ans;
    for (const char c : word1)
      ans += keyToValue[c];
    return ans;
  }

  int decrypt(string word2) {
    return encryptedCount[word2];
  }

 private:
  unordered_map<char, string> keyToValue;
  unordered_map<string, int> encryptedCount;
};
