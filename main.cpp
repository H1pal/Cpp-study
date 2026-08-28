#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(const ll n1, const ll n2) {
    return n2 == 0 ? n1 : gcd(n2, n1 % n2);
}

ll examine(const ll n1, const ll n2) {
    return n1 > n2 ? gcd(n1, n2) : gcd(n2, n1);
}

int main() {



    /* 유클리드 호제법 이용해서 최대공약수와 최소공배수 구하기
    ll cs, num, multiple;
    cin >> cs >> num;

    ll divisor = multiple = num;
    for (int i = 0; i < cs - 1; i++)
    {
        cin >> num;

        divisor = examine(divisor, num);
        multiple = multiple / examine(num, multiple) * num;
    }

    cout << divisor << ' ' << multiple << endl;
    */


    // int i, j;
    // int cs, arr[14], mx = 0, mn, mul = 1, chk = 0;
    // cin >> cs;
    //
    // for (i = 0;i < cs;i++)
    // {
    //     cin >> arr[i];
    //
    //     if (i == 0) { //최솟값 변수가 값이 없는 상태 배제
    //         mn = arr[0];
    //     }
    //
    //     if (arr[i] > mx) { //최댓값 구하기
    //         mx = arr[i];
    //     }
    //
    //     if (arr[i] < mn) { //최솟값 구하기
    //         mn = arr[i];
    //     }
    // }
    //
    // int multiple = mx;
    //
    // while (true) {
    //     for (i = 0;i < cs;i++)
    //     {
    //         if (multiple % arr[i] != 0) {
    //             chk = 0;
    //             break;
    //         }
    //         chk = 1;
    //     }
    //
    //     if (chk) {
    //         break;
    //     }
    //     multiple += mx;
    //
    // }
    //
    // int divisor = mn;
    // for (i = mn;i >= 1;i--)
    // {
    //     divisor = i;
    //
    //     for (j = 0;j < cs;j++)
    //     {
    //         if (arr[j] % divisor != 0)
    //         {
    //             chk = 0;
    //             break;
    //         }
    //         chk = 1;
    //     }
    //
    //     if (chk) {
    //         break;
    //     }
    // }
    //
    // cout << divisor << " " << multiple << endl;
}