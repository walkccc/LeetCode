class Solution {
 public:
  bool isValid(string code) {
    if (code[0] != '<' || code.back() != '>')
      return false;

    stack<string> stack;

    for (int i = 0; i < code.length(); ++i) {
      int closeIndex = 0;
      if (stack.empty() && containsTag)
        return false;
      if (code[i] == '<') {
        // It's inside a tag, so check if it's a cdata.
        if (!stack.empty() && code[i + 1] == '!') {
          closeIndex = code.find("]]>", i + 2);
          if (closeIndex == string::npos ||
              !isValidCdata(code.substr(i + 2, closeIndex - i - 2)))
            return false;
        } else if (code[i + 1] == '/') {  // the end tag
          closeIndex = code.find('>', i + 2);
          if (closeIndex == string::npos ||
              !isValidTagName(stack, code.substr(i + 2, closeIndex - i - 2),
                              true))
            return false;
        } else {  // the start tag
          closeIndex = code.find('>', i + 1);
          if (closeIndex == string::npos ||
              !isValidTagName(stack, code.substr(i + 1, closeIndex - i - 1),
                              false))
            return false;
        }
        i = closeIndex;
      }
    }

    return stack.empty() && containsTag;
  }

 private:
  bool containsTag = false;

  bool isValidCdata(const string& s) {
    return s.find("[CDATA[") == 0;
  }

  bool isValidTagName(stack<string>& stack, const string& tagName,
                      bool isEndTag) {
    if (tagName.empty() || tagName.length() > 9)
      return false;

    for (const char c : tagName)
      if (!isupper(c))
        return false;

    if (isEndTag) {
      if (stack.empty())
        return false;
      if (stack.top() != tagName)
        return false;
      stack.pop();
      return true;
    }

    containsTag = true;
    stack.push(tagName);
    return true;
  }
};
