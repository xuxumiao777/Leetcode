class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> hashmap;
        int m=n;
        while(m!=1){
            hashmap.insert(m);
            int sum=0;
            while(m!=0){
                sum+=pow(m%10,2);
                m=m/10;
            }
            m=sum;
            if(hashmap.count(m)){
                return false;

            }

        }
        return true;

    }
};