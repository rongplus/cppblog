
#include "common.h"
void testclient()
{
   
}
int main()
{
   int shmid = GetShm(4096);
	sleep(1);
	
	ShareInfo *addr = (ShareInfo *)shmat(shmid,NULL,0);
	sleep(2);
	int i = 0;
	while(i < 26)
	{
		addr[i].a = i;
		addr[i].s ='a'+i ;
		i++;
	
		sleep(1);
	}
	shmdt(addr);
	sleep(2);


    return 0;
}

//ipcs -m //查看创建的共享内存的个数

//ipcrm -m shm_id //删除共享内存