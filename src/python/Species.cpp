//
// Created by matteo on 6/7/20.
//

#include "../Species.h"
#include <boost/python.hpp>

void export_Species()
{
    using namespace NEAT;
    boost::python::class_<Species>("Species", boost::python::init<Genome, int>())
            .def("GetLeader", &Species::GetLeader)
            .def("NumIndividuals", &Species::NumIndividuals)
            .def("GensNoImprovement", &Species::GensNoImprovement)
            .def("ID", &Species::ID)
            .def("AgeGens", &Species::AgeGens)
            .def("IsBestSpecies", &Species::IsBestSpecies)
            .def_readwrite("Individuals", &Species::m_Individuals)
            .def_readonly("Red", &Species::m_R)
            .def_readonly("Green", &Species::m_G)
            .def_readonly("Blue", &Species::m_B)
            .def_readwrite("EvalsNoImprovement", &Species::m_EvalsNoImprovement)
            .def_readwrite("BestFitness", &Species::m_BestFitness)
            ;

}