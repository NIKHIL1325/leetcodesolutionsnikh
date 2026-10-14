class Solution {
public:
    int missingNumber(vector<int>& nums) {
int n = nums.size();
int found = 0;
        for(int i=0;i<=n;i++){
            for(int j =0;j<n;j++){
                if(i == nums[j] ){
                    found = 1;
                }
            }
            if(found == 0){
                return i;
            }
            found = 0;
        }
      
        return 0;
    }
};