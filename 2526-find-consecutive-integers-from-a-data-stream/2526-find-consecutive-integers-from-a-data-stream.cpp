class DataStream {
public:
    int val,z,cnt=0;
    queue<int> q;
    map<int,int> m;
    
    DataStream(int value, int k) {
        val=value;
        z=k;
        
        
    }
    
    bool consec(int num) {
        
      if(num==val)
            cnt++;
        else
            cnt=0;
        
        if(cnt>=z)
            return true;
        else
            return false;
       
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */