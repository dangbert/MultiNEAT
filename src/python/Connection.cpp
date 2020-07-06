//
// Created by matteo on 6/7/20.
//

#include "../NeuralNetwork.h"
#include <boost/python.hpp>

void export_Connection()
{
    using namespace NEAT;
    boost::python::class_<Connection>("Connection", boost::python::init<>())
            .def_readwrite("source_neuron_idx", &Connection::m_source_neuron_idx)
            .def_readwrite("target_neuron_idx", &Connection::m_target_neuron_idx)
            .def_readwrite("weight", &Connection::m_weight)
            .def_readwrite("recur_flag", &Connection::m_recur_flag)
            .def_readwrite("hebb_rate", &Connection::m_hebb_rate)
            .def_readwrite("hebb_pre_rate", &Connection::m_hebb_pre_rate)
            ;

}