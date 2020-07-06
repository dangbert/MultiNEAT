//
// Created by matteo on 6/7/20.
//

#include "../Random.h"
#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

#include "../Genome.h"
#include "../Species.h"
#include "../NeuralNetwork.h"

void export_Lists()
{
    boost::python::class_< std::vector<double> >("DoublesList")
            .def(boost::python::vector_indexing_suite< std::vector<double> >() )
            ;

    boost::python::class_< std::vector< std::vector<double> > >("DoublesList2D")
            .def(boost::python::vector_indexing_suite< std::vector< std::vector<double> > >() )
            ;

    boost::python::class_< std::vector<float> >("FloatsList")
            .def(boost::python::vector_indexing_suite< std::vector<float> >() )
            ;

    boost::python::class_< std::vector< std::vector<float> > >("FloatsList2D")
            .def(boost::python::vector_indexing_suite< std::vector< std::vector<float> > >() )
            ;

    boost::python::class_< std::vector<int> >("IntsList")
            .def(boost::python::vector_indexing_suite< std::vector<int> >() )
            ;

    boost::python::class_< std::vector< std::vector<int> > >("IntsList2D")
            .def(boost::python::vector_indexing_suite< std::vector< std::vector<int> > >() )
            ;

    // These are necessary to let us iterate through the vectors of species, genomes and genes
    boost::python::class_< std::vector<NEAT::Genome> >("GenomeList")
            .def(boost::python::vector_indexing_suite< std::vector<NEAT::Genome> >() )
            ;

    boost::python::class_< std::vector<NEAT::Species> >("SpeciesList")
            .def(boost::python::vector_indexing_suite< std::vector<NEAT::Species> >() )
            ;

    // These are necessary to iterate through lists of Neurons and Connections
    boost::python::class_< std::vector<NEAT::Neuron> >("NeuronList")
            .def(boost::python::vector_indexing_suite< std::vector<NEAT::Neuron> >() )
            ;

    boost::python::class_< std::vector<NEAT::Connection> >("ConnectionList")
            .def(boost::python::vector_indexing_suite< std::vector<NEAT::Connection> >() )
            ;

    boost::python::class_< std::vector<NEAT::NeuronGene> >("NeuronGeneList")
            .def(boost::python::vector_indexing_suite< std::vector<NEAT::NeuronGene> >() )
            ;

    boost::python::class_< std::vector<NEAT::LinkGene> >("LinkGeneList")
            .def(boost::python::vector_indexing_suite< std::vector<NEAT::LinkGene> >() )
            ;

    // For dealing with Phenotype behaviors
    boost::python::class_< std::vector<NEAT::PhenotypeBehavior> >("PhenotypeBehaviorList")
            .def(boost::python::vector_indexing_suite< std::vector<NEAT::PhenotypeBehavior> >() )
            ;
}