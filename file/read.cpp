#include <iostream>
#include <fstream> 
#include <string>
#include <unordered_set>
using namespace std;

void test()
{
    ifstream ff("C:\\Users\\metar\\Downloads\\5000_total.txt");
    if (ff.is_open() == false)
    {
        std::cout << "file error" << std::endl;
        return ;
    }
    string line;
    const int total = 1000;
    unordered_set<string> uset[total];
    size_t nfile=0;
    size_t index=0;
    ofstream ffin("C:\\Users\\metar\\Downloads\\total--1.txt");
    while( getline(ff,line))
    {
        if (line.length() !=109)
            ffin << line.length() << endl;
        line = "";
    }
    ffin.close();

}

int main()
{
   // test();
  //  return 0;
    ifstream ff("C:\\Users\\metar\\Downloads\\5000.txt");
    if (ff.is_open() == false)
    {
        std::cout << "file error" << std::endl;
        return 0;
    }
    string line;
    const int total = 28;
    unordered_set<string> uset[total];
    size_t nfile=0;
    size_t index=0;
    ofstream ffin("C:\\Users\\metar\\Downloads\\5000_total.txt");
    while( getline(ff,line))
    {
        if (line.length() < 50)
            continue;
        uset[index++].emplace(line);
        if(index==total)
            index=0;
      
        if (0)
        {
        //    ofstream ffin("C:\\Users\\metar\\Downloads\\5000_" +to_string(++nfile) + ".txt");
           for (int n=0; n< total; n++)
           {
                for (auto &it: uset[n])
                {
                    ffin << it << endl;
                }
                uset[n].swap( unordered_set<string> ());
           }
       //     ffin.close();
            
            
           

            

        }
       
        //std::cout << line << std::endl;
    }
// ofstream ffin("C:\\Users\\metar\\Downloads\\5000_" +to_string(++index) + ".txt");
// ofstream ffin("C:\\Users\\metar\\Downloads\\5000_" +to_string(++nfile) + ".txt");
           for (int n=0; n< total; n++)
           {
               ofstream ffin("C:\\Users\\metar\\Downloads\\5000_" +to_string(n) + ".txt");
                for (auto &it: uset[n])
                {
                    ffin << it << endl;
                }
                uset[n].swap( unordered_set<string> ());
                 ffin.close();
           }
           
    
std::cout << "done - remove short" << std::endl;



    return 0;
}