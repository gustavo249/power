/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:47:23 by rcrisan           #+#    #+#             */
/*   Updated: 2015/12/02 16:46:22 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	ft_merge(int *L, int *R, int *A, int lsize, int rsize, int size)
{
	int i;
	int j;
	int k;


	// i - is for the elements in the left sub-array
	// j - is for the elements in the right sub-array
	// k - is for the elements in the original array

	i = 0; j = 0; k = 0;
	while (i < lsize && j < rsize)
	{
		if (L[i] <= R[j])
			A[k++] = L[i++];
		else
			A[k++] = R[j++];
	}
	while (i < lsize)
		A[k++] = L[i++];
	while (j < rsize)
		A[k++] = R[j++];
}

void	ft_mergesort(int *a, int len)
{
	int *left;
	int *right;
	int mid = len / 2;
	int i;

	if (len < 2)
		return ;
	if (!(left = (int*)malloc(sizeof(int) * mid)))
		left = NULL;
	if(!(right = (int*)malloc(sizeof(int) * (len - mid))))
		right = NULL;

	for (i = 0; i < mid; i++)
		left[i] = a[i];
	for (i = mid; i < len; i++)
		right[i - mid] = a[i];

	ft_mergesort(left, mid);
	ft_mergesort(right, len - mid);
	ft_merge(left, right, a, mid, len - mid, len);
	free(left);
	free(right);
}	

int		ft_findkey(int key, int *a, int len)
{
	int mid;
	int min;
	int max;

	min = 0;
	max = len - 1;
	while (min <= max)
	{
		mid = (min + max) / 2;
		if (a[mid] > key)
			max = mid - 1;
		else if (a[mid] < key)
			min = mid + 1;
		else
			return (mid);
	}
	return (0);
}

int main ()
{
	int a[9] = { 9, 5, 2, 7, 4, 1, 8, 3, 6};
	int len = sizeof(a) / sizeof(a[0]);

	ft_mergesort(a, len);
	printf("%d\n", ft_findkey(22, a, len));
	for (int i = 0; i < len; i++)
		printf("%d ", a[i]);

}
