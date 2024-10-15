#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;cin >> str;
    int p1 = str.find(';',0);
    int p2 = str.find(';',p1+1);
    int p3 = str.find(';',p2+1);
    string partA = str.substr(3,p1-3);
    string partB = str.substr(p1+4,p2-p1-4);
    string partC = str.substr(p2+4,p3-p2-4);
    if(partA == "")partA = "0";
    if(partC == "")partC = "0";
    if(partB == "")partB = "0";
    while(partA[0]>57 || partB[0]>57 || partC[0]>57){
        if(partA[0]=='b'){
            if(partB[0]<57)partA = partB;
        }
        if(partA[0]=='c'){
            if(partC[0]<57)partA = partC;
        }
        if(partB[0]=='a'){
            if(partA[0]<57)partB = partA;
        }
        if(partB[0]=='c'){
            if(partC[0]<57)partB = partC;
        }
        if(partC[0]=='b'){
            if(partB[0]<57)partC = partB;
        }
        if(partC[0]=='a'){
            if(partA[0]<57)partC = partA;
        }
    }
    cout << partA << ' ' << partB << ' ' << partC;
    
    return 0;
}