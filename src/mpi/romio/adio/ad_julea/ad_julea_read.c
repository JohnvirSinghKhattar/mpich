/* -*- Mode: C; c-basic-offset:4 ; indent-tabs-mode:nil ; -*- */
/*
 *
 *   Copyright (C) 1997 University of Chicago.
 *   See COPYRIGHT notice in top-level directory.
 */

//#include <julea.h>
//#include <julea-object.h>
#include "ad_julea.h"
#include "adio_extern.h"
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

void ADIOI_JULEA_ReadContig(ADIO_File fd, void *buf, int count,
                          MPI_Datatype datatype, int file_ptr_type,
                          ADIO_Offset offset, ADIO_Status * status, int *error_code)
{
    ssize_t err = -1;
    MPI_Count datatype_size, len;
    ADIO_Offset bytes_xfered = 0;
    size_t rd_count;
    static char myname[] = "ADIOI_JULEA_READCONTIG";
    char *p;

    if (count == 0) {
        err = 0;
        goto fn_exit;
    }

    MPI_Type_size_x(datatype, &datatype_size);
    len = datatype_size * (ADIO_Offset) count;

    JBatch* batch = j_batch_new_for_template(J_SEMANTICS_TEMPLATE_DEFAULT);
    j_object_read(fd->fs_ptr, ad_julea, len + 1, 0, &nbytes, batch);
    j_batch_execute(batch);
}
