class Solution {
   public:
    string fractionAddition(string expression) {
        istringstream istr(expression);
        char c;
        int ret1 = 0, ret2 = 1, nxt1, nxt2;
        while (istr >> nxt1 >> c >> nxt2) {
            //cout<<"nxt1:"<<nxt1<<"c:"<<c<<"nxt2:"<<nxt2<<endl;
            int t = __gcd(ret2, nxt2);
            ret1 = ret1 * (nxt2 / t) + nxt1 * (ret2 / t);
            ret2 = ret2 / t * nxt2;
            t = abs(__gcd(ret1, ret2));
            ret1 /= t;
            ret2 /= t;
        }
        stringstream sstr;
        sstr << ret1 << '/' << ret2;
        return sstr.str();
    }
};