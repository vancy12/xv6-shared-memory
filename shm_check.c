#include "types.h"
#include "stat.h"
#include "user.h"

#define SHM_KEY 1234  // Example shared memory key
#define SHM_SIZE 4096 // Shared memory size
#define SHM_FLAG 0    // Example flag

int main() {
    int shmid;
    void *shmaddr;

    // Test shmget
    shmid = shmget(SHM_KEY, SHM_SIZE, SHM_FLAG);
    if (shmid < 0) {
        printf(1, "shmget failed\n");
        exit();
    }
    printf(1, "shmget success, shmid: %d\n", shmid);

    // Test shmat
    shmaddr = (void *)shmat(shmid, 0, 0);  // Attach at system-chosen address
    if (shmaddr == (void *)-1) {
        printf(1, "shmat failed\n");
        exit();
    }
    printf(1, "shmat success, attached at: %p\n", shmaddr);

    // Test shmdt
    if (shmdt(shmaddr) < 0) {
        printf(1, "shmdt failed\n");
        exit();
    }
    printf(1, "shmdt success, detached memory\n");

    // Test shmctl
    if (shmctl(shmid, 0) < 0) {
        printf(1, "shmctl failed\n");
        exit();
    }
    printf(1, "shmctl success, control operation executed\n");

    exit();
}
