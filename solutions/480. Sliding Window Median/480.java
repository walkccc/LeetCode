class Solution {
    class DualHeap {
        TreeMap<Integer, Integer> small = new TreeMap<>(Collections.reverseOrder()); 
        TreeMap<Integer, Integer> large = new TreeMap<>(); 
        int k;
        int smallSize = 0, largeSize = 0;

        public DualHeap(int k) {
            this.k = k;
        }

        public void insert(int num) {
            if (small.isEmpty() || num <= small.firstKey()) {
                small.put(num, small.getOrDefault(num, 0) + 1);
                smallSize++;
            } else {
                large.put(num, large.getOrDefault(num, 0) + 1);
                largeSize++;
            }
            balance();
        }

        public void erase(int num) {
            if (small.containsKey(num)) {
                small.put(num, small.get(num) - 1);
                if (small.get(num) == 0) small.remove(num);
                smallSize--;
            } else {
                large.put(num, large.get(num) - 1);
                if (large.get(num) == 0) large.remove(num);
                largeSize--;
            }
            balance();
        }

        private void balance() {
        
            if (smallSize > largeSize + 1) {
                int move = small.firstKey();
                small.put(move, small.get(move) - 1);
                if (small.get(move) == 0) small.remove(move);
                smallSize--;

                large.put(move, large.getOrDefault(move, 0) + 1);
                largeSize++;
            } else if (largeSize > smallSize) {
                int move = large.firstKey();
                large.put(move, large.get(move) - 1);
                if (large.get(move) == 0) large.remove(move);
                largeSize--;

                small.put(move, small.getOrDefault(move, 0) + 1);
                smallSize++;
            }
        }

        public double getMedian() {
            if (k % 2 == 1) {
                return small.firstKey();
            } else {
                return ((long) small.firstKey() + (long) large.firstKey()) / 2.0;
            }
        }
    }

    public double[] medianSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        double[] result = new double[n - k + 1];

        DualHeap dh = new DualHeap(k);
        for (int i = 0; i < k; i++) {
            dh.insert(nums[i]);
        }
        result[0] = dh.getMedian();

        for (int i = k; i < n; i++) {
            dh.insert(nums[i]);
            dh.erase(nums[i - k]);
            result[i - k + 1] = dh.getMedian();
        }

        return result;
    }
}
