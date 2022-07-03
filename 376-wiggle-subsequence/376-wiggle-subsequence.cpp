class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int cc=0;
        int n=nums.size();
        unordered_set<int>set;
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()) st.push(nums[i]);
            else if(st.top()!=nums[i]){
                st.push(nums[i]);
            }
        }
        vector<int>nums1;
        while(!st.empty()){
            nums1.push_back(st.top());
            st.pop();
        }
        // for(int i=0;i<nums1.size();i++) cout<<nums1[i]<<" ";
        
        if(nums1.size()==1) return 1;
        if(n>2){
            for(int i=1;i<nums1.size()-1;i++){
                if( (nums1[i]>nums1[i-1] && nums1[i]>nums1[i+1]) || (nums1[i]<nums1[i-1] && nums1[i]<nums1[i+1]) ){
                    ;
                }
                else cc++;
            }
            return n-cc-(n-nums1.size());
        }
        else if(n==2){
            if(nums1[0]==nums1[1]) return 1;
        }
        return n;
    }
};