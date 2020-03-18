/* -*- Mode: C; c-basic-offset:4 ; indent-tabs-mode:nil ; -*- */
/*
 *
 *   Copyright (C) 2020  TODOD
 *   See COPYRIGHT notice in top-level directory.
 */

#include "ad_julea.h"

void ADIOI_JULEA_Open(ADIO_File fd, int *error_code)        //Open Methode laut Interface
{
    static char myname[] = "ADIOI_JULEA_OPEN";              

    JBatch batch = j_batch_new_for_template(J_SEMANTICS_TEMPLATE_DEFAULT); //Erstellung eines Batch
    JObject* object = j_object_new("ad", fd->filename); //Erstellung Object
                                                        //filename über die übergebene File
    j_object_create(object, batch);                     //Objekt wird auf Festplatte erstellt
    j_batch_execute(batch);                             //Batch wird ausgeführt
 
    fd->fs_ptr = object;                                //Objekt wird über den Pointer fs_ptr referenziert

    if (fd->fd_sys == -1) {
        *error_code = ADIOI_Err_create_code(myname, fd->filename, errno);
    } else
        *error_code = MPI_SUCCESS;
}