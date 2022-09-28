class Trans {
  public String name;
  public int time;
  public int amount;
  public String city;
  public Trans(String name, int time, int amount, String city) {
    this.name = name;
    this.time = time;
    this.amount = amount;
    this.city = city;
  }
}

class Solution {
  public List<String> invalidTransactions(String[] transactions) {
    List<String> ans = new ArrayList<>();
    Map<String, List<Trans>> nameToTranses = new HashMap<>();

    for (final String t : transactions) {
      Trans trans = getTrans(t);
      nameToTranses.putIfAbsent(trans.name, new ArrayList<>());
      nameToTranses.get(trans.name).add(trans);
    }

    for (final String t : transactions) {
      Trans currTrans = getTrans(t);
      if (currTrans.amount > 1000) {
        ans.add(t);
      } else if (nameToTranses.containsKey(currTrans.name)) {
        // iterate through all transactions w/ the same name,
        // check if within 60 minutes in a different city
        for (Trans trans : nameToTranses.get(currTrans.name))
          if (Math.abs(trans.time - currTrans.time) <= 60 && !trans.city.equals(currTrans.city)) {
            ans.add(t);
            break;
          }
      }
    }

    return ans;
  }

  private Trans getTrans(final String t) {
    String[] s = t.split(","); // [name, time, amount, city]
    return new Trans(s[0], Integer.parseInt(s[1]), Integer.parseInt(s[2]), s[3]);
  }
}
