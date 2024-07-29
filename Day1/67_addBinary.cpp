class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int pa = a.size() - 1;
        int pb = b.size() - 1;
        int carry = 0;

        while (pa >= 0 || pb >= 0 || carry) {
            int sum = carry;
            if (pa >= 0) sum += a[pa--] - '0';
            if (pb >= 0) sum += b[pb--] - '0';

            cout<<sum<<endl;

            carry = sum / 2;
            ans = to_string(sum % 2) + ans;
        }

        return ans;
    }
};