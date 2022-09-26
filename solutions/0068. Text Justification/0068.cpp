class Solution {
 public:
  vector<string> fullJustify(vector<string>& words, size_t maxWidth) {
    vector<string> ans;
    vector<string> row;
    size_t rowLetters = 0;

    for (const string& word : words) {
      // if we put the word in this row, it'll exceed the maxWidth,
      // so we cannot put the word to this row and have to pad spaces to
      // each word in this row
      if (rowLetters + row.size() + word.length() > maxWidth) {
        const int spaces = maxWidth - rowLetters;
        if (row.size() == 1) {
          // pad all spaces after row[0]
          for (int i = 0; i < spaces; ++i)
            row[0] += " ";
        } else {
          // evenly pad spaces to each word (expect the last one) in this row
          for (int i = 0; i < spaces; ++i)
            row[i % (row.size() - 1)] += " ";
        }
        ans.push_back(join(row, ""));
        row.clear();
        rowLetters = 0;
      }
      row.push_back(word);
      rowLetters += word.length();
    }
    ans.push_back(ljust(join(row, " "), maxWidth));

    return ans;
  }

 private:
  string join(const vector<string>& v, const string& c) {
    string s;
    for (auto p = begin(v); p != end(v); ++p) {
      s += *p;
      if (p != end(v) - 1)
        s += c;
    }
    return s;
  }

  string ljust(string s, int width) {
    for (int i = 0; i < s.length() - width; ++i)
      s += " ";
    return s;
  }
};
