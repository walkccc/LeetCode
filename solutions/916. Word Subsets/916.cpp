class Solution {
 public:
  vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
    vector<string> ans;
    vector<int> countB(26);

    for (const string& b : B) {
      vector<int> temp = counter(b);
      for (int i = 0; i < 26; ++i)
        countB[i] = max(countB[i], temp[i]);
    }

    for (const string& a : A)
      if (isUniversal(counter(a), countB))
        ans.push_back(a);

    return ans;
  }

 private:
  vector<int> counter(const string& s) {
    vector<int> count(26);
    for (char c : s)
      ++count[c - 'a'];
    return count;
  }

  bool isUniversal(vector<int> countA, vector<int>& countB) {
    for (int i = 0; i < 26; ++i)
      if (countA[i] < countB[i])
        return false;
    return true;
  }
};
