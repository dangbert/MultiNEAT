//
// Created by matteo on 6/7/20.
//

#include "../Genes.h"
#include <boost/python.hpp>

void export_ActivationFunction()
{
    boost::python::enum_<NEAT::ActivationFunction>("ActivationFunction")
            .value("SIGNED_SIGMOID", NEAT::ActivationFunction::SIGNED_SIGMOID)
            .value("UNSIGNED_SIGMOID", NEAT::ActivationFunction::UNSIGNED_SIGMOID)
            .value("TANH", NEAT::ActivationFunction::TANH)
            .value("TANH_CUBIC", NEAT::ActivationFunction::TANH_CUBIC)
            .value("SIGNED_STEP", NEAT::ActivationFunction::SIGNED_STEP)
            .value("UNSIGNED_STEP", NEAT::ActivationFunction::UNSIGNED_STEP)
            .value("SIGNED_GAUSS", NEAT::ActivationFunction::SIGNED_GAUSS)
            .value("UNSIGNED_GAUSS", NEAT::ActivationFunction::UNSIGNED_GAUSS)
            .value("ABS", NEAT::ActivationFunction::ABS)
            .value("SIGNED_SINE", NEAT::ActivationFunction::SIGNED_SINE)
            .value("UNSIGNED_SINE", NEAT::ActivationFunction::UNSIGNED_SINE)
            .value("LINEAR", NEAT::ActivationFunction::LINEAR)
            .value("RELU", NEAT::ActivationFunction::RELU)
            .value("SOFTPLUS", NEAT::ActivationFunction::SOFTPLUS)
            ;

}