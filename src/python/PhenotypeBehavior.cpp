//
// Created by matteo on 6/7/20.
//

#include "../Genome.h"
#include "../PhenotypeBehavior.h"
#include <boost/python.hpp>

void export_PhenotypeBehavior()
{
    using namespace NEAT;
    boost::python::class_<PhenotypeBehavior, PhenotypeBehavior*>("PhenotypeBehavior", boost::python::init<>())

            .def("Acquire", &PhenotypeBehavior::Acquire)
            .def("Distance_To", &PhenotypeBehavior::Distance_To)
            .def("Successful", &PhenotypeBehavior::Successful)

            .def_readwrite("m_Data", &PhenotypeBehavior::m_Data)
            ;
}

namespace boost
{
// Fix Visual Studio 2015 linker bug affecting linking wiht boost-python
// https://stackoverflow.com/questions/38261530/unresolved-external-symbols-since-visual-studio-2015-update-3-boost-python-link
template <>
NEAT::PhenotypeBehavior const volatile * get_pointer<class NEAT::PhenotypeBehavior const volatile >(
        class NEAT::PhenotypeBehavior const volatile *c)
{
    return c;
}
}
