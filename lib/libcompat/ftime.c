/*
 * Copyright (c) 1994 Joerg Wunsch
 *
 * All rights reserved.
 *
 * This program is free software.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by Joerg Wunsch
 * 4. The name of the developer may not be used to endorse or promote
 *    products derived from this software without specific prior written
 *    permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE DEVELOPERS ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE DEVELOPERS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * ftime.c
 * get time, OBSOLETED BY gettimeofday(2)
 *
 */

#include <sys/types.h>
#include <sys/time.h>
#include <sys/timeb.h>

int
#if __STDC__
ftime(struct timeb *tp)
#else
ftime(tp)
     struct timeb *tp;
#endif
{
	struct timeval tv;
	struct timezone tz;

	if(gettimeofday(&tv, &tz) < 0)
		return -1;	/* any error */

	tp->time = tv.tv_sec;
	tp->millitm = tv.tv_usec / 1000;
	/*
	 * timezone and dstflag below are bogus
	 * the timezone is no longer part of the kernel, thus the information
	 * obtained by gettimeofday() wrt. the timezone is useless
	 */
	tp->timezone = tz.tz_minuteswest;
	tp->dstflag = tz.tz_dsttime != DST_NONE;
	return 0;
}
