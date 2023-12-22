#ifndef LAYER_H_
#define LAYER_H_
#include <vector>
#include <iostream>
#include "Neuron.h"
#pragma once

/**
 * An enum.
 * Enum typ with two elemnets. 
 */
enum typ { standard, output };

/**
 * Class Layer is composed of multiple neurons which it stores 
 * in its private section: vector<Neuron> neurons.
 */
class Layer
{
private:
	/**
	 * Container for neurons.
	 */
	std::vector<Neuron> neurons;
	/**
	 * private variable numberofneurons.
	 * Stores information about size of neurons vector, without bias.
	 */
	int numberofneurons;
public:
	/**
	 * Constructor.
	 * Adds new neurons to vector neurons.
	 * 
	 * \param numberofneuron_ stores information how many neurons are supposed to be in layer.
	 * \param typee information about type of layer.
	 */
	Layer(int , typ);
	/**
	 * normal member.
	 * 
	 * \return numberofneurons.
	 */
	int Size_of_layer() const;
	/**
	 * Member returning adress of vector of class neuron.
	 * 
	 * \return neurons.
	 */
	std::vector<Neuron>& use_neurons();
	/**
	 * public variable of enum typ.
	 * Contains type of Layer.
	 */
	typ layer_type;
	/**
	 * void function which initialize weights for each neuron.
	 * 
	 * \param outss number of neurons in next layer.
	 */
	void initializeweights(int);
};

#endif

