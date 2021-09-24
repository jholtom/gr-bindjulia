/* -*- c++ -*- */
/*
 * Copyright 2021 Jacob Holtom.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "cppmult_impl.h"
#include <gnuradio/io_signature.h>

namespace gr {
namespace bindjulia {

using input_type = float;
using output_type = float;
cppmult::sptr cppmult::make() {
  return gnuradio::make_block_sptr<cppmult_impl>();
}

/*
 * The private constructor
 */
cppmult_impl::cppmult_impl()
    : gr::sync_block(
          "cppmult",
          gr::io_signature::make(1 /* min inputs */, 2 /* max inputs */,
                                 sizeof(input_type)),
          gr::io_signature::make(1 /* min outputs */, 1 /*max outputs */,
                                 sizeof(output_type))) {
    }

/*
 * Our virtual destructor.
 */
cppmult_impl::~cppmult_impl() {}


bool cppmult_impl::start() {
        jl_init();

}

bool cppmult_impl::stop() {

}


int cppmult_impl::work(int noutput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items) {
  const input_type *in0 = reinterpret_cast<const input_type *>(input_items[0]);
  const input_type *in1 = reinterpret_cast<const input_type *>(input_items[1]);
  output_type *out = reinterpret_cast<output_type *>(output_items[0]);

jl_function_t *func = jl_get_function(jl_base_module, "muladd");
jl_value_t *arg1 = jl_box_float64(2.0);
jl_value_t *arg2 = jl_box_float64(4.0);
jl_value_t *arg3 = jl_box_float64(1.0);
jl_value_t *ret = jl_call3(func, arg1, arg2, arg3);
if (jl_typeis(ret, jl_float64_type)) {
    double ret_unboxed = jl_unbox_float64(ret);
    printf("Muladd out: %f\n", ret_unboxed);
}
else {
    printf("ERROR: unexpected return type from muladd(::Float64)\n");
}
/*
for(int i = 0; i < noutput_items; i++){

jl_value_t *arg1 = jl_box_float64(in0[i]);
jl_value_t *arg2 = jl_box_float64(in1[i]);
jl_value_t *arg3 = jl_box_float64(0.0);
jl_value_t *ret = jl_call3(func, arg1, arg2, arg3);

if (jl_typeis(ret, jl_float64_type)) {
    double ret_unboxed = jl_unbox_float64(ret);
    out[i] = static_cast< float >(ret_unboxed);
}
else {
    printf("ERROR: unexpected return type from muladd(::Float64)\n");
}
}
*/
  // Tell runtime system how many output items we produced.
  return noutput_items;
}

} /* namespace bindjulia */
} /* namespace gr */
