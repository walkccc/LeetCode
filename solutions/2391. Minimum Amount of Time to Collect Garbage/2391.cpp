class Solution {
 public:
  int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    vector<int> prefix(travel.size());
    partial_sum(begin(travel), end(travel), begin(prefix));
    const int timeM = getTime(garbage, prefix, 'M');
    const int timeP = getTime(garbage, prefix, 'P');
    const int timeG = getTime(garbage, prefix, 'G');
    return timeM + timeP + timeG;
  }

 private:
  int getTime(const vector<string>& garbage, const vector<int>& prefix,
              char c) {
    int characterCount = 0;
    int lastIndex = -1;
    for (int i = 0; i < garbage.size(); ++i) {
      const string& s = garbage[i];
      if (any_of(begin(s), end(s), [c](const char g) { return g == c; }))
        lastIndex = i;
      characterCount += std::count(begin(s), end(s), c);
    }
    return characterCount + (lastIndex <= 0 ? 0 : prefix[lastIndex - 1]);
  }
};
