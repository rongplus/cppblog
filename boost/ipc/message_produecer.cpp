#include <boost/interprocess/ipc/message_queue.hpp>
#include <iostream>
#include <vector>
using namespace boost::interprocess;

int main()
{

    try
    {

        /*Erase previous message queue   */
        message_queue::remove("message_queue");

        /*Create a message_queue.  */
        message_queue mq(create_only //only create
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
