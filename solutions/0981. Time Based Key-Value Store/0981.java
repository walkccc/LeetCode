class TimeMap {
  public void set(String key, String value, int timestamp) {
    if (!map.containsKey(key))
      map.put(key, new TreeMap<>());
    map.get(key).put(timestamp, value);
  }

  public String get(String key, int timestamp) {
    Integer floorKey = map.get(key).floorKey(timestamp);
    return floorKey == null ? "" : map.get(key).get(floorKey);
  }

  private Map<String, TreeMap<Integer, String>> map = new HashMap<>();
}
