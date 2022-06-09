#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

#include <chrono>
#include <ctime>

using namespace std;

const string g_file_path2 = R"(D:\install_file\)";
const string g_file_path1 = R"(C:\Users\metar\Downloads\)";
const string g_file_path = g_file_path2;
const int g_total = 28;

void test() {
  ifstream ff(g_file_path + "5000_total.txt");
  if (ff.is_open() == false) {
    std::cout << "file error" << std::endl;
    return;
  }
  string line;
  const int total = 1000;
  unordered_set<string> uset[total];
  size_t nfile = 0;
  size_t index = 0;
  ofstream ffin(g_file_path + "total--1.txt");
  while (getline(ff, line)) {
    if (line.length() != 109)
      ffin << line.length() << endl;
    line = "";
  }
  ffin.close();
}

void deal(int n) {
  ifstream ff(g_file_path + "5000_" + to_string(n) + ".txt");
  if (ff.is_open() == false) {
    std::cout << "file error - " << n << std::endl;
    return;
  }
  const int total = 100;
  unordered_set<string> uset[total];
  string line;
  int index = 0;

  while (getline(ff, line)) {
    uset[index++].emplace(line);
    if (index == total)
      index = 0;
  }

  ofstream ffin(g_file_path + "5000_result_" + to_string(n) + ".txt");

  for (auto &it : uset) {
    for (auto &s : it) {
      ffin << s << endl;
    }
    // uset[n].swap( unordered_set<string> ());
  }

  ffin.close();
}
void print_time(string msg) {
  auto start = std::chrono::system_clock::now();
  std::time_t end_time = std::chrono::system_clock::to_time_t(start);
  cout << msg << "--" << std::ctime(&end_time) << endl;
}

int split()
{
  const int total = g_total;

  ifstream ff(g_file_path + "5000.txt");
  if (ff.is_open() == false) {
    std::cout << "file error" << std::endl;
    return;
  }
  string line;

  unordered_set<string> uset[total];
  size_t nfile = 0;
  size_t index = 0;

  ofstream ffout[total];
  vector<ofstream> out_list;
  for (int n = 0; n < total; ++n) {
    out_list.push_back(ofstream(g_file_path + "5000_" + to_string(n) + ".txt"));
  }
  while (getline(ff, line)) {
    if (line.length() < 50)
      continue;
    out_list[index++] << line << endl;
    if (index >= total)
      index = 0;
  }
 for( auto &it: out_list)
    {
        it.close();
    }
    ff.close();
    return 0;
}
int main()
{

  print_time("splite");
  split();
  const int total = 28;

  print_time("deal");
  for (int n = 0; n < total; ++n) {
    deal(n);
    cout << "done file " << n << endl;
  }

  ofstream ffin(g_file_path + "5000_result_" + to_string(10) + ".txt");
  ffin << "ds" << endl;
  ffin.close();

  std::cout << "done - remove short" << std::endl;
  print_time("Done");

  return 0;
}