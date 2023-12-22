#ifndef NEURALNETWORK_H_
#define NEURALNETWORK_H_

#pragma once
#include <vector>
#include <iostream>
#include "Neuron.h"
#include "Layer.h"

/**
 * Class NeuralNetowork.
 * The main class of the project.
 * It initializes whole network. 
 */
class NeuralNetwork
{
public:
	/**
	 * Fucntion add_layer.
	 * Adds layer to the whole network.
	 * \param neuronss - number of neurons that new layer will have.
	 * \param laayertype of enum typ it either is standard or output on which depends if layer gets bias neuron.
	 */
	void add_layer(unsigned neurons, typ);
	/**
	* Function Initialize_weights.
	* Initializes all weights in the network.
	* Every weight is going to be random between numbers 0.0 to 1.0.
	*/
	void Initialize_weights();
	/**
	 * Function Feedforward.
	 * It calls each layer to compute output of neurons in
	 * the next layer.
	 * 
	 */
	void Feedforward();
	/**
	 * Function set_input.
	 * In the first layer of network sets neurons to desired input values
	 * \param inputvalss address of vector which stores desired input values.
	 */
	void set_input(std::vector<double> inputvals);
	/**
	 * Function Backpropagation.
	 * Computes how to alter weights between neurons so that output of network
	 * corresponds to given target values.
	 * 
	 * \param targets Address of vector. Desired target values for output layer of the network.
	 */
	void Backpropagation(std::vector<double>& target);
	/**
	 * Function totalerrorshow.
	 * Like the name suggets it returns error of the network.
	 * 
	 * \return	double total error.
	 */
	double totalerrorshow() const;
	/**
	 * Adds output values of network to the desired vector.
	 * 
	 * \param results adress of results vector which is going to store predicted values.
	 */
	void get_results(std::vector<double>& results);
private:
	/**
	 * Vector of Layer classes stores all the whole network.
	 */
	std::vector<Layer> topologi;
	/**
	 * Error of the network.
	 */
	double total_error;
};

#endif

