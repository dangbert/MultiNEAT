//
// Created by matteo on 6/7/20.
//

#include "../Genes.h"
#include <boost/python.hpp>

void export_LinkGene()
{
    using namespace NEAT;
    boost::python::class_<LinkGene>("LinkGene", boost::python::init<>())
            .def_readwrite("FromNeuronID", &LinkGene::m_FromNeuronID)
            .def_readwrite("ToNeuronID", &LinkGene::m_ToNeuronID)
            .def_readwrite("InnovationID", &LinkGene::m_InnovationID)
            .def_readwrite("Weight", &LinkGene::m_Weight)
            .def_readwrite("IsRecurrent", &LinkGene::m_IsRecurrent)
            ;

}