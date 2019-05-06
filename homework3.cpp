#include <iostream>
#include <stdlib.h>

using namespace std;

class Calculator
{
    private:
        string Minus_n(string a, string b);
        string Shift_n(string a, int n);
        string Add_n(string a, string b);
        void help(int a, int b, int &c);
    public:
        string Multiply_n(string a, string b);
};

string Calculator::Multiply_n(string a, string b){
    if(a.length()==1 && b.length()==1){
        if(a[0]-'0'==1&&b[0]-'0'==1) return "1";
        else return "0";
    }
    else{
        int n=a.length()/2;
        string next_a1(a, 0, n); string next_a2(a, n, npos);
        string next_b1(b, 0, n); string next_b2(a, n, npos);
        string add_one=Multiply_n(next_a1, next_b1);
        string add_two=Multiply_n(next_a2, next_b2);
        string amc=Minus_n(next_a1, next_b1); string bmd=Minus_n(next_a2, next_b2);
        string add_three=Multiply_n(amc, bmd);
        add_one=Shift_n(add_one, 2*(a.length()-n); add_two=Shift_n(add_two, a.length()-n);
        string result=Add_n(add_one, add_two); result=Add_n(result, add_three);
        return result;
    }
    return result;
}

string Calculator::Minus_n(string a, string b){
    int c=0; tmp;
    int a1, b1;
    string result;
    for(int i=a.length(); i>=0; i--){
        a1=a[i]-'0'; b1=b[i]-'0';
        tmp = help(a1, b1, c);
        result.insert(0, tmp+'0');
    }
    result.push_back(c+'0');
    return result;
}

int Calculator::help(int a, int b, int &c){
    if((a==0&&((b==0&&c==1)||(b==1))) || (a==1&&b==1&&c==1)) c=1;
    else c=0;
    if((a==0&&b==0&&c==0) || (a==0&&b==1&&c==1) || (a==1&&b==0&&c==1) && (a==1&&b==1&&c==0)) return 0;
    else return 1;
}

string Shift_n(string a, int n){
    string tmp(n, '0');
    a+=tmp;
    return a;
}

string Add_n(string a, string b){
    
}