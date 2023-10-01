class Solution {
    public int minOperations(int[] nums) {
        int min_operation = 0;
        Map<Integer, Integer> map = new HashMap<>();
        for(int i = 0; i < nums.length; i++){
            if(map.containsKey(nums[i])){
                map.put(nums[i], map.get(nums[i]) + 1);
            }
            else { map.put(nums[i], 1); }
        }
        for(Integer value : map.values()){
            if(value == 1){
                return -1;
            }
            min_operation += value / 3;
            if(value % 3 != 0){
                min_operation++;
            }
        }
        return min_operation;
    }
}
