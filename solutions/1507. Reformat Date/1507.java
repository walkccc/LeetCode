class Solution {
  public String reformatDate(String date) {
    Map<String, String> months = getMonths();
    String[] words = date.split("\\s+");
    final String day =
        (words[0].length() == 4) ? words[0].substring(0, 2) : "0" + words[0].substring(0, 1);
    final String month = months.get(words[1]);
    final String year = words[2];
    return year + "-" + month + "-" + day;
  }

  private Map<String, String> getMonths() {
    Map<String, String> months = new HashMap<>();
    months.put("Jan", "01");
    months.put("Feb", "02");
    months.put("Mar", "03");
    months.put("Apr", "04");
    months.put("May", "05");
    months.put("Jun", "06");
    months.put("Jul", "07");
    months.put("Aug", "08");
    months.put("Sep", "09");
    months.put("Oct", "10");
    months.put("Nov", "11");
    months.put("Dec", "12");
    return months;
  }
}
