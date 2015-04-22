#include "super.h"

void lc(char *str)
{
    size_t i;

    for (i = 0; str[i]; i++)
	str[i] = tolower(str[i]);
}

char *int2smalltime(int t)
{
    static char time_string[BUFSIZ], *fill;
    int days, hrs, mins, secs;

    if (t == -1)
	return "Never";

    if (t == 0)
	return "0s";

    days = t / 86400;
    hrs = (t / 3600) % 24;
    mins = (t / 60) % 60;
    secs = t % 60;
    fill = time_string;

    if (days) {
	snprintf(fill, BUFSIZ - 1, "%dd", days);

	while (*fill)
	    fill++;
    }
    if (hrs) {
	snprintf(fill, BUFSIZ - 1, "%dh", hrs);
	while (*fill)
	    fill++;

	*fill++ = 0;
	return time_string;
    }
    if (mins) {
	snprintf(fill, BUFSIZ - 1, "%dm", mins);
	while (*fill)
	    fill++;
    }
    if (secs) {
	snprintf(fill, BUFSIZ - 1, "%ds", secs);
	while (*fill)
	    fill++;
    }

    *fill++ = 0;
    return time_string;
}
