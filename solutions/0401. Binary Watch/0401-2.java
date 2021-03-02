class Solution {
  public List<String> readBinaryWatch(int num) {
    List<String> ans = new LinkedList<>();

    for (int h = 0; h < 12; ++h)
      for (int m = 0; m < 60; ++m)
        if (Integer.bitCount(h) + Integer.bitCount(m) == num)
          ans.add(h + (m < 10 ? ":0" : ":") + m);

    return ans;
  }
}
