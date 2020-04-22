/* -*- Mode: C; c-basic-offset:4 ; indent-tabs-mode:nil ; -*- */
/*
 *   Copyright (C) 2020 by TODO
 *   See COPYRIGHT notice in top-level directory.
 */

#ifndef AD_JULEA_H_INCLUDED
#define AD_JULEA_H_INCLUDED

#include "adio.h"

//------------------------------------------------------------------------????????????
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
// #include <julea.h>
#include <julea-object.h>

#ifdef HAVE_SIGNAL_H
#include <signal.h>
#endif
#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#ifdef HAVE_AIO_LITE_H
#include <aio-lite.h>
#else
#ifdef  HAVE_AIO_H
#include <aio.h>
#endif
#ifdef HAVE_SYS_AIO_H
#include <sys/aio.h>
#endif
#endif

/* Workaround for incomplete set of definitions if __REDIRECT is not
   defined and large file support is used in aio.h */
#if !defined(__REDIRECT) && defined(__USE_FILE_OFFSET64)
#define aiocb aiocb64
#endif

int ADIOI_JULEA_aio(ADIO_File fd, void *buf, int len, ADIO_Offset offset,
                  int wr, MPI_Request * request);

#ifdef SX4
#define lseek llseek
#endif
//------------------------------------------------------------------------????????????

void ADIOI_JULEA_Open(ADIO_File fd, int *error_code);
void ADIOI_JULEA_ReadContig(ADIO_File fd, void *buf, int count,
                          MPI_Datatype datatype, int file_ptr_type,
                          ADIO_Offset offset, ADIO_Status * status, int
                          *error_code);
void ADIOI_JULEA_WriteContig(ADIO_File fd, const void *buf, int count,
                           MPI_Datatype datatype, int file_ptr_type,
                           ADIO_Offset offset, ADIO_Status * status, int
                           *error_code);


#endif /* AD_JULEA_H_INCLUDED */
