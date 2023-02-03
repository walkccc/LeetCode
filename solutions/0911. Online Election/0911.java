class TopVotedCandidate {
  public TopVotedCandidate(int[] persons, int[] times) {
    this.times = times;
    int lead = -1;
    Map<Integer, Integer> count = new HashMap<>(); // {person: voted}

    for (int i = 0; i < persons.length; ++i) {
      count.merge(persons[i], 1, Integer::sum);
      if (count.get(persons[i]) >= count.getOrDefault(lead, 0))
        lead = persons[i];
      timeToLead.put(times[i], lead);
    }
  }

  public int q(int t) {
    final int i = Arrays.binarySearch(times, t);
    return i < 0 ? timeToLead.get(times[-i - 2]) : timeToLead.get(times[i]);
  }

  private final int[] times;
  private Map<Integer, Integer> timeToLead = new HashMap<>();
}
