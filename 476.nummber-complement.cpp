class Solution {
    public:
    int findComplement(int num) {
        int s = -1;
        //找到最高位的一，之后按位取反
        for (int i = 31; i >= 0; i--) {
            if (((num >> i) & 1) != 0) {
                s = i;
                break;
            }
        }
        int ans = 0;
        for (int i = 0; i < s; i++) {
			//该位为0，取反为1
            if (((num >> i) & 1) == 0) ans |= (1 << i);
        }
        return ans;
    }
};
