// https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/flip-columns/problem
// https://www.youtube.com/watch?v=Kc43BLd3JJM&ab_channel=AnuragCodes

#include<iostream>
#include<algorithm>
#include<map>
#include<climits>
using namespace std;

int main() {
    int n, m, k, zero, count;
    char ch;
    int i, j;
    string key;
    map<string, int> mp;
    char arr[100][100];
    cin>> n >> m >> k;

    for (i = 0; i < n; i++) {
        key = "";
        for (j = 0; j < m; j++) {
            cin>> ch;
            key += ch;
        }
        if (mp.find(key) == mp.end()) {
            mp[key] = 1;
        } else {
            mp[key] += 1;
        }
    }

    map<string, int>::iterator it;
    int mx = 0;
    for (it = mp.begin(); it != mp.end(); it++) {
        key = it->first;
        count = it->second;

        zero = 0;
        for (i = 0; i < m; i++) {
            if (key[i] == '0')
                zero++;
        }

        if (zero > k)
            continue;
        else {
            if ((k-zero) % 2 == 0)
                mx = max(mx, count);
        }
    }
    cout<< mx << "\n";

    return 0;
}
