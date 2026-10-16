class Solution {
public:
    int fun(vector<int>& nums, int divi){
        int sum =0;
        for(int i = 0 ; i<nums.size();i++ ){
            sum += (nums[i] + divi - 1) / divi;
            
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
int mini = INT_MAX;
int maxi = INT_MIN;
    for(int i =0 ; i<nums.size();i++){
        mini =min(mini,nums[i]);
        maxi = max(maxi,nums[i]);

    }
    int ans = -1;

    int low = 1;
    int high = maxi;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(fun(nums,mid)<= threshold){
            ans = mid;
            high = mid -1;

        }else{
            low = mid+1;
        }
    }
    return ans;
        
        
    }
};