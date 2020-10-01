class Solution {
  public List<String> invalidTransactions(String[] transactions) {
    Set<String> ans = new HashSet<>();
    Map<String, List<String[]>> nameToTransactions = new HashMap<>();

    for (final String transaction : transactions) {
      String[] token = transaction.split(",");
      if (Integer.valueOf(token[2]) > 1000)
        ans.add(transaction);
      if (nameToTransactions.containsKey(token[0]))
        for (final String[] val : nameToTransactions.get(token[0]))
          if (Math.abs(Integer.valueOf(val[1]) - Integer.valueOf(token[1])) <= 60 && !val[3].equals(token[3])) {
            ans.add(transaction);
            ans.add(val[0] + "," + val[1] + "," + val[2] + "," + val[3]);
          }
      nameToTransactions.computeIfAbsent(token[0], k -> new ArrayList<>())
          .add(new String[] { token[0], token[1], token[2], token[3] });
    }

    return new ArrayList<>(ans);
  }
}