#include "lab1.hpp"

using namespace std;


bool isPrime(ulong p)
{  
   ulong b=(ulong)pow(p,0.5); 
    
   for(ulong i=2;i<=b;++i)
   {
      if ((p%i)==0) return false;        
   }     
     
   return true;      
}


ulong getBin(ulong x, ushort* bin) //transforms x into binary and stores in bin array + returns len of x in binary form
{
    ulong last_bit;
    ushort *arr = bin;
    ushort len_x = 0;
    //cout<<"Binary form is:"<<endl;
    for(;x!=0;x>>1, len_x++)
    {
        last_bit=x&1;
        arr[len_x]=last_bit;
        //cout<<last_bit; debug     
        x=x>>1;  
    }
    //cout<<endl; debug
    return len_x; //len of x in binary form
}


ulong primeGen()
{
    ulong x;
    //srand(time(NULL)); govna podkinuli ono vse portit
 
    uint range=100;
    do
    {
        x=rand()%range;
    } while(isPrime(x)==false);
    
    cout << x << "\n\n";       
    return x;
}


ulong quickModExp(ulong base, ulong val, ulong mod)
{
    if (mod == 0) return 0;
    ulong output = 1;
    ushort bin[64];
    ushort i = getBin(val, bin);
    ushort j = 1;
    ulong arrBase[i];
    arrBase[0]=base;
    for(; j<i; j++)
    {
        arrBase[j] = (arrBase[j-1] * arrBase[j-1])%mod;
        //cout << "arr[" << j <<"] = " << arrBase[j] << endl; //debug
    }

    for(j=0; j<i; j++)
    {
        //cout << "output = " << output << endl; //debug
        output *= pow(arrBase[j], bin[j]); 
    }

    //cout << "output = " << output << endl;
    return (output%mod);
}


ulong DH()
{
    ulong q = primeGen();
    return (DH(q));
}


ulong DH(ulong q)
{
    srand(time(NULL));
    ulong p = 2*q + 1;
    ulong g = 2;

    for(ulong ugli_g = quickModExp(g, q, p); g >= p-1 || ugli_g <= 1; cout << "g = " << g,  g = primeGen(), ugli_g = quickModExp(g, q, p)); //generate g
    
    //ulong pKeyA = rand(); //generate private keys
    //ulong pKeyB = rand();

    ulong pKeyA = 7; //for testing purposes
    ulong pKeyB = 13;

    ulong oKeyA = quickModExp(g, pKeyA, p); //calculate open keys
    ulong oKeyB = quickModExp(g, pKeyB, p);

    ulong conKeyAB = quickModExp(oKeyA, pKeyB, p); //calculate connection keys
    ulong conKeyBA = quickModExp(oKeyB, pKeyA, p);

    cout << "\nconnection key ab = " << conKeyAB << "\nconnection key ba = " << conKeyBA<< endl;
    return conKeyAB;
}


ulong euc(ulong a, ulong b) //calculates greatest common denominator
{
    ulong temp;
    for(; b > 0; a = temp)
    {
        temp = b;
        b = a%b;
    }
    return a;
}


ulong babyGiantStep(ulong g, ulong h, ulong n)
{
    ulong output;
}


int main()
{
    /*ulong base, val, mod; //quickmodexp test
    cin >> base;
    cin >> val;
    cin >> mod;
    ulong ans = quickModExp(base, val, mod);*/ 

    ulong q = 11;
    ulong ans = DH(q);

    cout << ans << endl;
    return 0;
}
