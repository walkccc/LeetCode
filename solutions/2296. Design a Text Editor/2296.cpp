class TextEditor {
 public:
  void addText(string text) {
    s += text;
  }

  int deleteText(int k) {
    const int numDeleted = min(k, static_cast<int>(s.length()));
    for (int i = 0; i < numDeleted; ++i)
      s.pop_back();
    return numDeleted;
  }

  string cursorLeft(int k) {
    while (!s.empty() && k--)
      stack.push(s.back()), s.pop_back();
    return getString();
  }

  string cursorRight(int k) {
    while (!stack.empty() && k--)
      s += stack.top(), stack.pop();
    return getString();
  }

  string getString() {
    if (s.length() < 10)
      return s;
    return s.substr(s.length() - 10);
  }

 private:
  string s;
  stack<char> stack;
};
