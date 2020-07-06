//
// Created by matteo on 6/7/20.
//

#include "../Genome.h"
#include <boost/python.hpp>

void export_Genome()
{
    using namespace NEAT;

    void (Genome::*Genome_Save)(const char*) = &Genome::Save;

    boost::python::class_<Genome, Genome*>("Genome", boost::python::init<>())

            .def(boost::python::init<char*>())
            .def(boost::python::init<const Genome&>())
            .def(boost::python::init<unsigned int, unsigned int, unsigned int, unsigned int,
                    ActivationFunction, ActivationFunction, Parameters>())
            .def(boost::python::init<unsigned int, unsigned int, unsigned int, unsigned int,
                    bool, ActivationFunction, ActivationFunction, int, Parameters, unsigned int>())

            .def("NumNeurons", &Genome::NumNeurons)
            .def("NumLinks", &Genome::NumLinks)
            .def("NumInputs", &Genome::NumInputs)
            .def("NumOutputs", &Genome::NumOutputs)

            .def_readwrite("NeuronGenes", &Genome::m_NeuronGenes)
            .def_readwrite("LinkGenes", &Genome::m_LinkGenes)
            .def_readwrite("behavior", &Genome::m_behavior)

            .def("GetFitness", &Genome::GetFitness)
            .def("SetFitness", &Genome::SetFitness)
            .def("GetAdjFitness", &Genome::GetAdjFitness)
            .def("SetAdjFitness", &Genome::SetAdjFitness)
            .def("GetID", &Genome::GetID)
            .def("SetID", &Genome::SetID)
            .def("GetDepth", &Genome::GetDepth)
            .def("CalculateDepth", &Genome::CalculateDepth)
            .def("DerivePhenotypicChanges", &Genome::DerivePhenotypicChanges)
            .def("CompatibilityDistance", &Genome::CompatibilityDistance)
            .def("IsCompatibleWith", &Genome::IsCompatibleWith)

            .def("PrintAllTraits", &Genome::PrintAllTraits)

            .def("BuildPhenotype", &Genome::BuildPhenotype)
            .def("BuildHyperNEATPhenotype", &Genome::BuildHyperNEATPhenotype)
            .def("BuildESHyperNEATPhenotype", &Genome::BuildESHyperNEATPhenotype)

            .def("Randomize_LinkWeights", &Genome::Randomize_LinkWeights)
            .def("Randomize_Traits", &Genome::Randomize_Traits)
            .def("Mutate_NeuronActivations_A", &Genome::Mutate_NeuronActivations_A)
            .def("Mutate_NeuronActivations_B", &Genome::Mutate_NeuronActivations_B)
            .def("Mutate_NeuronActivation_Type", &Genome::Mutate_NeuronActivation_Type)
            .def("Mutate_NeuronTimeConstants", &Genome::Mutate_NeuronTimeConstants)
            .def("Mutate_NeuronBiases", &Genome::Mutate_NeuronBiases)
            .def("GetNeuronTraits", &Genome::GetNeuronTraits)
            .def("GetLinkTraits", &Genome::GetLinkTraits)
            .def("GetGenomeTraits", &Genome::GetGenomeTraits)

            .def("FailsConstraints", &Genome::FailsConstraints)

            .def("IsEvaluated", &Genome::IsEvaluated)
            .def("SetEvaluated", &Genome::SetEvaluated)
            .def("ResetEvaluated", &Genome::ResetEvaluated)

            .def("Save", Genome_Save)

            .def("Mate", &Genome::Mate)
            .def("Mutate", &Genome::Mutate)

            .def("Serialize", &Genome::Serialize)
            .def("Deserialize", &Genome::Deserialize)
            .def_pickle(Genome_pickle_suite())
            ;

}