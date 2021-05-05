#include <boost/interprocess/ipc/message_queue.hpp>  
#include <iostream>  
#include <vector>  
#include <boost/interprocess/sync/named_mutex.hpp> 
#include <boost/interprocess/sync/named_condition.hpp>
using namespace boost::interprocess; 
 
int main () 
{ 
  try{ 
    boost::interprocess::named_mutex named_mtx(boost::interprocess::open_or_create, "mtx"); 
    boost::interprocess::named_condition named_cnd(boost::interprocess::open_or_create, "cnd"); 
   /*Open a message queue.  */
   message_queue mq 
     (open_only    //only create  
     ,"message_queue" //name  
     ); 
 
   unsigned int priority; 
   message_queue::size_type recvd_size; 
 
   /*Receive 100 numbers  */
   for(int i = 0; i < 100; ++i){ 
     int number; 
     char h[10];
     mq.receive(h, sizeof(char)*10, recvd_size, priority); 
     std::cout << "get----" << i << std::endl;
     std::cout << "Get " << h << std::endl;
    //  if( recvd_size != sizeof(number)) 
    //   {
    //     std::cout << "Error" << std::endl;
    //     return 1; 
    //   }
   } 
  } 
  catch(interprocess_exception &ex){ 
   message_queue::remove("message_queue"); 
   std::cout <<"exp: " <<ex.what() << std::endl; 
   return 1; 
  } 
  message_queue::remove("message_queue"); 
  return 0; 
} 

