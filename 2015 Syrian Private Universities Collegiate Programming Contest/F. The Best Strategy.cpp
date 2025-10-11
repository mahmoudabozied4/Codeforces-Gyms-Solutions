#include <bits/stdc++.h>
// علمكم الله ما ينفعكم و نفعكم بما تعلمتم و زادكم علما
// وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ، وَأَنَّ سَعْيَهُ سَوْفَ يُرَىٰ
using namespace std;
#define IO(NAME) \
cin.tie(0)->sync_with_stdio(0); \
if(fopen(NAME ".in","r")) freopen(NAME ".in","r",stdin), \
freopen(NAME ".out","w",stdout);

void Zied() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}

void preprocessing() {
}

#define int long long


void Solve() {
    int n;
    cin >> n;
    vector<int> v(n);for (auto &it : v) cin >> it ;

    sort(v.begin(), v.end());

    int cont = 0, ans = 0;
    int num = 0;
    for (int i = 0; i < n; i++) {
        if (ans + v[i] <=300) {
            num++;
            ans += v[i];
            cont += ans;
        } else break;
    }
    cout << num << " " << cont << endl;
}

int32_t main() {
    Zied();

    preprocessing();
    int test_cases = 1;
    cin >> test_cases;
    for (int tc = 1; tc <= test_cases; tc++) {
        //        cout << "Case #" << tc << ": ";
        Solve();
        //                cout << endl;
    }
    //    Time
}

/*
              ,   .-'"'=;_  ,
              |\.'-~`-.`-`;/|
              \.` '.'~-.` './
              (\`,__=-'__,'/)
           _.-'-.( d\_/b ).-'-._
         /'.-'   ' .---. '   '-.`\
       /'  .' (=    (_)    =) '.  `\
      /'  .',  `-.__.-.__.-'  ,'.  `\
     (     .'.   V       V  ; '.     )
     (    |::  `-,__.-.__,-'  ::|    )
     |   /|`:.               .:'|\   |
     |  / | `:.              :' |`\  |
     | |  (  :.             .:  )  | |
     | |   ( `:.            :' )   | |
     | |    \ :.           .: /    | |
     | |     \`:.         .:'/     | |
     ) (      `\`:.     .:'/'      ) (
     (  `)_     ) `:._.:' (     _(`  )
     \  ' _)  .'           `.  (_ `  /
      \  '_) /   .'"```"'.   \ (_`  /
       `'"`  \  (         )  /  `"'`
   ___   MZ   `.`.       .'.'        ___
 .`   ``"""'''--`_)     (_'--'''"""``   `.
(_(_(___...--'"'`         `'"'--...___)_)_)
*/
