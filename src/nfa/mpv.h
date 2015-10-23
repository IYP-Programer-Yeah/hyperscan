/*
 * Copyright (c) 2015, Intel Corporation
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *  * Neither the name of Intel Corporation nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef MPV_H
#define MPV_H

#include "ue2common.h"

struct mq;
struct NFA;

char nfaExecMpv0_Q(const struct NFA *n, struct mq *q, s64a end);
char nfaExecMpv0_reportCurrent(const struct NFA *n, struct mq *q);
char nfaExecMpv0_inAccept(const struct NFA *n, ReportID report, struct mq *q);
char nfaExecMpv0_queueInitState(const struct NFA *n, struct mq *q);
char nfaExecMpv0_initCompressedState(const struct NFA *n, u64a offset,
                                     void *state, u8 key);
char nfaExecMpv0_queueCompressState(const struct NFA *nfa, const struct mq *q,
                                    s64a loc);
char nfaExecMpv0_expandState(const struct NFA *nfa, void *dest, const void *src,
                             u64a offset, u8 key);

#define nfaExecMpv0_testEOD NFA_API_NO_IMPL
#define nfaExecMpv0_inAccept NFA_API_NO_IMPL
#define nfaExecMpv0_QR NFA_API_NO_IMPL
#define nfaExecMpv0_Q2 NFA_API_NO_IMPL /* for non-chained suffixes. */
#define nfaExecMpv0_B_Reverse NFA_API_NO_IMPL
#define nfaExecMpv0_zombie_status NFA_API_ZOMBIE_NO_IMPL

/**
 * return 0 if the mpv dies, otherwise returns the location of the next possible
 * match (given the currently known events). */
s64a nfaExecMpv0_QueueExecRaw(const struct NFA *nfa, struct mq *q, s64a end);

#endif
