#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0;
    if(n==1){
        ans += s[0] - '0';
        cout << ans << "\n"; 
        return;
    }
    if(n==2){
        ans = (s[0] - '0')*10 + s[1] - '0';
        if(ans==10 && 1 <= k) ans = 1;
        cout << ans << "\n";
        return;
    }
    int f_1 = -1; // first occrence of 1
    int l_1 = -1; // last occurence of 1
    
    for(int i=1;i<n-1;i++){
        if(s[i]=='1'){
            if(f_1 == -1) f_1 = i;
            l_1 = i;
            ans += 11;
        }
    }
    if(f_1==-1){
	    if(s[0]=='1' && s[n-1]=='1') ans = 11;
	    else if(s[0]=='1') {
	    	if(n-1 <= k) ans = 1;
	    	else ans = 10;
	    }
	    else if(s[n-1]=='1') ans = 1;
        cout << ans << "\n";
        return;
    }
    // assert n > 2;
    if(s[0]=='1' && s[n-1]=='1') ans += 11;
    else if(s[0]=='1'){
        if(n-1 - l_1 <= k) ans -= 10;
        ans += 10;
    }
    else if(s[n-1]=='1'){
        if(f_1 <= k) ans -= 1;
        ans += 1;
    } else {
        if(f_1 == l_1){
            if(n-1 - l_1 <= k) ans -= 10;
            else if(f_1 <= k) ans -= 1;
        } else {
            if(n-1 - l_1 <= k){
            	ans -= 10;
            	k -= n-1 - l_1;
            }
            if(f_1 <= k) ans -= 1;
        }
    }
    cout << ans << "\n";
}

int main(){
    int n;
    cin >> n;
    while(n--){
        solve();
    }
    return 0;
}
