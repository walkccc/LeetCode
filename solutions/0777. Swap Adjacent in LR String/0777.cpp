class Solution {
 public:
  bool canTransform(string start, string end) {
    if (removeX(start) != removeX(end))
      return false;

    int i = 0;  // start's index
    int j = 0;  // end's index

    while (i < start.length() && j < end.length()) {
      while (i < start.length() && start[i] == 'X')
        ++i;
      while (j < end.length() && end[j] == 'X')
        ++j;
      if (i == start.length() && j == end.length())
        return true;
      if (i == start.length() || j == end.length())
        return false;
      if (start[i] == 'L' && i < j)
        return false;
      if (start[i] == 'R' && i > j)
        return false;
      ++i;
      ++j;
    }

    return true;
  }

 private:
  string removeX(const string& s) {
    string t = s;
    t.erase(remove(begin(t), end(t), 'X'), end(t));
    return t;
  }
};
