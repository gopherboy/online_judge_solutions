#define int64 long long
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;
#define int64 long long
const int64 D = 31;
const int64 N = 40;
const int64 base = (1ll << D);
const int64 bitmask = base - 1;
struct BigInt{
	int64 digits[N];
	int cnt;
	BigInt(int64 n = 0) {
		cnt = 0;
		memset(digits, 0, sizeof digits);
		for(int i = 0; i < N && n; n >>= D) {
			digits[i] = n & bitmask;
			cnt = ++i;
		}
	}
	BigInt(string s) {
		*this = BigInt(0);
		for(int i = 0; i < s.length(); i ++)
			*this = *this * 10 + s[i] - '0';
	}
	void operator=(const BigInt& b) {
		memcpy(digits, b.digits, sizeof digits);
		cnt = b.cnt;
	}
	BigInt operator+(const BigInt& b) const {
		int64 r = 0;
		BigInt result;
		for(int i = 0; i < max(cnt, b.cnt) || r; i ++) {
			r += digits[i] + b.digits[i];
			result.digits[i] = r & bitmask;
			r >>= D;
			result.cnt = i + 1;
		}
		return result;
	}
	BigInt operator-(const BigInt& b) const {
		BigInt result;
		int64 r = 0;
		for(int i = 0; i < cnt; i ++) {
			if((result.digits[i] = digits[i] - b.digits[i] + r) < 0)
				result.digits[i] += base, r = -1;
			else
				r = 0;
			if(result.digits[i]) result.cnt = i+1;
		}
		return result;
	}
	BigInt operator*(int64 n) const {
		int64 r = 0;
		BigInt result;
		for(int i = 0; (i < cnt || r) && n; i ++) {
			r += n * digits[i];
			result.digits[i] = r & bitmask;
			r >>= D;
			result.cnt = i + 1;
		}
		return result;
	}
	BigInt operator*(const BigInt& b) const {
		BigInt result;
		for(int i = cnt-1; i >= 0; i --)
			result = result * base + b * digits[i];
		return result;
	}
	void shiftLeft() {
		int r = 0;
		for(int i = 0; i < cnt+1 && i < N; i ++) {
			int nr = 0;
			if(digits[i] & (1 << (D-1)))
				nr = 1;
			digits[i] = (digits[i] << 1) & bitmask;
			digits[i] += r;
			r = nr;
			if(digits[i]) cnt = i + 1;
		}
	}
	BigInt operator/(const BigInt& b) const {
		BigInt result, row;
		for(int i = cnt-1; i >= 0; i --) {
			int64 digit = 0;
			for(int j = D-1; j >= 0; j --) {
				row.shiftLeft();
				row = row + ((digits[i] & (1 << j)) != 0);
				digit <<= 1;
				if(row >= b) row = row - b, digit += 1;
			}
			result = result * base + digit;
		}
		return result;
	}
	BigInt operator%(const BigInt& b) const {
		return (*this) - (*this / b) * b;
	}
	bool operator<(const BigInt& b) const {
		if(cnt != b.cnt)
			return cnt < b.cnt;
		else
			for(int i = cnt-1; i >= 0; i --)
				if(digits[i] != b.digits[i])
					return digits[i] < b.digits[i];
		return false;
	}
	bool operator==(const BigInt& b) const{ return !(*this < b) && !(b < *this); }
	bool operator<=(const BigInt& b) const{ return !(b < *this); }
	bool operator>(const BigInt& b)  const{ return !(*this <= b); }
	bool operator>=(const BigInt& b) const{ return !(*this < b); }
	bool operator!=(const BigInt& b) const{ return !(*this == b); }
	string str() const {
		string result = "0";
		for(int i = cnt-1; i >= 0; i --) {
			string temp;
			int64 r = 0;
			for(int j = result.length()-1; j >= 0 || r; j --) {
				if( j >= 0 ) r += (result[j] - '0') * base;
				temp += char('0' + r % 10);
				r /= 10;
			}
			result = "";
			r = digits[i];
			for(int j = 0; j < temp.length() || r; j ++) {
				if( j < temp.length() ) r += (temp[j] - '0');
				result += char('0' + r % 10);
				r /= 10;
			}
			reverse(result.begin(), result.end());
		}
		return result;
	}
};
int comb(int a,int b)
{
	if(b>0&&a>b)
		return comb(a-1,b-1)+comb(a-1,b);
	return 1;
}
void display(BigInt e)
{
	int rew[1000];
	int counter = 0;
	for(int t = 0;t<e.cnt;t++)
		cout<<e.digits[t];
}
BigInt pow(BigInt a,BigInt b)
{
	if(b <2)
		return 1;
	return a*pow(a,b-1);
}	
int main()
{
	int a;
	cin>>a;
	BigInt e = (BigInt)comb(9,2)*pow(comb(11,2),a);
	display(e);
	return 0;
}
