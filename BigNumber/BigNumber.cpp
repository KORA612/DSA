#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class BigNumber
{
private:
    long long int len;
    int *arr;
    bool sign;

public:
    // Constructors :
    BigNumber();
    BigNumber(string number);
    BigNumber(int number);

    // Copy constructor :
    BigNumber(const BigNumber &);

    // Destructor :
    ~BigNumber();

    // Output :
    void print();

    // Shifts :
    BigNumber shift_Left();
    BigNumber shift_Left(int);
    BigNumber shift_Right();
    BigNumber shift_Right(int);

    // Mathematical Operators :
    friend BigNumber operator+(const BigNumber &, const BigNumber &);
    friend BigNumber operator-(const BigNumber &, const BigNumber &);
    friend BigNumber operator*(const BigNumber &, const BigNumber &);
    friend BigNumber operator*(const BigNumber &, int);
    friend BigNumber operator/(const BigNumber &, const BigNumber &);
    friend BigNumber operator^(const BigNumber &, const BigNumber &);

    // Comparison Operators :
    friend bool operator==(const BigNumber &, const BigNumber &);
    friend bool operator>(const BigNumber &, const BigNumber &);
    friend bool operator<(const BigNumber &, const BigNumber &);

    // Tools
    friend bool isNull(const BigNumber &);
    friend void clean(BigNumber &);
};

// Constructors :

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

// Copy constructor :

BigNumber::BigNumber(const BigNumber &other)
{
    len = other.len;
    sign = other.sign;
    arr = new int[len];

    for (int i = 0; i < len; ++i)
        arr[i] = other.arr[i];
}

// Destructor :

BigNumber::~BigNumber()
{
    delete[] arr;
}

// Output :

void BigNumber::print()
{
    if (sign)
        cout << "- ";
    else
        cout << "+ ";

    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Add :

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

    clean(temp);
    return temp;
}

// Minus :

BigNumber operator-(const BigNumber &first, const BigNumber &second)
{

    if (!first.sign && second.sign) // + - -> +
    {
        BigNumber temp = second;
        temp.sign = 0;
        temp = first + temp;
        return temp;
    }

    else if (first.sign && !second.sign) // - + -> -
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

    if (AbsoluteFirst > AbsoluteSecond && !(first.sign && second.sign)) // ++
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

    if (AbsoluteFirst > AbsoluteSecond && (first.sign && second.sign)) // --
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

    if (AbsoluteFirst < AbsoluteSecond && !(first.sign && second.sign)) // ++
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

    if (AbsoluteFirst < AbsoluteSecond && (first.sign && second.sign)) // --
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

    clean(temp);
    return temp;
}

// Multiplication :

BigNumber operator*(const BigNumber &first, const BigNumber &second)
{
    BigNumber AbsoluteFirst = first, AbsoluteSecond = second, res1;
    bool flag = true;
    if (AbsoluteFirst.sign && AbsoluteSecond.sign)
        flag = true;
    else if (AbsoluteFirst.sign || AbsoluteSecond.sign)
        flag = false;
    AbsoluteFirst.sign = true;
    AbsoluteSecond.sign = true;

    if (AbsoluteFirst > AbsoluteSecond)
    {
        long long int carry = 0;
        for (long long int i = AbsoluteSecond.len - 1; i >= 0; i--)
        {
            string tmp;
            long long int s = AbsoluteSecond.len - 1 - i;
            while (s > 0)
            {
                tmp.append("0");
                s--;
            }
            for (long long int j = AbsoluteFirst.len - 1; j >= 0; j--)
            {
                long long int m = (AbsoluteFirst.arr[j]) * (AbsoluteSecond.arr[i]) + carry;
                tmp.insert(0, to_string(m % 10));
                carry = m / 10;
            }
            while (carry > 0)
            {
                tmp.insert(0, to_string(carry % 10));
                carry /= 10;
            }
            BigNumber res2(tmp);
            res2.sign = !flag;
            res1 = res1 + res2;
        }
    }
    else
    {
        long long int carry = 0;
        for (long long int i = AbsoluteFirst.len - 1; i >= 0; i--)
        {
            string tmp;
            long long int s = AbsoluteFirst.len - 1 - i;
            while (s > 0)
            {
                tmp.append("0");
                s--;
            }
            for (long long int j = AbsoluteSecond.len - 1; j >= 0; j--)
            {
                long long int m = (AbsoluteFirst.arr[i]) * (AbsoluteSecond.arr[j]) + carry;
                tmp.insert(0, to_string(m % 10));
                carry = m / 10;
            }
            while (carry > 0)
            {
                tmp.insert(0, to_string(carry % 10));
                carry /= 10;
            }
            BigNumber res2(tmp);
            res2.sign = !flag;
            res1 = res1 + res2;
        }
    }
    return res1;
}

