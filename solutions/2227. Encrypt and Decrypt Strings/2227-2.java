class Encrypter {
  public Encrypter(char[] keys, String[] values, String[] dictionary) {
    for (int i = 0; i < keys.length; ++i)
      keyToValue.put(keys[i], values[i]);

    for (final String word : dictionary)
      encryptedCount.merge(encrypt(word), 1, Integer::sum);
  }

  public String encrypt(String word1) {
    StringBuilder sb = new StringBuilder();
    for (final char c : word1.toCharArray())
      sb.append(keyToValue.get(c));
    return sb.toString();
  }

  public int decrypt(String word2) {
    return encryptedCount.getOrDefault(word2, 0);
  }

  private Map<Character, String> keyToValue = new HashMap<>();
  private Map<String, Integer> encryptedCount = new HashMap<>();
}
