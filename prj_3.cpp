#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include <algorithm>

using namespace std;

struct People
{
  string name;
  int age;

  People(string n, int a) : name(n), age(a){}

  void Dump() const { cout << name << "(" << age <<")" <<endl; }
};

bool cmp_name(const shared_ptr<People>& a1, const shared_ptr<People>&  a2)
{
  return a1->name < a2->name;
}

bool cmp_age(const shared_ptr<People>& a1, const shared_ptr<People>&  a2)
{

  return a1->age < a2->age;
}


int main()
{
  vector<shared_ptr<People>> v;

  v.push_back(make_shared<People>("kim", 10));
  v.push_back(make_shared<People>("lee", 15));
  v.push_back(make_shared<People>("park", 5));
  v.push_back(make_shared<People>("jung", 20));
  v.push_back(make_shared<People>("choi", 12));

// 이름순 정렬
  cout << "Sort with Name"<<endl;
  sort(v.begin(), v.end(), cmp_name);

  for (auto n : v)
    n->Dump();

// 나이순 정렬
  cout <<endl;
  cout << "Sort with Age"<<endl;
  sort(v.begin(), v.end(), cmp_age);

  for (auto n : v)
    n->Dump();
}
