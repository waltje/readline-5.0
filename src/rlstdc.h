/* stdc.h -- macros to make source compile on both ANSI C and K&R C
   compilers. */

/* Copyright (C) 1993 Free Software Foundation, Inc.

   This file is part of GNU Bash, the Bourne Again SHell.

   Bash is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   Bash is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with Bash; see the file COPYING.  If not, write to the Free
   Software Foundation, 59 Temple Place, Suite 330, Boston, MA 02111 USA. */

#if !defined (_RL_STDC_H_)
#define _RL_STDC_H_

/* Adapted from BSD /usr/include/sys/cdefs.h. */

/* A function can be defined using prototypes and compile on both ANSI C
   and traditional C compilers with something like this:
	extern char *func PARAMS((char *, char *, int)); */

#if !defined (PARAMS)
#  if defined (__STDC__) || defined (__GNUC__) || defined (__cplusplus)
#    define PARAMS(protos) protos
#  else
#    define PARAMS(protos) ()
#  endif
#endif


#ifndef __attribute__
#  if (defined(__GNUC__) && __GNUC__ < 2) || (__GNUC__ == 2 && __GNUC_MINOR__ < 8)
#    define __attribute__(x)
#  endif
#endif


#ifndef READLINE_API
#  if defined (_WIN32) && defined (_MSC_VER)
#    define _RL_IMPORT __declspec(dllimport)
#    define _RL_EXPORT __declspec(dllexport)
#  elif defined (__GNUC__)
#    define _RL_IMPORT __declspec(dllimport)
#    define _RL_EXPORT __declspec(dllexport)
#  else
#    define _RL_IMPORT __attribute__((dllimport))
#    define _RL_EXPORT __attribute__((dllexport))
#  endif

#  if defined (__WIN32__) || defined (_WIN32)
#    if defined (BUILD_READLINE_DLL)
#      define READLINE_API _RL_EXPORT
#    elif defined (READLINE_STATIC)
#      define READLINE_API
#    elif defined (USE_READLINE_DLL)
#      define READLINE_API _RL_IMPORT
#    elif defined (USE_READLINE_STATIC)
#      define READLINE_API
#    else /* assume USE_READLINE_DLL */
#      define READLINE_API _RL_IMPORT
#    endif
#  else /* __WIN32__ */
#    define READLINE_API   /*notused*/
#  endif
#endif

#endif /* !_RL_STDC_H_ */
