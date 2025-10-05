#include <iostream>

using namespace std;

void up_Star(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout << "*";
        }
        cout << "\n";
    }
}

void down_start(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout << "*";
        }
        cout << "\n";
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        up_Star(n/2);
        for(int i=0;i<(n+1)/2;i++){
            char c = 'A' + i;
            cout << c;
        }
        cout << "\n";
        down_start(n/2);
        cout << "\n";
    }
    return 0;
}