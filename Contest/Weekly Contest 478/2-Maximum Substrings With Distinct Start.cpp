class Solution {
public:
    int maxDistinct(string s) {
        string velo =s;

        unordered_set<char> st;

        for(char c : velo){
            st.insert(c);
        }
        return st.size();
    }
};
