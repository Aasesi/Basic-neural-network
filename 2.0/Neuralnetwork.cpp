#include "NeuralNetwork.h"

/**
 * Function adds to topologi vector additional element of class Layer.
 * 
 * \param neurons
 * \param laayertype of enum
 */
void NeuralNetwork::add_layer(unsigned neuronss, typ laayertype)
{
	topologi.push_back(Layer(neuronss, laayertype));
}
/**
 * Simple for loop which calls initializeweights(int) for a topolgi vector element which is of class: Layer.
 * It also gives the element number of neurons in the next layer.
 */
void NeuralNetwork::Initialize_weights() 
{
	for (unsigned i = 0; i < topologi.size() - 1; i++)
	{
		int outputs = topologi[i + 1].Size_of_layer();
		topologi[i].initializeweights(outputs);
	}
}
/**
 * First for loop goes throught every layer of network except for the first layer.
 * Then prevlayer vector& is created to give next for loop needed information.
 * Last loop goes throught all neurons to call their class function feedforward_neuron(vector<Neuron>&).
 */
void NeuralNetwork::Feedforward()
{
	for (unsigned l = 1; l < topologi.size(); l++)
	{
		std::vector<Neuron>& prevlayer = topologi[l - 1].use_neurons(); 
		for (int n = 0; n < topologi[l].Size_of_layer(); n++) 
		{
			topologi[l].use_neurons()[n].feedforward_neuron(prevlayer);
		}
	}

}
/**
 * Like name suggests function sets input values for the first layer's neurons.
 * 
 * \param inputvalss
 */
void NeuralNetwork::set_input(std::vector<double> inputvalss)
{
	for (unsigned i = 0; i < inputvalss.size(); i++)
	{
		topologi[0].use_neurons()[i].Set_output_val(inputvalss[i]);
	}
}
/**
 * Function calculates total error then secound loop calls function member of class Neuron to determine gradients for output layer and update the weights.
 * Next loop has the same job but it computes gradients for the rest of the network.
 * 
 * \param targets
 */
void NeuralNetwork::Backpropagation(std::vector<double>& targets)
{
	total_error = 0.0;
	for (int n = 0; n < topologi.back().Size_of_layer(); n++)
	{
		double out =topologi.back().use_neurons()[n].Output_val_show();
		double first_part = targets[n] - out;
		total_error += (first_part * first_part) * 0.5
			;
	}
	for (int n = 0; n < topologi.back().Size_of_layer(); n++)
	{
		Layer& prevlayer = topologi[topologi.size() - 2];
		topologi.back().use_neurons()[n].Backpropagate_output(prevlayer.use_neurons(), targets[n]);
	}

	for (int l = topologi.size() - 2; l > 0; l--)
	{
		Layer& currentlayer = topologi[l];
		Layer& prevlayer = topologi[l - 1];
		for (int n = 0; n < currentlayer.Size_of_layer(); n++)
		{
			currentlayer.use_neurons()[n].Backpropagate_rest(prevlayer.use_neurons(), targets[0], topologi.back().use_neurons()[0].Output_val_show());
		}
	}
}
/**
 * Returns total error.
 * 
 * \return 
 */
double NeuralNetwork::totalerrorshow() const
{
	return total_error;
}
/**
 * Gets output values of the last layer.
 * 
 * \param results
 */
void NeuralNetwork::get_results(std::vector<double>& results)
{
	results.clear();
	results.push_back(topologi.back().use_neurons()[0].Output_val_show());
}
