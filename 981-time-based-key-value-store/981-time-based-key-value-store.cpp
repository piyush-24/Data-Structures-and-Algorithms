class TimeMap 
{
    unordered_map<string,vector<pair<int, string>> > mp;
public:
    TimeMap() 
    {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) 
    {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) 
    {
        vector <pair<int, string>> &v = mp[key];
        int low = 0, high = size(v) - 1, res = -1;
        
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            
            if (v[mid].first > timestamp) 
                high = mid - 1;
            else 
                res = mid, low = mid + 1;
        }
        return res== -1 ? "" : v[res].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */