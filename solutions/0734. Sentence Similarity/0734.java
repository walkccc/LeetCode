class Solution {
  public boolean areSentencesSimilar(String[] sentence1, String[] sentence2,
                                     List<List<String>> similarPairs) {
    if (sentence1.length != sentence2.length)
      return false;

    // map[key] := all similar words of key
    Map<String, Set<String>> map = new HashMap<>();

    for (List<String> pair : similarPairs) {
      map.putIfAbsent(pair.get(0), new HashSet<>());
      map.putIfAbsent(pair.get(1), new HashSet<>());
      map.get(pair.get(1)).add(pair.get(0));
      map.get(pair.get(0)).add(pair.get(1));
    }

    for (int i = 0; i < sentence1.length; ++i) {
      if (sentence1[i].equals(sentence2[i]))
        continue;
      if (!map.containsKey(sentence1[i]))
        return false;
      if (!map.get(sentence1[i]).contains(sentence2[i]))
        return false;
    }

    return true;
  }
}
