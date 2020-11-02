/*
A program that simulates Fully Associative Cache,
Created by Daronhil Mauricette, March 2019 
*/

public class AssocCache extends Cache {
  
  int csize, lsize;
  int record;
  int noOfLines;
  int tag[];
  boolean valid[];
  Object data[];
  int index;

  public AssocCache (int size, int line_size) {
    csize = size;
    lsize = line_size;
    noOfLines = size / line_size;
    tag = new int[noOfLines];
    valid = new boolean[noOfLines];
    data = new Object[noOfLines];
    index = 0;
  } // Constructor

  // Identifies whether the item at the address is in the cache
  @Override
  public Object cacheSearch(int addr) 
  {  
    for (int i = 0; i < noOfLines; i++)
    {
     // System.out.println("Tag:" + tag[i]);
      //System.out.println("Addr:" + (addr / (lsize % csize)));
      if (tag[i] == (addr / (lsize % csize)) && valid[i] == true)
      {
        record = i;
        return data[i];
      } // If
    } // For
    return null;
  } // CacheSearch

  // Enters a new entry in to the cache
  public oldCacheLineInfo cacheNewEntry(int addr)
  {
    oldCacheLineInfo oldInfo = new oldCacheLineInfo();
    if (index == noOfLines-1)
      index = 0;
    else
      index++;

    tag[index] = addr / (lsize % csize);
    oldInfo.old_valid = valid[index];
    valid[index] = true;
    oldInfo.data = data[index] = new Integer(-1);
    return oldInfo;
  } // CacheNewEntry

  @Override
  public void cacheWriteData(Object newData)
  {
    data[record] = newData;
  } // CacheWriteData

} // AssocCache
