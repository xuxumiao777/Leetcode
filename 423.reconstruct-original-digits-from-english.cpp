class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char,int> hashmap;
        for(auto num:s){
            hashmap[num]++;
        }
        int num[10];
        num[0]=hashmap['z'];
        num[2]=hashmap['w'];
        num[6]=hashmap['x'];
        num[7]=hashmap['s']-num[6];
        num[5]=hashmap['v']-num[7];
        num[4]=hashmap['f']-num[5];
        num[8]=hashmap['g'];
        num[9]=hashmap['i']-num[5]-num[6]-num[8];
        num[1]=hashmap['o']-num[0]-num[2]-num[4];
        num[3]=hashmap['r']-num[4]-num[0];
        string res;

        for(int i=0;i<10;i++){
            while(num[i]--){
                cout<<i<<endl;
                res.append(to_string(i));
            }
        }
        return res;
    }
};