//
// Created by matteo on 6/7/20.
//

#include "../NeuralNetwork.h"
#include <boost/python.hpp>

void export_Neuron()
{
    using namespace NEAT;
    boost::python::class_<Neuron>("Neuron", boost::python::init<>())
            .def_readwrite("a", &Neuron::m_a)
            .def_readwrite("b", &Neuron::m_b)
            .def_readwrite("time_const", &Neuron::m_timeconst)
            .def_readwrite("bias", &Neuron::m_bias)
            .def_readwrite("activation", &Neuron::m_activation)
            .def_readwrite("activation_function_type", &Neuron::m_activation_function_type)
            .def_readwrite("split_y", &Neuron::m_split_y)
            .def_readwrite("type", &Neuron::m_type)
            .def_readwrite("x", &Neuron::m_x)
            .def_readwrite("y", &Neuron::m_y)
            .def_readwrite("z", &Neuron::m_z)
            .def_readwrite("substrate_coords", &Neuron::m_substrate_coords)
            ;

}