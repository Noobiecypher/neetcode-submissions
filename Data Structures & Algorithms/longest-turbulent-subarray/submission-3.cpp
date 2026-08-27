class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size() <= 1) return arr.size();

        int finCount = 1;
        int count = 1;

        bool flag = true;

        if(arr[1] > arr[0])
            flag = false;
        else if(arr[1] < arr[0])
            flag = true;
        else
            flag = false;

        if(arr[1] != arr[0])
            count = 2;

        finCount = max(finCount, count);

        for(int i = 2; i < arr.size(); i++) {

            if(arr[i] < arr[i-1] && flag == false) {
                count++;
                flag = !flag;
            }

            else if(arr[i] > arr[i-1] && flag == true) {
                count++;
                flag = !flag;
            }

            else {
                if(arr[i] == arr[i-1])
                    count = 1;
                else
                    count = 2;

                if(arr[i] > arr[i-1])
                    flag = false;
                else
                    flag = true;
            }

            finCount = max(finCount, count);
        }

        return finCount;
    }
};