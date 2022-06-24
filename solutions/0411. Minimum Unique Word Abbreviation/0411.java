class Solution {
  public String minAbbreviation(String target, String[] dictionary) {
    final int m = target.length();
    List<Integer> masks = new ArrayList<>();

    for (final String word : dictionary) {
      if (word.length() != m)
        continue;
      masks.add(getMask(target, word));
    }

    if (masks.isEmpty())
      return String.valueOf(m);

    List<String> abbrs = new ArrayList<>();

    final int maxCand = (int) Math.pow(2, m);
    // for all candidate representation of target
    for (int i = 0; i < maxCand; ++i) {
      final int cand = i;
      // all masks have at lease one bit different from candidate
      if (masks.stream().allMatch(mask -> (cand & mask) > 0))
        abbrs.add(getAbbr(target, cand));
    }

    String ans = target;

    for (final String abbr : abbrs)
      if (getAbbrLen(abbr) < getAbbrLen(ans))
        ans = abbr;

    return ans;
  }

  private int getMask(final String target, final String word) {
    final int m = target.length();
    // mask[i] = 0 := target[i] == word[i]
    // mask[i] = 1 := target[i] != word[i]
    // e.g. target = "apple"
    //        word = "blade"
    //        mask =  11110
    int mask = 0;
    for (int i = 0; i < m; ++i)
      if (word.charAt(i) != target.charAt(i))
        mask |= 1 << m - 1 - i;
    return mask;
  }

  String getAbbr(final String target, int cand) {
    final int m = target.length();
    StringBuilder sb = new StringBuilder();
    int replacedCount = 0;
    for (int i = 0; i < m; ++i)
      if ((cand >> m - 1 - i & 1) == 1) {
        // cand[i] = 1, abbr should show the original character
        if (replacedCount > 0)
          sb.append(replacedCount);
        sb.append(target.charAt(i));
        replacedCount = 0;
      } else {
        // cand[i] = 0, abbr can be replaced
        ++replacedCount;
      }
    if (replacedCount > 0)
      sb.append(replacedCount);
    return sb.toString();
  }

  int getAbbrLen(final String abbr) {
    int abbrLen = 0;
    int i = 0;
    int j = 0;
    while (i < abbr.length()) {
      if (Character.isAlphabetic(abbr.charAt(j)))
        ++j;
      else
        while (j < abbr.length() && Character.isDigit(abbr.charAt(j)))
          ++j;
      ++abbrLen;
      i = j;
    }
    return abbrLen;
  }
}
