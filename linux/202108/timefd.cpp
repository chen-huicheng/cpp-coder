#include <sys/timerfd.h>
#include <time.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int main()
{
    struct itimerspec ts;
    struct timespec start, now;
    int secs, nanosecs;

    memset(&ts, 0, sizeof(struct itimerspec));

    ts.it_value.tv_sec = 0;
    ts.it_value.tv_nsec = 10000000; //10ms一次
    ts.it_interval.tv_sec = 0;
    ts.it_interval.tv_nsec = 5000000; //5ms一次

    int fd = timerfd_create(CLOCK_REALTIME, TFD_NONBLOCK); //设置为非阻塞
    if (-1 == fd)
        perror("timerfd_create");

    if (timerfd_settime(fd, 0, &ts, NULL) == -1)
        perror("timefd_settime");

    if (clock_gettime(CLOCK_MONOTONIC, &start) == -1)
        perror("clock_gettime");

    ssize_t s;
    uint64_t numExp, totalExp, maxExp = 10;

    for (totalExp = 0; totalExp < maxExp;)
    {
        s = read(fd, &numExp, sizeof(uint64_t));
        if (s != sizeof(uint64_t))
            perror("read");

        totalExp += numExp;

        if (clock_gettime(CLOCK_MONOTONIC, &now) == -1)
            perror("clock_gettime");

        secs = now.tv_sec - start.tv_sec;
        nanosecs = now.tv_nsec - start.tv_nsec;
        if (nanosecs < 0)
        {
            secs--;
            nanosecs += 1000000000;
        }
        printf("%d.%03d: expirations read: %lu; total=%lu\n",
               secs, (nanosecs + 500000) / 1000000, (unsigned long)numExp,
               (unsigned long)totalExp);
    }
    return 0;
}
