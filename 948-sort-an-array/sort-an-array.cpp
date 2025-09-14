class Solution {
public:
    void merge(vector<int> &nums,int s, int mid,int e){
        int s1 = mid-s+1;
        int s2 = e-mid;

        vector<int> left(s1);
        vector<int> right(s2);
        
        for(int i=0;i<s1;i++){
            left[i] = nums[s+i];
        }
        for(int i=0;i<s2;i++){
            right[i] = nums[mid+1+i];
        }
        
        int i=0,j=0,k=s;
        while(i<s1 && j<s2){
            if(left[i]<=right[j]){
                nums[k++] = left[i++];
            }
            else{
                nums[k++] = right[j++];
            }
        }

        while(i<s1){
            nums[k++]=left[i++];
        }
        while(j<s2){
            nums[k++]=right[j++];
        }
    }
    void mergeSort(vector<int> &nums,int s,int e){
        if(s>=e){
            return;
        }

        int mid = s+(e-s)/2;
        
        //devide
        mergeSort(nums,s,mid);
        mergeSort(nums,mid+1,e);

        //conquer
        merge(nums,s,mid,e);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() < 2){
            return nums;
        }

        mergeSort(nums,0,n-1);
        return nums;
    }
};