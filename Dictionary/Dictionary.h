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
    bool const tryGetValue(const TKey key, TValue& value);
    void addItem(const TKey key, const TValue& value);
    bool remove(const TKey key);
    bool remove(const TKey key, TValue& value);
    int const getCount();
    const Dictionary<TKey, TValue>& operator =(Dictionary<TKey, TValue>& other);
    TValue operator [](const TKey key);

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
inline bool const Dictionary<TKey, TValue>::tryGetValue(const TKey key, TValue& value)
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
    if (containtsKey(key))
    {
        return;
    }

    Item* tempArray = new Item[getCount() + 1];

    for (int i = 0; i < getCount(); i++)
    {
        tempArray[i].itemKey = m_items[i].itemKey;
        tempArray[i].itemValue = m_items[i].itemValue;
    }

    tempArray[getCount()].itemKey = key;
    tempArray[getCount()].itemValue = value;

    delete[] m_items;
    m_items = tempArray;
    m_count++;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key)
{
    if (!containtsKey(key))
    {
        return false;
    }

    Item* tempArray = new Item[getCount() - 1];

    for (int i = 0; i < getCount() - 1; i++)
    {
        if (m_items[i].itemKey != key)
        {
            tempArray[i] = m_items[i];
        }
    }

    delete[] m_items;
    m_items = tempArray;
    m_count--;
    return true;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key, TValue& value)
{
    if (!containtsKey(key))
    {
        return false;
    }

    Item* tempArray = new Item[getCount() - 1];

    for (int i = 0; i < getCount() - 1; i++)
    {
        if (m_items[i].itemKey != key)
        {
            tempArray[i] = m_items[i];
        }
        else
        {
            value = m_items[i].itemValue;
        }
    }

    delete[] m_items;
    m_items = tempArray;
    m_count--;
    return true;
}

template<typename TKey, typename TValue>
inline int const Dictionary<TKey, TValue>::getCount()
{
    return m_count;
}

template<typename TKey, typename TValue>
inline const Dictionary<TKey, TValue>& Dictionary<TKey, TValue>::operator=(Dictionary<TKey, TValue>& other)
{
    clear();

    for (int i = 0; i < other.getCount(); i++)
    {
        addItem(other.m_items[i].itemKey, other.m_items[i].itemValue);
    }

    m_count = other.getCount();

    return *this;
}

template<typename TKey, typename TValue>
inline TValue Dictionary<TKey, TValue>::operator[](const TKey key)
{
    for (int i = 0; i < getCount(); i++)
    {
        if (m_items[i].itemKey == key)
        {
            return m_items[i].itemValue;
        }
    }
 
    return TValue();
}
