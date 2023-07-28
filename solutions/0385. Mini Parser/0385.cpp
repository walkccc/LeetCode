class Solution {
 public:
  NestedInteger deserialize(string s) {
    if (s[0] != '[')
      return NestedInteger(stoi(s));

    stack<NestedInteger> stack;
    int start;  // the start index of num

    for (int i = 0; i < s.length(); ++i) {
      switch (s[i]) {
        case '[':
          stack.push(NestedInteger());
          start = i + 1;
          break;
        case ',':
          if (i > start) {
            const int num = stoi(s.substr(start, i));
            stack.top().add(NestedInteger(num));
          }
          start = i + 1;
          break;
        case ']':
          NestedInteger popped = stack.top();
          stack.pop();
          if (i > start) {
            const int num = stoi(s.substr(start, i));
            popped.add(NestedInteger(num));
          }
          if (stack.empty())
            return popped;
          else
            stack.top().add(popped);
          start = i + 1;
          break;
      }
    }

    throw;
  }
};
