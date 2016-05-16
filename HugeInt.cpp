#include <iostream>
#include <string>
#include <cstdlib>
#define SIZE 10000
using namespace std;
class HugeInt{
    
public:
    HugeInt()
    {
        int i;
        for(i=0;i<SIZE;i++)
        {
            this->num[i] = 0;
        }
    }
    HugeInt(long y)
    {
        int i;
        for(i=0;i<SIZE;i++)
        {
            this->num[i] = 0;
        }
        i = 0;
        while(y)
        {
            this->num[i] = y % 10;
            y /= 10;
            i++;
        }
    }
    HugeInt(string z)
    {
        int i;
        for(i=0;i<SIZE;i++)
        {
            this->num[i] = 0;
        }
        longS = z;
        lenS = longS.length();
        for(i=0;i<lenS;i++)
        {
            num[i]=longS[lenS-i-1] - '0';
        }
    }
    ~HugeInt()
    {
    }
    friend ostream &operator <<(ostream &out, const HugeInt &p)
    {
        int i;
        for(i=SIZE-1;i>=0 && p.num[i] == 0;i--);
        for(i;i>=0;i--)
        {
            out<<p.num[i];
        }
        return out;
    }
    friend istream &operator >>(istream &in, HugeInt &p)
    {
        int i;
        long tmp;
        in >> tmp;
        for(i=0;i<SIZE;i++)
        {
            p.num[i] = 0;
        }
        i=0;
        while(tmp)
        {
            p.num[i] = tmp % 10;
            tmp /= 10;
            i++;
        }
        return in;
    }
    HugeInt operator + (const HugeInt &p)
    {
        int i;
        HugeInt hi;
        for(i=0;i<SIZE;i++)
        {
            hi.num[i] = (this->num[i]) + (p.num[i]);
        }
        for(i=0;i<SIZE;i++)
        {
            hi.num[i+1] += hi.num[i] / 10;
            num[i] %= 10;
        }
        return hi;    
    }
    HugeInt operator - (const HugeInt &p)
    {
        int i;
        HugeInt hi;
        for(i=0;i<SIZE;i++)
        {
            hi.num[i] = (this->num[i]) - (p.num[i]);
        }
        for(i=0;i<SIZE;i++)
        {
            if(hi.num[i] < 0)
            {
                num[i] += 10;
                num[i+1] -= 1;
            }
        }
        return hi;    
    }
private:
    int num[SIZE];
    string longS;
    int lenS;
};

int main() 
{
     HugeInt x; 
     HugeInt y(28825252); 
     HugeInt z("314159265358979323846"); 
     HugeInt result; 
     cin >> x; 
     result = x+y; 
     cout << x << " + " << y << " = " << result << endl; 
     result = z-x; 
     cout << z << " - " << x << " = " << result << endl; 
     //cout << result <<endl;
     return 0; 
}
