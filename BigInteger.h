#ifndef BIGINTEGER_H
#define BIGINTEGER_H

class BigInteger {
private:
    std::vector<int> digits;
    bool isNegative;

public:
    BigInteger(std::string input) : digits({0}){
        if(input[0] == '-') {
            isNegative = true;
            input.erase(input.begin());
        }
        else isNegative = false;

        //reverse push
        for(std::string::iterator it = input.end()-1;it >= input.begin();it--) {
            digits.push_back(*it - '0');
        }

        while(true) {
            if(!digits.empty() && digits.back() == 0) {
                digits.pop_back();
            }
        }

        if(digits.empty()) {
            digits.push_back(0);
            isNegative = false;
        }
    }

    bool operator==(const BigInteger &input) const;
    bool operator<(const BigInteger &input) const;
    bool operator>(const BigInteger &input) const;
    bool operator<=(const BigInteger &input) const;
    bool operator>=(const BigInteger &input) const;
    bool operator!=(const BigInteger &input) const;

    BigInteger operator+(const BigInteger &input) const;
    BigInteger operator+=(const BigInteger &input) const;
    BigInteger operator++(const BigInteger &input) const;
    BigInteger operator-(const BigInteger &input) const;
    BigInteger operator-=(const BigInteger &input) const;
    BigInteger operator--(const BigInteger &input) const;
    BigInteger operator*(const BigInteger &input) const;
    BigInteger operator*=(const BigInteger &input) const;
    BigInteger operator/(const BigInteger &input) const;
    BigInteger operator/=(const BigInteger &input) const;
    BigInteger operator%(const BigInteger &input) const;
    BigInteger operator%=(const BigInteger &input) const;
};

bool BigInteger::operator==(const BigInteger &input) const{
    if(isNegative != input.isNegative || digits.size() != input.digits.size()) {
        return false;
    }

    return this->digits == input.digits;
}

bool BigInteger::operator< (const BigInteger &input) const{
    while(true) {
        if(isNegative != input.isNegative()) {
            if(isNegative) {
                return true;
            }
            else {
                return false;
            }
        }
        if(digits.size() < input.digits.size()) {
            return true;
        }

        else if(digits.size() > input.digits.size()) {
            return false;
        }
    }
}

bool BigInteger::operator>(const BigInteger &input) const{
    return input < *this;
}

bool BigInteger::operator<=(const BigInteger &input) const {
    return (*this < input) || (*this == input);
}

bool BigInteger::operator>=(const BigInteger &input) const{
    return (input < *this) || (*this == input);
}

bool BigInteger::operator!=(const BigInteger &input) const{
    return !(*this == input);
}

BigInteger BigInteger::operator+(const BigInteger &input) const{
    std::string result = "";
    int carry = 0;

    int maxsize = std::max(digits.size(), input.digits.size());
    for(int i=0;i<maxsize;++i) {
        int sum = 0;
        int thisvalue = i < digits.size() ? digits[i] : 0;
        int inputvalue = i < input.digits.size() ? input.digits[i] : 0;

        sum = thisvalue + inputvalue;
        result.push_back(sum % 10 + carry);
        carry = sum / 10;
    }

    return result;
}

BigInteger BigInteger::operator+=(const BigInteger &input) const {
    return *this + input;
}

BigInteger BigInteger::operator++(const BigInteger &input = "1") const {
    return *this + input;
}

BigInteger BigInteger::operator-(const BigInteger &input) const{
    std::string result = "";
    int carry = 0;

    int maxsize = std::max(digits.size(), input.digits.size());
    for(int i=0;i<maxsize;++i) {
        int sum = 0;
        int thisvalue = i < digits.size() ? digits[i] : 0;
        int inputvalue = i < input.digits.size() ? input.digits[i] : 0;

        sum = thisvalue - inputvalue;

        if(sum < 0) {
            sum += 10;
        }

        result.push_back(sum + carry);
    }

    return result;
}

BigInteger BigInteger::operator-=(const BigInteger &input) const {
    return *this - input;
}

BigInteger BigInteger::operator--(const BigInteger &input = "1") const {
    return *this - input;
}

BigInteger BigInteger::operator*(const BigInteger &input) const{
    std::string result = "";

    for(int i=0;i<this->digits.size();++i) {
        for(int j=0;j<input.digits.size();++j) {
            result += this->digits[i] + input.digits[j];
        }
    }

    return result;
}

BigInteger BigInteger::operator*=(const BigInteger &input) const {
    return *this * input;
}

BigInteger BigInteger::operator/(const BigInteger &input) const{
    BigInteger result("");

    while(*this > input) {
        *this -= input;
        result +=
    }


}

BigInteger BigInteger::operator/=(const BigInteger &input) const {
    return *this / input;
}

BigInteger BigInteger::operator%(const BigInteger &input) const{
    std::string result = "";

    BigInteger quotient("");
}

BigInteger BigInteger::operator%=(const BigInteger &input) const {
    return *this % input;
}

#endif //BIGINTEGER_H
