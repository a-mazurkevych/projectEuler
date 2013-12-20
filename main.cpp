#include <QCoreApplication>
#include <math.h>
#include <iostream>
#include "fstream"
#include <sstream>
#include <vector>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>

int evenFibonacciNumbers(int range)
{
    int res = 0, numFibon = 1, temp = 1;
    do
    {
        int help = numFibon;
        numFibon += temp;
        temp = help;
        if(numFibon % 2 == 0)
            res += numFibon;
    }while(numFibon + temp < range);
    return res;
}

void sieveOfEratosthenes(long long range)
{
    bool *sieve = new bool[(int)sqrt(range) + 1];

    for(long long i = 0; i < (int)sqrt(range); i++)
    {
        sieve[i] = true;
    }

    for(long long i = 2; i * i < (int)sqrt(range) + 1; i++)
    {
        if(sieve[i])
            for(long long j = i * i; j < (int)sqrt(range) + 1; j += i)
                sieve[j] = false;
    }
    delete[] sieve;
}

void largestPrimeFactor(long long range)
{
    bool *sieve = new bool[(int)sqrt(range) + 1];

    for(long long i = 0; i < (int)sqrt(range); i++)
    {
        sieve[i] = true;
    }

    for(long long i = 2; i * i < (int)sqrt(range) + 1; i++)
    {
        if(sieve[i])
            for(long long j = i * i; j < (int)sqrt(range) + 1; j += i)
                sieve[j] = false;
    }

    long long res = 0;
    for(int i = 2; i < (int)sqrt(range); i++)
    {
        if(sieve[i])
        {
            if(range % i == 0)
            {
                res = i;
            }
        }
    }
    delete[] sieve;
    std::cout << res << std::endl;
}

bool isPalindrome(std::string str)
{
    for(int i = 0; i < str.length() / 2; i++)
    {
        if(str[i] != str[str.length() - i - 1])
            return false;
    }
    return true;
}

template <typename T> std::string toStr(T value)
{
    std::ostringstream s;
    s << value;
    return s.str();
}

void largestPalindromeProduct()
{
    int res = 0, temp;
    for(int i = 100; i < 1000; i++)
        for(int j = i; j < 1000; j++)
        {
            if(isPalindrome(toStr(i * j)))
            {
                temp = i * j;
                if(temp > res)
                    res = temp;
            }
        }
    std::cout << res << std::endl;
}

void smallestMultiple(int range)
{
    int res = range;
    bool isSmallest = false;
    while(!isSmallest)
    {
        for(int i = 1; i <= range; i++)
        {
            if(res % i == 0)
                isSmallest = true;
            else
            {
                isSmallest = false;
                res += range;
                break;
            }
        }
    }
    std::cout << res << std::endl;
}

void sumSquareDifference(int range)
{
    int sumSquares = 0, squareSums = 0, res;
    for(int i = 1; i <= range; i++)
    {
        sumSquares += i * i;
        squareSums += i;
    }
    res = squareSums * squareSums - sumSquares;
    std::cout << res << std::endl;
}

void _10001stPrime(long long range)
{
    bool *sieve = new bool[(int)sqrt(range) + 1];

    for(long long i = 0; i < (int)sqrt(range); i++)
    {
        sieve[i] = true;
    }

    for(long long i = 2; i * i < (int)sqrt(range) + 1; i++)
    {
        if(sieve[i])
            for(long long j = i * i; j < (int)sqrt(range) + 1; j += i)
                sieve[j] = false;
    }

    long long res = 0, n = 1;
    for(int i = 2; i < (int)sqrt(range) + 1; i++)
    {
        if(sieve[i])
        {
            if(n == 10001)
            {
                res = i;
                break;
            }
            else
                n++;
        }
    }
    std::cout << res << std::endl;
    delete[] sieve;
}

