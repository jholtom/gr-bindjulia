#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright 2021 Jacob Holtom.
#
# SPDX-License-Identifier: GPL-3.0-or-later
#


import numpy
import copy
from gnuradio import gr

class pyjulia_mult(gr.sync_block):
    """
    docstring for block pyjulia_mult
    """
    def __init__(self):
        gr.sync_block.__init__(self,
            name="pyjulia_mult",
            in_sig=[numpy.float32, numpy.float32 ],
            out_sig=[numpy.float32, ])

    def start(self):
        import julia
        return super().start()

    def stop(self):
        # Need to unload Julia safely
        julia = None
        return super().stop()

    def work(self, input_items, output_items):
        in0, in1 = input_items
        out = output_items[0]
        from julia import Main
        Main.in0 = in0
        Main.in1 = in1
        out[:] = Main.eval("in0 .* in1")
        return len(output_items[0])
