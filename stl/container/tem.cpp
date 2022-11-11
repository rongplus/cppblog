#include <string>
#include <memory>
using namespace std;
class A
{
    public:
    A(int, int, string)
    {}
};




 class DataFilter{
    public:
        template< typename Type,typename ... Args >
        DataFilter( Type,Args&& ... args ) :
            m_filter( std::make_unique< Type >( std::forward< Args >( args ) ... ) )
        {
        }
   
    private:
        std::unique_ptr< A > m_filter ;
    };

    int main()
    {
        DataFilter f(1,1,"str");
    }