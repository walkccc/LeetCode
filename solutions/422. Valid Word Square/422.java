class Solution {
  public boolean validWordSquare(List<String> words) {
    for (int i = 0; i < words.size(); ++i)
      for (int j = 0; j < words.get(i).length(); ++j) {
        if (words.size() <= j || words.get(j).length() <= i) // out-of-bounds
          return false;
        if (words.get(i).charAt(j) != words.get(j).charAt(i))
          return false;
      }
    return true;
  }
}
