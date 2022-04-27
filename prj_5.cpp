#include <iostream>
#include <map>
#include <functional>
#include <vector>
#include <utility>
#include <algorithm>
#include <tuple>
#include <thread>
#include <string>

#define NEW_THREAD 1

using namespace std;
using namespace placeholders;
using namespace std::string_literals;

using HANDLER = function<void(void*)>;


int compare(const tuple<HANDLER, int, int>& a1, const tuple<HANDLER, int, int>& a2)
{
  return get<1>(a1) > get<1>(a2);
}

void foo(void* p, string name)
{
  cout<<name<<endl;
}

class NotificationCenter
{

  map< string, vector<tuple<HANDLER, int, int>>  > noti_map;

public:
  void Register(string key, HANDLER h, int  pri)
  {
      noti_map[key].push_back(make_tuple(h, pri, 0));
  }

  void Register(string key, HANDLER h, int  pri, int is_thread)
  {
      noti_map[key].push_back(make_tuple(h, pri, is_thread));
  }

  void Notify(string key, void* data)
  {
    vector<tuple<HANDLER, int, int>>& tp = noti_map[key];

    sort(tp.begin(), tp.end(),compare );

    for (auto & n : tp)
    {
      if (get<2>(n))
      {
        cout << "start new thread"<<":";
        thread f1(get<0>(n), data);
        f1.detach();

      }
      else get<0>(n)(data);

    }
  }
};


int main()
{
  NotificationCenter nc;
  nc.Register("TEST_EVENT", bind(&foo, _1, "one"s), 1);
  nc.Register("TEST_EVENT", bind(&foo, _1, "two"s), 2, NEW_THREAD);
  nc.Register("TEST_EVENT", bind(&foo, _1, "three"s), 3);

  nc.Notify("TEST_EVENT", (void*)0);
  getchar();

}
