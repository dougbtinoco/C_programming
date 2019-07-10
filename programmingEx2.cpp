#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int d=0, v=0, u=0, up=0, upPrev=0;
    string::iterator it; 
    
    for(it=s.begin(); it!=s.end(); it++){
        if(*it == 'U'){
            u = u + 1;
            d = d - 1;

        } else if (*it == 'D') {
            u = u - 1;
            d = d + 1;
        }
        if(u > d){
            up = 1;
        }
        else if(u < d){
            up = -1;
        }
        else{
            upPrev = up;
            up = 0;
            if (upPrev < up) {
              v++;
            }
        }
    }
    return(v);
}

int main(){

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    cout << result << "\n";
    return 0;
}
