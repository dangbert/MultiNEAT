//
// Created by matteo on 6/7/20.
//

#include "../Innovation.h"
#include <boost/python.hpp>

void export_Innovation()
{
    using namespace NEAT;
    boost::python::class_<Innovation>("Innovation", boost::python::init<int, InnovationType, int, int, NeuronType, int>())
            .def("ID", &Innovation::ID)
            .def("InnovType", &Innovation::InnovType)
            .def("FromNeuronID", &Innovation::FromNeuronID)
            .def("ToNeuronID", &Innovation::ToNeuronID)
            .def("NeuronID", &Innovation::NeuronID)
            .def("GetNeuronType", &Innovation::GetNeuronType)
            ;

}