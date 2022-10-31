class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewelset;
        int result=0;
        for(auto jewel:jewels){
            jewelset.insert(jewel);
        }
        for(auto stone:stones){
            if(jewelset.count(stone)>0){
                result++;
            }
        }
        return result;



    }
};