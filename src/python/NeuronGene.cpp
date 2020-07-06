//
// Created by matteo on 6/7/20.
//

#include "../Genes.h"
#include <boost/python.hpp>

void export_NeuronGene()
{
    using namespace NEAT;
    boost::python::class_<NeuronGene>("NeuronGene", boost::python::init<>())
            .def_readwrite("ID", &NeuronGene::m_ID)
            .def_readwrite("A", &NeuronGene::m_A)
            .def_readwrite("B", &NeuronGene::m_B)
            .def_readwrite("TimeConstant", &NeuronGene::m_TimeConstant)
            .def_readwrite("Bias", &NeuronGene::m_Bias)
            .def_readwrite("ActFunction", &NeuronGene::m_ActFunction)
            .def_readwrite("Type", &NeuronGene::m_Type)
            .def_readwrite("x", &NeuronGene::x)
            .def_readwrite("y", &NeuronGene::y)
            .def_readwrite("SplitY", &NeuronGene::m_SplitY)
            ;

}