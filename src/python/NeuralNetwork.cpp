//
// Created by matteo on 6/7/20.
//

#include "../NeuralNetwork.h"
#include <boost/python.hpp>

void export_NeuralNetwork()
{
    using namespace NEAT;

    void (NeuralNetwork::*NN_Save)(const char*) = &NeuralNetwork::Save;
    bool (NeuralNetwork::*NN_Load)(const char*) = &NeuralNetwork::Load;
    void (NeuralNetwork::*NN_Input)(const py::list&) = &NeuralNetwork::Input_python_list;
    void (NeuralNetwork::*NN_Input_numpy)(const pyndarray&) = &NeuralNetwork::Input_numpy;

    boost::python::class_<NeuralNetwork>("NeuralNetwork", boost::python::init<>())

            .def(boost::python::init<bool>())

            .def("InitRTRLMatrix",
                 &NeuralNetwork::InitRTRLMatrix)
            .def("RTRL_update_gradients",
                 &NeuralNetwork::RTRL_update_gradients)
            .def("RTRL_update_error",
                 &NeuralNetwork::RTRL_update_error)
            .def("RTRL_update_weights",
                 &NeuralNetwork::RTRL_update_weights)

            .def("ActivateFast",
                 &NeuralNetwork::ActivateFast)
            .def("Activate",
                 &NeuralNetwork::Activate)
            .def("ActivateUseInternalBias",
                 &NeuralNetwork::ActivateUseInternalBias)
            .def("ActivateLeaky",
                 &NeuralNetwork::ActivateLeaky)

            .def("Adapt",
                 &NeuralNetwork::Adapt)

            .def("Flush",
                 &NeuralNetwork::Flush)
            .def("FlushCude",
                 &NeuralNetwork::InitRTRLMatrix)

            .def("NumInputs",
                 &NeuralNetwork::NumInputs)
            .def("NumOutputs",
                 &NeuralNetwork::NumOutputs)

            .def("Clear",
                 &NeuralNetwork::Clear)
            .def("Save",
                 NN_Save)
            .def("Load",
                 NN_Load)

            .def("Input",
                 NN_Input)
            .def("Input",
                 NN_Input_numpy)
            .def("Output",
                 &NeuralNetwork::Output)

            .def("AddNeuron",
                 &NeuralNetwork::AddNeuron)
            .def("AddConnection",
                 &NeuralNetwork::AddConnection)
            .def("SetInputOutputDimentions",
                 &NeuralNetwork::SetInputOutputDimentions)

            .def("GetTotalConnectionLength", &NeuralNetwork::GetTotalConnectionLength)


            .def_readwrite("neurons", &NeuralNetwork::m_neurons)
            .def_readwrite("connections", &NeuralNetwork::m_connections)
            ;

}