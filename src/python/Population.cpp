//
// Created by matteo on 6/7/20.
//

#include "../Population.h"
#include <boost/python.hpp>

void export_Population()
{
    using namespace NEAT;
    boost::python::class_<Population>("Population", boost::python::init<Genome, Parameters, bool, double, int>())
            .def(boost::python::init<char*>())
            .def("Epoch", &Population::Epoch)
            .def("Tick", &Population::Tick, boost::python::return_value_policy<boost::python::reference_existing_object>())
            .def("InitPhenotypeBehaviorData", &Population::InitPhenotypeBehaviorData)
            .def("NoveltySearchTick", &Population::NoveltySearchTick)
            .def("Save", &Population::Save)
            .def("GetBestFitnessEver", &Population::GetBestFitnessEver)
            .def("GetBestGenome", &Population::GetBestGenome)
            .def("GetSearchMode", &Population::GetSearchMode)
            .def("GetCurrentMPC", &Population::GetCurrentMPC)
            .def("GetBaseMPC", &Population::GetBaseMPC)
            .def("GetStagnation", &Population::GetStagnation)
            .def("GetMPCStagnation", &Population::GetMPCStagnation)
            .def("AccessGenomeByIndex", &Population::AccessGenomeByIndex, boost::python::return_value_policy<boost::python::reference_existing_object>())
            .def("AccessGenomeByID", &Population::AccessGenomeByID, boost::python::return_value_policy<boost::python::reference_existing_object>())
            .def("NumGenomes", &Population::NumGenomes)
            .def_readwrite("Species", &Population::m_Species)
            .def_readwrite("Parameters", &Population::m_Parameters)
            .def_readwrite("RNG", &Population::m_RNG)
            .def_readwrite("ID", &Population::m_ID)

            .def_pickle(Population_pickle_suite())
            ;
}