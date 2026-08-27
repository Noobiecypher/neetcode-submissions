class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();

        if (n <= 1) return n;

        int count = 1;
        int ans = 1;

        // false -> expect <
        // true  -> expect >
        bool flag;

        // Handle the first comparison
        if (arr[1] > arr[0]) {
            count = 2;
            flag = false;
        }
        else if (arr[1] < arr[0]) {
            count = 2;
            flag = true;
        }
        else {
            count = 1;
            flag = false;
        }

        ans = count;

        for (int i = 2; i < n; i++) {

            if (arr[i] < arr[i - 1] && flag == false) {
                count++;
                flag = true;
            }

            else if (arr[i] > arr[i - 1] && flag == true) {
                count++;
                flag = false;
            }

            else {
                // Turbulence breaks
                if (arr[i] == arr[i - 1]) {
                    count = 1;
                }
                else {
                    // Current pair itself is turbulent
                    count = 2;

                    // Set expectation based on current comparison
                    if (arr[i] > arr[i - 1])
                        flag = false;
                    else
                        flag = true;
                }
            }

            ans = max(ans, count);
        }

        return ans;
    }
};