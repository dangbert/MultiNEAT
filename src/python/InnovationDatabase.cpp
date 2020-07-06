//
// Created by matteo on 6/7/20.
//

#include "../Innovation.h"
#include <boost/python.hpp>

void export_InnovationDatabase()
{
    using namespace NEAT;
    boost::python::class_<InnovationDatabase>("InnovationDatabase", boost::python::init<>())
            .def(boost::python::init<int, int>())
            .def("Init_i_i", static_cast<void (InnovationDatabase::*)(int,int)>(&InnovationDatabase::Init))
            .def("Init_with_genome", static_cast<void (InnovationDatabase::*)(const Genome&)>(&InnovationDatabase::Init))
            .def("Init_with_file", static_cast<void (InnovationDatabase::*)(std::ifstream&)>(&InnovationDatabase::Init))
            .def("Flush", &InnovationDatabase::Flush)
            .def("GetInnovationByIdx", &InnovationDatabase::GetInnovationByIdx)
            .def("Save", &InnovationDatabase::Save)
            ;

}