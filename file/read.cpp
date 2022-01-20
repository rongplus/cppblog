#include <iostream>
#include <fstream> 
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

const string g_file_path2 = R"(c:\data\)";
const string g_file_path1 = R"(C:\Users\metar\Downloads\)";
const string g_file_path = g_file_path2;
const int g_total = 28;


void test()
{
    ifstream ff(g_file_path + "5000_total.txt");
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
    ofstream ffin(g_file_path+"total--1.txt");
    while( getline(ff,line))
    {
        if (line.length() !=109)
            ffin << line.length() << endl;
        line = "";
    }
    ffin.close();

}

void deal(int n)
{
     ifstream ff(g_file_path+ "5000_" +to_string(n) + ".txt");
        if (ff.is_open() == false)
        {
            std::cout << "file error - " << n << std::endl;
            return;
        }
    const int total = 100;
    unordered_set<string> uset[total];
     string line;
     int index = 0;

     while( getline(ff,line))
     {
         uset[index++].emplace(line);
         if(index==total)
             index=0;
     }

     ofstream ffin(g_file_path+"5000_result_" +to_string(n) + ".txt");

      for (auto &it: uset)
       {
            for(auto &s: it)
            {
                ffin << s << endl;
            }
           // uset[n].swap( unordered_set<string> ());
        }

        ffin.close();
}


int split()
{
    const int total = g_total;
//    for(int n=0; n< total; ++n)
//     {
//        deal(n);
//        cout << "done file " << n << endl;
//     }

//     return 0;

    ifstream ff(g_file_path + "5000.txt");
    if (ff.is_open() == false)
    {
        std::cout << "file error" << std::endl;
        return 0;
    }
    string line;
    
    unordered_set<string> uset[total];
    size_t nfile=0;
    size_t index=0;
   
    ofstream ffout[total];
    vector<ofstream> out_list;
    for(int n=0; n< total; ++n)
    {
        out_list.push_back( ofstream (g_file_path+"5000_" +to_string(n) + ".txt"));
    }   
    while( getline(ff,line))
    {
        if (line.length() < 50)
            continue;
      out_list[index++] << line << endl;
        if(index>=total)
            index=0;
        
    }

    cout << "Done read" << endl;

    for( auto &it: out_list)
    {
        it.close();
    }
    ff.close();
    return 0;
}
int main()
{
    split();
  
    for(int n=0; n< g_total; ++n)
    {
       deal(n);
       cout << "done file " << n << endl;
    }
    
    std::cout << "done - remove short" << std::endl;



    return 0;
}