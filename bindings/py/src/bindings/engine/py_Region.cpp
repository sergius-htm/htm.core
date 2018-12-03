/* ---------------------------------------------------------------------
 * Numenta Platform for Intelligent Computing (NuPIC)
 * Copyright (C) 2018, Numenta, Inc.  Unless you have an agreement
 * with Numenta, Inc., for a separate license for this software code, the
 * following terms and conditions apply:
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Affero Public License for more details.
 *
 * You should have received a copy of the GNU Affero Public License
 * along with this program.  If not, see http://www.gnu.org/licenses.
 *
 * http://numenta.org/licenses/
 *
 * Author: @chhenning, 2018
 * ---------------------------------------------------------------------
 */

/** @file
PyBind11 bindings for Region class
*/

// the use of 'register' keyword is removed in C++17
// Python2.7 uses 'register' in unicodeobject.h
#ifdef _WIN32
#pragma warning( disable : 5033)  // MSVC
#else
#pragma GCC diagnostic ignored "-Wregister"  // for GCC and CLang
#endif

#include <pybind11/pybind11.h>
#include <pybind11/iostream.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>

#include <nupic/engine/PyBindRegion.hpp>
#include <nupic/engine/TestNode.hpp>

namespace py = pybind11;
using namespace nupic;

namespace nupic_ext
{
    void init_Regions(py::module& m)
    {
        ///////////////////
        // PyRegion Node
        ///////////////////
        typedef nupic::PyBindRegion Region_t;
        py::class_<Region_t> py_Region(m, "PyRegion");

        py_Region.def("initialize", &Region_t::initialize)
            .def("compute", &Region_t::compute);

        py_Region.def("getSpec", &Region_t::getSpec);


        ///////////////////
        // Test Node
        ///////////////////
        py::class_<TestNode> py_TestNode(m, "TestNode");
        py_TestNode.def("initialize", &TestNode::initialize)
            .def("compute", &TestNode::compute)
            .def("getName", [](const TestNode& self) { return "Hello";  });

    }

} // namespace nupic_ext
