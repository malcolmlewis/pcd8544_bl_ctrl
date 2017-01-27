# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as
# published by the Free Software Foundation; either version 2.1 of the
# License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# Lesser General Public License for more details.
#
# Copyright (C) 2017 Malcolm Lewis <malcolmlewis@opensuse.org>

#
# Name: Makefile for pcd8544_bl_ctrl.c:
# Version: 0.1
# Date: Jan 25, 2017
#


PREFIX?=/usr
SBINDIR?=$(PREFIX)/sbin
INCLUDEDIR?=$(PREFIX)/include
LIBDIR?=$(PREFIX)/lib64
MANDIR?=$(PREFIX)/share/man

CC	= gcc
INCLUDE	= -I.
CFLAGS	= -fmessage-length=0 -grecord-gcc-switches -fstack-protector -Wall -funwind-tables -fasynchronous-unwind-tables
LDFLAGS	= -L$(LIBDIR)
LIBS	= -lwiringPi -lm -lpthread -lrt

SRC	= pcd8544_bl_ctrl.c

HEADERS	=

pcd8544_bl_ctrl:
	$Q echo [Compile] $<
	$Q $(CC) $(CFLAGS) -o $@ $(SRC) $(LDFLAGS) $(LIBS)

.PHONY:	clean
clean:
	$Q echo "[Clean]"
	$Q rm -f pcd8544_bl_ctrl

.PHONY:	install
install:
	$Q echo "[Install]"
	$Q mkdir -p		$(DESTDIR)$(SBINDIR)
	$Q cp pcd8544_bl_ctrl	$(DESTDIR)$(SBINDIR)
	$Q mkdir -p		$(DESTDIR)$(MANDIR)/man1
	$Q cp pcd8544_bl_ctrl.1	$(DESTDIR)$(MANDIR)/man1

.PHONY:	uninstall
uninstall:
	$Q echo "[UnInstall]"
	$Q rm -f $(DESTDIR)$(SBINDIR)/pcd8544_bl_ctrl
	$Q rm -f $(DESTDIR)$(MANDIR)/man1/pcd8544_bl_ctrl.1

