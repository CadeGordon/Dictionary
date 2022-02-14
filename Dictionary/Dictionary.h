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
    public:
        Key itemKey;
        Value itemValue;
    };

    Item* m_items = nullptr;
    int m_count = 0;

    
};

template<typename Key, typename Value>
inline Dictionary<Key, Value>::Dictionary()
{
    m_items = nullptr;
    m_count = 0;
}

template<typename Key, typename Value>
inline Dictionary<Key, Value>::Dictionary(const Dictionary<typename Key, typename Value>& other)
{
    m_items = other.m_items;
    m_count = other.m_count;
}

template<typename Key, typename Value>
inline Dictionary<Key, Value>::~Dictionary()
{
}

template<typename Key, typename Value>
inline void Dictionary<Key, Value>::clear()
{
    delete m_items;
    m_count = 0;
}

template<typename Key, typename Value>
inline bool const Dictionary<Key, Value>::containtsKey(const typename Key object)
{
    for (int i = 0; i < getCount(); i++)
    {
        if (m_items[i].itemKey == object)
            return true;
    }
    return false;
}

template<typename Key, typename Value>
inline bool const Dictionary<Key, Value>::containsValue(const typename Value object)
{
    for (int i = 0; i < getCount(); i++)
    {
        if (m_items[i].itemValue == object)
            return true;
    }
    return false;
}

template<typename Key, typename Value>
inline bool const Dictionary<Key, Value>::tryGetValue(const typename Key key, const typename Value& value)
{
    for (int i = 0; i < getCount(); i++)
    {
        if (m_items[i].itemKey == key)
        {
          
           
            return true;
        }
            
    }
    return false;
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
