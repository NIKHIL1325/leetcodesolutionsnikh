class Solution {
public:
bool isvalid(vector<int>& nums, int mid,int k){
     int  pages =0;
       int stud =1;
    for(int i =0;i<nums.size();i++){
         if (nums[i] > mid) return false;
      
        if(pages + nums[i]<=mid){
            pages += nums[i];
        }else{
            stud++;
            pages = nums[i];

        }
    }

    if(stud <= k){
        return true;
    }
    return false;
}
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = INT_MIN;
        int sum =0;
        for (int i =0 ;i<n;i++){
            maxi = max(maxi,nums[i]);
            sum +=nums[i];
        }
        int low = maxi;
        int high = sum;
int ans = -1;
        while(low<=high){
            int mid = low + (high - low )/2;

            if(isvalid(nums,mid,k)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }


        }
        return ans;
    }
};