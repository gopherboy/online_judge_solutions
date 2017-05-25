#define int64 long long
#include <iostream>
#include <algorithm>
#include <string.h>
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

BigInt get_dp(int, int);

BigInt dp(int sum, int n) {
	if(n == 1) {
		if (sum > 9)
			return 0;
//		cout<<endl;
		return 1;
	}
	if(sum == 0)
		return 1;
	if(sum == 1)
		return n;
	if(sum == 2)
		return n * (n+1) / 2;
	BigInt poss = 0;
	for(int i = 0; i <= 9; i++) {
		if(sum - i < 0)
			break;
//		cout<<"dedicated:\t"<< i<<endl;
//		cout<<"dp("<<sum-i<<','<<n-1<<")\n";
		poss = poss + get_dp(sum - i, n - 1);
	}
//	cout<<endl;
	return poss;
}

BigInt store[501][51];

BigInt get_dp(int sum, int n) {
	if(store[sum][n] != -1)
		return store[sum][n];
	store[sum][n] = dp(sum, n);
	return store[sum][n];
}

int main() {
	for(int i = 0; i < 501; i++)
		for(int j = 0; j < 51; j++)
			store[i][j] = -1;
	int a;
	cin>>a;
	a = a / 2;
	BigInt sum = 0;
	for(int i = 0; i <= a * 9; i++)
		sum = sum + (get_dp(i, a) * get_dp(i, a));
	cout<<sum.str();
}
