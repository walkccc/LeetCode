class Solution {
 public:
  string minRemoveToMakeValid(string s) {
    stack<int> stack;  // unpaired '(' indices

    for (int i = 0; i < s.length(); ++i)
      if (s[i] == '(') {
        stack.push(i);  // Record the unpaired '(' index.
      } else if (s[i] == ')') {
        if (stack.empty())
          s[i] = '*';  // Mark the unpaired ')' as '*'.
        else
          stack.pop();  // Find a pair!
      }

    // Mark the unpaired '(' as '*'.
    while (!stack.empty())
      s[stack.top()] = '*', stack.pop();

    s.erase(remove(s.begin(), s.end(), '*'), s.end());
    return s;
  }
};
