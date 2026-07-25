class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        vector<int> ans(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++){
            int t = temperatures[i];
            while(!st.empty() && t > st.top().first){
                auto pair = st.top();
                st.pop();
                ans[pair.second] = i - pair.second;
            }
            st.push({t,i});
        }
        return ans;
    }
};
