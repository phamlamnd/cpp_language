#include<iostream>
#include<string>
#include<vector>
#include<ctime>
using namespace std;

class BigInt
{
private:
	std::vector<int> digits;
public:
	BigInt(){}
	BigInt(int x)
	{
		if (x == 0)
		{
			digits.push_back(0);
		}
		while (x != 0)
		{
			digits.push_back(x % 10);
			x /= 10;
		}
	}
	BigInt(long x)
	{
		if (x == 0)
		{
			digits.push_back(0);
		}
		while (x != 0)
		{
			digits.push_back(x % 10);
			x /= 10;
		}
	}
	BigInt(long long x)
	{
		if (x == 0)
		{
			digits.push_back(0);
		}
		while (x != 0)
		{
			digits.push_back(x % 10);
			x /= 10;
		}
	}
	BigInt(std::string s)
	{
		for (int i = s.length() - 1; i >= 0; i--)
		{
			this->digits.push_back(s[i] - 48);
		}
		while (digits.size() > 1 && digits.back() == 0)
		{
			digits.pop_back();
		}
	}
	BigInt(const BigInt &x) : digits(x.digits)
	{		
	}
	BigInt(BigInt &&x) : digits(x.digits)
	{
	}
	int operator[](int idx)
	{
		return this->digits[idx];
	}
	friend void Set(BigInt &a)
	{
		while (a.digits.size() > 1 && a.digits.back() == 0)
		{
			a.digits.pop_back();
		}
	}
	friend std::ostream& operator<<(std::ostream& os, BigInt &x)
	{
		for (int i = x.digits.size() - 1; i >= 0; i--)
		{
			os << x.digits[i];
		}
		return os;
	}
	friend std::istream& operator >> (std::istream& is, BigInt &x)
	{
		std::string s;
		std::getline(is, s);
		x.digits.resize(s.length());
		int idx = 0;
		for (int i = s.length() - 1; i >= 0; i--)
		{
			x.digits[idx++] = s[i] - 48;
		}
		Set(x);
		return is;
	}
	friend bool operator<(BigInt a, BigInt b)
	{
		Set(a);
		Set(b);
		if (a.digits.size() != b.digits.size()) return a.digits.size() < b.digits.size();
		for (int i = a.digits.size() - 1; i >= 0; i--)
		{
			if (a.digits[i] != b.digits[i])
			{
				return a.digits[i] < b.digits[i];
			}
		}
		return false;
	}
	friend bool operator>(BigInt a, BigInt b)
	{
		return b < a;
	}
	friend bool operator==(BigInt a, BigInt b)
	{
		return (!(a < b) && !(a > b));
	}
	friend bool operator<=(BigInt a, BigInt b)
	{
		return (a < b || a == b);
	}
	friend bool operator>=(BigInt a, BigInt b)
	{
		return (a > b || a == b);
	}
	friend bool operator!=(BigInt a, BigInt b)
	{
		return !(a == b);
	}
	friend BigInt max(BigInt a, BigInt b)
	{
		return a > b ? a : b;
	}
	friend BigInt min(BigInt a, BigInt b)
	{
		return a < b ? a : b;
	}
	friend BigInt operator+(BigInt a, BigInt b)
	{
		BigInt tem = max(a, b);
		BigInt result;
		int carry = 0;
		for (int i = 0; i < tem.digits.size(); i++)
		{
			if (i < a.digits.size()) carry += a.digits[i];
			if (i < b.digits.size()) carry += b.digits[i];
			result.digits.push_back(carry % 10);
			carry /= 10;
		}
		if (carry)
		{
			result.digits.push_back(carry);
		}
		return result;
	}
	friend BigInt operator+(BigInt a, int b)
	{
		return a + (BigInt)b;
	}
	friend BigInt operator++(BigInt &a) //++a
	{
		a = a + 1;
		return a;
	}
	friend BigInt operator++(BigInt &a, int x)
	{
		BigInt tem = a;
		++a;
		return tem;
	}
	friend void operator+=(BigInt &a, BigInt b)
	{
		a = a + b;
	}
	friend void operator+=(BigInt &a, int b)
	{
		a = a + b;
	}
	friend BigInt operator-(BigInt a, BigInt b)
	{
		Set(a);
		Set(b);
		BigInt result;
		int carry = 0;
		for (int i = 0; i < a.digits.size(); i++)
		{
			carry += a.digits[i] - (i < b.digits.size() ? b.digits[i] : 0);
			if (carry < 0)
			{
				result.digits.push_back(carry + 10);
				carry = -1;
			}
			else
			{
				result.digits.push_back(carry);
				carry = 0;
			}
		}
		Set(result);
		return result;
	}
	friend BigInt operator-(BigInt a, int b)
	{
		return a - (BigInt)b;
	}
	friend BigInt operator--(BigInt &a)
	{
		a = a - 1;
		return a;
	}
	friend BigInt operator--(BigInt &a, int x)
	{
		BigInt tem = a;
		a = a - 1;
		return tem;
	}
	friend void operator-=(BigInt &a, BigInt b)
	{
		a = a - b;
	}
	friend void operator-=(BigInt &a, int b)
	{
		a = a - b;
	}
	friend BigInt operator*(BigInt &a, BigInt &b)
	{
		Set(a);
		Set(b);
		BigInt result;
		result.digits.resize(a.digits.size() + b.digits.size(), 0);
		for (int i = 0; i < a.digits.size(); i++)
		{
			long long carry = 0;
			for (int j = 0; j < b.digits.size() || carry > 0; j++)
			{
				carry = result.digits[i + j] + carry + (long long)a.digits[i] * (j < b.digits.size() ? (long long)b.digits[j] : 0);
				result.digits[i + j] = carry % 10;
				carry /= 10;
			}
		}
		Set(result);
		return result;
	}
	friend BigInt operator*(BigInt a, int b)
	{
		return a * (BigInt)b;
	}
	friend BigInt operator*(int a, BigInt b)
	{
		return b * a;
	}
	friend void operator*=(BigInt &a, BigInt b)
	{
		a = a * b;
	}
	friend void operator*=(BigInt &a, int b)
	{
		a = a * b;
	}
	friend BigInt operator/(BigInt a, int b)
	{
		Set(a);
		BigInt ans;
		long long cur = 0;
		for (int i = a.digits.size() - 1; i >= 0; i--)
		{
			cur = cur * 10 + a.digits[i];
			ans = ans * 10 + cur / b;
			cur %= b;
		}
		Set(ans);
		return ans;
	}
	friend BigInt operator/(BigInt &a, BigInt &b)
	{
		Set(a);
		Set(b);
		BigInt ans = 0;
		BigInt cur = 0;
		for (int i = a.digits.size() - 1; i >= 0; i--)
		{
			cur = (cur * 10) + a.digits[i];
			for (int j = 9; j >= 0; j--)
			{
				if (b * j <= cur)
				{
					cur = cur - (b * j);
					ans = (ans * 10) + j;
					break;
				}
			}
			/*cur = cur * 10 + a.digits[i];
			int L = 0, R = 10, x = 0;
			while (L <= R)
			{
			int mid = (L + R) >> 1;
			if (b * mid > cur)
			{
			R = mid - 1;
			x = mid;
			}
			else
			{
			L = mid + 1;
			}
			}
			cur = cur - (b *(x - 1));
			ans = ans * 10 + (x - 1);*/
		}
		Set(ans);
		return ans;
	}
	friend void operator/=(BigInt &a, BigInt b)
	{
		a = a / b;
	}
	friend void operator/=(BigInt &a, int b)
	{
		a = a / b;
	}
	friend BigInt operator%(BigInt a, BigInt b)
	{
		Set(a);
		Set(b);
		BigInt ans = 0;
		for (int i = a.digits.size() - 1; i >= 0; i--)
		{
			ans = ans * 10 + a.digits[i];
			for (int j = 9; j >= 0; j--)
			{
				if (b * j <= ans)
				{
					ans = ans - (b * j);
				}
			}
		}
		Set(ans);
		return ans;
	}
	friend BigInt operator%(BigInt a, int b)
	{
		return a % (BigInt)b;
	}
	friend void operator%=(BigInt &a, BigInt b)
	{
		a = a % b;
	}
	friend void operator%=(BigInt &a, int b)
	{
		a = a % b;
	}
	friend BigInt gcd(BigInt a, BigInt b) //Greatest Common Divisor
	{
		if (a == (BigInt)0 || b == (BigInt)0)
		{
			return a + b;
		}
		while (a != b)
		{
			if (a > b)
			{
				a = a - b;
			}
			else
			{
				b = b - a;
			}
		}
		return a;
	}
	friend BigInt lcm(BigInt a, BigInt b) //lowest common multiple
	{
		return (a * b) / (gcd(a, b));
	}
	friend BigInt Pow(BigInt a, BigInt b)
	{
		BigInt sum = 1;
		for (BigInt i = 1; i <= b; i++)
		{
			sum *= a;
		}
		return sum;
	}
	friend BigInt Pow(BigInt a, int b)
	{
		return Pow(a, (BigInt)b);
	}
};

int main()
{
	BigInt a(2);
	cout << a;
	system("pause");
	return 0;
}