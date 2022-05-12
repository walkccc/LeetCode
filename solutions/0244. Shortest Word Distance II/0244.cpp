class WordDistance {
 public:
  WordDistance(vector<string>& words) {
    for (int i = 0; i < words.size(); ++i)
      wordToIndices[words[i]].push_back(i);
  }

  int shortest(string word1, string word2) {
    const vector<int> indices1 = wordToIndices[word1];
    const vector<int> indices2 = wordToIndices[word2];
    int ans = INT_MAX;

    for (int i = 0, j = 0; i < indices1.size() && j < indices2.size();) {
      ans = min(ans, abs(indices1[i] - indices2[j]));
      if (indices1[i] < indices2[j])
        ++i;
      else
        ++j;
    }

    return ans;
  }

 private:
  unordered_map<string, vector<int>> wordToIndices;
};
