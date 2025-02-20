class Solution {
 public:
  bool checkDistances(string s, vector<int>& distance) {
    vector<int> firstSeenIndex(26, -1);

    for (int i = 0; i < s.length(); ++i) {
      const int j = s[i] - 'a';
      int& prevIndex = firstSeenIndex[j];
      if (prevIndex != -1 && i - prevIndex - 1 != distance[j])
        return false;
      prevIndex = i;
    }

    return true;
  }
};
