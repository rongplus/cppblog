/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>
#include <vector>
using namespace  std;



  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  
class Solution1 {
public:

    ListNode* swapNode(ListNode* head)
    {
        if (head && head->next && head->next->next)
        {
            auto n1 = head->next;
            auto n2 = n1->next;
            swapNode(n1,n2);
      
            head->next = n2;

            return n1;
        }

        return nullptr;
    }
    ListNode* swapNode(ListNode* n1, ListNode* n2)
    {
        if (n1 && n2)
        {
            cout << n1 << "-" << n2 << endl;
            auto tmp = n2->next;
            {                
                auto t = n1;
                n1 = n2;
                n2 = t;   
               
                n1->next = n2;
                n2->next = tmp;
            }
            //swap(n1,n2); 
            cout << n1->val << n2->val << endl;
            cout << n1 << "-" << n2 << endl;
                  
            return tmp;
        }
        return nullptr;
    }
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        
     
        auto h2 = head->next;  
        auto h =head;

        swapNode(h, h->next);   
        h = h2->next;        
        while( h)
        {           
            h = swapNode(h);   
             
        }

        cout << "head = " << h2->val << endl;
        return h2;
        
    }
};

void dump(ListNode * node)
{
    while(node)
    {
        cout << node->val << endl;
        node = node->next; 
    }
}

class Solution2 {
public:
    int divide(int dividend, int divisor) {
        
        int factor = dividend/divisor;
        long long dd = abs(dividend);
        long long ds = abs(divisor);
        long long ds_tmp = ds;
        int result = 0;
        int ret = 1;
        if (ds==1)
        {
            if (dividend==INT_MIN && divisor == -1)
                return INT_MAX;
            return dividend*factor;
        }
        while(dd>(ds<<1))
        {         
            ds = ds <<1;
            ret = ret << 1;
        }
        cout << "--- " << ds << ", " << ret << endl;

        while(dd>ds_tmp)
        {
          
            if (dd>=ds)
            {
                result += ret;
                dd = dd -ds;
            }
            else
            {
                ds = ds >>1;
                ret = ret >> 1;
            }
        }
        
        return result * factor;
    }
};


class Solution {
public:
    int jump(vector<int>& nums) {
        
        int sz = nums.size();
        vector<int> steps(sz);
        steps[sz-1] = 0;
        steps[sz-2] = 1;
        //2  3 1 1 4
        sz-=3;
        while(sz>=0)
        {
            int step =INT_MAX;
            for (int n=sz+1; n<=sz+nums[sz];++n)
            {
                if ( n>= nums.size())
                    break;
                step = min( steps[n]+1,step);
                cout << "sz="<< sz << " nums[sz]=" << nums[sz] << " n=" << n <<  "---- step = " << step << endl;
            }
            steps[sz] = step;
            cout << "steps[" << sz << " ]" << step << endl;
            --sz;
        }      
        
        return steps[0];      
        
    }
};

void main()
{
    ListNode * node5 = new ListNode(5);
    ListNode * node4 = new ListNode(4,node4);
    ListNode * node3 = new ListNode(3,node4);
    ListNode * node2 = new ListNode(2,node3);
    ListNode * node1 = new ListNode(1,node2);

    //dump(node1);

    Solution s;
    vector<int> lt = { 2,3,1,1,4};
    auto t = s.jump(lt);

cout << "-----ret = -------------\n"   << t << "\n-------------------"<< endl;;
   //dump(t);

}