#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <net/if.h>
#include <unistd.h>
#include <linux/sockios.h>
#include <errno.h>

#define SORHTA_IOCTL_CHECK			(SIOCDEVPRIVATE + 0)
#define SORHTA_IOCTL_ALLOC_POOL		(SIOCDEVPRIVATE + 1)
#define SORHTA_IOCTL_FREE_POOL		(SIOCDEVPRIVATE + 2)

int main(int argc, char* argv[]) {
    int data;
    int sock;
    struct ifreq ifr;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    memset(&ifr, 0, sizeof(ifr));
    strcpy(ifr.ifr_name, "pfe2sl");
    ifr.ifr_data = (void*)&data;

    if(ioctl(sock, SORHTA_IOCTL_CHECK, &ifr) == -1) {
        printf("IOCTL Check failed: %d\n", errno);
    }
    if(ioctl(sock, SORHTA_IOCTL_ALLOC_POOL, &ifr) == -1) {
        printf("IOCTL alloc pool failed: %d\n", errno);
    }
    if(ioctl(sock, SORHTA_IOCTL_FREE_POOL, &ifr) == -1) {
        printf("IOCTL free pool failed: %d\n", errno);
    }
    return 0;
}