#ifndef NEURON_H_
#define NEURON_H_

#pragma once
#include <vector>
#include "Connection.h"
#include <cmath>

/**
 * Class Neuron the most important class in whole neural netowrk.
 * It contains all functions that do every necessary caluclation for network to work.
 */
class Neuron
{
public:
	/**
	 * Constructor of Neuron class.
	 * Sets few necessary variables of private section.
	 * 
	 * \param id_ information about its neuron_id.
	 * \param outputstart information about its output values.
	 */
	Neuron(unsigned id_, double);
	/**
	 * Normal member.
	 * 
	 * \return ouputvalue.
	 */
	double Output_val_show() const;
	/**
	 * Void member which adds elements to weights vector and sets num_of_outputs_in_next_layer of private section.
	 * 
	 * \param num number of outputs in next layer.
	 */
	void Set_num_of_weights(int);
	/**
	 * Void member.
	 * Sets num_of_outputs_in_next_layer.
	 * 
	 * \param 
	 */
	void Set_num_of_weights_for_bias(int);
	/**
	 * Void member it only sets outputvalue variable.
	 * 
	 * \param 
	 */
	void Set_output_val(double);
	/**
	 * Void member of Neuron class.
	 * It does all necessary math calculations to set outputvalue variable..
	 * 
	 * \param prevlayerr contains adress of previous layer.
	 */
	void feedforward_neuron(std::vector<Neuron>&);
	/**
	 * Void member.
	 * Contains algorthym for backpropagation of output layer neuron.
	 * 
	 * \param prevlayer reference to prevlayer.
	 * \param target
	 */
	void Backpropagate_output(std::vector<Neuron>&, double);
	/**
	 * Void member.
	 * Backpropagation algorythm for standard type layers.
	 * 
	 * \param prelayer reference to prevlayer
	 * \param prediction current outputvalue of next layer neuron.
	 * \param target targeted value.
	 */
	void Backpropagate_rest(std::vector<Neuron>&, double , double);
	/**
	 * Returns weights vector.
	 * 
	 * \return weights
	 */
	std::vector<Connection>& use_weights();
private:
	/**
	 * weights vector variable.
	 */
	std::vector<Connection> weights;
	/**
	 * variable eta.
	 */
	static double eta;
	/**
	 * Static double member.
	 * Returns sigmoid function of double.
	 * 
	 * \param double
	 * \return sigmoid function of parameter
	 */
	static double sigmoid_function(double);
	/**
	 * Static double member of private section.
	 * Returns simogid function derivative of parameter.
	 * 
	 * \param double
	 * \return double
	 */
	static double sigmoid_function_derivative(double);
	/**
	 * Output value parameter.
	 */
	double outputvalue;
	/**
	 * Int num_of_outputs_in_next_layer.
	 */
	int num_of_outputs_in_next_layer;
	/**
	 * Id of the neuron.
	 */
	unsigned neuron_id;
};

#endif
