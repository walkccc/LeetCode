class StringIterator {
 public:
  StringIterator(string compressedString) {
    int i = 0;  // compressedString's index
    while (i < compressedString.length()) {
      const char c = compressedString[i++];
      int num = 0;
      while (i < compressedString.length() && isdigit(compressedString[i]))
        num = num * 10 + (compressedString[i++] - '0');
      q.emplace(c, num);
    }
  }

  char next() {
    if (!hasNext())
      return ' ';

    const char c = q.front().first;
    if (--q.front().second == 0)
      q.pop();
    return c;
  }

  bool hasNext() {
    return !q.empty();
  }

 private:
  queue<pair<char, int>> q;  // (currentChar, num)
};
