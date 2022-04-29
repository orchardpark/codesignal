/**
 * Tracks the number of duplications to a particular
 * address in the storage system.
 * The first time unique data is written, a new ReferenceCounter instance
 * is created with refs == 1. Then each
 * subsequent duplicate write or delete will increment or decrement refs.
 * When there are no more references to the address (refs = 0),
 * the ReferenceCounter object should be discarded.
 */
class ReferenceCounter {
private:
  /**
   * _addr: integer index into a StorageArray's data_storage.
   * _refs : integer number of duplicate writes to addr.
   */
  int _addr, _refs;
public:
  ReferenceCounter(int addr, int refs) {
    _addr = addr;
    _refs = refs;
  }

  int addr() {
    return _addr;
  }

  int refs() {
    return _refs;
  }

  inline void increment_refs() {
    ++_refs;
  }

  inline void decrement_refs() {
    --_refs;
  }
};

/**
 * Basic implementation of an in-memory storage system
 * represented by an array. A lookaside hashtable tracks the
 * ReferenceCounters for duplicated data within the data_storage.
 * This basic storage system only supports three operations:
 *   - write data to next available address;
 *   - read data from specified address;
 *   - delete data from specified address.
 */
class StorageArray {
private:
  /**
   * data_storage: array of data objects of length 64.
   * alloc_addr_ptr : integer of the last allocated index.
   * dedup_lookaside : hashtable containing ReferenceCounters
                      to track writes of duplicate data.
   */
  std::vector<std::string> data_storage;
  int alloc_addr_ptr;
  std::unordered_map<std::string, ReferenceCounter> dedup_lookaside;

  /**
   * Internal method that grabs the next available free
   * address in the data_storage (i.e., address that does
   * not point to data with a corresponding ReferenceCounter
   * entry in the dedup_lookaside).
   *
   * @return Integer addr to use for the next write operation
   *         or -1 if no free addr is available.
   */
  int _alloc_addr() {
    int start_alloc_addr_ptr = alloc_addr_ptr;
    while (true) {
      auto ref_counter = dedup_lookaside.find(data_storage[alloc_addr_ptr]);
      if (ref_counter == dedup_lookaside.end() || ref_counter->second.addr() != alloc_addr_ptr) {
        break;
      }
      alloc_addr_ptr = (alloc_addr_ptr + 1) % data_storage.size();
      if (alloc_addr_ptr == start_alloc_addr_ptr) {
        // No free address available
        return -1;
      }
    }
    return alloc_addr_ptr;
  }
public:
  StorageArray() {
    data_storage.assign(64, "");
    alloc_addr_ptr = 0;
  }

  /**
   * Takes in a data object and stores it in the data_storage.
   * If the data duplicates to existing data, write() increments
   * the reference count instead of allocating a new address. If
   * the data is unique(i.e., does not have a corresponding
   * ReferenceCounter entry in the dedup_lookaside), but there
   * are not any available addresses, return -1 to signify the
   * write failed.
   *
   * @param data string to store in the data_storage or record duplicate of.
   * @return integer addr where the data is stored
   *         or -1 if space was required but not available.
   */
  int write(std::string data) {
    if(dedup_lookaside.find(data)==dedup_lookaside.end()){
      auto newAddr = _alloc_addr();
      if(newAddr!=-1){
        dedup_lookaside.insert(make_pair(data,ReferenceCounter(newAddr, 1)));
        data_storage[newAddr]=data;
      }
      return newAddr;
    }
    else{
      dedup_lookaside.at(data).increment_refs();
      return dedup_lookaside.at(data).addr();
      
    }
  }

  /**
   * Takes in an integer address and retrieves the data at the
   * location in the data_storage, only if there are still
   * references to the data. If there are no references(i.e.,
   * does not point to data with a corresponding ReferenceCounter
   * entry in the dedup_lookaside), then return "None" to
   * signify the address is unused or the data has been deleted.
   *
   * @param addr Integer address where the data is stored
   * @return object retrieved from data_storage at addr
   *         or "None" if there are no references on the data at the address.
   */
  std::string read(int addr) {
    if(addr<0 || addr>=data_storage.size()) return "None";
    else if(dedup_lookaside.find(data_storage[addr])==dedup_lookaside.end()){
      return "None";
    }
    else if(dedup_lookaside.at(data_storage[addr]).addr() != addr){
      return "None";
    }
    else{
      return data_storage[addr];
    }
  }

  /**
   * Takes in an integer address and deletes the data at the
   * location in the data_storage by decrementing the reference
   * count of the data's corresponding ReferenceCounter in the
   * dedup_lookaside. If the delete would decrement the count to
   * 0, remove the ReferenceCounter from the dedup_lookaside.
   *
   * @param addr Integer address where the data is stored
   * @return data stored in the address or "None" if there isn't any
   */
  std::string del(int addr) {
    if(addr<0 || addr>=data_storage.size()) return "None";
    else if(dedup_lookaside.find(data_storage[addr])==dedup_lookaside.end()){
      return "None";
    }
    else if(dedup_lookaside.at(data_storage[addr]).addr() != addr){
      return "None";
    }
    else{
      dedup_lookaside.at(data_storage[addr]).decrement_refs();
      if(dedup_lookaside.at(data_storage[addr]).refs()<=0){
        dedup_lookaside.erase(dedup_lookaside.find(data_storage[addr]));
      }
      return data_storage[addr];
    }
  }
};

std::vector<std::string> solution(std::vector<std::string> operations) {
  std::vector<std::string> ans;
  StorageArray dataStorage;
  for (auto operation : operations) {
    if (operation[0] == 'R') { // READ
      ans.push_back(dataStorage.read(stoi(operation.substr(5))));
    } else if (operation[0] == 'W') { // WRITE
      int addr = dataStorage.write(operation.substr(6));
      if (addr == -1) {
        ans.push_back("None");
      } else {
        ans.push_back(to_string(addr));
      }
    } else if (operation[0] == 'D') { // DELETE
      ans.push_back(dataStorage.del(stoi(operation.substr(7))));
    }
  }
  return ans;
}

