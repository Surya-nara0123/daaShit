#include <iostream>
#include <cmath>

using namespace std;


int ps(int n1, int n2){
    int c = 0;
    int c1 = 0;
    while(n1){
        c++;
        n1/=2;
    }
    while(n2){
        c1++;
        n2/=2;
    }

    if(c1 > c) return c1;
    return c;
}

int dnc(int n1, int n2){
    if(n1 < 2 || n2 < 2){
        return n1 * n2;
    } else {
        int halfSize = ps(n1, n2) / 2;
        int a = n1 / (int)pow(2, halfSize);
        int b = n1 % (int)pow(2, halfSize);
        int c = n2 / (int)pow(2, halfSize);
        int d = n2 % (int)pow(2, halfSize);
        int ac = dnc(a, c);
        int bd = dnc(b, d);
        int ad_bc = dnc(a+b, c+d) - ac - bd;

        return (ac << (2 * halfSize)) + (ad_bc << halfSize) + bd;
    }
}

int main(){
    int n1, n2;
    cout << "Karatsubha ALgorithm" << endl;
    cout << "enter number 1: ";
    cin >> n1;
    cout << "enter number 2: ";
    cin >> n2;

    cout << "Problem Size : " << ps(n1, n2) << endl;

    cout << "Answer is " << dnc(n1, n2) << endl;
    return 0;
}