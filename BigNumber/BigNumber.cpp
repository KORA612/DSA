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

        for (size_t i = 0; i < len; ++i)
            arr[i] = (num[i + 1] - '0');
    }
    else
    {
        len = num.size();
        arr = new int[len];
        sign = 0;

        for (size_t i = 0; i < len; ++i)
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
BigNumber::BigNumber(const BigNumber &bN)
{
    len = bN.len;
    sign = bN.sign;
    arr = new int[len];

    for (size_t i = 0; i < len; ++i)
        arr[i] = bN.arr[i];
}
BigNumber::~BigNumber()
{
    delete[] arr;
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
	BigNumber temp;
	BigNumber tempBN;
	int i = 1;
	int carry = 0;
	
	int max = std::max(this->len, other.len);
	int min = std::min(this->len, other.len);
	
	if( !this->sign && other.sign )
	{
		BigNumber temp = other;
		temp.sign = 0;
		temp = this->minus(temp);
		return temp;
	}

	else if( this->sign && !other.sign )
	{
		BigNumber temp = *this;
		temp.sign = 0;
		temp = temp.minus(*this);
		return temp;
	}

	if( this->sign && other.sign )
		temp.sign = 1;
	
	else if( !this->sign && !other.sign )
		temp.sign = 0;
	
	if( this->len >= other.len )
	{
		if( this->sign && !other.sign )
			return other.minus(*this);
	
		tempBN.len = max;
		tempBN.arr = new int[tempBN.len];
		memset(tempBN.arr, 0, tempBN.len);
		
		for(size_t k = 1; k <= min; ++k)
			tempBN.arr[max - k] = other.arr[min - k];
		
		for(size_t k = min + 1; k < max; ++k)
			tempBN.arr[max - k] = 0;

	}
	else if ( other.len > this->len )
	{
		if( other.sign && !this->sign )
			return this->minus(other);
		
		tempBN.len = max;
		tempBN.arr = new int[tempBN.len];
		memset(tempBN.arr, 0, tempBN.len);
		
		for(size_t k = 1; k <= min; ++k)
			tempBN.arr[max - k] = this->arr[min - k];
		
		for(size_t k = min + 1; k < max; ++k)
			tempBN.arr[max - k] = 0;

	
	}

	temp.len = max + 1;
	temp.arr = new int[temp.len];
	memset(temp.arr, 0, temp.len);
	int m;

	while ( max > 0 )
	{
		if( this->len >= other.len )
			m = this->arr[tempBN.len - i] + tempBN.arr[tempBN.len - i] + carry;

		if( other.len > this->len )
			m = tempBN.arr[tempBN.len - i] + other.arr[tempBN.len - i] + carry;
		
		temp.arr[temp.len - i] = m%10;
		carry = m/10;
		++i;
		--max;
	}
	
	if ( carry > 0 )
	{
		temp.arr[temp.len - i] += carry;
		++i;
	}
	
	temp.clean();
	return temp;
}
BigNumber BigNumber::div(BigNumber other)
{
    // res[i] = arr[i] + other.arr[i]
}
BigNumber BigNumber::pow(BigNumber other)
{
    // res[i] = arr[i] + other.arr[i]
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

    for (size_t j = 1; j <= len; ++j)
        tempArr[len - j] = arr[len + i - j];

    delete[] arr;
    arr = new int[len];

    for (size_t j = 0; j < len; ++j)
        arr[j] = tempArr[j];

    delete[] tempArr;
}

int main()
{
    string num1 = "123456789";
    int num2 = -123456789;
    BigNumber bn1(num1);
    BigNumber bn2(num2);
    bn1.print();
}