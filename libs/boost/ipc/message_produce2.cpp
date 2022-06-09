#include <boost/interprocess/ipc/message_queue.hpp>
#include <iostream>
#include <vector>
using namespace boost::interprocess;

int main()
{

    try
    {

       

        /*Create a message_queue.  */
        message_queue mq(open_or_create //only create
                         ,
                         "message_queue" //name
                         ,
                         1000 //max message number
                         ,
                         sizeof(char) *10 //max message size
        );

        /*Send 100 numbers   */
        for (int i = 0; i < 50; ++i)
        {
            int m = i+10;
            char h[10] = "hellod748";
            mq.send(&h, sizeof(char)*10, 0);
        }
    }

    catch (interprocess_exception &ex)
    {

        std::cout << "exp: " << ex.what() << std::endl;

        return 1;
    }

    return 0;
}
