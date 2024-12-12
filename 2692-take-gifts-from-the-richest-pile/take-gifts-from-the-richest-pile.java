class Solution {
    public long pickGifts(int[] gifts, int k) {
        int n=gifts.length;
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>((a,b) -> b-a);

        for(int ele: gifts){
            pq.offer(ele);
        }

        while(k-- > 0){
            int top = pq.poll();
            int rem = (int)Math.floor(Math.sqrt(top));
            pq.offer(rem);
        }

        long ans=0;
        while(!pq.isEmpty()){
            ans+=pq.poll();
        }
        return ans;
    }
}