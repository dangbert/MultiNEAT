//
// Created by matteo on 6/7/20.
//

#include "../Random.h"
#include <boost/python.hpp>

void export_RNG()
{
    boost::python::class_<NEAT::RNG>("RNG", boost::python::init<>())
            .def("Seed", &NEAT::RNG::Seed)
            .def("TimeSeed", &NEAT::RNG::TimeSeed)
            .def("RandPosNeg", &NEAT::RNG::RandPosNeg)
            .def("RandInt", &NEAT::RNG::RandInt)
            .def("RandFloat", &NEAT::RNG::RandFloat)
            .def("RandFloatSigned", &NEAT::RNG::RandFloatSigned)
            .def("RandGaussSigned", &NEAT::RNG::RandGaussSigned)
            .def("Roulette", &NEAT::RNG::Roulette)
            ;

}