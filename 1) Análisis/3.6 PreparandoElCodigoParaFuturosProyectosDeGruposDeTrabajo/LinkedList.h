template <typename T> struct NODE {
    T m_data;
    struct NODE<T>* m_pNext;
    static long id;
    NODE() : m_data(0), m_pNext(NULL) {}
};

template <typename T> class CLinkedList {
private:
    NODE<T>* m_pRoot;
public:
    // More methods go here
};

template <typename T> long NODE<T>::id = 0;
