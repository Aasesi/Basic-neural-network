#include "Neuron.h"

/**
 * Constructor sets outputvalue, num_of_outputs_in_next_layer, neuron_id to given parameters.
 * 
 * \param id
 * \param outputstart
 */
Neuron::Neuron(unsigned id_, double outputstart)
{
	outputvalue = outputstart;
	num_of_outputs_in_next_layer = 0;
	neuron_id = id_;
}
/**
 * Learning rate.
 */
double Neuron::eta = 0.01;
/**
 * Shows outputvalue.
 * 
 * \return outputvalue
 */
double Neuron::Output_val_show() const
{
	return outputvalue;
}
/**
 * Creates Connection class and adds it to weights vector.
 * 
 * \param num
 */
void Neuron::Set_num_of_weights(int num)
{
	num_of_outputs_in_next_layer = num;
	for (int i = 0; i < num_of_outputs_in_next_layer; i++)
	{
		weights.push_back(Connection());
	}
}
/**
 * Creates Connection class and adds it to weights vector.
 * 
 * \param num
 */
void Neuron::Set_num_of_weights_for_bias(int num)
{
	num_of_outputs_in_next_layer = num;
	for (int i = 0; i < num_of_outputs_in_next_layer; i++)
	{
		weights.push_back(Connection());
	}
}
/**
 * Sets outputvalue variable.
 * 
 * \param _output
 */
void Neuron::Set_output_val(double _output)
{
	outputvalue = _output;
}
/**
 * Returns weights variable
 * 
 * \return weights
 */
std::vector<Connection>& Neuron::use_weights()
{
	return weights;
}
/**
 * Calculates new outputvalue variable .
 * 
 * \param prevlayer
 */
void Neuron::feedforward_neuron(std::vector<Neuron>& prevlayerr)
{
	double sum = 0.0;
	for (unsigned i = 0; i < prevlayerr.size(); i++)
	{
		sum += prevlayerr[i].Output_val_show() * prevlayerr[i].use_weights()[neuron_id].use_weight();
	}
	outputvalue = sigmoid_function(sum);
}
/**
 * Sigmoid function.
 * 
 * \param sum
 * \return 
 */
double Neuron::sigmoid_function(double sum)
{
	//return tanh(sum);
	return 1 / (1 + exp(-sum));
}
/**
 * Sigmoid function derivative.
 * 
 * \param sum
 * \return 
 */
double Neuron::sigmoid_function_derivative(double sum)
{
	//return 1.0 - sum * sum;
	return sum * (1 - sum);
}
/**
 * Backpropagation Algorythm for output layer.
 * 
 * \param prevlayer
 * \param target
 */
void Neuron::Backpropagate_output(std::vector<Neuron>& prevlayer, double target)
{
	double derivative = target - Output_val_show();
	for (int i = 0; i < prevlayer.size(); i++)
	{
		double somenum = prevlayer[i].Output_val_show();
		double delta = derivative * somenum * sigmoid_function_derivative(Output_val_show());
		prevlayer[i].use_weights()[neuron_id].update_weight(delta, eta);

	}
}
/**
 * Backpropagation Algorythm for standard layer.
 * 
 * \param prelayer
 * \param prediction
 * \param target
 */
void Neuron::Backpropagate_rest(std::vector<Neuron>& prelayer, double prediction, double target)
{
	double derivative = prediction - target;
	for (int i = 0; i < prelayer.size(); i++)
	{
		double somenum = prelayer[i].Output_val_show();
		double currentweight = use_weights()[0].show_prevweight();
		double delta = derivative * somenum * sigmoid_function_derivative(Output_val_show()) * currentweight;
		prelayer[i].use_weights()[neuron_id].update_weight(delta, eta);
	}
}
