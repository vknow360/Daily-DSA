class Solution {
    public: string addStrings(string num1, string num2) {
        string result = "";
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';
            result.push_back((sum % 10) + '0');
            carry = sum / 10;
        }

        reverse(result.begin(), result.end());

        int pos = 0;
        while (pos < result.size() - 1 && result[pos] == '0') pos++;
        result = result.substr(pos);

        return result;
    }
    string minSum(vector<int> & arr) {
        // code here
        sort(arr.begin(), arr.end());
        string n1, n2;
        for (int i = 0; i < arr.size(); i++) {
            if (i % 2 != 0) {
                n2.push_back('0' + arr[i]);
            } else {
                n1.push_back('0' + arr[i]);
            }
        }

        return addStrings(n1, n2);
    }
};