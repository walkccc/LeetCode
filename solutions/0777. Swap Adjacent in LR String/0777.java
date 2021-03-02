class Solution {
  public boolean canTransform(String start, String end) {
    if (!start.replace("X", "").equals(end.replace("X", "")))
      return false;

    int i = 0; // start's index
    int j = 0; // end's index

    while (i < start.length() && j < end.length()) {
      while (i < start.length() && start.charAt(i) == 'X')
        ++i;
      while (j < end.length() && end.charAt(j) == 'X')
        ++j;
      if (i == start.length() && j == end.length())
        return true;
      if (i == start.length() || j == end.length())
        return false;
      if (start.charAt(i) == 'L' && i < j)
        return false;
      if (start.charAt(i) == 'R' && i > j)
        return false;
      ++i;
      ++j;
    }

    return true;
  }
}
