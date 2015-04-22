#include "super.h"

int myrand(void)
{
    struct timeval tv;
    unsigned int seed;

    gettimeofday(&tv, (struct timezone *) 0);
    seed =
	(tv.tv_sec % 10000) * 523 + tv.tv_usec * 13 +
	(getpid() % 1000) * 983;
    srand(seed);

    return rand();
}

char *rand2str(size_t len)
{
    static char buf[BUFSIZ];
    char *ptr = buf;
    char *alphabet =
	"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int i;

    if (len == 0)
	return (char *) 0;
    if (len >= BUFSIZ)
	len = BUFSIZ - 1;

    for (i = 0; i < len; i++) {
	int j = (myrand() & 0xffff) % (26 + 26 + 10);

	ptr[i] = alphabet[j];
    }

    return buf;
}
