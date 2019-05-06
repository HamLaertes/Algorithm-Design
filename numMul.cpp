#include <iostream>
#include <stdlib.h>

using namespace std;

class Solution
{
    public:
        bool get_sign(string a);
        string add(string a, string b);
        string sub(string a, string b);
        string shift(string a, int n);
        string mul(string a, string b);
};

bool Solution::get_sign(string a){
    if(a[0]=='-') {a.erase(a.begin()); return false;}
    else {return true;}
}


string Solution::add(string a, string b){
    bool sign_a=get_sign(a);
    bool sign_b=get_sign(b);
    if(sign_a^sign_b){//a、b异号做减法
        if(sign_a) return sub(a, b);
        else return sub(b, a);
    }
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
    if(!sign_a) result.insert(result.begin(), '-');
    //cout << result << " ";
    return result;
}

string Solution::sub(string a, string b){
    string result;
    bool sign_a=get_sign(a);
    bool sign_b=get_sign(b);
    if(!sign_a&&sign_b) {result=add(a, b); result.insert(result.begin(), '-'); return result;}//-a-b=-(a+b)
    if(sign_a&&!sign_b) {return add(a, b);}//a-(-b)=a+b
    if(!sign_a&&!sign_b) {return sub(b, a);}//-a-(-b)=b-a
    int x, y, r, c=0;
    while(!a.empty()){
        x=a.back()-'0';
        a.pop_back();
        if(!b.empty()) {y=b.back()-'0'; b.pop_back();}
        else y=0;
        r=x-y-c;
        if(r<0) {c=1; r=-r;}
        else c=0;
        result.insert(result.begin(), r+'0');
    }
    while(!b.empty()){
        x=0;
        y=b.back();
        b.pop_back();
        if(r<0) {c=1; r=-r;}
        else c=0;
        result.insert(result.begin(), r+'0');
    }
    if(c==1) result.insert(result.begin(), '-');
    return result;
}

string Solution::shift(string a, int n){
    if(a.length()==1&&a[0]=='0') return a;
    string result=a;
    for(int i=0; i<n; i++){
        result.insert(result.end(), '0');
    }
    return result;
}

string Solution::mul(string a, string b){
    bool sign_a=get_sign(a);
    bool sign_b=get_sign(b);
    if(sign_a^sign_b) {
        string result=mul(a, b);cout << result << " ";
        if(result[0]!='-'){
            result.insert(result.begin(), '-'); 
            return result;
        }
        else{
            result.erase(result.begin());
            return result;
        }
    }
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
    string a1, a2, b1, b2;
    int n1=a.length()/2;
    int n2=b.length()/2;
    for(int i=0; i<n1; i++) a1.insert(a1.end(), a[i]);
    for(int i=n1; i<a.length(); i++) a2.insert(a2.end(), a[i]);
    for(int i=0; i<n2; i++) b1.insert(b1.end(), b[i]);
    for(int i=n2; i<b.length(); i++) b2.insert(b2.end(), b[i]);
	string amb=sub(a1, a2);cout << amb <<" ";
	string dmc=sub(b2, b1);cout << dmc << " ";
	string m=mul(amb, dmc);cout << m << " ";
    string ac=mul(a1, b1);cout<<ac<<" ";
    string bd=mul(a2, b2);cout<<bd<<" ";
	m=add(m, ac); m=add(m, bd);
	ac=shift(ac, n1*2); m=shift(m, n1);cout<<ac<<" " << m << " ";
    string result=add(ac, m);cout << result << " " << bd << " ";
    result=add(result, bd);cout << result << " ";
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