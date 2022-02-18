#pragma once






template<typename TKey, typename TValue>
class Dictionary
{
public:
    /// <summary>
    /// A basic constructor for a dictionary.
    /// </summary>
    Dictionary<TKey, TValue>();

    /// <summary>
    /// A constructor that makes a copy of an established dictionary.
    /// </summary>
    /// <param name="other"> The dictionary being copied. </param>
    Dictionary<TKey, TValue>(const Dictionary<TKey, TValue>& other);

    /// <summary>
    /// A deconstructor for a dictionary.
    /// </summary>
    ~Dictionary<TKey, TValue>();

    /// <summary>
    /// Deletes all items in the dictionary.
    /// </summary>
    void clear();

    /// <summary>
    /// Checks the dictionary to see if it contains a particular key.
    /// </summary>
    bool const containtsKey(const TKey object);

    /// <summary>
    /// Checks the dictionary to see if it contains a particular value.
    /// </summary>
    bool const containsValue(const TValue object);

    /// <summary>
    /// Attempts to find a value with a given key.
    /// </summary>
    bool const tryGetValue(const TKey key, TValue& value);

    /// <summary>
    /// Attempts to add an item to the dictionary.
    /// </summary>
    /// <param name="key"> The key that will point to the new value. </param>
    /// <param name="value"> The value that the key will point to. </param>
    void addItem(const TKey key, const TValue& value);

    /// <summary>
    /// Attempts to remove an item from the dictionary by using its associated key.
    /// </summary>
    bool remove(const TKey key);

    /// <summary>
    /// Attempts to remove an item that has both the given key and value.
    /// </summary>
    bool remove(const TKey key, TValue& value);

    /// <summary>
    /// Gets the amount of items in the dictionary.
    /// </summary>
    int const getCount();

    /// <summary>
    /// An operator that checks to see if two dictionaries are equal.
    /// </summary>
    const Dictionary<TKey, TValue>& operator =(Dictionary<TKey, TValue>& other);

    /// <summary>
    /// Takes in a key and returns the value of that key if it could be found.
    /// </summary>
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
    // Searches through the list.
    for (int i = 0; i < getCount(); i++)
    {
        // If the key is the same as the object...
        if (m_items[i].itemKey == object)
            return true;
    }
    return false;
}

template<typename TKey, typename TValue>
inline bool const Dictionary<TKey, TValue>::containsValue(const TValue object)
{
    // Searches through the list.
    for (int i = 0; i < getCount(); i++)
    {
        // If the value is the same as the object...
        if (m_items[i].itemValue == object)
            return true;
    }
    return false;
}

template<typename TKey, typename TValue>
inline bool const Dictionary<TKey, TValue>::tryGetValue(const TKey key, TValue& value)
{
    // Searches through the list
    for (int i = 0; i < getCount(); i++)
    {
        // If the value is the same as the object...
        if (m_items[i].itemKey == key)
        {
            // ...sets the value equal to the value associated with the key.
            value = m_items[i].itemValue;
            return true;
        }
    }
    return false;
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::addItem(const TKey key, const TValue& value)
{
    //If the key is already in the dictionary
    if (containtsKey(key))
    {
        //return without adding an item
        return;
    }
    //Create a temporary array with length og one more than the current array
    Item* tempArray = new Item[getCount() + 1];
    //Copy all the value from the array into the new array
    for (int i = 0; i < getCount(); i++)
    {
        tempArray[i].itemKey = m_items[i].itemKey;
        tempArray[i].itemValue = m_items[i].itemValue;
    }
    //Set the last item of the array to the key and value of the item trying to be added
    tempArray[getCount()].itemKey = key;
    tempArray[getCount()].itemValue = value;

    delete[] m_items;
    m_items = tempArray;
    m_count++;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key)
{
    //If the key isn't in the dictionary
    if (!containtsKey(key))
    {
        //return without removing anything
        return false;
    }
    //Create a new item pointer that is one smaller than the current pointer
    Item* tempArray = new Item[getCount() - 1];
    //For the length of the new array
    for (int i = 0; i < getCount() - 1; i++)
    {
        //if the key isn't the one to remove
        if (m_items[i].itemKey != key)
        {
            //copy the values to the new array
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
    //If the key isn't in the dictionary
    if (!containtsKey(key))
    {
        //return without removing anything
        return false;
    }
    //Create a new item pointer that is one smaller than the current pointer
    Item* tempArray = new Item[getCount() - 1];
    //For the length of the new array
    for (int i = 0; i < getCount() - 1; i++)
    {
        //if the key isn't the one to remove
        if (m_items[i].itemKey != key)
        {
            //copy the values to the new array
            tempArray[i] = m_items[i];
        }
        else
        {
            //if not set the value equal to the value of the item being removed
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
    //returns the number of items
    return m_count;
}

template<typename TKey, typename TValue>
inline const Dictionary<TKey, TValue>& Dictionary<TKey, TValue>::operator=(Dictionary<TKey, TValue>& other)
{
    //clears the dictionary
    clear();

    //for the lengtth of the other dictionarys items
    for (int i = 0; i < other.getCount(); i++)
    {
        //copy the items from the other dictionary to the current one
        addItem(other.m_items[i].itemKey, other.m_items[i].itemValue);
    }

    //set the count to the other count
    m_count = other.getCount();

    //return the current dictionary
    return *this;
}

template<typename TKey, typename TValue>
inline TValue Dictionary<TKey, TValue>::operator[](const TKey key)
{
    //For the length of the dictionary
    for (int i = 0; i < getCount(); i++)
    {
        //If the key is found
        if (m_items[i].itemKey == key)
        {
            //return the value associated with it
            return m_items[i].itemValue;
        }
    }
 
    return TValue();
}
