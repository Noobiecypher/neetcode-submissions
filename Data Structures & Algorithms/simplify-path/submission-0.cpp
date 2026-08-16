class Solution {
   public:
    string simplifyPath(string path) {
        string s;
        stringstream ss(path);
        stack<string> st;
        while (getline(ss, s, '/')) {
            if (s == "." || s == "") continue;
            if (s == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(s);
            }
        }

        string ans;
        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        if (ans == "") return "/";
        return ans;
    }
};