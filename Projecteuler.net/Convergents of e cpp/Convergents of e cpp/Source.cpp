#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<ctime>
#include<string>
#include<iomanip>
//using namespace std;
class BigInt
{
private:
	std::vector<int> digits;
public:
	int get_size()
	{
		return this->digits.size();
	}
	int get_digit(int i)
	{
		return this->digits[i];
	}
	BigInt()
	{
		
	}
	BigInt(int x)
	{
		while (x != 0)
		{
			digits.push_back(x % 10);
			x /= 10;
		}
	}
	BigInt(long x)
	{
		while (x != 0)
		{
			digits.push_back(x % 10);
			x /= 10;
		}
	}
	BigInt(long long x)
	{
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
	BigInt(BigInt &x)
	{
		digits.resize(x.digits.size());
		for (int i = 0; i < x.digits.size(); i++)
		{
			this->digits[i] = x.digits[i];
		}
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
	friend std::ostream& operator<<(std::ostream& os, BigInt x)
	{
		for (int i = x.digits.size() - 1; i >= 0; i--)
		{
			os << x.digits[i];
		}
		return os;
	}
	friend std::istream& operator>>(std::istream& is, BigInt &x)
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
	friend BigInt operator*(BigInt a, BigInt b)
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
	friend BigInt operator/(BigInt a, BigInt b)
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

class PhanSo
{
private:
	BigInt TS;
	BigInt MS;
public:
	PhanSo()
	{
		TS = 0;
		MS = 1;
	}
	PhanSo(BigInt ts)
	{
		TS = ts;
		MS = 1;
	}
	PhanSo(BigInt ts, BigInt ms)
	{
		TS = ts;
		MS = ms;
	}
	PhanSo(PhanSo &ps)
	{
		TS = ps.TS;
		MS = ps.MS;
	}
	BigInt ucln()
	{
		BigInt a = TS;
		BigInt b = MS;
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
	void RutGon()
	{
		BigInt uc = ucln();
		TS = TS / uc;
		MS = MS / uc;
	}
	PhanSo NghichDao()
	{
		PhanSo nd;
		nd.TS = MS;
		nd.MS = TS;
		return nd;
	}
	PhanSo operator+(PhanSo ps)
	{
		PhanSo Tong;
		Tong.TS = this->TS * ps.MS + ps.TS * this->MS;
		Tong.MS = this->MS * ps.MS;
		Tong.RutGon();
		return Tong;
	}
	friend PhanSo operator+(BigInt x, PhanSo ps)
	{
		PhanSo Tong;
		Tong.TS = ps.TS + x * ps.MS;
		Tong.MS = ps.MS;
		Tong.RutGon();
		return Tong;
	}
	friend std::ostream& operator<<(std::ostream &os, PhanSo ps)
	{
		os << ps.TS << "/" << ps.MS;
		return os;
	}
	BigInt get_TS()
	{
		return TS;
	}
	BigInt get_MS()
	{
		return MS;
	}
};
class convergents_of_e
{
private:
	std::vector<BigInt> e;
public:
	convergents_of_e()
	{
		e.resize(100);
		e[0] = 2;
		e[1] = 1;
		int idx = 2;
		int k = 1;
		while (idx < 100)
		{
			e[idx++] = 2 * k++;
			if (idx < 100) 
			{
				e[idx++] = 1;
			}
			if (idx < 100) 
			{
				e[idx++] = 1;
			}
		}
	}
	convergents_of_e(int n)
	{
		e.resize(n);
		e[0] = 2;
		e[1] = 1;
		int idx = 2;
		int k = 1;
		while (idx < n)
		{
			e[idx++] = 2 * k++;
			if (idx < n) 
			{
				e[idx++] = 1;
			}
			if (idx < n) 
			{
				e[idx++] = 1;
			}
		}
	}
	BigInt get_e_th(int idx)
	{
		if (idx < e.size()) 
		{
			return e[idx];
		}
		else 
		{
			std::cout << "Error! Access out of range!";
			exit(0);
		}
	}
	PhanSo get_terms_of_convergents(int n)
	{
		PhanSo ps_n(1, e[n - 1]);
		PhanSo ps(2, 1);
		if (n >= 2)
		{
			for (int i = n - 2; i >= 1; i--)
			{
				ps = e[i] + ps_n;
				ps_n = ps.NghichDao();
			}
			return 2 + ps_n;
		}
		return ps;
	}
	int get_sum_of_digits_in_the_numerator(int n)
	{
		int sum = 0;
		PhanSo x = get_terms_of_convergents(n);
		BigInt nu = x.get_TS();
		for (int i = 0; i < nu.get_size(); i++)
		{
			sum += nu.get_digit(i);
		}
		return sum;
		
	}
	//double get_value(int n)
	//{
	//	PhanSo ps = get_terms_of_convergents(n);
	//	return (double)ps.get_TS() / ps.get_MS();
	//}
};
int main()
{
	clock_t t = clock(); 
	BigInt a = 1766319049;
	BigInt b = 226153980;
	std::cout << b.get_digit(0) << std::endl;
	std::cout << b[0];
	//cout << Pow(a, 2) - 61 * Pow(b, 2);
	
	std::cout << " done in " << (double)(clock() - t) * 1000/ CLOCKS_PER_SEC << "ms" << std::endl;
	system("pause");
	return 0;
}