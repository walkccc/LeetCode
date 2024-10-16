class Solution {
  public long dividePlayers(int[] skill) {
    final int n = skill.length;
    final int teamSkill = Arrays.stream(skill).sum() / (n / 2);
    long ans = 0;
    Map<Integer, Integer> count = new HashMap<>();

    for (final int s : skill)
      count.merge(s, 1, Integer::sum);

    for (Map.Entry<Integer, Integer> entry : count.entrySet()) {
      final int s = entry.getKey();
      final int freq = entry.getValue();
      final int requiredSkill = teamSkill - s;
      if (count.getOrDefault(requiredSkill, 0) != freq)
        return -1;
      ans += (long) s * requiredSkill * freq;
    }

    return ans / 2;
  }
}
