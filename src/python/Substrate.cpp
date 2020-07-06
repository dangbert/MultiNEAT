//
// Created by matteo on 6/7/20.
//

#include "../Substrate.h"
#include <boost/python.hpp>

void export_Substrate()
{
    using namespace NEAT;
    void (Substrate::*SetCustomConnectivity_Py)(py::list) = &Substrate::SetCustomConnectivity;

    boost::python::class_<Substrate>("Substrate", boost::python::init<>())
            .def(boost::python::init<boost::python::list, boost::python::list, boost::python::list>())
            .def("GetMinCPPNInputs", &Substrate::GetMinCPPNInputs)
            .def("GetMinCPPNOutputs", &Substrate::GetMinCPPNOutputs)
            .def("PrintInfo", &Substrate::PrintInfo)
            .def("SetCustomConnectivity", SetCustomConnectivity_Py)
            .def("ClearCustomConnectivity", &Substrate::ClearCustomConnectivity)

            .def_readwrite("m_leaky", &Substrate::m_leaky)
            .def_readwrite("m_with_distance", &Substrate::m_with_distance)
            .def_readwrite("m_custom_conn_obeys_flags", &Substrate::m_custom_conn_obeys_flags)
            .def_readwrite("m_query_weights_only", &Substrate::m_query_weights_only)
            .def_readwrite("m_hidden_nodes_activation", &Substrate::m_hidden_nodes_activation)
            .def_readwrite("m_output_nodes_activation", &Substrate::m_output_nodes_activation)

            .def_readwrite("m_allow_input_hidden_links", &Substrate::m_allow_input_hidden_links)
            .def_readwrite("m_allow_input_output_links", &Substrate::m_allow_input_output_links)
            .def_readwrite("m_allow_hidden_hidden_links", &Substrate::m_allow_hidden_hidden_links)
            .def_readwrite("m_allow_hidden_output_links", &Substrate::m_allow_hidden_output_links)
            .def_readwrite("m_allow_output_hidden_links", &Substrate::m_allow_output_hidden_links)
            .def_readwrite("m_allow_output_output_links", &Substrate::m_allow_output_output_links)
            .def_readwrite("m_allow_looped_hidden_links", &Substrate::m_allow_looped_hidden_links)
            .def_readwrite("m_allow_looped_output_links", &Substrate::m_allow_looped_output_links)

            .def_readwrite("m_max_weight_and_bias", &Substrate::m_max_weight_and_bias)
            .def_readwrite("m_min_time_const", &Substrate::m_min_time_const)
            .def_readwrite("m_max_time_const", &Substrate::m_max_time_const)

            .def_readwrite("m_input_coords", &Substrate::m_input_coords )
            .def_readwrite("m_hidden_coords", &Substrate::m_hidden_coords)
            .def_readwrite("m_output_coords", &Substrate::m_output_coords)

            .def_pickle(Substrate_pickle_suite())
            ;



}