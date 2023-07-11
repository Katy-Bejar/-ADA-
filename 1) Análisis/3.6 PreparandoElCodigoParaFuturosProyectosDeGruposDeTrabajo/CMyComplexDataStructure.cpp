#include "CMyComplexDataStructure.h"

void CMyComplexDataStructure::Insert(float fVal) {
    m_container.push_back(fVal);
}

template <typename objclass>
void CMyComplexDataStructure::sumone(objclass funobj) {
    typename std::vector<float>::iterator iter = m_container.begin();
    for (; iter != m_container.end(); iter++)
        funobj(*iter);
}

template <typename objclass>
void funcobjclass<objclass>::operator()(objclass& objinstance) {
    objinstance++;
}
