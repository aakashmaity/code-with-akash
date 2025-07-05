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
        int ans=-1;
        for(int key : mp.keySet()){
            if(key == mp.get(key) && key > ans){
                ans = key;
            }
        }
        return ans;
    }
}