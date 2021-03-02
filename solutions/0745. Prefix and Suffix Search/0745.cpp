class WordFilter {
 public:
  WordFilter(vector<string>& words) {
    for (int i = 0; i < words.size(); ++i) {
      const string& word = words[i];
      vector<string> prefixes;
      vector<string> suffixes;
      for (int j = 0; j <= word.length(); ++j) {
        const string prefix = word.substr(0, j);
        const string suffix = word.substr(j);
        prefixes.push_back(prefix);
        suffixes.push_back(suffix);
      }
      for (const string& prefix : prefixes)
        for (const string& suffix : suffixes)
          keyToIndex[prefix + '_' + suffix] = i;
    }
  }

  int f(string prefix, string suffix) {
    const string key = prefix + '_' + suffix;
    if (keyToIndex.count(key))
      return keyToIndex[key];
    return -1;
  }

 private:
  unordered_map<string, int> keyToIndex;
};
