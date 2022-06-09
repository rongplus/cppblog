#include <fstream>
#include <iostream>
#include <ratio>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

#include <chrono>
#include <codecvt>
#include <ctime>

using namespace std;

const string g_file_path2 = R"(D:\)";
const string g_file_path1 = R"(C:\Users\metar\Downloads\)";
const string g_file_path = g_file_path2;

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
  ifstream ff(g_file_path + "a" + to_string(n) + ".csv");
  if (ff.is_open() == false) {
    std::cout << "file error - " << n << std::endl;
    return;
  }
  const int total = 100;
  unordered_set<string> uset[total];
  string line;
  int index = 0;

  // ignore the title line
  getline(ff, line);
  int index1, // Zodiac in 1st column
      index2, // Zodiac in 2nd column
      index3, // Zodiac in 3rd column
      index4; // Zodiac in 4th column
  // loop whole file
  while (getline(ff, line)) {
    stringstream ss(line);
    string item;
    getline(ss, item, ','); //期数
    getline(ss, item, ','); //生肖
    getline(ss, item, ','); //逻辑
    // 4 items
    getline(ss, item, ','); // data 1
    cout << "first data= " << item << endl;
    // find theline index of the bigest numer of Chinese Zodiac
    {}
    getline(ss, item, ','); // data 2
    getline(ss, item, ','); // data 3
    getline(ss, item, ','); // data 4
    while (getline(ss, item, ',')) {
      /* code */
    }
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
void split() {
  const int total = 28;

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

  cout << "Done read" << endl;

  for (auto &it : out_list) {
    it.close();
  }
  ff.close();
}
void read_all_lines(const char *filename) {
  wifstream wifs;
  wstring txtline;
  int c = 0;

  wifs.open(filename);
  if (!wifs.is_open()) {
    wcerr << L"Unable to open file" << endl;
    return;
  }
  // We are going to read an UTF-8 file
  wifs.imbue(locale(wifs.getloc(),
                    new codecvt_utf8<wchar_t, 0x10ffff, consume_header>()));
  while (getline(wifs, txtline))
    wcout << txtline << endl;
  wcout << "Dend --" << endl;
}

// int rr() {
//   //读文件
//   ifstream fin("d:\\a0.csv");
//   if (!fin) {
//     cerr << "Error opening input stream" << endl;
//   }
//   char *buffer = (char *)malloc(6);
//   fin.getline(buffer, 6);
//   fin.close();
//   //打印文件中的中文多字符不需要使用setlocate指定编码
//   printf("printf file string :%s\n", buffer);
//   cout << "cout file string :" << buffer << endl;

//   //打印参数中的宽字符，输入参数为"中国人"
//   wchar_t arg[] = "中国人";
//   wprintf(L"wprintf setlocale before: %s\n", arg);
//   //把宽字符转成多字符打印，这种转换方式会多出一些乱码字符
//   int len = wcslen(argv[1]) * 2;
//   char *mbuf = (char *)malloc(len);
//   wcstombs(mbuf, argv[1], len);
//   printf("printf change buffer setlocale before:%s\n", mbuf);

//   //无需调用setlocale也不会乱码
//   int szlen =
//       ::WideCharToMultiByte(CP_ACP, 0, argv[1], -1, NULL, 0, NULL, NULL);
//   char *nbuf = new char[szlen + 1];
//   ::WideCharToMultiByte(CP_ACP, 0, argv[1], -1, nbuf, szlen, NULL, NULL);
//   cout << "no need setlocale way:" << nbuf << endl;
//   printf("printf nbuf:%s\n", nbuf);

//   //必须使用setlocale指定编码,才不会乱
//   setlocale(LC_ALL, "Chinese-simplified");
//   printf("printf change buffer setlocale after:%s\n", mbuf);
//   wprintf(L"setlocale after %s\n", arg);
//   wcout << "wcount buffer " << arg << endl;
//   getchar();
//   return 0;
// }
bool somefunction() {
  wcout << L"单元格";
  return false;
}

void abc() {
  string s1 = "第一";
  wstring s2 = L"第二";
  cout << s1 << endl;
  wcout.imbue(locale("chs"));
  wcout << s2 << endl;
}

int main() {
  setlocale(LC_ALL, "chs");
  somefunction();
  system("chcp 65001");
  abc();
  // std::locale::global(std::locale(""));
  // std::locale loc("");
  // std::wcout.imbue(loc);
  print_time("splite");
  // read_all_lines("d://a0.csv");

  wcout << "这个" << endl;
  const char str[] = "这里全是中文";
  printf_s("testing= 输出字符数:%d\n", printf(str));

  setlocale(LC_ALL, "chs");
  wchar_t wt[] = L"中";
  wcout << wt << endl;

  for (int n = 0; n < 1; ++n) {
    // deal(n);
    cout << "done file " << n << endl;
  }
  ofstream ffin(g_file_path + "5000_result_" + to_string(10) + ".txt");
  ffin << "ds放飞" << endl;
  ffin.close();
  std::cout << "done - remove short" << std::endl;
  print_time("Done");

  return 0;
}