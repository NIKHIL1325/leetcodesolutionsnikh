class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
     stack<int> st;
     unordered_map<int,int> nge;
      vector<int> ans;
        for(int i =nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top() < nums2[i] ){
                st.pop();
            }
            int current = nums2[i];
       nge[current] = st.empty() ? -1 : st.top();
         
         st.push(nums2[i]);

        }
        for(int nums : nums1){
         ans.push_back(nge[nums]);
        }
        return ans;
    }
};