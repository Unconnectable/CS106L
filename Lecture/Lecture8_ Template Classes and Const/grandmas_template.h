#define GENERATE_VECTOR(MY_TYPE)                             \
class MY_TYPE##Vector {                                     \
public:                                                     \
    MY_TYPE& at(size_t index);                             \
    void push_back(const MY_TYPE& elem);                   \
                                                           \
private:                                                    \
    MY_TYPE* elems;                                        \
    size_t logical_size;                                   \
};
