#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_POPULATION_SIZE 100

void generate_initial_population(unsigned int population[], unsigned int pop_size) {
    for (unsigned int i = 0; i < pop_size; i++) {
        population[i] = rand();
    }
}

unsigned int hamming_distance(unsigned int a, unsigned int b) {
    unsigned int dist = 0;
    unsigned int val = a ^ b;
    while (val) {
        dist += val & 1;
        val >>= 1;
    }
    return dist;
}

void select_top_k(unsigned int population[], unsigned int fitness[], unsigned int pop_size, unsigned int k) {
    if (k >= pop_size) {
        return;
    }

    // Create an array of indices
    unsigned int indices[MAX_POPULATION_SIZE];
    for (unsigned int i = 0; i < pop_size; i++) {
        indices[i] = i;
    }

    // Sort indices based on fitness values
    for (unsigned int i = 0; i < pop_size - 1; i++) {
        for (unsigned int j = i + 1; j < pop_size; j++) {
            if (fitness[indices[i]] > fitness[indices[j]]) {
                unsigned int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
    }

    // Select top k individuals
    for (unsigned int i = 0; i < k; i++) {
        population[i] = population[indices[i]];
    }
}

void crossover(unsigned int parent1, unsigned int parent2, unsigned int *child1, unsigned int *child2) {
    unsigned int size = 8 * sizeof(unsigned int);
    unsigned int point1 = rand() % size;
    unsigned int point2 = rand() % size;
    if (point1 > point2) { 
        unsigned int temp = point1;
        point1 = point2;
        point2 = temp;
    }
    unsigned int mask1 = ((1U << point1) - 1);
    unsigned int mask2 = ((1U << point2) - 1);
    *child1 = (parent1 & mask1) | (parent2 & ~mask1 & mask2) | (parent1 & ~mask2);
    *child2 = (parent2 & mask1) | (parent1 & ~mask1 & mask2) | (parent2 & ~mask2);
}

void mutate(unsigned int individual, unsigned int pm) {
    if (pm < 0 || pm > 100) {
        return;
    }
    if (rand() % 100 < pm) {
        unsigned int size = 8 * sizeof(unsigned int);
        unsigned int position = rand() % size;
        individual ^= (1U << position);
    }
}

int main() {
    unsigned int pop_size, k;
    unsigned int population[MAX_POPULATION_SIZE];
    unsigned int fitness[MAX_POPULATION_SIZE];
    unsigned int target;

    srand(time(NULL));

    // Read target number
    printf("Enter target unsigned integer: ");
    if (scanf("%u", &target) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    // Read population size
    printf("Enter population size (max %d): ", MAX_POPULATION_SIZE);
    if (scanf("%u", &pop_size) != 1) {
        printf("Invalid input\n");
        return 1;
    }
    if (pop_size > MAX_POPULATION_SIZE) {
        pop_size = MAX_POPULATION_SIZE;
    }

    // Read k
    printf("Enter k (number of top individuals to keep): ");
    if (scanf("%u", &k) != 1) {
        printf("Invalid input\n");
        return 1;
    }
    if (k >= pop_size) {
        k = pop_size - 1;
    }

    // Generate initial population
    generate_initial_population(population, pop_size);

    unsigned int generation = 0;
    const unsigned int max_iter = 100;

    while (generation < max_iter) {
        // Calculate fitness
        for (unsigned int i = 0; i < pop_size; i++) {
            fitness[i] = hamming_distance(population[i], target);
        }

        // Select top k individuals
        select_top_k(population, fitness, pop_size, k);

        // Crossover to generate the rest of the population
        for (unsigned int i = k; i < pop_size; i += 2) {
            unsigned int parent1 = fitness[rand() % k];
            unsigned int parent2 = fitness[rand() % k];
            crossover(parent1, parent2, &population[i], &population[i + 1]);
        }

        // Mutate the new population
        for (unsigned int i = 0; i < pop_size; i++) {
            mutate(population[i], 5);
        }

        generation++;

        if (population[0] == target) {
            printf("Target found after %d generations!", generation);
            return 0;
        }
    }

    // Find the best solution in the final generation
    unsigned int best_solution = population[0];
    unsigned int best_fitness = hamming_distance(population[0], target);
    for (unsigned int i = 1; i < pop_size; i++) {
        unsigned int current_fitness = hamming_distance(population[i], target);
        if (current_fitness < best_fitness) {
            best_fitness = current_fitness;
            best_solution = population[i];
        }
    }

    printf("Best solution found: %u with Hamming distance: %u\n", best_solution, best_fitness);

    return 0;
}