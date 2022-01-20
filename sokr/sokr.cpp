#include<iostream>
#include<vector>
using namespace std;
struct fraction {
    int first;
    int second;

    fraction() {
        first = 0;
        second = 0;
    }
    fraction(int numerator, int denominator) {
        first = numerator;
        second = denominator;
    }

    fraction& operator = (const fraction x1) {
        if (this == &x1) {
            return *this;
        }
        first = x1.first;
        second = x1.second;
        return *this;
    }

    fraction operator+(fraction x2) {
        return fraction(first + x2.first, second + x2.second);
    }
    fraction operator+(int c) {
        return fraction(first + c, second + c);
    }

    fraction& operator++() {
        ++first;
        ++second;
        return *this;
    }


    fraction sokr() {
        fraction w;
        for (int i = 2; i < 1000; ++i) {
            if (w.first % i == 0 && w.second % i == 0) {
                w.first = first / i;
                w.second = second / i;
                i = 2;

            }

        }
        cout << "Result = " << w << endl;
        return w;
    }

    friend istream& operator >>(istream& in, fraction& ST) {
        in >> ST.first >> ST.second;
        return in;
    }
    friend ostream& operator<<(ostream& out, fraction& ST) {
        out << ST.first << " " << ST.second;
        return out;
    }
    friend int operator +(int k, fraction j) {
        return k + j.first + j.second;
    }
    friend fraction operator++(fraction& fst, int);
};

fraction operator++(fraction& fst, int) {
    fraction d = fst;
    ++fst;
    return d;
}

int main() {
    fraction T;
    cout << "Enter numerator and denominator: ";
    cin >> T;
    cout << "1 constructor = " << T << endl;
    fraction S(4, 2);
    cout << "2 constructor = " << S << endl;
    fraction D(T);
    D.sokr();
    cout << "Overload= :";
    S = T;
    cout << S << endl;
    cout << "Overload+ :";
    fraction H;
    H = T + S;
    cout << H << endl;
    H = T + 5;
    cout << H << endl;
    cout << 5 + T.first << " " << 5 + T.second << endl;
    fraction G(6, 3);
    fraction P;
    P = G++;
    cout << "Check++:" << P << endl;
    cout << "Overload++:" << G << endl;
    fraction U(7, 8);
    P = ++U;
    cout << "++Check:" << P << endl;
    cout << "++Overload:" << U << endl;
    vector<fraction> examples;
    fraction temp;
    int N;
    cout << "Input the number of examples: ";
    cin >> N;
    for (int i = 0; i < N; i++) {
        cout << "Enter numerator and denominator: ";
        cin >> temp;
        examples.push_back(temp);
        examples[i].sokr();

    }

    return 0;
}