////std::string data =
////        "73167176531330624919225119674426574742355349194934" +
////        "96983520312774506326239578318016984801869478851843" +
////        "85861560789112949495459501737958331952853208805511" +
////        "12540698747158523863050715693290963295227443043557" +
////        "66896648950445244523161731856403098711121722383113" +
////        "62229893423380308135336276614282806444486645238749" +
////        "30358907296290491560440772390713810515859307960866" +
////        "70172427121883998797908792274921901699720888093776" +
////        "65727333001053367881220235421809751254540594752243" +
////        "52584907711670556013604839586446706324415722155397" +
////        "53697817977846174064955149290862569321978468622482" +
////        "83972241375657056057490261407972968652414535100474" +
////        "82166370484403199890008895243450658541227588666881" +
////        "16427171479924442928230863465674813919123162824586" +
////        "17866458359124566529476545682848912883142607690042" +
////        "24219022671055626321111109370544217506941658960408" +
////        "07198403850962455444362981230987879927244284909188" +
////        "84580156166097919133875499200524063689912560717606" +
////        "05886116467109405077541002256983155200055935729725" +
////        "71636269561882670428252483600823257530420752963450" ;

void largestProductInASeries(std::string data)
{
    int res = 1;
    for(int i = 0; i < data.length() - 5; i++)
    {
        int temp = 1;
        for(int j = i; j < i + 5; j++)
        {
            temp *= (int)(data[j] - '0');
        }
        if(temp > res)
            res = temp;
    }
    std::cout << res << std::endl;
}

void specialPythagoreanTriplet(int range)
{
    int res = 0;
    if(!res)
        for(int a = 1; a < range; a++)
            if(!res)
                for(int b = 1; b < range; b++)
                    if(!res)
                        for(int c = 1; c < range; c++)
                        {
                            if((a + b + c == 1000) && (a * a + b * b == c * c))
                                res = a * b * c;
                        }
    std::cout << res << std::endl;
}

void summationOfPrimes(long long range)
{
    bool *sieve = new bool[(int)sqrt(range) + 1];

    for(long long i = 0; i < (int)sqrt(range); i++)
    {
        sieve[i] = true;
    }

    for(long long i = 2; i * i < (int)sqrt(range) + 1; i++)
    {
        if(sieve[i])
            for(long long j = i * i; j < (int)sqrt(range) + 1; j += i)
                sieve[j] = false;
    }

    long long res = 0;
    for(long long i = 2; i < 92909981; i++)
    {
        if(sieve[i] && i < 2000000)
        {
            res += i;
        }
        if(i > 2000000)
            break;
    }
    std::cout << res << std::endl;

}

void largestProductInaGrid(std::string dataGrid)
{
    int size = 20, res = 0;
    int grid[size][size];
    std::fstream data(dataGrid.c_str());
    if(data)
    {
        for(int i = 0; i < size; i++)
            for(int j = 0; j < size; j++)
                data >> grid[i][j];
    }

    for(int i = 0; i < size - 3; i++)
        for(int j = 0; j < size - 3; j++)
        {
            unsigned int tempIm = 0, temp = 0, tm3 = 1, tm4 = 1;
            for(int n = 0; n < 4; n++)
            {
                unsigned int tm1 = 1, tm2 = 1;
                for(int m = 0; m < 4; m++)
                {
                    tm1 *= grid[i + n][j + m];
                    tm2 *= grid[i + m][j + n];
                }
                temp = (tm1 > tm2) ? tm1 : tm2;
                tm3 *= grid[i + 3 - n][j + n];
                tm4 *= grid[i + n][j + n];
            }
            res = (((res < temp) ? temp : res) < ((tm3 < tm4) ? tm4 : tm3) ? (((tm3 < tm4) ? tm4 : tm3)) : (((res < temp) ? temp : res)));
        }
    std::cout << res << "\n";
}

void highlyDivisibleTriangularNumber()
{
    bool isFind = false;
    long long n = 1;
    while(!isFind)
    {
        int k = 0;
        long long sum = (2 + n - 1) * n / 2;
        for(long long j = 1; j <= (sum + 1) / 2; j++)
        {
            if(sum % j == 0)
            {
                k++;
            }
            if(k + 1 > 500)
            {
                isFind = true;
                break;
            }
        }
        std::cout << n << "\t" << sum << "\t" << k << std::endl;
        n++;
    }
}

void largeSum(std::string pathToData)
{
    boost::multiprecision::cpp_int res = 0;
    std::fstream data(pathToData.c_str());
    while(data)
    {
        boost::multiprecision::cpp_int temp;
        data >> temp;
        res += temp;
    }
    std::cout << res << std::endl;
}

