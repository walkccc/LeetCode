class Solution {
 public:
  int wordsTyping(vector<string>& sentence, int rows, int cols) {
    const string& combined = getCombined(sentence);
    const int n = combined.length();
    int i = 0;  // (i % n) points to the index of combined in each row

    while (rows--) {
      i += cols;
      if (combined[i % n] == ' ') {
        ++i;
      } else {
        while (i > 0 && combined[(i - 1) % n] != ' ')
          --i;
      }
    }

    return i / n;
  }

 private:
  string getCombined(const vector<string>& sentence) {
    string combined;
    for (const string& word : sentence)
      combined += (word + ' ');
    return combined;
  }
};
