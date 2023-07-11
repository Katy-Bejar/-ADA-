#include <vector>
using namespace std;

class CMyComplexDataStructure {
    vector<float> m_container;
public:
    void Insert(float fVal);
    template <typename objclass>
    void sumone(objclass funobj);
};

template <typename objclass>
class funcobjclass {
public:
    void operator()(objclass& objinstance);
};

#include "CMyComplexDataStructure.cpp"
