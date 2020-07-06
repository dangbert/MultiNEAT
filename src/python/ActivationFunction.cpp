//
// Created by matteo on 6/7/20.
//

#include "../Genes.h"
#include <boost/python.hpp>

void export_NeuronType()
{
    boost::python::enum_<NEAT::NeuronType>("NeuronType")
            .value("NONE", NEAT::NeuronType::NONE)
            .value("INPUT", NEAT::NeuronType::INPUT)
            .value("BIAS", NEAT::NeuronType::BIAS)
            .value("HIDDEN", NEAT::NeuronType::HIDDEN)
            .value("OUTPUT", NEAT::NeuronType::OUTPUT)
            ;
}