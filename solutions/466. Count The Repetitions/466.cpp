struct Record {
  int count;
  int nextIndex;
};

class Solution {
 public:
  int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    // records[i].count := the number of times that s2 starting from index i has
    // been fully matched with s1
    // records[i].nextIndex := the next index in s2 to be matched after
    // completing a full match starting from index i
    vector<Record> records;

    for (int i = 0; i < s2.length(); ++i) {
      int count = 0;
      int nextIndex = i;
      for (const char c : s1)
        if (s2[nextIndex] == c)
          if (++nextIndex == s2.length()) {  // There's a match.
            ++count;
            nextIndex = 0;
          }
      records.emplace_back(count, nextIndex);
    }

    int matches = 0;  // the number of matches between `s1` x n1 and `s2`
    int i = 0;        // the index in `s2` to start matching

    while (n1-- > 0) {
      matches += records[i].count;
      i = records[i].nextIndex;
    }

    return matches / n2;
  }
};
