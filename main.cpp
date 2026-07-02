#include <iostream>
#include "Matrix.h"
#include "Layer.h"
#include "Network.h"
#include "Activations.h"

int main() {
    Network net;
    net.add_layer(Layer(2, 4, relu, relu_derivative));
    net.add_layer(Layer(4, 1, sigmoid, sigmoid_derivative));

    std::vector<std::vector<float>> inputs = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1}
    };

    std::vector<std::vector<float>> expectedOutputs = {
        {0},
        {1},
        {1},
        {0}
    };

    for (int epoch = 0; epoch < 10000; epoch++) {
        for (int i = 0; i < 4; i++) {
            Matrix input(2, 1); // cols, rows
            input.data = inputs[i];

            Matrix expected(1, 1);
            expected.data = expectedOutputs[i];

            Matrix prediction = net.forward(input);
            net.backward(prediction, expected);
        }
    }

    for (int i = 0; i < 4; i++) {
        Matrix input(2, 1);
        input.data = inputs[i];

        Matrix result = net.forward(input);
        std::cout << inputs[i][0] << " XOR " << inputs[i][1] << " = ";
        result.print();
    }

    // save/load
    /*
    net.save("model.txt");
    net.load("model.txt", 0); //expanding loading doesnt trigger a mismatch error size it just expands and randomizes new nodes for training purposes
    */

    return 0;

}



