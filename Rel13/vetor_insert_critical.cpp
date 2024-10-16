#include <vector>
#include <iostream>
#include <omp.h> 

double conta_complexa(int i) {
    return 2 * i;
}

int main() {
    int N = 10000; 
    std::vector<double> vec;
    
    double start_time = omp_get_wtime();
    
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        double value = conta_complexa(i);
        #pragma omp critical
        {
            vec.push_back(value); 
        }
    }
    
    double end_time = omp_get_wtime(); 
    
    std::cout << "Execution time with #pragma omp critical: " << end_time - start_time << " seconds\n";

    return 0;
}
