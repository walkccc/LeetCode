class Solution {
  public int numSpecialEquivGroups(String[] A) {
    Set<String> set = new HashSet<>();

    for (final String s : A) {
      String even = "";
      String odd = "";
      for (int i = 0; i < s.length(); ++i)
        if (i % 2 == 0)
          even += s.charAt(i);
        else
          odd += s.charAt(i);
      char[] evenCharArray = even.toCharArray();
      char[] oddCharArray = odd.toCharArray();
      Arrays.sort(evenCharArray);
      Arrays.sort(oddCharArray);
      set.add(new String(evenCharArray) + new String(oddCharArray));
    }

    return set.size();
  }
}
