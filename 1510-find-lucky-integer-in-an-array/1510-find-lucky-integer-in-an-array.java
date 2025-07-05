class Solution {
    public int findLucky(int[] arr) {
        HashMap<Integer, Integer> mp = new HashMap();

        for (int i = 0; i < arr.length; i++) {
            int k = arr[i];
            mp.put(k, mp.getOrDefault(k, 0) + 1);
        }
        int ans = -1;
        for (int key : mp.keySet()) {
            if (key == mp.get(key) && key > ans) {
                ans = key;
            }
        }
        return ans;
    }
}