class Solution {
  public List<String> invalidTransactions(String[] transactions) {
    List<String> ans = new ArrayList<>();
    Map<String, List<Trans>> nameToTrans = new HashMap<>();

    for (final String t : transactions) {
      Trans trans = getTrans(t);
      nameToTrans.putIfAbsent(trans.name, new ArrayList<>());
      nameToTrans.get(trans.name).add(trans);
    }

    for (final String t : transactions) {
      Trans currTrans = getTrans(t);
      if (currTrans.amount > 1000) {
        ans.add(t);
      } else if (nameToTrans.containsKey(currTrans.name)) {
        // Iterate through all the transactions with the same name, check if
        // they're within 60 minutes in a different city.
        for (Trans trans : nameToTrans.get(currTrans.name))
          if (Math.abs(trans.time - currTrans.time) <= 60 && !trans.city.equals(currTrans.city)) {
            ans.add(t);
            break;
          }
      }
    }

    return ans;
  }

  private record Trans(String name, int time, int amount, String city) {}

  private Trans getTrans(final String t) {
    String[] s = t.split(","); // [name, time, amount, city]
    return new Trans(s[0], Integer.parseInt(s[1]), Integer.parseInt(s[2]), s[3]);
  }
}
