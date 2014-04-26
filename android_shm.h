/* Copyright (C) 1995-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#ifndef _SYS_SHM_H
#define _SYS_SHM_H	1

#include <stddef.h>

/* Get common definition of System V style IPC.  */
#include <linux/ipc.h>

/* Get system dependent definition of `struct shmid_ds' and more.  */
#include <linux/shm.h>

__BEGIN_DECLS

/* The following System V style IPC functions implement a shared memory
   facility.  The definition is found in XPG4.2.  */

/* Shared memory control operation.  */
extern int shmctl (int __shmid, int __cmd, struct shmid_ds *__buf) ;

/* Get shared memory segment.  */
extern int shmget (key_t __key, size_t __size, int __shmflg);

/* Attach shared memory segment.  */
extern void *shmat (int __shmid, const void *__shmaddr, int __shmflg);

/* Detach shared memory segment.  */
extern int shmdt (const void *__shmaddr);

__END_DECLS

#endif /* sys/shm.h */
