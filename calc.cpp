//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//#include"doctest.h"
#include<iostream>
#include<string>

double compute(double const n,char const  op,double const  m)
{
    
    if(op=='+')
    {
        return n+m;
    }
    if(op=='*')
    {
        return n*m;
    
    }
    if(op=='-')
    {
        return n-m;
    }
    if(op=='/')
    {
        if(m==0)
        {
            return 0;
        }
        return n/m;
    }
    return 0;
}

int main() {
    std::cout<<"Inserire un'espressione\n";
    std::string ex;
    std::cin>>ex;
    std::cout<<compute(ex.at(0)-'0',ex.at(1),ex.at(2)-'0')<<"/n";
}
/*
TEST_CASE("Testing compute"){
    CHECK(compute(1,'+',1)==2);
    CHECK(compute(2,'*',3)==6);
    CHECK(compute(3,'/',2)==1.5);
    CHECK(compute(3,'/',0)==0);
    CHECK(compute(4,'-',7)==-3);
    CHECK(compute(4,'0',7)==0);
}
*/