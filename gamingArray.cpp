#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::string gamingArray(std::vector<int>& arr) {
    int maxval = 0;
    std::unordered_map<int, int> maxarr;
    std::unordered_map<int, int> newarr;
    for (int i = 0; i < arr.size(); i++) {
        maxval = std::max(arr[i], maxval);
        maxarr[i] = maxval;
        newarr[arr[i]] = i;
    }
    bool bobwin = false;
    int index = arr.size() - 1;
    while (index >= 0) {
        maxval = maxarr[index];
        index = newarr[maxval] - 1;
        bobwin = !bobwin;
    }
    return bobwin ? "BOB" : "ANDY";
}

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        std::vector<int> arr(n);
        for (int j = 0; j < n; j++) {
            std::cin >> arr[j];
        }
        std::cout << gamingArray(arr) << std::endl;
    }
    return 0;
}
