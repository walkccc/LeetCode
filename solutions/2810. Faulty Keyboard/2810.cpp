class Solution {
 public:
  string finalString(string s) {
    deque<char> dq;
    bool inversed = false;

    for (const char c : s)
      if (c == 'i')
        inversed = !inversed;
      else if (inversed)
        dq.push_front(c);
      else
        dq.push_back(c);

    return inversed ? string{dq.rbegin(), dq.rend()}
                    : string{dq.begin(), dq.end()};
  }
};
