#include <iostream>
#include <vector>
#include <cstdlib>

class BigInt
{
private:
	std::vector<uint8_t> m_digits;
public:
	BigInt()
	{
	}

	BigInt(unsigned int number)
	{
		uint8_t buff;
		while (number != 0)
		{
			buff = number % 10;
			m_digits.push_back(buff);
			number /= 10;
		}
	}

	BigInt(const std::vector<uint8_t> &digits) : m_digits(digits)
	{
	}

	BigInt(std::vector<uint8_t> &&digits) : m_digits(digits)
	{
	}

	BigInt(const BigInt &big) : m_digits(big.m_digits)
	{
	}

	BigInt(BigInt &&big) : m_digits(big.m_digits)
	{
	}

	int get_digit_sum() const
	{
		int sum = 0;
		for (const uint8_t &a : m_digits)
			sum += static_cast<int>(a);
		return sum;
	}

	BigInt& operator=(const BigInt &big)
	{
		m_digits = big.m_digits;
		return *this;
	}

	BigInt& operator=(BigInt &&big)
	{
		m_digits = big.m_digits;
		return *this;
	}

	friend BigInt operator+(const BigInt &a, const BigInt &b)
	{
		std::vector<uint8_t> c;
		int min, max;
		min = (a.m_digits.size() < b.m_digits.size()) ? a.m_digits.size() : b.m_digits.size();
		max = (a.m_digits.size() > b.m_digits.size()) ? a.m_digits.size() : b.m_digits.size();
		c.resize(max);
		for (int i = 0; i < min; i++)
			c[i] = a.m_digits[i] + b.m_digits[i];
		if (max == a.m_digits.size())
			for (int j = min; j < max; j++)
				c[j] = a.m_digits[j];
		else
			for (int j = min; j < max; j++)
				c[j] = b.m_digits[j];
		for (int k = 0; k < max - 1; k++)
			if (c[k] > 9)
			{
				c[k + 1] += (c[k] / 10);
				c[k] %= 10;
			}
		while (c[max - 1] > 9)
		{
			c.push_back(c[max - 1] / 10);
			c[max - 1] %= 10;
			max++;
		}
		return BigInt(c);
	}

	friend bool operator<(const BigInt &a, const BigInt &b)
	{
		if (a.m_digits.size() != b.m_digits.size())
			return a.m_digits.size() < b.m_digits.size();
		else
			for (int i = a.m_digits.size() - 1; i >= 0; i--)
				if (a.m_digits[i] != b.m_digits[i])
					return a.m_digits[i] < b.m_digits[i];
		return false;
	}

	friend BigInt operator*(const BigInt &a, const BigInt &b)
	{
		BigInt c, d(0);
		int min, max;
		min = (a < b) ? a.m_digits.size() : b.m_digits.size();
		max = (b < a) ? a.m_digits.size() : b.m_digits.size();
		const BigInt big_num = (b < a) ? a : b;
		const BigInt small_num = (a < b) ? a : b;
		for (int i = 0; i < min; i++)
		{
			int m = i;
			while (m-- > 0)
				c.m_digits.push_back(0);
			for (int j = 0; j < max; j++)
			{
				c.m_digits.push_back((small_num.m_digits[i]) * (big_num.m_digits[j]));
			}
			for (int k = 0; k < c.m_digits.size() - 1; k++)
				if (c.m_digits[k] > 9)
				{
					c.m_digits[k + 1] += (c.m_digits[k] / 10);
					c.m_digits[k] %= 10;
				}
			int count = c.m_digits.size() - 1;
			while (count > 0 && c.m_digits[count - 1] > 9)
			{
				c.m_digits.push_back(c.m_digits[count - 1] / 10);
				c.m_digits[count - 1] %= 10;
				count++;
			}
			d = d + c;
			c.m_digits.resize(0);
		}
		return BigInt(d);
	}

	friend std::ostream& operator<<(std::ostream &out, const BigInt &big)
	{
		for (int i = big.m_digits.size() - 1; i >= 0; i--)
			out << static_cast<int>(big.m_digits[i]);
		return out;
	}
};

void swap(BigInt &a, BigInt &b)
{
	BigInt temp = a;
	a = b;
	b = temp;
}

void continued_fraction(int d, std::vector<BigInt> &numbers)
{
	int n = sqrt(d);
	int a = 0, b = 1, c = n, e = 1;
	numbers.push_back(n);
	do
	{
		c *= b;
		e *= b;
		a -= c;
		b = (d - (a*a)) / e;
		a *= -1;
		c = (n + a) / b;
		numbers.push_back(BigInt(c));
		e = 1;
	} while (a != 0 && b != 1);
}

void min_diophantine(int d, BigInt &x, BigInt &y)
{
	static std::vector<BigInt> continued_numbers;
	continued_fraction(d, continued_numbers);


	int period_length = continued_numbers.size() - 1;
	int k = period_length - 1;
	BigInt num(1), den(1);
	if (period_length % 2 == 0)
	{
		den = continued_numbers[k];
		num = num + (continued_numbers[k - 1] * den);
		k -= 2;
		while (k >= 0)
		{
			swap(num, den);
			num = num + (continued_numbers[k--] * den);
		}
	}
	else if (period_length != 1)
	{
		den = continued_numbers[k];
		num = num + (continued_numbers[k - 1] * den);
		k -= 2;
		while (k >= 1)
		{
			swap(num, den);
			num = num + (continued_numbers[k--] * den);
		}
		k = period_length;
		while (k >= 0)
		{
			swap(num, den);
			num = num + (continued_numbers[k--] * den);
		}
	}
	else
	{
		k = period_length;
		den = continued_numbers[k];
		num = num + (continued_numbers[k - 1] * den);
	}
	x = std::move(num);
	y = std::move(den);
	continued_numbers.clear();
}

bool is_square(int a)
{
	int b = sqrtf(a);
	return a == (b * b);
}

int main(int argc, char **argv)
{
	int d;
	BigInt x, y, max_x(0);
	for (int i = 1; i <= 1000; i++)
		if (!is_square(i))
		{
			min_diophantine(i, x, y);
			if (max_x < x)
			{
				max_x = x;
				d = i;
			}
		}
	std::cout << d << '\n';
	system("pause");
	return 0;
}