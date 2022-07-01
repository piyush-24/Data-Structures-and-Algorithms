class Solution
{
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
    {
        int s=0,x=0;
        sort(boxTypes.begin(),boxTypes.end(),
             [](vector<int> &first, vector<int> &second)
             { 
                 return first[1]>second[1]; 
             }
            );
        
        for(int i=0;i<boxTypes.size();i++)
        {
            while(boxTypes[i][0])
            {
                 if(s+1<=truckSize)
                 {
                     s++;
                     x+=boxTypes[i][1];
                 }
                boxTypes[i][0]-=1;
            }       
        }
        return x;
    }
};