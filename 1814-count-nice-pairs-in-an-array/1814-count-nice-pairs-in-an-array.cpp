class Solution {
public:
    int rev(int n)
    {
        int revNum = 0;
        while(n) 
            revNum = revNum * 10 + (n % 10), n /= 10;
        
        return revNum;
}
    int countNicePairs(vector<int>& nums) 
    {
        long count = 0;
	unordered_map<int, long> mp;
        
	for(auto& num : nums) 
        mp[num - rev(num)]++;   
        
	for(auto& pair : mp)  
    {
        count+=((pair.second*(pair.second-1))/2); 
        count=count%1000000007;
    }
		
	
	return count;
    }
};