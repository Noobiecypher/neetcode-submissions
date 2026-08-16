class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int,double>> v;
        for(int i = 0; i < n; i++){
            double time = (double)(target - position[i]) / speed[i];
            v.push_back({position[i],time});
        }

        sort(v.begin(),v.end());
        stack<double> st;
        for(int i = n-1; i >= 0; i--){
            if(st.empty() || st.top() < v[i].second){
                st.push(v[i].second);
            }
        }
        return st.size();
    }
};
