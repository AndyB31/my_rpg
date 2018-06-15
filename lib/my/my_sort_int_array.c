/*
** EPITECH PROJECT, 2017
** my_sort_int_array
** File description:
** thomas.foubert@epitech.com
*/

void heapify(int *A, int i, int *heap_size)
{
	int k = 2 * i + 1;
	int r = 2 * i + 2;
	int largest = 0;

	if (k <= *heap_size && A[k] > A[i])
		largest = k;
	else
		largest = i;
	if (r <= *heap_size && A[r] > A[largest])
		largest = r;
	if (largest != i) {
		int temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		heapify(A, largest, heap_size);
	}
}

void build_heap(int *A, int size, int *heap_size)
{
	int i = 0;

	*heap_size = size - 1;
	for (i = (size - 1) / 2; i >= 0; i--)
		heapify(A, i, heap_size);
}

void my_sort_int_array(int *tab, int size)
{
	int heap_size = 0;
	int i = 0;
	int temp = 0;

	build_heap(tab, size, &heap_size);
	for (i = size - 1; i > 0; i--) {
		temp = tab[heap_size];
		tab[heap_size] = tab[0];
		tab[0] = temp;
		heap_size--;
		heapify(tab, 0, &heap_size);
	}
}
