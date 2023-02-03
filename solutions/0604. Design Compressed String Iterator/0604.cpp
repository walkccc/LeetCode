class StringIterator {
 public:
  StringIterator(string compressedString) : s(compressedString) {}

  char next() {
    if (!hasNext())
      return ' ';

    if (num == 0) {
      currentChar = s[i++];
      while (i < s.length() && isdigit(s[i]))
        num = num * 10 + (s[i++] - '0');
    }

    --num;
    return currentChar;
  }

  bool hasNext() {
    return i < s.length() || num > 0;
  }

 private:
  const string s;
  int i = 0;    // s's index
  int num = 0;  // currentChar's count
  char currentChar = ' ';
};
