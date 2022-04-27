#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<sstream>
#include<fstream>

using namespace std;

int main(int argc, char** argv)
{
  ifstream infile(argv[1]);
  ofstream outfile(argv[2]);

  string s;
  unordered_map<string, int> um;

  while(getline(infile, s))
  {
    istringstream iss(s);

    string word;
    bool flag = false;
    while (iss>>word)
    {
      if (word == "define")
      {
        string key;
        int val;
        iss>>key;
        iss>>val;
        um[key]  = val;

      }
      else if (um.count(word))
      {
        outfile<<um[word];
        flag = true;
      }
      else
      {
        outfile<<word;
        flag = true;
      }

    }
    if (flag) outfile<<"\n";

  }
  return 0;
}
