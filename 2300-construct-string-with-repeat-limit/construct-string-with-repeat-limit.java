class Solution {
    public String repeatLimitedString(String s, int repeatLimit) {
        int[] freq = new int[26];
        for(char ch: s.toCharArray()){
            freq[ch - 'a']++;
        }

        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) -> b[0]-a[0]);
        for(int i=0; i<26; i++){
            if(freq[i] > 0){
                pq.offer(new int[] {i+'a' , freq[i]});
            }
        }

        StringBuilder res = new StringBuilder();
        while(!pq.isEmpty()){
            int[] curr = pq.poll();
            char ch = (char)curr[0];
            int count = curr[1];

            int used = Math.min(repeatLimit,count);
            for(int i=0;i<used;i++){
                res.append(ch);
            }
            count -= used;

            if(count > 0){
                if(pq.isEmpty())
                    break;
                
                int[] next = pq.poll();
                res.append((char)next[0]);
                next[1]--;

                if(next[1] > 0){
                    pq.offer(next);
                }
                pq.offer(new int[] {ch,count});
            }
        }
        return res.toString();
    }
}