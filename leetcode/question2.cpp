#include <iostream>
#include <istream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>

using namespace std;
class Solution {
public:
  int lengthLongestPath(string input) {
    stringstream ss(input);
    string line;
    stack<string> q;
    int numofTab = 0;
    if (count(input.begin(), input.end(), '.') == 0)
      return 0;
    getline(ss, line, '\n');
    if (line == input) {
      if (count(line.begin(), line.end(), '.') != 0)
        return line.length();
      return 0;
    }
    q.push(line);
    size_t maxLen = line.length();
    size_t curLen = maxLen;
    while (getline(ss, line, '\n')) {

      // cout << line << endl;
      int n = std::count(line.begin(), line.end(), '\t');
      line = line.substr(n);
      if (numofTab + 1 == n) { // next
        q.push(line);
        numofTab++;
        curLen += line.length();
        cout << __LINE__ << "numofTab=" << numofTab << " curLen=" << curLen
             << "; line:" << line << endl;
      } else if (numofTab == n) { // same
        auto s = q.top();
        if (curLen + numofTab > maxLen && line.find('.') != std::string::npos)
          maxLen = curLen + numofTab;

        q.pop();
        curLen -= s.length();

        q.push(line);
        curLen += line.length();

        cout << __LINE__ << "numofTab=" << numofTab << " curLen=" << curLen
             << "line:" << line << endl;
      } else { // back
        if (curLen + numofTab > maxLen && line.find('.') != std::string::npos)
          maxLen = curLen + numofTab;

        for (int m = 0; m <= numofTab - n; ++m) {
          auto s = q.top();
          q.pop();
          curLen -= s.length();
          cout << "pop - " << s << endl;
        }
        numofTab = n;
        // while (n <= numofTab) {
        //   // get all len
        //   --numofTab;
        //   auto s = q.top();
        //   q.pop();
        //   curLen -= s.length();
        //   cout << "pop - " << s << endl;
        // }
        cout << __LINE__ << "numofTab=" << numofTab << " curLen=" << curLen
             << endl;
        q.push(line);

        curLen += line.length();
        //++numofTab;
        cout << "push - " << line << ";curLen=" << curLen << endl;
      }
    }

    cout << "final = " << curLen << "tab:" << numofTab << "max:" << maxLen
         << endl;
    if (line.find('.') != std::string::npos)
      return maxLen > curLen + numofTab ? maxLen : curLen + numofTab;
    return maxLen;
  }
};

int main() {
  Solution sl;
  string s = "dir\n\tsubdir1\n\t\tfile1."
             "ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
  s = "a\n\tb1\n\t\tf1.txt\n\taaaaa\n\t\tf2.txt";
  s = "rzzmf\n\taaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa."
      "txt\nv\n\tix\n\t\tiklav\n\t\t\ttqse\n\t\t\t\ttppzf\n\t\t\t\t\tzav\n\t\t"
      "\t\t\t\tkktei\n\t\t\t\t\t\t\thhmav\n\t\t\t\t\t\t\t\tbzvwf.txt";

  s = "sladjf\n\tlkjlkv\n\t\tlkjlakjlert\n\t\t\tlaskjglaksjf\n\t\t\t\tlakjgfljr"
      "t"
      "lj\n\t\t\t\t\tlskajflakjsvlj\n\t\t\t\t\t\tlskgjflkjrtlrjt\n\t\t\t\t\t\t"
      "\t"
      "lkjglkjlvkjdlvkj\n\t\t\t\t\t\t\t\tlfjkglkjfljdlv\n\t\t\t\t\t\t\t\t\tlkdf"
      "j"
      "glerjtkrjkljsd."
      "lkvjlkajlfk\n\t\t\t\t\t\t\tlskfjlksjljslvjxjlvkzjljajoiwjejlskjslfj."
      "slkjflskjldfkjoietruioskljfkljf\n\t\t\t\t\tlkasjfljsaljlxkcjzljvl."
      "asljlksaj\n\t\t\t\tasldjflksajf\n\t\t\t\talskjflkasjlvkja\n\t\t\t\twioeu"
      "o"
      "iwutrljsgfjlskfg\n\t\t\t\taslkjvlksjvlkjsflgj\n\t\t\t\t\tlkvnlksfgk."
      "salfkjaslfjskljfv\n\t\t\tlksdjflsajlkfj\n\t\t\tlasjflaskjlk\n\t\tlsakjfl"
      "k"
      "asjfkljas\n\t\tlskjvljvlkjlsjfkgljfg\n\tsaljkglksajvlkjvkljlkjvksdj\n\tl"
      "s"
      "akjglksajkvjlkjdklvj\n\tlskjflksjglkdjbkljdbkjslkj\n\t\tlkjglkfjkljsdflj"
      "\n\t\t\tlskjfglkjdfgkljsdflj\n\t\t\t\tlkfjglksdjlkjbsdlkjbk\n\t\t\t\t\tl"
      "k"
      "fgjlejrtljkljsdflgjl\n\t\t\t\t\tsalgkfjlksfjgkljsgfjl\n\t\t\t\t\tsalkfla"
      "j"
      "woieu\n\t\t\t\t\t\tlaskjfglsjfgljkkvjsdlkjbklds\n\t\t\t\t\t\t\tlasjglrio"
      "t"
      "uojgkjsldfgjsklfgjl\n\t\t\t\t\t\t\t\tlkajglkjskljsdljblkdfjblfjlbjs\n\t"
      "\t"
      "\t\t\t\t\t\t\tlkajgljroituksfglkjslkjgoi\n\t\t\t\t\t\t\t\t\t\tlkjglkjklj"
      "k"
      "ljdkbljsdfljgklfdj\n\t\t\t\t\t\t\t\t\t\t\tlkjlgkjljgslkdkldjblkj\n\t\t\t"
      "\t\t\t\t\t\t\t\t\tlkjfglkjlkjbsdklj."
      "slgfjalksjglkfjglf\n\t\t\t\t\t\t\t\t\t\t\t\tlkasjrlkjwlrjljsl\n\t\t\t\t"
      "\t"
      "\t\t\t\t\t\t\t\tlksjgflkjfklgjljbljls\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tlkjsg"
      "l"
      "kjlkjfkljdklbjkldf\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tlkjglkjdlsfjdglsdjgjlx"
      "l"
      "jjlrjsgjsjlk\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tlkjsgkllksjfgjljdslfkjlkas"
      "j"
      "dflkjxcljvlkjsgkljsfg\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tlaskjlkjsakljgl"
      "s"
      "djfgksdjlkgjdlskjb\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tlkajsgfljfklgjlk"
      "d"
      "jgfklsdjklj\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tlkjfglkjlkgjlkjl."
      "aslkjflasjlajglkjaf\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tlkjasflgjlskj"
      "g"
      "lkfjgklgsdjflkbjsdklfjskldfjgklsfdjgklfdjgl\n\tlskadjlkjsldwwwwwfj\n\t\t"
      "l"
      "kjflkasjlfjlkjajslfkjlasjkdlfjlaskjalvwwwwwwwwwwwwwwwkjlsjfglkjalsjgflkj"
      "a"
      "ljlkdsjslbjsljksldjlsjdlkjljvblkjlkajfljgasljfkajgfljfjgldjblkjsdljgsldj"
      "g"
      ".skljf";
  cout << sl.lengthLongestPath(s) << endl;
}