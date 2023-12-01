#include <iostream>
using namespace std;

class BigNumber
{
private:
    int len;
    int *arr;
    string numberStr;

public:
    BigNumber();
    BigNumber(string number);
    BigNumber(int number);

    void print();
/*
    BigNumber inc();
    BigNumber dec();

    BigNumber shiftR();
    BigNumber shiftL();
    BigNumber shiftR(int n);
    BigNumber shiftL(int n);
*/
    BigNumber sum(BigNumber other);
    BigNumber minus(BigNumber other);
    BigNumber mult(BigNumber other);
    BigNumber div(BigNumber other);
    BigNumber pow(BigNumber other);

    BigNumber multByOneDigit(int d);
};
BigNumber::BigNumber()
{
    len = 0;
}
BigNumber::BigNumber(string number)
{
    int flag = 0;
    if (static_cast<int>('-') == number[0])
    {
        len = number.length();
        arr = new int[len];
        arr[0] = 1;
        flag = 1;
    }
    else
    {
        len = number.length() + 1;
        arr = new int[len];
        arr[0] = 0;
    }

    for (int i = 1; i < len; i++)
    {
        arr[i] = number[i - 1 + flag] - '0';
    }
}
BigNumber::BigNumber(int number)
{
    if (number<0)
    {
        len = to_string(number).length();
        arr = new int[len];
        arr[0] = 1;
        number *= -1;
    }
    else
    {
        len = to_string(number).length() + 1;
        arr = new int[len];
        arr[0] = 0;
    }

    for (int i = len-1; i > 0; i--)
    {
        arr[i] = number % 10;
        number /= 10;
    }
}
void BigNumber::print()
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
}
BigNumber BigNumber::sum(BigNumber other)
{  
    //res[i] = arr[i] + other.arr[i]
}
BigNumber BigNumber::minus(BigNumber other)
{  
    if(other.arr[0] == 0) other.arr[0] = 1 ;
    else other.arr[0] = 0 ;
    return this->sum(other);
}
BigNumber BigNumber::mult(BigNumber other)
{  
    //res[i] = arr[i] + other.arr[i]
}
BigNumber BigNumber::div(BigNumber other)
{  
    //res[i] = arr[i] + other.arr[i]
}
BigNumber BigNumber::pow(BigNumber other)
{  
    //res[i] = arr[i] + other.arr[i]
}

int main()
{
    //string num = "123456789";
    int num = -123456789;
    BigNumber bn(num);
    bn.print();
}