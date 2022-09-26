struct Record {
  int count;
  int nextIndex;
  Record(int count, int nextIndex) : count(count), nextIndex(nextIndex) {}
};

class Solution {
 public:
  int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    vector<Record> records;  // [count(s1 matches s2[i:]), next index of s2[i:]]

    for (int i = 0; i < s2.length(); ++i) {
      int count = 0;
      int nextIndex = i;
      for (int j = 0; j < s1.length(); ++j)
        if (s2[nextIndex] == s1[j])
          if (++nextIndex == s2.length()) {  // have a match
            ++count;
            nextIndex = 0;
          }
      records.emplace_back(count, nextIndex);
    }

    int matches = 0;  // S1 matches s2
    int index = 0;

    while (n1--) {
      matches += records[index].count;
      index = records[index].nextIndex;
    }

    return matches / n2;  // S1 matches S2
  }
};
