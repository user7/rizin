/* radare - LGPL - Copyright 2009-2015 - ninjahacker */

#include <rz_types.h>
#include <rz_util.h>
#include "zimg.h"


struct rz_bin_zimg_obj_t* rz_bin_zimg_new_buf(RBuffer *buf) {
	struct rz_bin_zimg_obj_t *bin = R_NEW0 (struct rz_bin_zimg_obj_t);
	if (!bin) {
		goto fail;
	}
	bin->size = rz_buf_size (buf);
	bin->b = rz_buf_ref (buf);
	if (rz_buf_size (bin->b) < sizeof (struct zimg_header_t)) {
		goto fail;
	}
	rz_buf_read_at (bin->b, 0, (ut8 *)&bin->header, sizeof (bin->header));
	return bin;

fail:
	if (bin) {
		rz_buf_free (bin->b);
		free (bin);
	}
	return NULL;
}