void longestCollatzSequence(int in)
{
    int result = 1, res[in];
    for(int i = 2; i < in; i++)
    {
        long long temp = i, amt = 0;
        while(temp != 1)
        {
            if(temp % 2 == 0)
                temp /= 2;
            else
            {
                temp = temp * 3 + 1;
            }

            amt++;
        }
        res[i] = amt + 1;
        result = (res[result] <= res[i]) ? i : result;
    }
    std::cout << result <<  std::endl;
}

void latticePaths()
{
    const int gridSize = 20;
    long paths = 1;

    for (int i = 0; i < gridSize; i++) {
        paths *= (2 * gridSize) - i;
        paths /= i + 1;
    }
    std::cout << paths << std::endl;
}

void powerDigitSum(int n)
{
    boost::multiprecision::cpp_int temp = 1;
    int sum = 0;
    for(int i = 0; i < n; i++)
        temp *= 2;
    std::stringstream s;
    s << temp;
    std::string sss = s.str();
    for(int i = 0; i < sss.length(); i++)
    {
        sum += (int)sss[i] - '0';
    }
    std::cout << sum << std::endl;
}

/*
 *
 */

std::string checkUp(char symb)
{
    std::string res;
    int num = (int)symb - '0';
    switch(num)
    {
    case 9:
        res += "nine ";
        break;
    case 8:
        res += "eight ";
        break;
    case 7:
        res += "seven ";
        break;
    case 6:
        res += "six ";
        break;
    case 5:
        res += "five ";
        break;
    case 4:
        res += "four ";
        break;
    case 3:
        res += "three ";
        break;
    case 2:
        res += "two ";
        break;
    case 1:
        res += "one ";
        break;
    case 0:
        res += "";
        break;
    }
    return res;
}

std::string checkUpToTwenty(std::string numb)
{
    std::string res;
    int num = atoi(numb.c_str());
    switch(num)
    {
    case 19:
        res += "nineteen ";
        break;
    case 18:
        res += "eighteen ";
        break;
    case 17:
        res += "seventeen ";
        break;
    case 16:
        res += "sixteen ";
        break;
    case 15:
        res += "fifteen ";
        break;
    case 14:
        res += "fourteen ";
        break;
    case 13:
        res += "thirteen ";
        break;
    case 12:
        res += "twelve ";
        break;
    case 11:
        res += "eleven ";
        break;
    case 10:
        res += "ten ";
        break;
    }
    return res;
}

std::string checkUpToHundred(std::string symb)
{
    std::string res;
    if(symb.length() == 2)
    {
        int num = (int)symb[0] - '0';
        switch(num)
        {
        case 9:
            res += "ninety";
            break;
        case 8:
            res += "eighty";
            break;
        case 7:
            res += "seventy";
            break;
        case 6:
            res += "sixty";
            break;
        case 5:
            res += "fifty";
            break;
        case 4:
            res += "forty";
            break;
        case 3:
            res += "thirty";
            break;
        case 2:
            res += "twenty";
            break;
        case 1:
            res += checkUpToTwenty(symb);
            break;
        case 0:
            res += "";
            break;
        }
        if(num != 1)
        {
            if(symb[1] != '0' && symb[0] != '0')
            {
                res += "-" + checkUp(symb[1]);
            }
            else
                res += " " + checkUp(symb[1]);
        }

    }
    return res;
}

void numberLetterCounts()
{
    int res = 0;
    std::string sRes;

    for(int i = 1000; i > 0; i--)
    {
        std::string sTemp = toStr(i);
        if(i == 1000)
        {
            sRes += "one thousand ";
        }
        if(sTemp.length() == 3)
        {
            sRes += checkUp(sTemp[0]) + "hundred ";
            if(sTemp[2] != '0' || sTemp[1] != '0')
                sRes += "and ";
            sRes += checkUpToHundred(sTemp.substr(1, sTemp.size()));
        }
        if(sTemp.length() == 2)
        {
            sRes += checkUpToHundred(sTemp);
        }
        if(sTemp.length() == 1)
        {
            sRes += checkUp(sTemp[0]);
        }
    }
    for(int i = 0; i < sRes.length(); i++)
    {
        if(sRes[i] != ' ' && sRes[i] != '-')
            res++;
    }
    std::cout << res << std::endl;
}

