class Solution {
    public int findLucky(int[] arr) {
        HashMap<Integer, Integer> mp = new HashMap();

        for (int i = 0; i < arr.length; i++) {
            int k = arr[i];
            if (mp.containsKey(k)) {
                mp.put(k, mp.get(k) + 1);
            } else {
                mp.put(k, 1);
            }
        }
        // for (int n : arr) {
        //     mp.put(n, mp.getOrDefault(n, 0) + 1);
        // }
        int ans = -1;
        for (int key : mp.keySet()) {
            // System.out.println(key + " " + mp.get(key));
            if (key == mp.get(key)) {
                ans = key;
            }
        }
        return ans;
    }
}