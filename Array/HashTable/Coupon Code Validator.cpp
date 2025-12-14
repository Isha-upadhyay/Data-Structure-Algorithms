class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        
        // businessLine priority
        unordered_map<string, int> order = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        vector<pair<int, string>> validCoupons;

        // regex for valid code
        regex validCode("^[a-zA-Z0-9_]+$");

        for (int i = 0; i < code.size(); i++) {

            // check active
            if (!isActive[i]) continue;

            // check businessLine
            if (order.find(businessLine[i]) == order.end()) continue;

            // check code
            if (code[i].empty() || !regex_match(code[i], validCode)) continue;

            // valid coupon
            validCoupons.push_back({order[businessLine[i]], code[i]});
        }

        // sort as per rules
        sort(validCoupons.begin(), validCoupons.end(),
            [](auto &a, auto &b) {
                if (a.first != b.first)
                    return a.first < b.first;  // businessLine order
                return a.second < b.second;   // lexicographical code
            });

        // extract only codes
        vector<string> result;
        for (auto &p : validCoupons) {
            result.push_back(p.second);
        }

        return result;
    }
};