void maximumPathSumI(std::string pathToData)
{
    int size = 100;
    std::fstream data(pathToData.c_str());
    typedef std::vector<int> Set;
    std::vector<Set> trian;

    if(data)
    {
        for(int i = 0; i < size; i++)
        {
            Set set;
            set.clear();
            for(int j = 0; j < i + 1; j++)
            {
                int tm;
                data >> tm;
                set.push_back(tm);
            }
            trian.push_back(set);
        }

    }
    for(int i = size - 2; i >= 0; i--)
    {
        for(int j = 0; j <= i; j++)
        {
            trian[i][j] += (trian[i + 1][j] > trian[i + 1][j + 1]) ? trian[i + 1][j] : trian[i + 1][j + 1];
        }
    }
    std::cout << trian[0][0] << std::endl;
}

enum months {Jan = 31, Feb = 28, Mar = 31, Apr = 30, May, Jun = 30, Jul = 31, Aug = 31, Sep = 30, Oct, Nov, Dec = 31};

void countingSundays()
{
    int days = 0, res = 0;
    for(int i = 1901; i < 2001; i++)
    {
        days += Jan;
        if(days % 7 == 0)
            res++;
        if(!(i % 4) && (i % 400))
        {
            days += Feb + 1;
            if(days % 7 == 0)
                res++;
        }
        else
        {
            days += Feb;
            if(days % 7 == 0)
                res++;
        }
        days += Mar;
        if(days % 7 == 0)
            res++;
        days += Apr;
        if(days % 7 == 0)
            res++;
        days += May;
        if(days % 7 == 0)
            res++;
        days += Jun;
        if(days % 7 == 0)
            res++;
        days += Jul;
        if(days % 7 == 0)
            res++;
        days += Aug;
        if(days % 7 == 0)
            res++;
        days += Sep;
        if(days % 7 == 0)
            res++;
        days += Oct;
        if(days % 7 == 0)
            res++;
        days += Nov;
        if(days % 7 == 0)
            res++;
        days += Dec;
        if(days % 7 == 0)
            res++;
    }
    std::cout << res + 1 << std::endl;
}

void factorialDigitSum(int value)
{
    boost::multiprecision::cpp_int res = 1;
    for(int i = 1; i <= value; i++)
        res *= i;
    std::stringstream s;
    s << res;
    std::string str = s.str();
    res = 0;
    for(int i = 0; i < str.length(); i++)
        res += (int)(str[i] - '0');
    std::cout << res << std::endl;
}

// Problem 21

int sumOfProperDivisors(int value)
{
    int sum = 0;
    for(int i = 1; i < value / 2 + 1; i++)
    {
        if(value % i == 0)
            sum += i;
    }
    return sum;
}

bool isAmicable(int a)
{
    int b = sumOfProperDivisors(a);
    if(b < 10000 && a == sumOfProperDivisors(b) && a != b)
        return true;
    return false;
}

void amicableNumbers()
{
    int res = 0;
    for(int i = 0; i < 10000; i++)
    {
        if(isAmicable(i))
            res += i;
    }
    std::cout << res << std::endl;
}

// Problem 22
bool readNames(std::vector<std::string> &names, std::string path)
{
    std::fstream file(path.c_str());
    if(file)
    {
        std::string data;
        file >> data;
        for(int i = 0; i < data.length(); i++)
        {
            if(data[i] == '"' || data[i] == ',')
                data[i] = ' ';

        }
        std::stringstream stream(data);
        while(stream)
        {
            std::string name;
            stream >> name;
            names.push_back(name);
        }
        std::sort(names.begin(), names.end());
        return true;
    }
    else
        return false;
}

int getNameScore(std::string name)
{
    int score = 0;
    for(int i = 0; i < name.length(); i++)
        score += (int)(name[i] - '@');
    return score;
}

void namesScores(std::string pathToData)
{
    std::vector<std::string> names;
    readNames(names, pathToData);
    int res = 0;
    for(int i = 1; i < names.size(); i++)
        res += getNameScore(names[i]) * i;
    std::cout << res << std::endl;
}

