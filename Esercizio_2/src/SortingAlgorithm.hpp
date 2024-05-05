#ifndef __SORTING_ALGORITHM_H
#define __SORTING_ALGORITHM_H

#include <iostream>
#include <vector>

using namespace std;

namespace SortLibrary {

///FUNZIONE MERGE
    //la funzione Merge combina due sotto-array ordinati in un unico array ordinato
    //Il termine "di tipo T" si riferisce al fatto che la funzione Merge è una funzione template che può operare su un vettore di qualsiasi tipo T
    //Ad esempio, può essere usata con int, double, string, o qualsiasi altro tipo di dato che supporta gli operatori richiesti all'interno della funzione
///PASSO PER PASSO:
    //1. Viene dichiarata la funzione Merge come template che lavora su un vettore di tipo generico T
    //2. Vengono dichiarati quattro parametri:
        // v: il vettore da fondere e ordinare
        // sx: indice di inizio del primo sotto-array.
        // cx: indice di fine del primo sotto-array e inizio del secondo sotto-array
        // dx: indice di fine del secondo sotto-array
    //3. Viene inizializzata una variabile i all'indice di inizio del primo sotto-array e una variabile j all'indice di inizio del secondo sotto-array
    //4. Viene creato un vettore temporaneo b che verrà utilizzato per memorizzare gli elementi fusi ordinati. La dimensione del vettore b viene preventivamente riservata per evitare reallocazioni frequenti durante l'inserimento degli elementi
    //5. Viene eseguito un ciclo while finché non sono stati esaminati tutti gli elementi di entrambi i sotto-array
        //Se l'elemento corrente nell'array v[i] è minore o uguale all'elemento corrente nell'array v[j], l'elemento v[i] viene aggiunto al vettore temporaneo b e l'indice i viene incrementato
        //Altrimenti, l'elemento v[j] viene aggiunto a b e l'indice j viene incrementato
    //6. Se non tutti gli elementi del primo sotto-array sono stati inseriti in b, vengono aggiunti gli elementi rimanenti partendo dall'indice i.
    //7. Se non tutti gli elementi del secondo sotto-array sono stati inseriti in b, vengono aggiunti gli elementi rimanenti partendo dall'indice j.
    //8. i contenuti del vettore temporaneo b vengono copiati nel vettore originale v a partire dall'indice di inizio del primo sotto-array (sx). Questo riordina gli elementi di v nel range specificato.

template<typename T>
void Merge(vector<T>& v,
           const unsigned int& sx,
           const unsigned int& cx,
           const unsigned int& dx){

    unsigned int i = sx;
    unsigned int j = cx + 1;

    vector<T> b;
    b.reserve(dx - sx + 1);

    while( i <= cx && j <= dx)
    {
        if (v[i] <= v[j])
            b.push_back(v[i++]);
        else
            b.push_back(v[j++]);
    }

    if (i <= cx)
        b.insert(b.end(), v.begin() + i, v.begin() + cx + 1);
    if ( j <= dx)
        b.insert(b.end(), v.begin() + j, v.begin() + dx + 1);

    copy(b.begin(), b.end(), v.begin() + sx);

}


///MERGE SORT
    //Merge Sort divide ricorsivamente l'array in due metà, ordina le due metà separatamente e quindi fonde (merge) le due metà ordinate in un'unica sequenza ordinata

template<typename T>
void MergeSort(vector<T>& v,
               const unsigned int& sx,
               const unsigned int& dx){

    //Merge Sort è un algoritmo ricorsivo che si ferma quando l'intervallo che deve ordinare è di dimensione 1, cioè quando l'indice sinistro è uguale all'indice destro
    if (sx < dx)
    {
        //Questa riga calcola l'indice centrale dell'intervallo corrente
        unsigned int cx = (sx + dx) / 2;

        //Queste righe sono le chiamate ricorsive a MergeSort per ordinare le due metà dell'intervallo corrente
        MergeSort(v, sx, cx);
        MergeSort(v, cx + 1, dx);

        //Questa riga chiama la funzione Merge per fondere (merge) le due metà ordinate dell'intervallo corrente in un'unica sequenza ordinata.
        Merge(v, sx, cx, dx);
    }

}

//Prende solo il vettore v come argomento e inizia il processo di ordinamento chiamando la prima MergeSort con gli indici appropriati per ordinare l'intero vettore
template<typename T>
void MergeSort(vector<T>& v){
    MergeSort(v, 0, v.size()-1);
}



///BUBBLE SORT
    //L'algoritmo di Bubble Sort iterativamente attraversa il vettore, confrontando coppie di elementi adiacenti e scambiandoli se sono fuori ordine.
    //Questo processo continua fino a quando non viene completata un'iterazione senza alcuno scambio, indicando che il vettore è stato completamente ordinato.
    //Questa implementazione di Bubble Sort è ottimizzata per ridurre il numero di confronti durante l'ordinamento, poiché interrompe l'iterazione non appena viene completata un'iterazione senza alcuno scambio.

template<typename T>
void BubbleSort(std::vector<T>& data)
{
    //rem_size è la dimensione residua del vettore da considerare durante ogni iterazione.
    //All'inizio, è impostato uguale alla dimensione del vettore.
    size_t rem_size = data.size();

    //last_seen tiene traccia dell'indice dell'ultimo elemento scambiato durante l'iterazione corrente.
    //All'inizio, è impostato uguale alla dimensione del vettore.
    size_t last_seen = rem_size;

    //swapped è un flag che indica se durante l'iterazione corrente sono stati effettuati scambi.
    //È inizializzato a true per garantire che l'algoritmo inizi l'ordinamento.
    bool swapped = true;

    //Il ciclo while continua finché swapped è true, il che significa che durante l'iterazione corrente sono stati effettuati scambi
    while (swapped) {
        swapped = false;

        //scorre il vettore e confronta coppie di elementi adiacenti.
        //Se un elemento è maggiore del successivo, vengono scambiati e il flag swapped viene impostato su true, indicando che è stato effettuato uno scambio durante questa iterazione
        for (size_t i = 1; i < rem_size; i++) {
            if (data[i-1] > data[i]) {
                std::swap(data[i-1], data[i]);
                swapped = true;

                //last_seen viene aggiornato con l'indice dell'ultimo elemento scambiato durante l'iterazione corrente
                last_seen = i;
            }
        }
        //rem_size = rem_size - 1;
        //Alla fine di ogni iterazione, rem_size viene aggiornato con il valore di last_seen, che indica l'indice dell'ultimo elemento scambiato.
        //Questo riduce la dimensione residua del vettore da considerare durante la successiva iterazione, poiché gli elementi dopo last_seen sono già ordinat
        rem_size = last_seen;
    }
}

}

#endif // __SORTING_ALGORITHM_H
