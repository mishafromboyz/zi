#include "lab1.hpp"

using namespace std;

int main()
{
    ulong ans;

    /*ulong base, val, mod; //quickmodexp test
    cin >> base;
    cin >> val;
    cin >> mod;
    ans = quickModExp(base, val, mod);*/ 

/*  ulong q = 11;
    ans = DH(q); //dh test
*/

    ulong a; //euc test
    ulong b;
    cin >> a, b;
    ans = euc(a, b);

 
/*  ulong a = 2; //giantbaby test
    ulong p = 23;
    ulong y = 9;
    ans = giantbaby(a, p, y);
*/
    cout << ans << endl;
    return 0;
}