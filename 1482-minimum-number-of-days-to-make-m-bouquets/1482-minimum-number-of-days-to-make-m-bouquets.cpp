class Solution {
public:

 int possible(vector<int>& nums, int days,int m, int k){
    int cut =0 ;
    int noof = 0;
    for(int i =0;i<nums.size();i++){
        if(nums[i]<= days){
            cut++;
        }else{
            noof += (cut/k);
            cut = 0;
        }
    }
    noof += (cut/k);
    if(noof >= m){
        return true;
    }
return false;
 }
    int minDays(vector<int>& nums, int m, int k) {
        int  mini;
        int maxi;
          for (int i =0 ;i<nums.size();i++){
            maxi = max(maxi,nums[i]);
           mini = min(mini,nums[i]);
        } 
            int low = mini;
        int high = maxi;
int ans = -1;
        while(low<=high){
            int mid = low + (high - low )/2;

            if(possible(nums,mid,m,k)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }

        }
        return ans;
        
        
    }
};