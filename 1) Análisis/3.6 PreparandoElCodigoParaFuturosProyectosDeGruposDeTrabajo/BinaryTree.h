template <typename T> class CBinaryTree {
private:
    struct NODE {
        T m_data;
        struct NODE* m_pLeft, * m_pRight;
    };
    NODE* m_pRoot;
public:
    // More methods go here
};
