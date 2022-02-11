#pragma once






template<typename Key, typename Value>
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
    struct Item
    {
        Key itemKey;
        Value itemValue;
    };

    Item<typename Key, typename Value>* m_items = nullptr;
    int m_count = 0;

    
};

template<typename Key, typename Value>
inline Dictionary<Key, Value>::Dictionary()
{
}

template<typename Key, typename Value>
inline Dictionary<Key, Value>::Dictionary(const Dictionary<typename Key, typename Value>& other)
{
}

template<typename Key, typename Value>
inline Dictionary<Key, Value>::~Dictionary()
{
}

template<typename Key, typename Value>
inline void Dictionary<Key, Value>::clear()
{
}

template<typename Key, typename Value>
inline bool const Dictionary<Key, Value>::containtsKey(const typename Key object)
{
    return;
}

template<typename Key, typename Value>
inline bool const Dictionary<Key, Value>::containsValue(const typename Value object)
{
    return;
}

template<typename Key, typename Value>
inline bool const Dictionary<Key, Value>::tryGetValue(const typename Key key, const typename Value& value)
{
    return;
}

template<typename Key, typename Value>
inline void Dictionary<Key, Value>::addItem(const typename Key key, const typename Value& value)
{
}

template<typename Key, typename Value>
inline bool Dictionary<Key, Value>::remove(const typename Key key)
{
    return false;
}

template<typename Key, typename Value>
inline bool Dictionary<Key, Value>::remove(const typename Key key, typename Value& value)
{
    return false;
}

template<typename Key, typename Value>
inline int const Dictionary<Key, Value>::getCount()
{
    return;
}

template<typename Key, typename Value>
inline const Dictionary<typename Key, typename Value>& Dictionary<Key, Value>::operator=(const Dictionary<typename Key, typename Value> other)
{
    // TODO: insert return statement here
}
