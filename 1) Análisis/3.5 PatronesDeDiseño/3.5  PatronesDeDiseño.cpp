#include <vector> // without .h
#include <list>
#include <iostream>
using namespace std;

template <typename Container>

void Write(const Container& ds, ostream& os) {
    typename Container::const_iterator iter = ds.begin();
    for (; iter != ds.end(); iter++)
        os << *iter << "\n";
}

int main(int argc, char* argv[]) {
    list<float> mylist;
    vector<float> myvector;
    for (int i = 0; i < 10; i++) {
        mylist.push_back(i);
        myvector.push_back(i + 50);
    }
    Write(mylist, cout);
    Write(myvector, cout);
    return 0;
}