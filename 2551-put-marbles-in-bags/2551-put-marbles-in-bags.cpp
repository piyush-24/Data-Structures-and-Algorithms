class Solution {
public:
    long long putMarbles(vector<int>& A, int k) {
        long long sum = 0, sum1=0, n  = A.size() ;
        priority_queue<int> pq1,pq2;   
        
        for (int i = 0; i < n-1; ++i)
        {
            pq1.push(A[i]+A[i+1]);
            pq2.push(-1*(A[i]+A[i+1]));
            
            
        }
        
        sum=A[0] + A[n-1];
        sum1=A[0] + A[n-1];
        
        int z=k;
        
        while(k>1)
        {
            cout<<pq1.top()<<" "<<pq2.top()<<endl;
            sum+=pq1.top();
            pq1.pop();
            
           
            k--;
        }
        
        while(z>1)
        {
             sum1+=(-1*pq2.top());
             pq2.pop();
            z--;
        }
        return (sum - sum1);
    }
};