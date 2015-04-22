bin_PROGRAMS=sudosh sudosh-replay
sudosh_SOURCES=sudosh.c rand.c parse.c string.c getopt.h  struct.h  super.h util.c
sudosh_replay_SOURCES=replay.c getopt.c getopt.h string.c parse.c  util.c

EXTRA_DIST=sudosh.conf

sysconfdir = @sysconfdir@

install-sudosh.conf:
	test -z "$(sysconfdir)" || $(mkdir_p) "$(DESTDIR)$(sysconfdir)"
	test -f $(sysconfdir)/sudosh.conf || $(INSTALL) -o 0 -g 0 -m 0444 '$(srcdir)/sudosh.conf' '$(DESTDIR)$(sysconfdir)/sudosh.conf'

install: install-am install-sudosh.conf
