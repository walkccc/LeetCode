class Solution {
  public int numSpecialEquivGroups(String[] words) {
    Set<String> set = new HashSet<>();

    for (final String word : words) {
      String even = "";
      String odd = "";
      for (int i = 0; i < word.length(); ++i)
        if (i % 2 == 0)
          even += word.charAt(i);
        else
          odd += word.charAt(i);
      char[] evenCharArray = even.toCharArray();
      char[] oddCharArray = odd.toCharArray();
      Arrays.sort(evenCharArray);
      Arrays.sort(oddCharArray);
      set.add(new String(evenCharArray) + new String(oddCharArray));
    }

    return set.size();
  }
}
