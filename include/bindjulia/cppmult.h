/* -*- c++ -*- */
/*
 * Copyright 2021 Jacob Holtom.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_BINDJULIA_CPPMULT_H
#define INCLUDED_BINDJULIA_CPPMULT_H

#include <bindjulia/api.h>
#include <gnuradio/sync_block.h>
#include <julia/julia.h>

namespace gr {
namespace bindjulia {

/*!
 * \brief <+description of block+>
 * \ingroup bindjulia
 *
 */
class BINDJULIA_API cppmult : virtual public gr::sync_block {
public:
  typedef std::shared_ptr<cppmult> sptr;

  /*!
   * \brief Return a shared_ptr to a new instance of bindjulia::cppmult.
   *
   * To avoid accidental use of raw pointers, bindjulia::cppmult's
   * constructor is in a private implementation
   * class. bindjulia::cppmult::make is the public interface for
   * creating new instances.
   */
  static sptr make();
};

} // namespace bindjulia
} // namespace gr

#endif /* INCLUDED_BINDJULIA_CPPMULT_H */
