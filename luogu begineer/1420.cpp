#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long> nums(n);
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int max_len = 1; 
    for (int i = 0; i < n; i++) {
        int curr_len = 1; 
        for (int j = i + 1; j < n; j++) {
            if (nums[j] == nums[j - 1] + 1) {
                curr_len++;
            } else {
                break;
            }
        }
        max_len = max(max_len, curr_len);
    }

    cout << max_len << endl;

    return 0;
}
