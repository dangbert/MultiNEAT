/*
 * PythonBindings.cpp
 *
 *  Created on: Jun 26, 2012
 *      Author: peter
 */

///////////////////////////////////////////////////////////////////////////////////////////
//    MultiNEAT - Python/C++ NeuroEvolution of Augmenting Topologies Library
//
//    Copyright (C) 2012 Peter Chervenski
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Lesser General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU Lesser General Public License
//    along with this program.  If not, see < http://www.gnu.org/licenses/ >.
//
//    Contact info:
//
//    Peter Chervenski < spookey@abv.bg >
//    Shane Ryan < shane.mcdonald.ryan@gmail.com >
///////////////////////////////////////////////////////////////////////////////////////////

#ifdef USE_BOOST_PYTHON

#include <boost/python.hpp>

#include <boost/version.hpp>
#if BOOST_VERSION < 106500
    #include <boost/python/numeric.hpp>
#else
    #include <boost/python/numpy.hpp>
#endif

#include <boost/python/tuple.hpp>

//#include "../NeuralNetwork.h"
//#include "../Genome.h"

namespace py = boost::python;
//using namespace NEAT;
using namespace py;

#if BOOST_VERSION < 106500
    typedef typename numeric::array pyndarray;
#else
    typedef typename numpy::ndarray pyndarray;
#endif

void export_NeuronType();
void export_ActivationFunction();
void export_SearchMode();
void export_RNG();
void export_Connection();
void export_Neuron();
void export_NeuralNetwork();
void export_LinkGene();
void export_NeuronGene();
void export_Genome();
void export_Species();
void export_Substrate();
void export_PhenotypeBehavior();
void export_Population();
void export_Innovation();
void export_InnovationDatabase();
void export_Parameters();
void export_Lists();

BOOST_PYTHON_MODULE(_multineat)
{
    Py_Initialize();

    #if BOOST_VERSION < 106500
        numeric::array::set_module_and_type("numpy", "ndarray");
    #else
        boost::python::numpy::initialize();
        PyErr_Print(); // Print possible error from initialize call as otherwise it will crash if another error occurs
        // On MacOS with 'ImportError: numpy.core.umath failed to import' error is produced, but NEAT still works
    #endif

///////////////////////////////////////////////////////////////////
// Enums
///////////////////////////////////////////////////////////////////

    export_NeuronType();
    export_ActivationFunction();
    export_SearchMode();

///////////////////////////////////////////////////////////////////
// RNG class
///////////////////////////////////////////////////////////////////
    export_RNG();

///////////////////////////////////////////////////////////////////
// Neural Network class
///////////////////////////////////////////////////////////////////

    export_Connection();
    export_Neuron();
    export_NeuralNetwork();

///////////////////////////////////////////////////////////////////
// Genome class
///////////////////////////////////////////////////////////////////

    export_LinkGene();
    export_NeuronGene();
    export_Genome();

///////////////////////////////////////////////////////////////////
// Species class
///////////////////////////////////////////////////////////////////

    export_Species();

///////////////////////////////////////////////////////////////////
// Substrate class
///////////////////////////////////////////////////////////////////

    export_Substrate();

///////////////////////////////////////////////////////////////////
// PhenotypeBehavior class
///////////////////////////////////////////////////////////////////

    export_PhenotypeBehavior();

///////////////////////////////////////////////////////////////////
// Population class
///////////////////////////////////////////////////////////////////

    export_Population();

    export_Innovation();

    export_InnovationDatabase();

///////////////////////////////////////////////////////////////////
// Parameters class
///////////////////////////////////////////////////////////////////

    export_Parameters();

/////////////////////////////////////////////////////////
// General stuff applicable across the entire module
/////////////////////////////////////////////////////////

    export_Lists();

}

#endif // USE_BOOST_PYTHON
