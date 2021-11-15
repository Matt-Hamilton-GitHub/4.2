#include <iostream>
#include <string>
#include <cmath>
using namespace std;


void rbinToDec(long binaryNumber, int& decimal, int& weight);
void rdecToBin(int decimal, int base, long& binarynumber);
void ibinToDec(long binaryNumber, int& decimal, int& weight);
void idecToBin(int decimal, int base, long & binarynumber);

int main()
{
    int decimal = 1023;
    long binarynumber = -1;
    idecToBin(decimal, 20, binarynumber);
    cout << binarynumber << endl;
    
    system("pause");
    return 0;
}


void ibinToDec(long binaryNumber, int& decimal, int& weight)
{
    int bit;
    weight = 0;
    decimal = 0;
    while (binaryNumber > 0)
    {
        bit = binaryNumber % 10;
        
        decimal += bit * static_cast<int>(pow(2.0, weight));
        binaryNumber = binaryNumber / 10;
        weight++;
    }
}


void rbinToDec(long binaryNumber, int& decimal, int& weight)
{
    int bit;
    if (binaryNumber > 0)
    {
        bit = binaryNumber % 10;
        decimal = decimal
            + bit * static_cast<int>(pow(2.0, weight));
        binaryNumber = binaryNumber / 10;
        weight++;
        rbinToDec(binaryNumber, decimal, weight);
    }
}


// -----------------------
void idecToBin(int decimal, int base, long& binarynumber)
{
        int binArr[20];//declare an array of 20 elements to store the values because the values will come in reverse order
        int idx = 0;//declare index
      //loop through the array
        for( idx = 0; decimal > 0; idx++) {   
              binArr[idx] = decimal % 2;
              decimal = decimal / 2;
        }    
      binarynumber = 0;
  for( idx = idx-1 ; idx >= 0 ;idx--)    
        {
                //  shift all digit by one place to left.
                binarynumber = binarynumber * 10 + binArr[idx];
        }    
        
}
//--------------------------

void rdecToBin(int decimal, int base, long& binarynumber)
{
    if (decimal > 0)
    {
        rdecToBin(decimal / base, base, binarynumber);
        int bit = decimal % base;
        binarynumber = 10 * binarynumber + bit;
    }
    else
        binarynumber = 0;
}