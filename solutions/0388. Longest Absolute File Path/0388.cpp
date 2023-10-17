struct T {
  int depth;
  size_t length;
  T(int depth, size_t length) : depth(depth), length(length) {}
};

class Solution {
 public:
  int lengthLongestPath(string input) {
    size_t ans = 0;
    stack<T> stack{{{-1, 0}}};  // Placeholder
    istringstream iss(input);

    for (string token; getline(iss, token, '\n');) {
      const int depth = count_if(token.begin(), token.end(),
                                 [](char c) { return c == '\t'; });
      token.erase(remove(token.begin(), token.end(), '\t'), token.end());
      while (depth <= stack.top().depth)
        stack.pop();
      if (isFile(token))
        ans = max(ans, stack.top().length + token.length());
      else  // Directory + '/'
        stack.emplace(depth, stack.top().length + token.length() + 1);
    }

    return ans;
  }

 private:
  bool isFile(const string& token) {
    return token.find('.') != string::npos;
  }
};
