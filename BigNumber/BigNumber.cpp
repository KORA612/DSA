#include <iostream>
#include <cstring>
using namespace std;

class BigNumber
{
private:
    int len;
    int *arr;
    bool sign;

    void clean();

public:
    // Constructors :
    BigNumber();
    BigNumber(string number);
    BigNumber(int number);

    // Copy constructor :
    BigNumber(const BigNumber &);

    // Destructor :
    ~BigNumber();

    void print();

    BigNumber shiftL();
    BigNumber shiftL(int);
    BigNumber shiftR();
    BigNumber shiftR(int);

    friend bool isNull(const BigNumber &);

    friend BigNumber operator+(const BigNumber &, const BigNumber &);
    friend BigNumber operator-(const BigNumber &, const BigNumber &);
    friend BigNumber operator*(const BigNumber &, const BigNumber &);
    friend BigNumber operator*(const BigNumber &, int);
    friend BigNumber operator/(const BigNumber &, const BigNumber &);
    friend BigNumber operator^(const BigNumber &, const BigNumber &);

    friend bool operator==(const BigNumber &, const BigNumber &);
    friend bool operator>(const BigNumber &, const BigNumber &);
    friend bool operator<(const BigNumber &, const BigNumber &);
};

BigNumber::BigNumber()
{
    len = 1;
    sign = 0;
    arr = new int[1];
    arr[0] = 0;
}
BigNumber::BigNumber(std::string num)
{
    if (num[0] == '-')
    {
        len = num.size() - 1;
        arr = new int[len];
        sign = 1;

        for (int i = 0; i < len; ++i)
            arr[i] = (num[i + 1] - '0');
    }
    else
    {
        len = num.size();
        arr = new int[len];
        sign = 0;

        for (int i = 0; i < len; ++i)
            arr[i] = (num[i] - '0');
    }
}
BigNumber::BigNumber(int num)
{
    if (num < 0)
    {
        sign = 1;
        len = std::to_string(num).length() - 1;
    }

    else
    {
        sign = 0;
        len = std::to_string(num).length();
    }

    arr = new int[len];
    num = abs(num);

    for (int i = len - 1; i >= 0; --i)
    {
        arr[i] = num % 10;
        num /= 10;
    }
}
BigNumber::BigNumber(const BigNumber &other)
{
    len = other.len;
    sign = other.sign;
    arr = new int[len];

    for (int i = 0; i < len; ++i)
        arr[i] = other.arr[i];
}
BigNumber::~BigNumber()
{
    delete[] arr;
}
void BigNumber::print()
{
    if (sign)
        cout<<"- ";
    else
        cout<<"+ ";
    
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
BigNumber operator+(const BigNumber &first, const BigNumber &second)
{
    BigNumber temp;
    BigNumber tempother;
    int i = 1;
    int carry = 0;

    int max = std::max(first.len, second.len);
    int min = std::min(first.len, second.len);

    if (!first.sign && second.sign)
    {
        BigNumber temp = second;
        temp.sign = 0;
        temp = first - temp;
        return temp;
    }

    else if (first.sign && !second.sign)
    {
        BigNumber temp = first;
        temp.sign = 0;
        temp = second - temp;
        return temp;
    }

    if (first.sign && second.sign)
        temp.sign = 1;

    else if (!first.sign && !second.sign)
        temp.sign = 0;

    if (first.len >= second.len)
    {
        if (first.sign && !second.sign)
            return second - first;

        tempother.len = max;
        tempother.arr = new int[tempother.len];
        memset(tempother.arr, 0, tempother.len);

        for (int k = 1; k <= min; ++k)
            tempother.arr[max - k] = second.arr[min - k];

        for (int k = min + 1; k < max; ++k)
            tempother.arr[max - k] = 0;
    }
    else if (second.len > first.len)
    {
        if (second.sign && !first.sign)
            return first - second;

        tempother.len = max;
        tempother.arr = new int[tempother.len];
        memset(tempother.arr, 0, tempother.len);

        for (int k = 1; k <= min; ++k)
            tempother.arr[max - k] = first.arr[min - k];

        for (int k = min + 1; k < max; ++k)
            tempother.arr[max - k] = 0;
    }

    temp.len = max + 1;
    temp.arr = new int[temp.len];
    memset(temp.arr, 0, temp.len);
    int m;

    while (max > 0)
    {
        if (first.len >= second.len)
            m = first.arr[tempother.len - i] + tempother.arr[tempother.len - i] + carry;

        if (second.len > first.len)
            m = tempother.arr[tempother.len - i] + second.arr[tempother.len - i] + carry;

        temp.arr[temp.len - i] = m % 10;
        carry = m / 10;
        ++i;
        --max;
    }

    if (carry > 0)
    {
        temp.arr[temp.len - i] += carry;
        ++i;
    }

    temp.clean();
    return temp;
}
BigNumber operator-(const BigNumber &first, const BigNumber &second)
{

    if (!first.sign && second.sign)
    {
        BigNumber temp = second;
        temp.sign = 0;
        temp = first + temp;
        return temp;
    }

    else if (first.sign && !second.sign)
    {
        BigNumber temp = first;
        temp.sign = 0;
        temp = temp + second;
        temp.sign = 1;
        return temp;
    }

    int max = std::max(first.len, second.len);
    int min = std::min(first.len, second.len);

    BigNumber temp;
    temp.len = max;
    temp.arr = new int[temp.len];
    memset(temp.arr, 0, temp.len);

    int t = 0;
    int s;

    BigNumber AbsoluteFirst = first;
    BigNumber AbsoluteSecond = second;
    AbsoluteFirst.sign = 0;
    AbsoluteSecond.sign = 0;

    if (AbsoluteFirst > AbsoluteSecond && !(first.sign && second.sign))
    {
        temp.sign = 0;
        for (int i = 1; i <= max; ++i)
        {
            if (i <= min)
                s = first.arr[max - i] - second.arr[min - i] + t;
            else
                s = first.arr[max - i] + t;
            if (s < 0)
            {
                s += 10;
                t = -1;
            }
            else
                t = 0;

            temp.arr[max - i] = s;
        }
    }

    if (AbsoluteFirst > AbsoluteSecond && (first.sign && second.sign))
    {
        temp.sign = 1;
        for (int i = 1; i <= max; ++i)
        {
            if (i <= min)
                s = first.arr[max - i] - second.arr[min - i] + t;
            else
                s = first.arr[max - i] + t;
            if (s < 0)
            {
                s += 10;
                t = -1;
            }
            else
                t = 0;

            temp.arr[max - i] = s;
        }
    }

    if (AbsoluteFirst < AbsoluteSecond && !(first.sign && second.sign))
    {
        temp.sign = 1;
        for (int i = 1; i <= max; ++i)
        {
            if (i <= min)
                s = second.arr[max - i] - first.arr[min - i] + t;
            else
                s = second.arr[max - i] + t;
            if (s < 0)
            {
                s += 10;
                t = -1;
            }
            else
                t = 0;

            temp.arr[max - i] = s;
        }
    }

    if (AbsoluteFirst < AbsoluteSecond && (first.sign && second.sign))
    {
        temp.sign = 0;
        for (int i = 1; i <= max; ++i)
        {
            if (i <= min)
                s = second.arr[max - i] - first.arr[min - i] + t;
            else
                s = second.arr[max - i] + t;
            if (s < 0)
            {
                s += 10;
                t = -1;
            }
            else
                t = 0;
            temp.arr[max - i] = s;
        }
    }

    if (first == second)
    {
        delete[] temp.arr;
        temp.len = 1;
        temp.arr = new int[temp.len];
        temp.arr[0] = 0;
    }

    temp.clean();
    return temp;
}

// multiplication
BigNumber operator*(const BigNumber &first, const BigNumber &second)
{

    BigNumber temp1;
    temp1.len = first.len + second.len;
    temp1.arr = new int[temp1.len];
    memset(temp1.arr, 0, temp1.len);

    BigNumber tempother = first;
    tempother.sign = 0;

    BigNumber temp2 = temp1;

    if (isNull(first) || isNull(second))
        return 0;

    if ((first.sign && !second.sign) || (!first.sign && second.sign))
        temp2.sign = 1;
    else
        temp2.sign = 0;

    for (int j = 0; j < second.len; ++j)
        temp1 = temp1 + (tempother * (int)second.arr[second.len - j - 1]).shiftL(j);

    for (int i = 1; i <= temp2.len; ++i)
        temp2.arr[temp2.len - i] = temp1.arr[temp1.len - i];

    temp2.clean();
    return temp2;
}

BigNumber operator*(const BigNumber &other, int num)
{
    if (isNull(other) || num == 0)
        return 0;

    BigNumber temp;
    temp.len = other.len + 1;
    temp.arr = new int[temp.len];
    memset(temp.arr, 0, temp.len);

    if ((num < 0 && !other.sign) || (num > 0 && other.sign))
        temp.sign = 1;
    else
        temp.sign = 0;

    int s;
    int t = 0;
    int i;

    for (i = 1; i <= other.len; ++i)
    {
        s = other.arr[other.len - i] * abs(num) + t;
        temp.arr[temp.len - i] = s % 10;
        t = s / 10;
    }

    if (t > 0)
        temp.arr[temp.len - i] = t;

    temp.clean();
    return temp;
}

// division
BigNumber operator/(const BigNumber &first, const BigNumber &second)
{
    if (isNull(second))
        throw("Zero division is undefined!");

    BigNumber AbsoluteFirst = first;
    AbsoluteFirst.sign = 0;
    BigNumber AbsoluteSecond = second;
    AbsoluteSecond.sign = 0;

    if (AbsoluteSecond > AbsoluteFirst)
        return 0;
    if (second == first)
        return 1;
    // when XOR of both numbers' sign is T
    if (AbsoluteFirst == AbsoluteSecond)
        return BigNumber(-1);

    BigNumber quotient;

    if ((!first.sign && second.sign) || (first.sign && !second.sign))
        quotient.sign = 1;
    else
        quotient.sign = 0;

    int index;
    quotient.len = 0;
    int quotientDigit;
    int *result = new int[first.len];
    memset(result, 0, first.len);
    BigNumber t;

    for (index = 0; t * 10 + AbsoluteFirst.arr[index] < AbsoluteSecond; index++)
    {
        t = t * 10;
        t = t + AbsoluteFirst.arr[index];
    }

    for (; index < AbsoluteFirst.len; index++)
    {
        t = t * 10 + AbsoluteFirst.arr[index];
        for (quotientDigit = 9; quotientDigit * AbsoluteSecond > t; quotientDigit--)
            ;
        t = t - (quotientDigit * AbsoluteSecond);
        result[quotient.len++] = quotientDigit;
    }

    quotient.arr = new int[quotient.len];

    for (index = 0; index < quotient.len; index++)
        quotient.arr[index] = result[index];

    delete[] result;

    return quotient;
}

// power
BigNumber operator^(const BigNumber &first, const BigNumber &second)
{

    if (second.sign)
        throw("Negative power not allowed!");
    if (isNull(first) && isNull(second))
    {
        throw("Zero powered to zero is undefined!");
    }

    if (isNull(first))
        return 0;

    if (isNull(second))
        return 1;

    BigNumber temp1(1);

    BigNumber Exponent, Base;
    Base = first;
    Exponent = second;
    while (!isNull(Exponent))
    {
        if (Exponent.arr[Exponent.len - 1] & 1)
            temp1 = temp1 * Base;
        Base = Base * Base;
        Exponent = Exponent / 2;
    }

    return temp1;
}
bool operator>(const BigNumber &other1, const BigNumber &other2)
{
    if (other1.sign && !other2.sign)
        return false;

    else if (!other1.sign && other2.sign)
        return true;

    else if (other1.sign && other2.sign)
    {
        BigNumber temp1 = other1;
        BigNumber temp2 = other2;
        temp1.sign = 0;
        temp2.sign = 0;
        return temp1 < temp2;
    }

    if (other1.len > other2.len)
        return true;

    else if (other1.len < other2.len)
        return false;

    else
    {
        for (int i = 0; i < other1.len; ++i)
        {
            if (other1.arr[i] > other2.arr[i])
                return true;

            if (other1.arr[i] < other2.arr[i])
                return false;
        }
        // completely identical
        return false;
    }
}

bool operator<(const BigNumber &other1, const BigNumber &other2)
{
    if (other1.sign && !other2.sign)
        return true;

    else if (!other1.sign && other2.sign)
        return false;

    else if (other1.sign && other2.sign)
    {
        BigNumber temp1 = other1;
        BigNumber temp2 = other2;
        temp1.sign = 0;
        temp2.sign = 0;
        return temp1 > temp2;
    }

    if (other1.len > other2.len)
        return false;

    if (other1.len < other2.len)
        return true;

    else
    {
        for (int i = 0; i < other1.len; ++i)
        {

            if (other1.arr[i] > other2.arr[i])
                return false;

            if (other1.arr[i] < other2.arr[i])
                return true;
        }
        // completely identical
        return false;
    }
}
bool operator==(const BigNumber &other1, const BigNumber &other2)
{
    if ((!other1.sign && other2.sign) || (other1.sign && !other2.sign))
        return false;

    if (other1.len > other2.len)
        return false;

    if (other1.len < other2.len)
        return false;

    else
    {
        for (int i = 0; i < other1.len; ++i)
            if (other1.arr[i] != other2.arr[i])
                return false;

        // completely identical
        return true;
    }
}

BigNumber BigNumber::shiftL()
{
    return shiftL(1);
}

BigNumber BigNumber::shiftL(int n)
{
    if (n == 0)
        return *this;
    BigNumber temp = *this;
    len += n;
    delete[] arr;
    arr = new int[len];
    memset(arr, 0, len);

    for (int i = 0; i < temp.len; ++i)
        arr[i] = temp.arr[i];

    return *this;
}

BigNumber BigNumber::shiftR()
{
    return shiftR(1);
}

BigNumber BigNumber::shiftR(int n)
{
    if (n == 0)
        return *this;
    BigNumber temp = *this;
    len -= n;
    delete[] arr;
    arr = new int[len];

    for (int i = len - 1; i >= 0; --i)
        arr[i] = temp.arr[i];

    return *this;
}

bool isNull(const BigNumber &other)
{
    for (int i = 0; i < other.len; ++i)
        if (other.arr[i] != 0)
            return false;
    return true;
}

void BigNumber::clean()
{
    int *tempArr;
    int i;

    for (i = 0; i < len; ++i)
        if (arr[i] != 0)
            break;

    len -= i;
    tempArr = new int[len];

    for (int j = 1; j <= len; ++j)
        tempArr[len - j] = arr[len + i - j];

    delete[] arr;
    arr = new int[len];

    for (int j = 0; j < len; ++j)
        arr[j] = tempArr[j];

    delete[] tempArr;
}

int main()
{
    string num1 = "123456789";
    int num2 = -123456789;
    BigNumber first(num1);
    BigNumber second(num2);
    BigNumber res;
    first.print();
    second.print();
    res = first * second;
    res.print();
}