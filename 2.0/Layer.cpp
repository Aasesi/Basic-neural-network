#include "Layer.h"

/**
 * Function first initializes some using data given in parameters class variables.
 * Then checks type of layer to decide if it should contain bias neuron.
 * Lastly in for loop creates new Neuron Class and adds it to neurons vector.
 * 
 * \param numberofneuron
 * \param typee
 */
Layer::Layer(int numberofneuron_, typ typee)
{
	layer_type = typee;
	numberofneurons = numberofneuron_;
	if (layer_type == typ::standard) {
		for (int i = 0; i <= numberofneurons; i++)
		{
			if (i == numberofneurons)
			{
				neurons.push_back(Neuron(i, 0.50));
			}

			else
			{
				neurons.push_back(Neuron(i, 0.0));
			}
		}
	}
	else {
		for (int i = 0; i < numberofneurons; i++)
		{
			neurons.push_back(Neuron(i, 0.0));
		}
	}
}

int Layer::Size_of_layer() const
{
	return numberofneurons;
}

std::vector<Neuron>& Layer::use_neurons()
{
	return neurons;
}
/**
 * For every neuron in neurons container calls neuron class function to initialize their weights.
 * 
 * \param outss
 */
void Layer::initializeweights(int outss)
{
	for (int i = 0; i < Size_of_layer() + 1; i++)
	{
		if (i == Size_of_layer())
		{
			int outs = outss;
			use_neurons()[i].Set_num_of_weights_for_bias(outs);
		}
		else {
			int outs = outss;
			use_neurons()[i].Set_num_of_weights(outs);
		}
	}
}