#include <iostream>
#include "Neuralnetwork.h"
#include <vector>
#include <iostream>
#include <fstream>
/**
 * Simple program to check if neural network works corectly by determining xor outcome.
 * Firstly Creates n object of class NeuralNetowrk then adds layers to it and initializes weights.
 * Then it reads xor txt file to get input values and target values.
 * Next part is learning process; during it program couts necessary information about how weights, error and output value changes to
 * determine if network learns corectly.
 * 
 * \return 0
 */
int main()
{
    NeuralNetwork n;
    n.add_layer(2, standard);
    n.add_layer(4, standard);
    n.add_layer(1, output);
    n.Initialize_weights();


    std::vector<double> inputvalues, targetvalues, outputvalues;

    std::string filename("xor.txt");

    double number;
    int numberofepochs = 500;
    std::ifstream input_file(filename);
    if (!input_file.is_open()) {
        std::cerr << "Could not open the file - '"
            << filename << "'" << std::endl;
        return EXIT_FAILURE;
    }

    int random_number = 1;
    while (input_file >> number)
    {
        if (random_number % 3 == 0 && random_number != 0)
        {
            targetvalues.push_back(number);
            random_number++;
        }
        else {
            inputvalues.push_back(number);
            random_number++;
        }
    }

    int counter = 0;
    for (int j = 0; j < 100;j++)
    { 
        std::cout << "Generation: " << j << std::endl;
        for (int i = 0; i < numberofepochs; i++)
        {
            std::vector<double> mininput;
            mininput.push_back(inputvalues[counter]);
            mininput.push_back(inputvalues[counter + 1]);
            std::vector<double> minitarget;
            minitarget.push_back(targetvalues[i]);
            n.set_input(mininput);
            n.Feedforward();
            n.Backpropagation(minitarget);
            n.get_results(outputvalues);
            if (i % 25 == 0) {
                std::cout << i << ": Inputvalues:" << mininput[0] << " " << mininput[1] << std::endl;
                std::cout << "Targets: " << minitarget[0] << std::endl;
                std::cout << "Outputs: " << outputvalues[0] << std::endl;
                std::cout << "error: " << n.totalerrorshow() << std::endl;
                outputvalues.clear();
                counter = counter + 2;
            }
            else {
                outputvalues.clear();
                counter = counter + 2;
            }
        }
        counter = 0;
    }
}
