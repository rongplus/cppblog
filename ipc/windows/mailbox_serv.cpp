#include <stdio.h>

#include <Windows.h>

int main(void)
{
    HANDLE Mailslot;
    char Buffer[256];
    DWORD NumberOfBytesRead;

    if ((Mailslot = CreateMailslot("\\\\.\\mailslot\\sample_mailslot", 0, MAILSLOT_WAIT_FOREVER, NULL)) == INVALID_HANDLE_VALUE)
    {
        printf("Failed to Create a mailslot %d/n", GetLastError());
        return -1;
    }

    while (ReadFile(Mailslot, Buffer, 256, &NumberOfBytesRead, NULL) != 0)
    {
        printf("%.*s\n", NumberOfBytesRead, Buffer);
    }
    return 0;
}