class Solution {
 public:
  vector<string> findOcurrences(string text, string first, string second) {
    vector<string> ans;
    stringstream ss(text);

    for (string prev2, prev, word; ss >> word;) {
      if (prev2 == first && prev == second)
        ans.push_back(word);
      prev2 = prev;
      prev = word;
    }

    return ans;
  }
};
