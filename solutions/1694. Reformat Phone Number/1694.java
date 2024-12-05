class Solution {
  public String reformatNumber(String number) {
    StringBuilder sb = new StringBuilder();

    number = number.replaceAll("[-\\s]", "");

    int i = 0; // number's index
    for (i = 0; i + 4 < number.length(); i += 3)
      sb.append(number.substring(i, i + 3) + '-');

    final int countFinalDigits = number.length() - i;
    if (countFinalDigits < 4)
      sb.append(number.substring(i));
    else // countFinalDigits == 4
      sb.append(number.substring(i, i + 2) + '-' + number.substring(i + 2));

    return sb.toString();
  }
}
