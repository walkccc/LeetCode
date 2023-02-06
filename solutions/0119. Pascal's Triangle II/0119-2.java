class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> prev = new ArrayList();
        for(int i=0; i< rowIndex + 1 ; i++){
            List<Integer> temp = new ArrayList(); 
            for(int j=0; j<=i; j++){
                if(j==0 || j==i){
                    temp.add(1);
                }
                else{
                    temp.add(prev.get(j) + prev.get(j-1));
                }
            }
            prev = temp;
        }
        return prev;
    }
}
