#pragma once






template<typename TKey, typename TValue>
class Dictionary
{
public:
    Dictionary<TKey, TValue>();
    Dictionary<TKey, TValue>(const Dictionary<TKey, TValue>& other);
    ~Dictionary<TKey, TValue>();
    void clear();
    bool const containtsKey(const TKey object);
    bool const containsValue(const TValue object);
    bool const tryGetValue(const TKey key, const TValue& value);
    void addItem(const TKey key, const TValue& value);
    bool remove(const TKey key);
    bool remove(const TKey key, TValue& value);
    int const getCount();
    const Dictionary<TKey, TValue>& operator =(const Dictionary<TKey, TValue> other);

private:
    struct Item
    {
    public:
        TKey itemKey;
        TValue itemValue;
    };

    Item* m_items = nullptr;
    int m_count = 0;

    
};

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::Dictionary()
{
    m_items = nullptr;
    m_count = 0;
}

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::Dictionary(const Dictionary<TKey, TValue>& other)
{
    m_items = other.m_items;
    m_count = other.m_count;
}

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::~Dictionary()
{
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::clear()
{
    delete m_items;
    m_count = 0;
}

template<typename TKey, typename TValue>
inline bool const Dictionary<TKey, TValue>::containtsKey(const TKey object)
{
    for (int i = 0; i < getCount(); i++)
    {
        if (m_items[i].itemKey == object)
            return true;
    }
    return false;
}

template<typename TKey, typename TValue>
inline bool const Dictionary<TKey, TValue>::containsValue(const TValue object)
{
    for (int i = 0; i < getCount(); i++)
    {
        if (m_items[i].itemValue == object)
            return true;
    }
    return false;
}

template<typename TKey, typename TValue>
inline bool const Dictionary<TKey, TValue>::tryGetValue(const TKey key, const TValue& value)
{
    for (int i = 0; i < getCount(); i++)
    {
        if (m_items[i].itemKey == key)
        {
            value = m_items[i].itemValue;
            return true;
        }
            
    }
    return false;
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::addItem(const TKey key, const TValue& value)
{
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key)
{
    return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key, TValue& value)
{
    return false;
}

template<typename TKey, typename TValue>
inline int const Dictionary<TKey, TValue>::getCount()
{
    return;
}

template<typename TKey, typename TValue>
inline const Dictionary<TKey, TValue>& Dictionary<TKey, TValue>::operator=(const Dictionary<TKey, TValue> other)
{
    // TODO: insert return statement here
}
