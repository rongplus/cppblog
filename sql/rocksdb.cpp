#include <cstdio>
#include <string>
 //C:/software/vcpkg/packages/rocksdb_x64-windows/include/
#include "rocksdb/db.h"
#include "rocksdb/slice.h"
#include "rocksdb/options.h"
 
using namespace std;
using namespace rocksdb;

#pragma comment(lib,"C:/software/vcpkg/packages/rocksdb_x64-windows/lib/rocksdb.lib") //Winsock Library

class PinnalbeSlice
{
public:
    PinnalbeSlice() = default;
};
 
//The path of database storage
std::string kDBPath = "/tmp/rocksdb_simple_example";
 
int main(){
	DB * db;
	Options options;
 
	 //Increase concurrency and horizontal compaction style
	options.IncreaseParallelism();
	//options.OptimizieLevelStyleCompaction();
 
	options.create_if_missing = true;
 
	//open DB
	Status s=DB::Open(options,kDBPath,&db);
	assert(s.ok());
 
	//Put key-value
	s = db->Put(WriteOptions(),"key1","value");
	assert(s.ok());
 
	std::string value;
	//get value
	s = db->Get( ReadOptions(),"key1",&value);
	assert(s.ok());
	assert(value == "value");
 
	 //Atomize a set of updates
	{
		WriteBatch batch;
		batch.Delete("key1");
		batch.Put("key2",value);
		s = db->Write(WriteOptions::WriteOptions(),&batch);
	}
 
	s = db->Get(ReadOptions::ReadOptions(),"key1",&value);
	assert(s.IsNotFound());
 
	db->Get(ReadOptions::ReadOptions(),"key2",&value);
	assert(value=="value");
 
	{
		PinnableSlice pinnable_val;
		db->Get(ReadOptions(),db->DefaultColumnFamily(),"key2",&pinnable_val);
		assert(pinnable_val=="value");
	}
 
	{
		std::string string_val;
		 //If the value cannot be locked, copy the value to its internal buffer
		 //The internal buffer can be set during construction
		PinnableSlice pinnable_val (&string_val);
		db->Get(ReadOptions(),db->DefaultColumnFamily(),"key2",&pinnable_val);
		assert(pinnable_val=="value");
		 //If the value is not fixed, it must be in the internal buffer
		assert(pinnable_val.IsPinned()||string_val=="value");
	}
 
 
	string pinnable_val;
	db->Get(ReadOptions(),db->DefaultColumnFamily(),"key1",&pinnable_val);
	assert(s.IsNotFound());
	 //Reset PinnableSlice after each use and before each reuse
	//pinnable_val.Reset();
	db->Get(ReadOptions(),db->DefaultColumnFamily(),"key2",&pinnable_val);
	//assert(pinnable_val == "value");
	//pinnable_val.Reset();
	 //After this, the Slice pointed to by pinnable_val is invalid.
 
	delete db;
	
	return 0;
}