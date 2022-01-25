class Solution {
public:
    bool validMountainArray(vector<int>& arr) 
    {
        bool mt=false;
        if(arr.size()<3)
            return false;
            
        int mark=-1;
        for(int i=1;i<arr.size()-1;i++)
        {
            if(arr[i]==arr[i-1])
                return false;
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
               mark=i;
        }
        
        if(mark==-1)
            return false;
        
        for(int i=1;i<=mark;i++)
        {
            if(arr[i-1]>=arr[i])
                return false;
        }
        for(int i=mark+1;i<arr.size();i++)
        {
            if(arr[i-1]<=arr[i])
                return false;
        }
        
        return true;
    }
};