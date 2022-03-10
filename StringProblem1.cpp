/*
A sequence of Strings consisting of only two characters '0' and '1' is defined as

S0 = “0”  
any string Sn of sequence  can be defined as below

Sn = flip_bits(Sn-1) + “0” + Sn-1

flip_bits is a function that takes a string and changes 0 to 1 and 1 to 0
e.g. flip_bits("100") = "011"

below are examples of some  values of the sequence

S1 = “100”  = flip_bit(S0) + 0 + S0
S2 = “0110100” = flip_bits(100) + “0” + 100 = 011 0 100

S3 = “1001011 0 0110100”



Problem

write a function f that takes two numbers n and k and returns the character in kth position of Sn
f(n,k) => character at kth position of Sn

e.g.
f(1,3) = 0
f(2,7) = 0
f(3,7) = 1
f(1,1) = 1 
*/


#include <iostream>
#include <math.h>
using namespace std;

char f(int x, int k)
{
    //calculating length of Sn
    int n = 2 * (pow(2,x) - 1) + 1;
    bool flipped = false;
    while(k>0)
    {
        //on left side of center
        if(k<(n/2+1))
        {
            flipped = !flipped;
        }
        //on right side of center
        else if(k>(n/2+1))
        {
            //flipped = false;
            k -= ((n-1)/2) + 1;
        }
        //center
        else
        {
            return flipped? '1':'0';
        }
        n = (n-1)/2;
    }
    return flipped? '1':'0';
}

int main()
{
    std::cout << f(1,3);
}
