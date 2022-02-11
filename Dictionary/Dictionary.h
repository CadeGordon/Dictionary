#pragma once

template<typename T>
class Dictionary
{
public:
    Dictionary<typename Key, typename Value>();
    Dictionary<typename Key, typename Value>(const Dictionary<typename Key, typename Value>& other);
    ~Dictionary<typename Key, typename Value>();
    void clear();
    bool const containtsKey(const typename Key object);
    bool const containsValue(const typename Value object);
    bool const tryGetValue(const typename Key key, const typename Value& value);
    void addItem(const typename Key key, const typename Value& value);
    bool remove(const typename Key key);
    bool remove(const typename Key key, typename Value& value);
    int const getCount();
    const Dictionary<typename Key, typename Value>& operator =(const Dictionary<typename Key, typename Value> other);

private:
    Item<typename Key, typename Value>* m_items = nullptr;
    int m_count = 0;

};

template<typename T>
inline Dictionary<T>::Dictionary()
{
}

template<typename T>
inline Dictionary<T>::Dictionary(const Dictionary<typename Key, typename Value>& other)
{
}

template<typename T>
inline Dictionary<T>::~Dictionary()
{
}

template<typename T>
inline void Dictionary<T>::clear()
{
}

template<typename T>
inline bool const Dictionary<T>::containtsKey(const typename Key object)
{
    return NULL;
}

template<typename T>
inline bool const Dictionary<T>::containsValue(const typename Value object)
{
    return NULL;
}

template<typename T>
inline bool const Dictionary<T>::tryGetValue(const typename Key key, const typename Value& value)
{
    return NULL;
}

template<typename T>
inline void Dictionary<T>::addItem(const typename Key key, const typename Value& value)
{
}

template<typename T>
inline bool Dictionary<T>::remove(const typename Key key)
{
    return false;
}

template<typename T>
inline bool Dictionary<T>::remove(const typename Key key, typename Value& value)
{
    return false;
}

template<typename T>
inline int const Dictionary<T>::getCount()
{
    return NULL;
}

template<typename T>
inline const Dictionary<typename Key, typename Value>& Dictionary<T>::operator=(const Dictionary<typename Key, typename Value> other)
{
    // TODO: insert return statement here
}