// Scaller Multiplication :

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

    clean(temp);
    return temp;
}

// Division :

BigNumber operator/(const BigNumber &first, const BigNumber &second)
{
    if (isNull(second))
    {
        cout << "ERR";
        exit(0);
    }
    BigNumber AbsoluteFirst = first, AbsoluteSecond = second;
    bool flag;
    if ((!AbsoluteFirst.sign && !AbsoluteSecond.sign) || AbsoluteFirst.sign && AbsoluteSecond.sign)
        flag = 1;
    else if (!AbsoluteFirst.sign || !AbsoluteSecond.sign)
        flag = 0;
    long long int var = 0;
    AbsoluteFirst.sign = 0;
    AbsoluteSecond.sign = 0;

    string tmp;
    for (int i = 0; i < AbsoluteSecond.len; i++)
    {
        tmp += std::to_string(AbsoluteSecond.arr[i]);
    }
    // AbsoluteFirst .print();

    while (AbsoluteFirst > AbsoluteSecond)
    {
        long long int n = AbsoluteFirst.len - AbsoluteSecond.len;
        string a = tmp;
        // cout << a;
        long long int summ = 1;
        for (int i = 1; i < n; i++)
        {
            a.append("0");
            summ *= 10;
        }
        BigNumber temp(a);
        while (AbsoluteFirst > temp || AbsoluteFirst == temp)
        {
            AbsoluteFirst = AbsoluteFirst - temp;
            var += summ;
        }
    }
    BigNumber ans(var);
    ans.sign = !flag;
    return ans;
}

BigNumber operator^(const BigNumber &first, const BigNumber &second)
{
    long long int var1, var2;
    string tmp1, tmp2;
    for (int i = 0; i < first.len; i++)
    {
        tmp1 += std::to_string(first.arr[i]);
    }
    for (int i = 0; i < second.len; i++)
    {
        tmp2 += std::to_string(second.arr[i]);
    }
    long long int var = pow(stoi(tmp1), stoi(tmp2));
    BigNumber res(var);
    return res;
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

        return true;
    }
}

BigNumber BigNumber::shift_Left()
{
    return shift_Left(1);
}

BigNumber BigNumber::shift_Left(int n)
{
    if (n == 0)
        return *this;
    BigNumber temp = *this;
    len += n;
    delete[] arr;
    arr = new int[len];
    memset(arr, 0, len);

    for (int i = 0; i < temp.len; ++i) // n=3 : 1 2 3 0 0 0
        arr[i] = temp.arr[i];

    return *this;
}

BigNumber BigNumber::shift_Right()
{
    return shift_Right(1);
}

BigNumber BigNumber::shift_Right(int n)
{
    if (n == 0)
        return *this;
    BigNumber temp = *this;
    len -= n;
    delete[] arr;
    arr = new int[len];

    for (int i = len - 1; i >= 0; --i) // n=1 : 1 2
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

void clean(BigNumber &other)
{
    int *tempArr;
    int i;

    for (i = 0; i < other.len; ++i)
        if (other.arr[i] != 0)
            break;

    other.len -= i;
    tempArr = new int[other.len];

    for (int j = 1; j <= other.len; ++j)
        tempArr[other.len - j] = other.arr[other.len + i - j];

    delete[] other.arr;
    other.arr = new int[other.len];

    for (int j = 0; j < other.len; ++j)
        other.arr[j] = tempArr[j];

    delete[] tempArr;
}

int main()
{
    string num1 = "43234253712";
    string num2 = "4623846372";
    BigNumber first(num1);
    BigNumber second(num2);
    BigNumber res;

    first.print();
    second.print();
    res = first / second;
    res.print();
}