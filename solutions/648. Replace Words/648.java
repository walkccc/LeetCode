//Aditya Konda 
class Solution {
    public String replaceWords(List<String> dictionary, String sentence) {
        Set<String> rootSet = new HashSet<>(dictionary);
        String[] words = sentence.split(" ");
        StringBuilder result = new StringBuilder();
        for (String word : words) {
            String prefix = "";
            for (int i = 1; i <= word.length(); i++) {
                prefix = word.substring(0, i);
                if (rootSet.contains(prefix)) {
                    break;
                }
            }
            if (result.length() > 0) {
                result.append(" ");
            }
            result.append(prefix);
        }
        return result.toString();
    }
    public static void main(String[] args) {
        Solution sol = new Solution();
        List<String> dictionary = Arrays.asList("cat", "bat", "rat");
        String sentence = "the cattle was rattled by the battery";
        System.out.println(sol.replaceWords(dictionary, sentence)); 
    }
}
