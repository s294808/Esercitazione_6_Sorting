#include "SortingAlgorithm.hpp"
#include <iostream>
#include <vector>
#include <chrono>

using namespace SortLibrary;
using namespace std::chrono;

using namespace std;

int main(int argc, char* argv[])
{
    //argc: numero di argomenti che sono stati passati al programma, incluso il nome del programma stesso
    //argv: array di puntatori a stringhe, dove ogni elemento dell'array punta alla stringa che rappresenta uno degli argomenti passati al programma
        //L'elemento argv[0] contiene il nome del programma stesso

    // Controlliamo se nel vettore c'è qualche elemento oltre il nome del programma
    if (argc <= 1) {
        cerr << "Non ci sono elementi nel vettore" << endl;
        return 1;
    }


    // Ottieniamo  la dimensione del vettore dalla riga di comando
    int vector_size = atoi(argv[1]);

    // Generiamo un vettore di numeri casuali
    vector<int> random_vector(vector_size);
    for (int i = 0; i < vector_size; i++) {
        random_vector[i] = rand();
    }

    cout << "Il vettore di partenza non ordinato ha dimensione: " << vector_size << endl;

    vector<int> vect_BubbleSort = random_vector;

    auto start_bubble = steady_clock::now();
    BubbleSort(vect_BubbleSort);
    auto stop_bubble = steady_clock::now();
    auto duration_bubble = duration_cast<nanoseconds>(stop_bubble - start_bubble);

    cout << "Tempo di ordinamento tramite l'algoritmo di Bubble Sort per il vettore non ordinato di dimensione  " << vector_size << ": " << duration_bubble.count() << " milliseconds" << endl;

    vector<int> vect_MergeSort = random_vector;

    auto start_merge = steady_clock::now();
    MergeSort(vect_MergeSort);
    auto stop_merge = steady_clock::now();
    auto duration_merge = duration_cast<nanoseconds>(stop_merge - start_merge);

    cout << "Tempo di ordinamento tramite l'algoritmo di Merge Sort per il vettore non ordinato di dimensione  " << vector_size << ": " << duration_merge.count() << " milliseconds" << endl;

    //VETTORI ORDINATI

    cout << "Il vettore di partenza ordinato ha dimensione: " << vector_size << endl;

    vector<int> vect_BubbleSort_ordinato = vect_BubbleSort;

    auto start_bubble_ordinato = steady_clock::now();
    BubbleSort(vect_BubbleSort_ordinato);
    auto stop_bubble_ordinato = steady_clock::now();
    auto duration_bubble_ordinato = duration_cast<nanoseconds>(stop_bubble_ordinato - start_bubble_ordinato);

    cout << "Tempo di ordinamento tramite l'algoritmo di Bubble Sort per il vettore ordinato di dimensione  " << vector_size << ": " << duration_bubble_ordinato.count() << " milliseconds" << endl;

    vector<int> vect_MergeSort_ordinato = vect_MergeSort;

    auto start_merge_ordinato = steady_clock::now();
    MergeSort(vect_MergeSort_ordinato);
    auto stop_merge_ordinato = steady_clock::now();
    auto duration_merge_ordinato = duration_cast<nanoseconds>(stop_merge_ordinato - start_merge_ordinato);

    cout << "Tempo di ordinamento tramite l'algoritmo di Merge Sort per il vettore ordinato di dimensione  " << vector_size << ": " << duration_merge_ordinato.count() << " milliseconds" << endl;

    //*************************************************************************************************************************************************************************************************************
    //CONCLUSIONI:

    cout << "Merge Sort e' un algoritmo di ordinamento, con una complessità temporale di O(n log n), il che lo rende molto efficiente per grandi quantità di dati, garantisce sempre le stesse prestazioni, indipendentemente dall'ordine iniziale degli elementi" << endl;
    cout << "Bubble Sort e' un algoritmo di ordinamento, con una complessità temporale di O(n^2), inefficiente per grandi quantità di dati, ma più adatto per vettori di dimensioni ridotte, garantisce un tempo di esecuzione considerevolmente minore se il vettore è già ordinato" << endl;

    return 0;
}

