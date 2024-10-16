#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <omp.h>
void print_iterations(const std::string& description,
const std::vector< std::vector<int> >& vectors,
const int n)
{
    std::vector< std::string > strings(4, std::string());
for (int i = 0; i != n; i++)
    {
for (int j = 0; j != 4; j++)
        {
const auto& vector = vectors[j];
auto it = std::find(vector.begin(), vector.end(), i);
if (it != vector.end())
            {
                strings[j] += "*";
            }
else 
            { 
                strings[j] += " ";
            }
        }
    }
    std::cout << description << std::endl;
for (auto& s : strings)
    {
        std::cout << s << "\n";
    }
    std::cout << std::endl;
}
template <typename T>
double schedule(T function, 
                const std::string& description, 
                const int n)
{
    std::vector< std::vector<int> > vectors(4, std::vector<int>());
    double start_time = omp_get_wtime();
    function(vectors, n);
    double end_time = omp_get_wtime();
    print_iterations(description, vectors, n);
    return end_time - start_time;
}
void scheduleDefault(std::vector< std::vector<int> >& vectors,
int n)
{
#pragma omp parallel num_threads(4), shared(vectors, n)
    {    
#pragma omp for 
for (int i = 0; i < n; i++)
        {
            vectors[omp_get_thread_num()].push_back(i);
        }
    }
}
void scheduleStatic(std::vector< std::vector<int> >& vectors,
int n)
{
#pragma omp parallel num_threads(4), shared(vectors, n)
    {    
        #pragma omp for schedule(static)
for (int i = 0; i < n; i++)
        {
            vectors[omp_get_thread_num()].push_back(i);
        }
    }
}
void scheduleStatic4(std::vector< std::vector<int> >& vectors,
int n)
{
#pragma omp parallel num_threads(4), shared(vectors, n)
    {    
#pragma omp for schedule(static, 4)
for (int i = 0; i < n; i++)
        {
            vectors[omp_get_thread_num()].push_back(i);
        }
    }
}
void scheduleStatic8(std::vector< std::vector<int> >& vectors,
int n)
{
#pragma omp parallel num_threads(4), shared(vectors, n)
    {    
#pragma omp for schedule(static, 8)
for (int i = 0; i < n; i++)
        {
            vectors[omp_get_thread_num()].push_back(i);
        }
    }
}
void scheduleDynamic(std::vector< std::vector<int> >& vectors,
int n)
{
#pragma omp parallel num_threads(4), shared(vectors, n)
    {    
#pragma omp for schedule(dynamic)
for (int i = 0; i < n; i++)
        {
            vectors[omp_get_thread_num()].push_back(i);
        }
    }
}
void scheduleDynamic1(std::vector< std::vector<int> >& vectors,
int n)
{
#pragma omp parallel num_threads(4), shared(vectors, n)
    {    
#pragma omp for schedule(dynamic, 1)
for (int i = 0; i < n; i++)
        {
            vectors[omp_get_thread_num()].push_back(i);
        }
    }
}
void scheduleDynamic4(std::vector< std::vector<int> >& vectors,
int n)
{
#pragma omp parallel num_threads(4), shared(vectors, n)
    {    
#pragma omp for schedule(dynamic, 4)
for (int i = 0; i < n; i++)
        {
            vectors[omp_get_thread_num()].push_back(i);
        }
    }
}
void scheduleDynamic8(std::vector< std::vector<int> >& vectors,
int n)
{
#pragma omp parallel num_threads(4), shared(vectors, n)
    {    
#pragma omp for schedule(dynamic, 8)
for (int i = 0; i < n; i++)
        {
            vectors[omp_get_thread_num()].push_back(i);
        }
    }
}
void scheduleGuided(std::vector< std::vector<int> >& vectors,
int n)
{
#pragma omp parallel num_threads(4), shared(vectors, n)
    {    
#pragma omp for schedule(guided)
for (int i = 0; i < n; i++)
        {
            vectors[omp_get_thread_num()].push_back(i);
        }
    }
}
void scheduleGuided2(std::vector< std::vector<int> >& vectors,
int n)
{
#pragma omp parallel num_threads(4), shared(vectors, n)
    {    
#pragma omp for schedule(guided, 2)
for (int i = 0; i < n; i++)
        {
            vectors[omp_get_thread_num()].push_back(i);
        }
    }
}
void scheduleGuided4(std::vector< std::vector<int> >& vectors,
int n)
{
#pragma omp parallel num_threads(4), shared(vectors, n)
    {    
#pragma omp for schedule(guided, 4)
for (int i = 0; i < n; i++)
        {
            vectors[omp_get_thread_num()].push_back(i);
        }
    }
}
void scheduleGuided8(std::vector< std::vector<int> >& vectors,
int n)
{
#pragma omp parallel num_threads(4), shared(vectors, n)
    {    
#pragma omp for schedule(guided, 8)
for (int i = 0; i < n; i++)
        {
            vectors[omp_get_thread_num()].push_back(i);
        }
    }
}
void scheduleAuto(std::vector< std::vector<int> >& vectors,
int n)
{
#pragma omp parallel num_threads(4), shared(vectors, n)
    {    
#pragma omp for schedule(auto)
for (int i = 0; i < n; i++)
        {
            vectors[omp_get_thread_num()].push_back(i);
        }
    }
}
void scheduleRuntime(std::vector< std::vector<int> >& vectors,
int n)
{
#pragma omp parallel num_threads(4), shared(vectors, n)
    {    
#pragma omp for schedule(auto)
for (int i = 0; i < n; i++)
        {
            vectors[omp_get_thread_num()].push_back(i);
        }
    }
}
int main()
{
    const int n = 64;
    int num_runs = 3;
    double total_time;

    for (int i = 0; i < num_runs; i++) {
        total_time = schedule(scheduleDefault,  "default:               ", n);
        std::cout << "Execution time (default): " << total_time << " secs\n";
        
        total_time = schedule(scheduleStatic,   "schedule(static):      ", n);
        std::cout << "Execution time (static): " << total_time << " secs\n";
        
        total_time = schedule(scheduleDynamic,  "schedule(dynamic):     ", n);
        std::cout << "Execution time (dynamic): " << total_time << " secs\n";
        
        total_time = schedule(scheduleGuided,   "schedule(guided):      ", n);
        std::cout << "Execution time (guided): " << total_time << " secs\n";
        
        total_time = schedule(scheduleAuto,     "schedule(auto):        ", n);
        std::cout << "Execution time (auto): " << total_time << " secs\n";
    }

    return 0;
}