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

    if (count == 0) {
        err = 0;
    } 
    MPI_Type_size_x(datatype, &datatype_size);
    len = datatype_size * (ADIO_Offset) count;

    JBatch* batch = j_batch_new_for_template(J_SEMANTICS_TEMPLATE_DEFAULT);
    j_object_write(fd->fs_ptr, buf, len, offset, (guint64*) file_ptr_type, batch);
    j_batch_execute(batch);
}
