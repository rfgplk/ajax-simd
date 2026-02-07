
#include "../src/simd.hpp"

#include <iostream>

int
main()
{
  // Simple feedforward: output = ReLU(weights * input + bias)

  // 4 inputs
  ajax::vfloat inputs = { 0.5f, -0.3f, 0.8f, -0.2f };
  // Weights for one neuron
  ajax::vfloat weights = { 0.4f, 0.6f, -0.3f, 0.7f };
  // Bias
  float bias = 0.1f;

  std::cout << "Inputs: ";
  for ( size_t i = 0; i < 4; ++i )
    std::cout << inputs[i] << " ";
  std::cout << "\n";

  std::cout << "Weights: ";
  for ( size_t i = 0; i < 4; ++i )
    std::cout << weights[i] << " ";
  std::cout << "\n";

  // Element-wise multiplication
  ajax::vfloat products = inputs * weights;
  std::cout << "Products: ";
  for ( size_t i = 0; i < 4; ++i )
    std::cout << products[i] << " ";
  std::cout << "\n";

  // Sum (dot product)
  float sum = 0.0f;
  for ( size_t i = 0; i < 4; ++i ) {
    sum += products[i];
  }
  sum += bias;

  std::cout << "Weighted sum + bias: " << sum << "\n";

  // ReLU activation
  float output = (sum > 0.0f) ? sum : 0.0f;
  std::cout << "Output (ReLU): " << output << "\n";

  // Batch processing: 8 samples at once
  std::cout << "\nBatch processing (8 samples):\n";
  ajax::wfloat batch_inputs = { 0.5f, -0.3f, 0.8f, -0.2f, 0.6f, -0.1f, 0.7f, 0.4f };
  ajax::wfloat batch_weights = { 0.4f, 0.6f, -0.3f, 0.7f, 0.5f, -0.2f, 0.3f, 0.8f };

  ajax::wfloat batch_products = batch_inputs * batch_weights;
  ajax::wfloat batch_biased = batch_products + 0.1f;

  std::cout << "Batch outputs: ";
  for ( size_t i = 0; i < 8; ++i ) {
    float val = (batch_biased[i] > 0.0f) ? batch_biased[i] : 0.0f;
    std::cout << val << " ";
  }
  std::cout << "\n";
}
