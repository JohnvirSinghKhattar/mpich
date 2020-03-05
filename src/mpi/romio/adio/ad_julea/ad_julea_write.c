/* -*- Mode: C; c-basic-offset:4 ; indent-tabs-mode:nil ; -*- */
/*
 *
 *   Copyright (C) 2020 TODO
 *   See COPYRIGHT notice in top-level directory.
 */

#include "ad_julea.h"
#include "adio_extern.h"
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

void ADIOI_JULEA_WriteContig(ADIO_File fd, const void *buf, int count,
                           MPI_Datatype datatype, int file_ptr_type,
                           ADIO_Offset offset, ADIO_Status * status, int *error_code)
{
    ssize_t err = -1;
    MPI_Count datatype_size, len;
    ADIO_Offset bytes_xfered = 0;
    size_t wr_count;
    static char myname[] = "ADIOI_JULEA_WRITECONTIG";
    char *p;

    if (count == 0) {
        err = 0;
        goto fn_exit;
    }

    JBatch batch = j_batch_new_for_template(J_SEMANTICS_TEMPLATE_DEFAULT);
    j_object_write(fd->fs_ptr, ad_julea, strlen(ad_julea) + 1, 0, &nbytes, batch)
    j_batch_execute(batch);
}