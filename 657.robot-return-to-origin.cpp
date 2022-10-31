class Solution {
public:
    //也可以不用hashmap，用两个变量就可以减少内存消耗
    bool judgeCircle(string moves) {
        unordered_map<char,int> hashmap;
        for(auto character:moves){
            hashmap[character]++;
        }
        if(hashmap['U']==hashmap['D']&&hashmap['L']==hashmap['R']){
            return true;
        }
        return false;
    }
};