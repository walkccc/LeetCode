class Solution {
 public:
  int minTimeToType(string word) {
    int moves = 0;
    char letter = 'a';

    for (const char c : word) {
      const int diff = abs(c - letter);
      moves += min(diff, 26 - diff);
      letter = c;
    }

    return moves + word.length();
  }
};
