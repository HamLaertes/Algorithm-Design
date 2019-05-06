#include <iostream>
#include <stdlib.h>

using namespace std;

class Solution
{
    public:
        string add(string a, string b);
        string shift(string a, int n);
        string mul(string a, string b);
};

string Solution::shift(string a, int n){
    string result=a;
    for(int i=0; i<n; i++){
        result.insert(result.end(), '0');
    }
    return result;
}

string Solution::add(string a, string b){
    string result;
    int x, y, r, c=0;
    while(!a.empty()){
        x=a.back()-'0';
        a.pop_back();
        if(b.empty()) y=0;
        else{
            y=b.back()-'0';
            b.pop_back();
        }
        r=x+y+c;
        if(r>=10) {c=1; r-=10;}
        else c=0;
        result.insert(result.begin(), r+'0');
    }
    while(!b.empty()){
        x=0;
        y=b.back()-'0';
        b.pop_back();
        r=x+y+c;
        if(r>=10) {c=1; r-=10;}
        else c=0;
        result.insert(result.begin(), r+'0');
    }
    if(c==1){result.insert(result.begin(), '1');}
    //cout << result << " ";
    return result;
}

string Solution::mul(string a, string b){
    if(a.length()==1&&a.front()=='1') return b;
    if(b.length()==1&&b.front()=='1') return a;
    if(a.length()==1) {
        string result;
        int c=0, r;
        int x=a[0]-'0';
        int y;
        while(b.length()!=0){
            y=b.back()-'0';
            b.pop_back();
            r=x*y+c;
            if(r>10) {c=r/10; result.insert(result.begin(), r%10+'0');}
            else {c=0; result.insert(result.begin(), r+'0');}
        }
        if(c!=0) result.insert(result.begin(), c+'0');
        return result;
    }
    if(b.length()==1) {
        string result;
        int c=0, r;
        int y=b[0]-'0';
        int x;
        while(a.length()!=0){
            x=a.back()-'0';
            a.pop_back();
            r=x*y+c;
            if(r>10) {c=r/10; result.insert(result.begin(), r%10+'0');}
            else {c=0; result.insert(result.begin(), r+'0');}
        }
        if(c!=0) result.insert(result.begin(), c+'0');
        return result;
    }
    string result;
    string a1, a2, b1, b2;
    int n1=a.length()/2;
    int n2=b.length()/2;
    for(int i=0; i<n1; i++) a1.insert(a1.end(), a[i]);
    for(int i=n1; i<a.length(); i++) a2.insert(a2.end(), a[i]);
    for(int i=0; i<n2; i++) b1.insert(b1.end(), b[i]);
    for(int i=n2; i<b.length(); i++) b2.insert(b2.end(), b[i]);
    string ac=mul(a1, b1);
    string bd=mul(a2, b2);
    string ad=mul(a1, b2);
    string bc=mul(a2, b1);
	ac=shift(ac, a.length()+b.length()-n1-n2); 
    ad=shift(ad, a.length()-n1);
    bc=shift(bc, b.length()-n2);
    result=add(result, bd);
    result=add(result, bc);
    result=add(result, ac);
    result=add(result, ad);
    return result;
}

int main(){
    string a, b;
    cin >> a >> b;
    Solution st;
    string result=st.mul(a, b);
    cout << result << endl;
    system("pause");
}