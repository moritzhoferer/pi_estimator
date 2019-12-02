// Moritz Hoferer
// Date: Jan 16, 2019
// Pi = 3.14159265358979323846264338327950288419716939937510582097494459230781640
// 628620899862803482534211706798214808651328230664709384460955058223172535940812
// 8481117450284102701938521105559644622948954930381964428810975665933446128475

#include <iostream>
#include <fstream>
#include <random>
#include <cmath>
#include <vector>

int main(int argc, char **argv) {

    // Set up the random number generator
    std::mt19937 engine;
    engine.seed(314);
    std::uniform_real_distribution<double> random(0., 1.);

    // Initialize all counters
    double pi_estimate;
    unsigned long long int counter = 0;
    unsigned long long int maximum_iterations = strtoul(argv[1], nullptr, 0);
    unsigned long long int next_record = 10;

    std::vector<unsigned long long int> record_iteration;
    std::vector<double> record_estimate;
    std::vector<double> record_deviation;

    std::cout << "Maximum iterations: " << maximum_iterations << std::endl;

    // Start calculation
    for (unsigned long long int i = 0; i <= maximum_iterations; ++i) {

        // Random point inside or outside the circle?
        if (sqrt(pow(random(engine), 2) + pow(random(engine), 2)) <= 1.){
            counter += 1;
        }

        // Write intermediate result in output file
        if (i == next_record){
            pi_estimate = 4. * double(counter) / double(i);
            record_iteration.push_back(i);
            record_estimate.push_back(pi_estimate);
            record_deviation.push_back(std::abs(pi_estimate - M_PI));
            next_record *= 10;
        }

    }

    // Prepare the output file
    std::string output_file_name = "pi.csv";
    std::ofstream output_file;
    output_file.open(output_file_name);
    output_file << "Iterations,Result,Absolute deviation" << std::endl;

    for (unsigned int i = 0; i < record_iteration.size(); ++i){
        output_file << record_iteration[i] << ",";
        output_file << record_estimate[i] << ",",
        output_file << record_deviation[i] << std::endl;
    }
    
    // Finally close the output file
    output_file.close();

    return 0;
}