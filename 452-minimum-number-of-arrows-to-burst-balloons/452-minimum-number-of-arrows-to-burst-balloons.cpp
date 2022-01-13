class Solution {
public:
   
    int findMinArrowShots(vector<vector<int>>& vect) 
    {
        sort(vect.begin(), vect.end(), [] (auto &p1, auto&p2)
        {
            return p1[1] < p2[1];
        });
        int arrow=1,end=vect[0][1];
        
        for(int i=1;i<vect.size();i++)
        {
            if(vect[i][0]>end)
            {
                 arrow++;
                end=vect[i][1];
            }
            
        }
        return arrow;
    }
};