// Problrm 23
bool isAbundant(int value)
{
    return (sumOfProperDivisors(value) > value) ? true : false;
}

bool isSumOfTwoAbundant(int value)
{
    for(int i = 1; i < (value) / 2 + 1; i++)
    {
        if(isAbundant(i))
            if(isAbundant(value - i))
            {
                return true;
                break;
            }
    }
    return false;
}

void non_abundantSums(int edge)
{
    int res = 0;
    for(int i = 1; i < edge + 1; i++)
    {
        std::cout << i << std::endl;
        if(!isSumOfTwoAbundant(i))
            res += i;
    }
    std::cout << res << std::endl;
}

// Problem 24

int factorial(int n)
{
    if(n < 0)
        return 0;
    if(n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

void lexicographicPermutations(std::string value)
{
    std::vector<char> set;
    for(int i = 0; i < value.length(); i++)
    {
        set.push_back(value[i]);
    }

    int remain = 1000000;
    std::string res = "";
    for(int i = 1; i < 10; i++)
    {
        int j = remain / factorial(value.length() - i);
        std::cout << remain << std::endl;
        remain -= j * factorial(value.length() - i);
        res += set[j];
        set.erase(set.begin() + j);
        if(!remain)
            break;
    }

    for (int i = 0; i < set.size(); i++)
        res += set[i];

    std::cout << res << std::endl;
}

// Problem 25

void _1000_digitFibonacciNumber()
{
    boost::multiprecision::cpp_int prev = 1, temp = 1;
    int k = 2, lenght;
    while(lenght != 1000)
    {
        boost::multiprecision::cpp_int res = prev + temp;
        prev = temp;
        temp = res;
        ++k;
        std::stringstream stream;
        stream << res;
        lenght = stream.str().length();
    }
    std::cout << k << std::endl;
}

// Problem 26

void reciprocalCycles(int n)
{
    int seqLenght = 0;
    for(int i = 1000; i > 1; i--)
    {
        if(seqLenght >= i)
            break;
        int* foundRemainders = new int[i];
        int value = 1;
        int pos = 0;

        while(foundRemainders[value] == 0 && value != 0)
        {
            foundRemainders[value] = pos;
            value *= 10;
            value %= i;
            pos++;
        }

        if(pos - foundRemainders[value] > seqLenght)
            seqLenght = pos - foundRemainders[value];

        std::cout << seqLenght << "\t" << pos << std::endl;
    }
}

//Problem 27

bool isPrime(int v)
{
    for(int i = 2; i < v / 2 + 1; i++)
        if(v % i == 0)
        {
            return false;
            break;
        }
    return true;
}

void quadraticPrimes()
{
    int res = 1, maxN = 0;
    for(int a = -999; a < 1000; a++)
        for(int b = -999; b < 1000; b++)
        {
            int n = 0;
            while(isPrime(abs(n * n + n * a + b)))
                n++;
            if(n > maxN)
            {
                maxN = n;
                res = a * b;
            }
        }
    std::cout << res << std::endl;
}

//Problem 28

void numberSpiralDiagonals(int range)
{
    int res = 0;
    for(int i = range; i > 1; i = i - 2)
    {
        res += (i * i) + (i * i - (i - 1)) + (i * i - 2 * (i - 1)) + (i * i - 3 * (i - 1));
    }
    res += 1;
    std::cout << res << std::endl;
}

// Problem 29

typedef boost::multiprecision::cpp_int li;

li liPow(li x, li y)
{
    li res = 1;
    for(li i = 0; i < y; i++)
        res *= x;
    return res;
}

void distinctPowers(int range)
{
    std::vector<li> res;
    for(li i = 2; i <= range; i++)
        for(li j = 2; j <= range; j++)
            res.push_back(liPow(i, j));

    std::cout << res.size() << std::endl;

    int n = res.size();
    for(int i = 0; i < res.size(); i++)
    {
        std::cout << i << std::endl;
        li temp = res[i];
        for(int j = i + 1; res.size(); j++)
            if(temp == res[j])
                n--;
    }
    std::cout << n << std::endl;
}

int main(int argc, char *argv[])
{
    distinctPowers(100);
}
