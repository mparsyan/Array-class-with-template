#ifndef __ARR_CLASS_TEMP__
#define __ARR_CLASS_TEMP__

template <typename T>
class Array
{

private:
    unsigned int m_size = 0;
    T *arr;

public:
    Array();
    Array(unsigned int);
    unsigned int size();
    T &operator[](unsigned int);
    Array &operator=(const Array<T> &);
    bool operator==(const Array<T> &);

    Array(const Array &) = delete;
    Array(Array &&) = delete;
    Array &operator=(Array &&) = delete;
};

template <typename T>
Array<T>::Array() : m_size{0}, arr{nullptr} {}

template <typename T>
Array<T>::Array(unsigned int n) : m_size{n}
{
    arr = new T[m_size]{0};
}

template <typename T>
unsigned int Array<T>::size()
{
    return m_size;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index < 0 || index >= m_size)
    {
        std::cout << "Please enter the valid size of array!\n";
    }
    return arr[index];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
    if (*this == other)
    {
        return *this;
    }
    delete[] arr;
    m_size = other.m_size;
    if (m_size != 0)
    {
        arr = new int[m_size];
        for (unsigned int i = 0; i < m_size; i++)
        {
            arr[i] = other.arr[i];
        }
    }
    else
    {
        arr = nullptr;
    }
    return *this;
}

template <typename T>
bool Array<T>::operator==(const Array<T> &other)
{
    if (this->arr == other.arr)
    {
        return true;
    }
    if (this->m_size != other.m_size)
    {
        return false;
    }
    for (unsigned int i = 0; i < m_size; i++)
    {
        if (arr[i] != other.arr[i])
        {
            return false;
        }
    }
    return true;
}
#endif // __ARR_CLASS_TEMP__