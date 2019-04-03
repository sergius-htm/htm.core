# ----------------------------------------------------------------------
# Numenta Platform for Intelligent Computing (NuPIC)
# Copyright (C) 2019, David McDougall
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero Public License version 3 as
# published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU Affero Public License for more details.
#
# You should have received a copy of the GNU Affero Public License
# along with this program.  If not, see http://www.gnu.org/licenses.
# ----------------------------------------------------------------------

"""Unit tests for Grid Cell Encoder."""

import pickle
import numpy as np
import unittest
import pytest
import time

from nupic.encoders.grid_cell_encoder import GridCellEncoder
from nupic.bindings.sdr import SDR, Metrics

class GridCellEncoder_Test(unittest.TestCase):

    def testSanity(self):
        1/0

    def testStatistics(self):
        1/0

    def testNan(self):
        gc = GridCellEncoder(
            size = 200,
            sparsity = .25,
            periods = [6, 8.5, 12, 17, 24],
            seed = 42)
        zero = SDR(gc.dimensions)
        zero.randomize( .25 )
        gc.encode([3, float('nan')], zero)
        assert( zero.getSum() == 0 )

    def testDeterminism(self):
        GOLD = SDR(200)
        GOLD.sparse = [
            8, 11, 13, 15, 16, 18, 29, 32, 37, 39, 41, 42, 45, 47, 57, 59, 69,
            71, 72, 75, 80, 84, 88, 94, 95, 96, 99, 101, 106, 116, 121, 126,
            128, 135, 139, 143, 149, 150, 158, 159, 160, 171, 176, 178, 182,
            184, 188, 194, 197, 198]

        gc = GridCellEncoder(
            size = GOLD.size,
            sparsity = .25,
            periods = [6, 8.5, 12, 17, 24],
            seed = 42)

        actual = gc.encode([77, 88])
        print( actual )
        assert( actual == GOLD )
