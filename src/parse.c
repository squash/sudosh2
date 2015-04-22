#include "super.h"
#include "struct.h"

extern void parse(option *, const char *);
extern void mklogdir(char * logdir);

void parse(option * c, const char *file)
{
    FILE *f;
    char line[BUFSIZ];
	int leftside;
    char key[BUFSIZ], value[BUFSIZ];
    char *p;
    struct stat defshell_stat;
    struct stat logdir_stat;
    char *shell;
    int found = FALSE;
    unsigned int x=0;

	bzero(c, sizeof (struct s_option));
	// Set up some defaults
	strcpy(c->logdir, LOGDIR);
	c->fdl='-';
	strcpy(c->defshell, "/bin/sh");
	c->priority=-1; // No defaults here
	c->facility=-1; // or here...
	c->clearenvironment=1;
	f = fopen(file, "r");
	if (f==NULL)
		{
		fprintf(stderr,"Warning: No config file found. Using compiled-in defaults:\nLogdir\t%s\nDefault Shell:\t%s\nSyslog disabled\n",c->logdir, c->defshell);
		// Just run with the defaults, ignore the rest
		return;
		}
    while (fgets(line, BUFSIZ-1, f))
	{
	p=strchr(line,'=');
	if (!p)
		{
//		fprintf(stderr, "Invalid line in config file: %s\n",line);
		continue;
		}
	leftside=1;
	key[0]=value[0]=0;
	if (line[0]=='#')
		continue; // Ignore comments, blank lines
	// Trim the whitespace, split into key/value
	for (x=0 ; x<strlen(line);x++)
	if (!isspace(line[x]))
		{
		if (line[x]=='=')
			{
			leftside=0;
			continue;
			}

		if (leftside)
			strncat(key, &line[x], 1);
		else
			strncat(value, &line[x], 1);
		}
//	fprintf(stderr, "Parsed key [%s] and value [%s]\n",key, value);

	if (strcmp(key,"-cargallow")==0)
		{
		strcat(c->argallow,"$");
		strcat(c->argallow,value);
		strcat(c->argallow,"$");
		}
	if (strcmp(key,"logdir")==0)
		strcpy(c->logdir,value);
	if (strcmp(key,"clearenvironment")==0)
		{
		if(strncmp(value,"no",2)==0)
			{
			c->clearenvironment=0;
			}
		else
			c->clearenvironment=1;
		}

	if (strcmp(key,"defaultshell")==0)
		strcpy(c->defshell,value);


	if (strcmp(key,"delimiter")==0)
		c->fdl=value[0];
	
	if (strcmp(key,"syslog.facility")==0)
		{ // I really hate the way this is done...
		found = FALSE;
#ifdef LOG_AUTH
	    if (!strcmp(value, "LOG_AUTH")) {
		c->facility = LOG_AUTH;
		found = TRUE;
	    }
#endif				/* LOG_AUTH */
#ifdef LOG_AUTHPRIV
	    if (!strcmp(value, "LOG_AUTHPRIV")) {
		c->facility = LOG_AUTHPRIV;
		found = TRUE;
	    }
#endif				/* LOG_AUTHPRIV */
#ifdef LOG_CRON
	    if (!strcmp(value, "LOG_CRON")) {
		c->facility = LOG_CRON;
		found = TRUE;
	    }
#endif				/* LOG_CRON */
#ifdef LOG_DAEMON
	    if (!strcmp(value, "LOG_DAEMON")) {
		c->facility = LOG_DAEMON;
		found = TRUE;
	    }
#endif				/* LOG_DAEMON */
#ifdef LOG_FTP
	    if (!strcmp(value, "LOG_FTP")) {
		c->facility = LOG_FTP;
		found = TRUE;
	    }
#endif				/* LOG_FTP */
#ifdef LOG_KERN
	    if (!strcmp(value, "LOG_KERN")) {
		c->facility = LOG_KERN;
		found = TRUE;
	    }
#endif				/* LOG_KERN */
#ifdef LOG_LOCAL0
	    if (!strcmp(value, "LOG_LOCAL0")) {
		c->facility = LOG_LOCAL0;
		found = TRUE;
	    }
#endif				/* LOG_LOCAL0 */
#ifdef LOG_LOCAL1
	    if (!strcmp(value, "LOG_LOCAL1")) {
		c->facility = LOG_LOCAL1;
		found = TRUE;
	    }
#endif				/* LOG_LOCAL1 */
#ifdef LOG_LOCAL2
	    if (!strcmp(value, "LOG_LOCAL2")) {
		c->facility = LOG_LOCAL2;
		found = TRUE;
	    }
#endif				/* LOG_LOCAL2 */
#ifdef LOG_LOCAL3
	    if (!strcmp(value, "LOG_LOCAL3")) {
		c->facility = LOG_LOCAL3;
		found = TRUE;
	    }
#endif				/* LOG_LOCAL3 */
#ifdef LOG_LOCAL4
	    if (!strcmp(value, "LOG_LOCAL4")) {
		c->facility = LOG_LOCAL4;
		found = TRUE;
	    }
#endif				/* LOG_LOCAL4 */
#ifdef LOG_LOCAL5
	    if (!strcmp(value, "LOG_LOCAL5")) {
		c->facility = LOG_LOCAL5;
		found = TRUE;
	    }
#endif				/* LOG_LOCAL5 */
#ifdef LOG_LOCAL6
	    if (!strcmp(value, "LOG_LOCAL6")) {
		c->facility = LOG_LOCAL6;
		found = TRUE;
	    }
#endif				/* LOG_LOCAL6 */
#ifdef LOG_LOCAL7
	    if (!strcmp(value, "LOG_LOCAL7")) {
		c->facility = LOG_LOCAL7;
		found = TRUE;
	    }
#endif				/* LOG_LOCAL7 */
#ifdef LOG_LPR
	    if (!strcmp(value, "LOG_LPR")) {
		c->facility = LOG_LPR;
		found = TRUE;
	    }
#endif				/* LOG_LPR */
#ifdef LOG_MAIL
	    if (!strcmp(value, "LOG_MAIL")) {
		c->facility = LOG_MAIL;
		found = TRUE;
	    }
#endif				/* LOG_MAIL */
#ifdef LOG_NEWS
	    if (!strcmp(value, "LOG_NEWS")) {
		c->facility = LOG_NEWS;
		found = TRUE;
	    }
#endif				/* LOG_NEWS */
#ifdef LOG_SYSLOG
	    if (!strcmp(value, "LOG_SYSLOG")) {
		c->facility = LOG_SYSLOG;
		found = TRUE;
	    }
#endif				/* LOG_SYSLOG */
#ifdef LOG_USER
	    if (!strcmp(value, "LOG_USER")) {
		c->facility = LOG_USER;
		found = TRUE;
	    }
#endif				/* LOG_USER */
#ifdef LOG_UUCP
	    if (!strcmp(value, "LOG_UUCP")) {
		c->facility = LOG_UUCP;
		found = TRUE;
	    }
#endif				/* LOG_UUCP */

	    if (found == FALSE) {
		fprintf(stderr,"Invalid syslog.facility in config file\n");
		exit(-1);
		}


	}
	if (strcmp(key,"syslog.priority")==0)
		{
		
	    int found = FALSE;

#ifdef LOG_EMERG
	    if (!strcmp(value, "LOG_EMERG")) {
		c->priority = LOG_EMERG;
		found = TRUE;
	    }
#endif				/* LOG_EMERG */
#ifdef LOG_ALERT
	    if (!strcmp(value, "LOG_ALERT")) {
		c->priority = LOG_ALERT;
		found = TRUE;
	    }
#endif				/* LOG_ALERT */
#ifdef LOG_CRIT
	    if (!strcmp(value, "LOG_CRIT")) {
		c->priority = LOG_CRIT;
		found = TRUE;
	    }
#endif				/* LOG_CRIT */
#ifdef LOG_ERR
	    if (!strcmp(value, "LOG_ERR")) {
		c->priority = LOG_ERR;
		found = TRUE;
	    }
#endif				/* LOG_ERR */
#ifdef LOG_WARNING
	    if (!strcmp(value, "LOG_WARNING")) {
		c->priority = LOG_WARNING;
		found = TRUE;
	    }
#endif				/* LOG_WARNING */
#ifdef LOG_NOTICE
	    if (!strcmp(value, "LOG_NOTICE")) {
		c->priority = LOG_NOTICE;
		found = TRUE;
	    }
#endif				/* LOG_NOTICE */
#ifdef LOG_INFO
	    if (!strcmp(value, "LOG_INFO")) {
		c->priority = LOG_INFO;
		found = TRUE;
	    }
#endif				/* LOG_INFO */
#ifdef LOG_DEBUG
	    if (!strcmp(value, "LOG_DEBUG")) {
		c->priority = LOG_DEBUG;
		found = TRUE;
	    }
#endif				/* LOG_DEBUG */
	    if (found == FALSE)
		{
		fprintf(stderr, "%s: syslog.priority: level '%s' is unknown.\n",
			file, value);
		exit(EXIT_FAILURE);
		}
	}
    }
// Validation
// delimiter
if (!ispunct(c->fdl))
	{
	fprintf(stderr,"%s: delimiter [%c] must be punctuation\n",file, c->fdl);
	exit(EXIT_FAILURE);
	}

// defaultshell
#ifdef HAVE_GETUSERSHELL

setusershell();
while ((shell =  (char *)getusershell()))
	if (!strcmp(shell, c->defshell))
		found = TRUE;
endusershell();

if (!found)
	{
	fprintf(stderr, "default shell '%s' is not in /etc/shells.\n", c->defshell);
	exit(EXIT_FAILURE);
	}
#endif				/* HAVE_GETUSERSHELL */

if ((stat(c->defshell, &defshell_stat)) == -1)
	{
	fprintf(stderr, "default shell '%s': %s (%i)\n", value, strerror(errno), errno);
	exit(EXIT_FAILURE);
	}

// logdir
/* check everything at once, attempt to fix if incorrect, die if it cannot be fixed */
if (((stat(c->logdir, &logdir_stat)) == -1)  || !(logdir_stat.st_mode & S_IFDIR))
	mklogdir (c->logdir);

if ((stat(c->logdir, &logdir_stat)) == -1)
	{
	fprintf(stderr, "Fatal error - logdir %s invalid: %s\n", c->logdir, strerror(errno));
	exit(EXIT_FAILURE);
	}

if (!(logdir_stat.st_mode & S_IFDIR))
	{
	fprintf(stderr, "logdir '%s' is not a directory.\n", c->logdir);
	exit(EXIT_FAILURE);
	}

fclose(f);
}

/* So really, we have a small number of options we need to parse:
. logdir
. default shell
. delimiter
. -c arg allow
. syslog.priority
. syslog.facility

So for backwards compatibility, we need to be able to deal with whitespace. To make things easier, I'll just kill all whitespace.
*/
    

