class Solution {
 public:
  string minRemoveToMakeValid(string s) {
    stack<int> stack;  // unpaired '(' indices

    for (int i = 0; i < s.length(); ++i)
      if (s[i] == '(') {
        stack.push(i);  // record unpaired '(' index
      } else if (s[i] == ')') {
        if (stack.empty())
          s[i] = '*';  // mark unpaired ')' as '*'
        else
          stack.pop();  // find a pair!
      }

    // mark unpaired '(' as '*'
    while (!stack.empty())
      s[stack.top()] = '*', stack.pop();

    s.erase(remove(begin(s), end(s), '*'), end(s));
    return s;
  }
};
