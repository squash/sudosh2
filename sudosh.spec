#	$Id: sudosh.spec,v 1.2 2010/07/09 20:05:53 squash Exp $
#
%define origname sudosh2
%define name sudosh2
%define version 1.0.4
%define release 1.el5

Name: %{name}
Version: %{version}
Release: %{release}
Summary: Logged root shell that can be used for auditing

Group: System/SDL-custom
License: OSL
URL: http://sourceforge.net/projects/sudosh2/
Source: http://sudosh2.sourceforge.net/sudosh2-%{version}.tbz2

Packager: John Barton <jbarton@technicalworks.net>
BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-root
# BuildArch: i386
Requires: sudo
Provides: %{origname} = %{version}-%{release}, %{name} = %{version}-%{release}

%description
sudosh2 works directly with sudo to provide a fully functional shell that
users may use to obtain full root access. Unlike providing a team of system
administrators full root access through sudo, it guarantees that detailed
logs are kept. It uses the script command in conjunction with a secure FIFO
and comes with a utility to view sessions and drill down deeper and see the
actual session output. 

%prep
%setup -q -n %{origname}-%{version}

%{__cat} <<EOF >sudosh.conf.tmp
# Sudosh Configuration File
logdir                  = /var/log/sudosh
default shell           = /bin/bash
delimiter               = -
syslog.priority         = LOG_NOTICE
syslog.facility         = LOG_DAEMON

# Allow Sudosh to execute -c arguements?  If so, what?
-c arg allow = scp
-c arg allow = sftp
-c arg allow = /usr/libexec/openssh/sftp-server
# -c arg allow = rsync
EOF

%build
%configure \
	--program-prefix="%{?_program_prefix}"
%{__make} %{?_smp_mflags}

%install
%{__rm} -rf %{buildroot}
%makeinstall
mkdir -p %{buildroot}/var/log/sudosh
install -m 0744 sudosh.conf.tmp %{buildroot}/etc/sudosh.conf

%clean
%{__rm} -rf %{buildroot}


%files
%defattr(-, root, root, 0755)
%doc AUTHORS ChangeLog COPYING INSTALL NEWS README
%doc %{_mandir}/man1/sudosh.1*
%doc %{_mandir}/man5/sudosh.conf*
%doc %{_mandir}/man8/sudosh-replay.8*
%{_bindir}/sudosh
%{_bindir}/sudosh-replay
%config(noreplace) %{_sysconfdir}/sudosh.conf
%dir %attr(0733 root root) /var/log/sudosh

%changelog
* Fri Jul 09 2010 John Barton <jbarton@technicalworks.net> - 1.0.4-1
- Update for version 1.0.4

