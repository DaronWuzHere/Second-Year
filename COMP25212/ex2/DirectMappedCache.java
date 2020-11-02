/* 
Program that simulates direct mapped cache.
Created by Daronhil Mauricette, February 2019
*/

public class DirectMappedCache extends Cache {
  
  int csize, lsize;
  int record;
  int noOfLines;
  int tag[];
  boolean valid[];
  Object data[];

  public DirectMappedCache(int size, int line_size) 
  { 
    csize = size;
    lsize = line_size;
    noOfLines = csize/lsize;
    tag = new int[noOfLines];
    valid = new boolean[noOfLines];
    data = new Object[noOfLines];
  } // Constructor
  
  
  
  // Identifies whether the item at the address is in the cache
  @Override
  public Object cacheSearch(int addr) 
  {  
    int point = addr % (csize / lsize);
    point = point % noOfLines;
    if ((tag[point] == (addr / (lsize % csize))) && (valid[point] == true))
    {
      record = point;
      return data[point];
    }
    return null;
  } // CacheSearch

  // Returns the value of the previuos value of he valid bit aswell as updating 
  // the cache line
  @Override
  public oldCacheLineInfo cacheNewEntry(int addr) 
  {
    oldCacheLineInfo oldInfo = new oldCacheLineInfo();
    int point = (addr % (csize / lsize)); 
    point = point % noOfLines;  

    oldInfo.old_valid = valid[point];
    
    tag[point] = addr / lsize;     
    valid[point] = true;
    oldInfo.data = data[point] = new Integer(-1);

    return oldInfo;

  } // OldCacheLineInfo

  // Updates the data field of the cache line with the supplied parameter
  @Override
  public void cacheWriteData(Object newData)
  {
    data[record] = newData;
  } // CacheWriteData

} // DirectMappedCache
