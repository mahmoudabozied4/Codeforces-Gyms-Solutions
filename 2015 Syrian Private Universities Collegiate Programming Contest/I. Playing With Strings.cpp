#include <bits/stdc++.h>

using namespace std;
#define speed ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

void input() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    // freopen("metro.in", "r", stdin);
    // freopen("mex.in", "w", stdout);
#endif
}

void solve() {
    string s;
    cin >> s;
    map<char, int> mp;
    for (auto i: s)mp[i]++;
    string ans = "";
    int c  = 0 ;
    bool flag = true;
    for (auto i: mp) {
        if (i.second % 2) {
            if (flag) {
                flag = false;
                string t((i.second - 1) / 2, i.first);
                //                cout << t << endl;

                ans += t;
                c = i.first;
            } else {
                return void(cout << "impossible\n");
            }
        }else {
            string t((i.second) / 2, i.first);
            ans += t;
            //            cout << t << endl;

        }
    }
    if(c) {
        cout << ans << char(c);
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }else {
        cout << ans;
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
}

int main() {
    speed;
    input();
    int t;
    cin >> t;
    //    t = 1;
    while (t--) {
        solve();
        /*
        ⢸⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⡷⠀⠀
        ⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⠢⣀⠀⠀
        ⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇ Did you get accepted, son?
        ⢸⠀⠀⠀⠀ ⠖⠒⠒⠒⢤⠀⠀⠀⠀⠀⡇⠀⠀
        ⢸⠀⠀⣀⢤⣼⣀⡠⠤⠤⠼⠤⡄⠀⠀⡇⠀
        ⢸⠀⠀⠑⡤⠤⡒⠒⠒⡊⠙⡏⠀⢀⠀⡇⠀
        ⢸⠀⠀⠀⠇⠀⣀⣀⣀⣀⢀⠧⠟⠁⠀⡇
        ⢸⠀⠀⠀⠸⣀⠀⠀⠈⢉⠟⠓⠀⠀⠀⠀
        ⢸⠀⠀⠀⠀⠈⢱⡖⠋⠁⠀⠀⠀⠀⠀⠀⡇
        ⢸⠀⠀⠀⠀⣠⢺⠧⢄⣀⠀⠀⣀⣀⠀⠀⡇
        ⢸⠀⠀⠀⣠⠃⢸⠀⠀⠈⠉⡽⠿⠯⡆
        ⢸⠀⠀⣰⠁⠀⢸⠀⠀⠀⠀⠉⠉⠉⠀⠀⡇
        ⢸⠀⠀⠣⠀⠀⢸⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀
        ⢸⠀⠀⠀⠀⠀⢸⠀⢇⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀
        */
    }
    return 0;
}
