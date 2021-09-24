/* -*- c++ -*- */
/*
 * Copyright 2021 Jacob Holtom.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_BINDJULIA_CPPMULT_IMPL_H
#define INCLUDED_BINDJULIA_CPPMULT_IMPL_H

#include <bindjulia/cppmult.h>

namespace gr {
namespace bindjulia {

class cppmult_impl : public cppmult {
private:
  // Nothing to declare in this block.

public:
  cppmult_impl();
  ~cppmult_impl();

  // Where all the action really happens
  int work(int noutput_items, gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
};

} // namespace bindjulia
} // namespace gr

#endif /* INCLUDED_BINDJULIA_CPPMULT_IMPL_H */
