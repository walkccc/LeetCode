class Solution {
    public int minimumDeviation(int[] nums) {
        int mn=Integer.MAX_VALUE;
        int mx=Integer.MIN_VALUE;

        PriorityQueue<Integer> mxHeap = new PriorityQueue<>((e1,e2)->(e2-e1));
        for(int i=0;i<nums.length;i++){
            if(nums[i]%2==1){
                nums[i] = nums[i]*2;
            }
            mn = mn>nums[i]?nums[i]:mn;
            mx = mx<nums[i]?nums[i]:mx;

            mxHeap.add(nums[i]);
        }

        int mnDiff = mx-mn;

        while(mxHeap.peek()%2==0){
            int top = mxHeap.poll();
            top/=2;
            mxHeap.add(top);
            mn = mn>top?top:mn;
            mx = mxHeap.peek();
            mnDiff = mnDiff<=mx-mn?mnDiff:mx-mn;

        }
        return mnDiff;
        
    }
}