class Solution {
public:
    long long lastInteger(long long n) {

        long long head = 1;
        long long step = 1;
        long long rem = n;


        long long tovar = n;
        
        bool left = true;

        while(rem>1)
            {
                if(!left)
                {
                    if(rem%2==0) head+=step;
                }

                rem=(rem+1)/2;
                step *= 2;
                left = !left;
            }

        return head;
    }
};
