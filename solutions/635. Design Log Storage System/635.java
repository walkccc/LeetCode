class LogSystem {
  public LogSystem() {
    granularityToIndices.put("Year", 4);
    granularityToIndices.put("Month", 7);
    granularityToIndices.put("Day", 10);
    granularityToIndices.put("Hour", 13);
    granularityToIndices.put("Minute", 16);
    granularityToIndices.put("Second", 19);
  }

  public void put(int id, String timestamp) {
    idAndTimestamps.add(new Pair<>(id, timestamp));
  }

  public List<Integer> retrieve(String start, String end, String granularity) {
    List<Integer> ans = new ArrayList<>();
    final int index = granularityToIndices.get(granularity);
    final String s = start.substring(0, index);
    final String e = end.substring(0, index);

    for (Pair<Integer, String> idAndTimestamp : idAndTimestamps) {
      final String timestamp = idAndTimestamp.getValue();
      final String t = timestamp.substring(0, index);
      if (t.compareTo(s) >= 0 && t.compareTo(e) <= 0)
        ans.add(idAndTimestamp.getKey());
    }

    return ans;
  }

  private Map<String, Integer> granularityToIndices = new HashMap<>();
  private List<Pair<Integer, String>> idAndTimestamps = new ArrayList<>();
}
