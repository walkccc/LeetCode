class Solution {
    public int beautySum(String s) {
        int beautySum=0;
        for(int i=0;i<s.length();++i){
            int[] count=new int[26];
            for(int j=i;j<s.length();++j){
                ++count[s.charAt(j)-'a'];
                int max=Integer.MIN_VALUE, min=Integer.MAX_VALUE;
                for(int k=0;k<26;++k){
                    if(count[k]!=0){
                        max=Math.max(count[k],max);
                        min=Math.min(count[k],min);
                    }
                }
                beautySum+=max-min;
            }
        }
        return beautySum;
    }
}
