#ifndef SAFE_HASH_TABLE_HPP
#define SAFE_HASH_TABLE_HPP

#include <unordered_map>
#include <shared_mutex>
#include <mutex>

namespace threads {

template <typename K, typename V> 
class SafeHashTable {    

    const V Get(K a_key);
    size_t Count() const; //number of elements in a specific key
    bool Contains(K a_key) const; //checks if the map contains a specific key
    V& operator[](const K a_key);
    void Insert(const K a_key, const V a_value);
    void Erase(const K a_key);

private:
    std::unordered_map<K,V> m_safeHashTable;
    std::shared_mutex m_sharedMutex;
};

#include "inl/safe_hashTable.hxx"

} //threads

#endif //SAFE_HASH_TABLE_HPP