#include "common.h"
void testserver()
{
    int shmid = CreateShm(4096);
 
	ShareInfo *addr = (ShareInfo *)shmat(shmid,NULL,0);
	sleep(2);
	int i = 0;
	while(i++ < 26)
	{
		for(int n=0; n< 10; n++)

			printf("client# %d - %s\n",addr[n].a, addr[n].s.c_str());
		printf("-----------------------\n");
		sleep(1);
	}
	shmdt(addr);
	sleep(2);
	DestroyShm(shmid);

}
int main()
{
    testserver();
    return 0;
}