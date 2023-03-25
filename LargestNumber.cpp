#include <iostream>
#include <string>
#include <stack>

using namespace std;

string largestNumber(string num, int k) {
    stack<char> s;
    int n = num.length();
    for (int i = 0; i < n; i++) {
        while (!s.empty() && k > 0 && s.top() < num[i]) {
            s.pop();
            k--;
        }
        s.push(num[i]);
    }
    while (k > 0) {
        s.pop();
        k--;
    }
    string result = "";
    while (!s.empty()) {
        result = s.top() + result;
        s.pop();
    }
    return result;
}

int main() {
    string num;
    int k;
    cin >> num;
    cin >> k;
    string result = largestNumber(num, k);
    cout << result << endl;
    return 0;
}
