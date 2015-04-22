# sudosh2

sudosh2 is an auditing layer between sudo and a user's shell, that can also be used as a login shell.

User sessions are recorded and are available for later playback by the system administrator.

sudosh2 does not record command history except when executed remotely via ssh's command option. If you're looking for something to just log commands, there are other tools for that.

sudosh2 does not log sessions to syslog. If you need to consolidate session logs to a single location, logging them to a network filesystem is currently the only real option.

sudosh2 was forked from sudosh, which was pulled by its original developer when a commercial company bought it from him. The initial project goals were to fix several major bugs, 
make it 64 bit safe, and port to newer versions of Unix operating systems. The initial targets were RHEL5 and Solaris 10, but most recent free Unix systems should work perfectly.
There are known issues with AIX and HP/UX that I can't currently fix as I don't have access to either platform. Patches for these platforms would be accepted.

sudosh2 is generally in maintenance mode. I'll accept portability issues and simple feature requests, but probably not major feature requests at this time. 

sudosh2 is under the Open Source License 2.0 (which is very similar to BSD with Attribution), a copy of wihch is in the COPYING file. This is the license chosen by the original author.

