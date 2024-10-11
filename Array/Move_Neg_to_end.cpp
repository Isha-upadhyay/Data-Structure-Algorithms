
#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    void segregateElements(vector<int>& arr) {
        int n = arr.size();
        if(n == 0 || n==1){
            return;
        }
        vector<int> result(n);
        int posIndex = 0;
        
        
        for(int i =0; i<n;i++){
            if(arr[i] >= 0){
                result[posIndex++] = arr[i];
            }
        }
        
        for(int i =0; i<n;i++){
            if(arr[i] < 0){
                result[posIndex++] = arr[i];
            }
        }
        for (int i = 0; i < n; i++) {
            arr[i] = result[i];
        }
        
    }
};



int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        ob.segregateElements(nums);

        for (int x : nums)
            cout << x << " ";
        cout << endl;
    }
}
