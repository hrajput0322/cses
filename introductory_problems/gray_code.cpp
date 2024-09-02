#include <bits/stdc++.h>
using namespace std;

vector<string> generateGrayCode(int n) {
    // Base case for n = 1
    if (n == 1) {
        return {"0", "1"};
    }

    // Recursive case for generating Gray code for length n
    vector<string> prevGrayCode = generateGrayCode(n - 1);
    vector<string> result;

    // Add '0' to the first half
    for (string code : prevGrayCode) {
        result.push_back("0" + code);
    }

    // Add '1' to the second half (in reverse order)
    for (int i = prevGrayCode.size() - 1; i >= 0; i--) {
        result.push_back("1" + prevGrayCode[i]);
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<string> grayCode = generateGrayCode(n);

    // Print the Gray code
    for (string code : grayCode) {
        cout << code << endl;
    }

    return 0;
}
