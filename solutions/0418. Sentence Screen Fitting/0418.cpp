class Solution {
 public:
  int wordsTyping(vector<string>& sentence, int rows, int cols) {
    const string& combined = getCombined(sentence);
    const int n = combined.length();

    int start = 0;  // the start index of combined in each row

    for (int i = 0; i < rows; ++i) {
      start += cols;
      if (combined[start % n] == ' ') {
        ++start;
      } else {
        while (start > 0 && combined[(start - 1) % n] != ' ')
          --start;
      }
    }

    return start / n;
  }

 private:
  string getCombined(const vector<string>& sentence) {
    string combined;
    for (const string& word : sentence)
      combined += (word + ' ');
    return combined;
  }
};
