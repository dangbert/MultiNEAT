//
// Created by matteo on 6/7/20.
//

#include "../Utils.h"
#include <boost/python.hpp>

void export_SearchMode()
{
    boost::python::enum_<SearchMode>("SearchMode")
            .value("COMPLEXIFYING", COMPLEXIFYING)
            .value("SIMPLIFYING", SIMPLIFYING)
            .value("BLENDED", BLENDED)
            ;
}