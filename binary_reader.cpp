#include<iostream>
#include<fstream>
#include <cstring>
#include<iomanip>
#include<sstream>
using namespace std;

string ToHex(const string& s, bool upper_case)
{
    ostringstream ret;

    for (string::size_type i = 0; i < s.length(); ++i)
    {
        int z = s[i]&0xff;
        ret << std::hex << std::setfill('0') << std::setw(2) << (upper_case ? std::uppercase : std::nouppercase) << z;
    }
    return ret.str();
}

void read_word(istream& is, int8_t& value)
{
    int i=0;
    char buf[sizeof(int8_t)];
    
    for(i = 0; i< 100; ++i)
    {
        is.read(buf, sizeof(buf));
        
        memcpy(&value, buf, sizeof(value));
        string str1 = ToHex(buf, true);
        cout<<str1<<" ";
        is.read(buf, sizeof(buf));
    
        memcpy(&value, buf, sizeof(value));
        string str2 = ToHex(buf, true);
        cout<<str2<<" ";
    }
}
int main(int argc, char ** argv){
    ifstream ifs(argv[1], ios::binary);
    int8_t a;
    read_word(ifs, a);
    return 0;
    
}
