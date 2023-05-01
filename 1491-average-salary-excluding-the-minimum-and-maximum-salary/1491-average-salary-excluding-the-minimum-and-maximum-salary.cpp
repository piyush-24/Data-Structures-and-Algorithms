class Solution {
public:
    double average(vector<int>& salary) {
        int n=salary.size();
        sort(salary.begin(), salary.end());
        double s=0;
        for(int i=1;i<n-1;i++)
        {
            cout<<salary[i]<<" ";
            s+=(salary[i]);
        }
        
        return (s/(n-2));
    }
};