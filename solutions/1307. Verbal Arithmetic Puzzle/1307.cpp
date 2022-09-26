class Solution {
 public:
  bool isSolvable(vector<string>& words, string result) {
    usedDigit = vector<bool>(10);
    words.push_back(result);
    rows = words.size();
    for (const string& word : words)
      cols = max(cols, static_cast<int>(word.length()));
    return dfs(words, 0, 0, 0);
  }

 private:
  unordered_map<char, int> letterToDigit;
  vector<bool> usedDigit;
  int rows;
  int cols;

  bool dfs(vector<string>& words, int row, int col, int sum) {
    if (col == cols)
      return sum == 0;
    if (row == rows)
      return sum % 10 == 0 && dfs(words, 0, col + 1, sum / 10);

    string word = words[row];
    if (col >= word.length())
      return dfs(words, row + 1, col, sum);

    char letter = word[word.length() - col - 1];
    int sign = row == rows - 1 ? -1 : 1;

    if (letterToDigit.count(letter) &&
        (letterToDigit[letter] > 0 || col < word.length() - 1))
      return dfs(words, row + 1, col, sum + sign * letterToDigit[letter]);

    for (int digit = 0; digit < 10; ++digit)
      if (!usedDigit[digit] && (digit > 0 || col + 1 < word.length())) {
        letterToDigit[letter] = digit;
        usedDigit[digit] = true;
        if (dfs(words, row + 1, col, sum + sign * digit))
          return true;
        usedDigit[digit] = false;
        letterToDigit.erase(letter);
      }

    return false;
  }
};
